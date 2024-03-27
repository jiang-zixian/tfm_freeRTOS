#include "func.h"

uint32_t func_info_size = 137;

func_info_t func_info[137] = {
    {0x8055905, 96, 0},  //MX_GPIO_Init
    {0x8055615, 4, 0},  //EXTI2_IRQHandler
    {0x80556b5, 4, 0},  //TIM8_TRG_COM_IRQHandler
    {0x80556b9, 4, 0},  //TIM8_CC_IRQHandler
    {0x8055621, 4, 0},  //EXTI5_IRQHandler
    {0x80555d5, 4, 0},  //DebugMon_Handler
    {0x8055641, 4, 0},  //EXTI13_IRQHandler
    {0x8055691, 4, 0},  //TIM1_CC_IRQHandler
    {0x8055749, 4, 0},  //TSC_IRQHandler
    {0x80555bd, 4, 0},  //HardFault_Handler
    {0x80555f1, 4, 0},  //TAMP_IRQHandler
    {0x80556a5, 4, 0},  //TIM6_IRQHandler
    {0x805563d, 4, 0},  //EXTI12_IRQHandler
    {0x80555dd, 4, 0},  //SysTick_Handler
    {0x8055567, 44, 0},  //HAL_GPIO_WritePin
    {0x8055aa9, 50, 0},  //RandomInteger
    {0x80555d9, 4, 0},  //PendSV_Handler
    {0x805588d, 4, 0},  //foo2
    {0x8055735, 4, 0},  //DMA2_Channel8_IRQHandler
    {0x80555b9, 4, 0},  //NMI_Handler
    {0x8055619, 4, 0},  //EXTI3_IRQHandler
    {0x805562d, 4, 0},  //EXTI8_IRQHandler
    {0x80556f1, 4, 0},  //LPTIM2_IRQHandler
    {0x8055775, 4, 0},  //DFSDM1_FLT1_IRQHandler
    {0x8055593, 38, 0},  //HAL_GPIO_TogglePin
    {0x8055891, 4, 0},  //foo3
    {0x8055705, 4, 0},  //USB_FS_IRQHandler
    {0x805573d, 4, 0},  //I2C3_ER_IRQHandler
    {0x8055779, 4, 0},  //DFSDM1_FLT2_IRQHandler
    {0x8055977, 18, 0},  //Test
    {0x80551f7, 880, 0},  //HAL_GPIO_Init
    {0x805564d, 4, 0},  //DMAMUX1_IRQHandler
    {0x8055761, 4, 0},  //LPTIM3_IRQHandler
    {0x8055601, 4, 0},  //SERR_IRQHandler
    {0x805560d, 4, 0},  //EXTI0_IRQHandler
    {0x80556c5, 4, 0},  //I2C2_EV_IRQHandler
    {0x8055755, 4, 0},  //FPU_IRQHandler
    {0x8055681, 4, 0},  //FDCAN1_IT1_IRQHandler
    {0x8055609, 4, 0},  //RCC_IRQHandler_S
    {0x8055651, 4, 0},  //DMAMUX1_IRQHandler_S
    {0x80555c9, 4, 0},  //UsageFault_Handler
    {0x8055675, 4, 0},  //ADC1_2_IRQHandler
    {0x80556cd, 4, 0},  //SPI1_IRQHandler
    {0x8055711, 4, 0},  //OCTOSPI1_IRQHandler
    {0x80556b1, 4, 0},  //TIM8_UP_IRQHandler
    {0x8055adb, 14, 0},  //InitSeed
    {0x805571d, 4, 0},  //DMA2_Channel2_IRQHandler
    {0x8055661, 4, 0},  //DMA1_Channel4_IRQHandler
    {0x8055745, 4, 0},  //SAI2_IRQHandler
    {0x805577d, 4, 0},  //DFSDM1_FLT3_IRQHandler
    {0x805575d, 4, 0},  //PKA_IRQHandler
    {0x8055649, 4, 0},  //EXTI15_IRQHandler
    {0x80556fd, 4, 0},  //TIM17_IRQHandler
    {0x80556dd, 4, 0},  //USART3_IRQHandler
    {0x80555e9, 4, 0},  //RTC_IRQHandler
    {0x8055631, 4, 0},  //EXTI9_IRQHandler
    {0x805566d, 4, 0},  //DMA1_Channel7_IRQHandler
    {0x805578d, 210, 0},  //Reset_Handler
    {0x80556e5, 4, 0},  //UART5_IRQHandler
    {0x805569d, 4, 0},  //TIM4_IRQHandler
    {0x8055719, 4, 0},  //DMA2_Channel1_IRQHandler
    {0x80556bd, 4, 0},  //I2C1_EV_IRQHandler
    {0x8055669, 4, 0},  //DMA1_Channel6_IRQHandler
    {0x80556f9, 4, 0},  //TIM16_IRQHandler
    {0x80556e1, 4, 0},  //UART4_IRQHandler
    {0x8055725, 4, 0},  //DMA2_Channel4_IRQHandler
    {0x80555cd, 4, 0},  //SecureFault_Handler
    {0x8055699, 4, 0},  //TIM3_IRQHandler
    {0x8055605, 4, 0},  //RCC_IRQHandler
    {0x805568d, 4, 0},  //TIM1_TRG_COM_IRQHandler
    {0x8055655, 4, 0},  //DMA1_Channel1_IRQHandler
    {0x8055731, 4, 0},  //DMA2_Channel7_IRQHandler
    {0x8055aff, 42, 0},  //verify_benchmark
    {0x8055789, 4, 0},  //OTFDEC1_IRQHandler
    {0x8055671, 4, 0},  //DMA1_Channel8_IRQHandler
    {0x80555fd, 4, 0},  //FLASH_IRQHandler_S
    {0x80556a9, 4, 0},  //TIM7_IRQHandler
    {0x8055715, 4, 0},  //SDMMC1_IRQHandler
    {0x80556a1, 4, 0},  //TIM5_IRQHandler
    {0x8055781, 4, 0},  //UCPD1_IRQHandler
    {0x80556f5, 4, 0},  //TIM15_IRQHandler
    {0x8055739, 4, 0},  //I2C3_EV_IRQHandler
    {0x8055965, 18, 0},  //benchmark
    {0x80555e5, 4, 0},  //PVD_PVM_IRQHandler
    {0x80556d1, 4, 0},  //SPI2_IRQHandler
    {0x80555c1, 4, 0},  //MemManage_Handler
    {0x80558cd, 56, 0},  //main
    {0x8055645, 4, 0},  //EXTI14_IRQHandler
    {0x8055639, 4, 0},  //EXTI11_IRQHandler
    {0x80555d1, 4, 0},  //SVC_Handler
    {0x8055729, 4, 0},  //DMA2_Channel5_IRQHandler
    {0x8055709, 4, 0},  //CRS_IRQHandler
    {0x8055665, 4, 0},  //DMA1_Channel5_IRQHandler
    {0x805561d, 4, 0},  //EXTI4_IRQHandler
    {0x80551f5, 2, 0},  //SystemInit
    {0x8055751, 4, 0},  //RNG_IRQHandler
    {0x8055865, 40, 0},  //spin_100000
    {0x8055ae9, 22, 0},  //initialise_benchmark
    {0x805565d, 4, 0},  //DMA1_Channel3_IRQHandler
    {0x8055701, 4, 0},  //COMP_IRQHandler
    {0x8055689, 4, 0},  //TIM1_UP_IRQHandler
    {0x80555e1, 4, 0},  //WWDG_IRQHandler
    {0x805576d, 4, 0},  //I2C4_EV_IRQHandler
    {0x80556e9, 4, 0},  //LPUART1_IRQHandler
    {0x805572d, 4, 0},  //DMA2_Channel6_IRQHandler
    {0x805567d, 4, 0},  //FDCAN1_IT0_IRQHandler
    {0x8055695, 4, 0},  //TIM2_IRQHandler
    {0x8055989, 204, 0},  //Sum
    {0x8055895, 56, 0},  //foo
    {0x8055629, 4, 0},  //EXTI7_IRQHandler
    {0x8055685, 4, 0},  //TIM1_BRK_IRQHandler
    {0x8055679, 4, 0},  //DAC_IRQHandler
    {0x8055611, 4, 0},  //EXTI1_IRQHandler
    {0x80555ed, 4, 0},  //RTC_IRQHandler_S
    {0x805574d, 4, 0},  //AES_IRQHandler
    {0x80556d9, 4, 0},  //USART2_IRQHandler
    {0x8055771, 4, 0},  //DFSDM1_FLT0_IRQHandler
    {0x80556c9, 4, 0},  //I2C2_ER_IRQHandler
    {0x8055659, 4, 0},  //DMA1_Channel2_IRQHandler
    {0x80556ad, 4, 0},  //TIM8_BRK_IRQHandler
    {0x80555f9, 4, 0},  //FLASH_IRQHandler
    {0x805585f, 6, 0},  //r9Init
    {0x8055a55, 84, 0},  //Initialize
    {0x80555c5, 4, 0},  //BusFault_Handler
    {0x80556d5, 4, 0},  //USART1_IRQHandler
    {0x8055635, 4, 0},  //EXTI10_IRQHandler
    {0x8055765, 4, 0},  //SPI3_IRQHandler
    {0x80556c1, 4, 0},  //I2C1_ER_IRQHandler
    {0x805570d, 4, 0},  //FMC_IRQHandler
    {0x8055625, 4, 0},  //EXTI6_IRQHandler
    {0x80556ed, 4, 0},  //LPTIM1_IRQHandler
    {0x8055769, 4, 0},  //I2C4_ER_IRQHandler
    {0x8055785, 4, 0},  //ICACHE_IRQHandler
    {0x80555f5, 4, 0},  //TAMP_IRQHandler_S
    {0x8055741, 4, 0},  //SAI1_IRQHandler
    {0x8055759, 4, 0},  //HASH_IRQHandler
    {0x8055721, 4, 0},  //DMA2_Channel3_IRQHandler
};
