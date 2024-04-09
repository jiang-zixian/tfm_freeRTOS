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
    // initialise_benchmark();
    // int result = benchmark();
    // verify_benchmark(result);
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

int main() {
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    //HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    MX_GPIO_Init();

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
    }
}