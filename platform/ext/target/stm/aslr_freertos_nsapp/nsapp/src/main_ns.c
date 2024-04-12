#include "main_ns.h"
#include "FreeRTOS.h"
#include "assert.h"
#include "stm32l562xx.h"
#include "stm32l5xx_hal.h"
#include "stm32l5xx_hal_flash.h"
#include "stm32l5xx_hal_rcc.h"
#include "support.h"
#include "task.h"
#define TFM_SPM_LOG_LEVEL TFM_SPM_LOG_LEVEL_DEBUG

__attribute__((section(".tram_section"))) __attribute__((naked)) void trampoline_A_B(void)
{
    __asm volatile(
        "str      lr,[r10]                   \n" /* Clear RAM before jump */
        "add      r10,#8                   \n" /* Clear RAM before jump */
        "blx      r8                   \n" /* Clear RAM before jump */
        "sub      r10,#8                   \n" /* Clear RAM before jump */
        "ldr      pc,[r10]                      \n" /* Jump to Reset_handler */
    );
}

__attribute__((section(".tram_section"))) __attribute__((naked)) void trampoline_B_A(void)
{
    __asm volatile(
        "str      lr,[r10]                   \n" /* Clear RAM before jump */
        "add      r10,#8                   \n" /* Clear RAM before jump */
        "blx      r8                   \n" /* Clear RAM before jump */
        "sub      r10,#8                   \n" /* Clear RAM before jump */
        "ldr      pc,[r10]                      \n" /* Jump to Reset_handler */
    );
}

__attribute__((section(".tram_section"))) __attribute__((naked)) void trampoline_blx(void)
{
    __asm volatile(
        "str        lr,[r10]                      \n"
        "add        r10,#32                       \n"
        "str        r8,[r10,#-4]                  \n"
        "str        r0,[r10,#-8]                  \n"
        "subs       r0,lr,r8                      \n"
        "cmp.w      r0,#20480                       \n"
        "ble        #8                             \n"/*lr-r8<=0x5000 */
        "b          #-2                             \n"/*lr-r8>0x5000 B to A */
        /*设A为可执行，B不可执行*/
        "ldr        r0,[r10,#-8]                  \n"
        "blx        r8                            \n"
        /*设B为可执行，A不可执行*/
        "b          #24                             \n"/*跳到结尾*/
        "subs       r0,r8,lr                      \n"
        "cmp.w      r0,#20480                       \n"
        "ble        #8                             \n"/*r8-lr<=0x5000 */
        "b          #-2                             \n"/*r8-lr>0x5000 A to B */
        /*设B为可执行，A不可执行*/
        "ldr        r0,[r10,#-8]                  \n"/*恢复r0*/
        "blx        r8                            \n"
        /*设A为可执行，B不可执行*/
        "b          #4                              \n"/*跳到结尾*/
        /*以下说明不跨区域*/
        "ldr        r0,[r10,#-8]                  \n"/*恢复r0*/
        "blx        r8                            \n"
        "sub        r10,#32                       \n" 
        "ldr        pc,[r10]                      \n"
    );
}



static void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_SET);

    /*Configure GPIO pin : LED9_Pin */
    GPIO_InitStruct.Pin = LED9_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(LED9_GPIO_Port, &GPIO_InitStruct);
}

void spin_100000() {
    for (int i = 0; i < 100000; i++) {
        __ASM volatile("nop");
    }
}

void testThread2(void* pvParameters) {
    int a = 0;
    initialise_benchmark();
    int result = benchmark();
    verify_benchmark(result);
    while (1) { 
        a++;
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_3);
        spin_100000();
    }
}

void testThread1(void* pvParameters) {
    // initialise_benchmark();
    // int result = benchmark();
    // assert(verify_benchmark(result));
    //     while (1) {
    //     HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_3);
    //     vTaskDelay(500);
    //   }
    while (1) {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_3);
        for (int i = 0; i < 100000; i++) {
        __ASM volatile("nop");
    }
    }
}

// uint32_t  ctrl_before;
// uint32_t  limit_cfg;
// MPU_Type* mpu;
// #define mpu_region_switch_from_to(region_id1, region_id2) \
//     mpu = (MPU_Type*)MPU_BASE;                            \
//     ctrl_before = mpu->CTRL;                              \
//     mpu->CTRL = 0;                                        \
//     mpu->RNR = region_id1 & 0xff;                         \
//     limit_cfg = mpu->RLAR;                                \
//     limit_cfg &= 0xFFFFFFFE;                              \
//     mpu->RLAR = limit_cfg;                                \
//     mpu->RNR = region_id2 & 0xff;                         \
//     limit_cfg = mpu->RLAR;                                \
//     limit_cfg |= MPU_RLAR_EN_Msk;                         \
//     mpu->RLAR = limit_cfg;                                \
//     mpu->CTRL = ctrl_before;                              \
//     __DSB();                                              \
//     __ISB();

int jzxX(uint16_t a,uint16_t b){
    if(a-b>0x5000){
        trampoline_B_A();
        return a+b+b;
    }else if(b-a>0x5000){
        trampoline_A_B();
        return a+b;
    }else{
        __asm("movw r8,#25069");
        __asm("movt r8,#8192");
        return a;
    }
    //__asm("str      lr,[r10]");
}

int main() {
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    //HAL_Init();
    typedef void (*FunctionPointer)(void);
    FunctionPointer ptr = MX_GPIO_Init;

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */
    ptr();
    //MX_GPIO_Init();

     //testThread2();

    BaseType_t xReturned;

    xReturned = xTaskCreate(
        testThread2,           /* Function that implements the task. */
        "testThread1",         /* Text name for the task. */
        ((uint16_t)300),       /* Stack size in words, not bytes. */
        NULL,                  /* Parameter passed into the task. */
        1 | portPRIVILEGE_BIT, /* Priority at which the task is created. */
        NULL);                 /* Used to pass out the created task's handle. */

    /* 启动调度器 */
    vTaskStartScheduler();



    /* 如果系统正常工作，以下代码不会执行 */
    for (;;){
        trampoline_A_B();
        trampoline_B_A();
        jzxX(1,2);
        trampoline_blx();
    }
}