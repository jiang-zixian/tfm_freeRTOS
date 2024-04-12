#include "func.h"

uint32_t func_info_size = 205;

func_info_t func_info[205] = {
    {0x8055a13, 112, 0},  //MX_GPIO_Init
    {0x8055cd7, 274, 0},  //prvCreateTask
    {0x8055de9, 384, 0},  //prvAddNewTaskToReadyList
    {0x8056bd7, 318, 0},  //prvInitialiseNewTask
    {0x8056d15, 192, 0},  //prvInitialiseTaskLists
    {0x8055f69, 60, 0},  //prvResetNextTaskUnblockTime
    {0x8055fa5, 42, 0},  //prvDeleteTCB
    {0x8055fdf, 280, 0},  //prvAddCurrentTaskToDelayedList
    {0x80564d3, 158, 0},  //prvCreateIdleTasks
    {0x8056dd5, 56, 0},  //prvIdleTask
    {0x8056e0d, 124, 0},  //prvCheckTasksWaitingTermination
    {0x8056f01, 190, 0},  //prvCheckForValidListAndQueue
    {0x8056fbf, 56, 0},  //prvTimerTask
    {0x8056ff7, 64, 0},  //prvGetNextExpireTime
    {0x8057037, 202, 0},  //prvProcessTimerOrBlockTask
    {0x8057101, 466, 0},  //prvProcessReceivedCommands
    {0x80572d3, 86, 0},  //prvSampleTimeNow
    {0x8057329, 104, 0},  //prvProcessExpiredTimer
    {0x805742d, 152, 0},  //prvInsertTimerInActiveList
    {0x80573ed, 64, 0},  //prvReloadTimer
    {0x8057391, 92, 0},  //prvSwitchTimerLists
    {0x80577bf, 170, 0},  //prvHeapInit
    {0x8057979, 292, 0},  //prvInsertBlockIntoFreeList
    {0x8057d4d, 82, 0},  //prvInitialiseNewQueue
    {0x8057d9f, 240, 0},  //prvUnlockQueue
    {0x805813b, 58, 0},  //prvIsQueueEmpty
    {0x80580ef, 76, 0},  //prvCopyDataFromQueue
    {0x8058509, 68, 0},  //prvTaskExitError
    {0x8055609, 4, 0},  //EXTI2_IRQHandler
    {0x80556a9, 4, 0},  //TIM8_TRG_COM_IRQHandler
    {0x80556ad, 4, 0},  //TIM8_CC_IRQHandler
    {0x8055615, 4, 0},  //EXTI5_IRQHandler
    {0x80555d1, 4, 0},  //DebugMon_Handler
    {0x8058335, 72, 0},  //vPortExitCritical
    {0x8055635, 4, 0},  //EXTI13_IRQHandler
    {0x805867d, 44, 0},  //vRestoreContextOfFirstTask
    {0x8055685, 4, 0},  //TIM1_CC_IRQHandler
    {0x805573d, 4, 0},  //TSC_IRQHandler
    {0x80555bd, 4, 0},  //HardFault_Handler
    {0x8058229, 134, 0},  //vQueueWaitForMessageRestricted
    {0x80555e5, 4, 0},  //TAMP_IRQHandler
    {0x8055699, 4, 0},  //TIM6_IRQHandler
    {0x8055631, 4, 0},  //EXTI12_IRQHandler
    {0x805837d, 72, 0},  //SysTick_Handler
    {0x8055909, 126, 0},  //jzxX
    {0x8055567, 44, 0},  //HAL_GPIO_WritePin
    {0x8055bdf, 50, 0},  //RandomInteger
    {0x8058913, 18, 0},  //trampoline_A_B
    {0x80586f1, 80, 0},  //PendSV_Handler
    {0x8055729, 4, 0},  //DMA2_Channel8_IRQHandler
    {0x80555b9, 4, 0},  //NMI_Handler
    {0x805560d, 4, 0},  //EXTI3_IRQHandler
    {0x8055621, 4, 0},  //EXTI8_IRQHandler
    {0x80556e5, 4, 0},  //LPTIM2_IRQHandler
    {0x8055769, 4, 0},  //DFSDM1_FLT1_IRQHandler
    {0x8055593, 38, 0},  //HAL_GPIO_TogglePin
    {0x80556f9, 4, 0},  //USB_FS_IRQHandler
    {0x80586c9, 22, 0},  //ulSetInterruptMask
    {0x8055731, 4, 0},  //I2C3_ER_IRQHandler
    {0x805576d, 4, 0},  //DFSDM1_FLT2_IRQHandler
    {0x8056a8d, 36, 0},  //vTaskInternalSetTimeOutState
    {0x8055a9d, 26, 0},  //Test
    {0x80551f7, 880, 0},  //HAL_GPIO_Init
    {0x8055641, 4, 0},  //DMAMUX1_IRQHandler
    {0x8055755, 4, 0},  //LPTIM3_IRQHandler
    {0x80555f5, 4, 0},  //SERR_IRQHandler
    {0x80586a9, 32, 0},  //vStartFirstTask
    {0x805854d, 304, 0},  //xPortStartScheduler
    {0x8058761, 236, 0},  //memcpy
    {0x805680d, 78, 0},  //vTaskPlaceOnEventList
    {0x80582af, 70, 0},  //vPortSetupTimerInterrupt
    {0x8055601, 4, 0},  //EXTI0_IRQHandler
    {0x80556b9, 4, 0},  //I2C2_EV_IRQHandler
    {0x8057869, 272, 0},  //vPortFree
    {0x8055749, 4, 0},  //FPU_IRQHandler
    {0x8058937, 70, 0},  //trampoline_blx
    {0x8055675, 4, 0},  //FDCAN1_IT1_IRQHandler
    {0x80555fd, 4, 0},  //RCC_IRQHandler_S
    {0x8055645, 4, 0},  //DMAMUX1_IRQHandler_S
    {0x80555c9, 4, 0},  //UsageFault_Handler
    {0x8055669, 4, 0},  //ADC1_2_IRQHandler
    {0x80556c1, 4, 0},  //SPI1_IRQHandler
    {0x8055705, 4, 0},  //OCTOSPI1_IRQHandler
    {0x8057acb, 14, 0},  //vListInitialiseItem
    {0x8057e8f, 608, 0},  //xQueueReceive
    {0x80556a5, 4, 0},  //TIM8_UP_IRQHandler
    {0x8055c11, 14, 0},  //InitSeed
    {0x8055711, 4, 0},  //DMA2_Channel2_IRQHandler
    {0x8055655, 4, 0},  //DMA1_Channel4_IRQHandler
    {0x8055739, 4, 0},  //SAI2_IRQHandler
    {0x80574c5, 762, 0},  //pvPortMalloc
    {0x8055771, 4, 0},  //DFSDM1_FLT3_IRQHandler
    {0x8055751, 4, 0},  //PKA_IRQHandler
    {0x8057a9d, 46, 0},  //vListInitialise
    {0x805563d, 4, 0},  //EXTI15_IRQHandler
    {0x80556f1, 4, 0},  //TIM17_IRQHandler
    {0x80556d1, 4, 0},  //USART3_IRQHandler
    {0x80567f9, 20, 0},  //xTaskGetTickCount
    {0x80555dd, 4, 0},  //RTC_IRQHandler
    {0x8055625, 4, 0},  //EXTI9_IRQHandler
    {0x8055661, 4, 0},  //DMA1_Channel7_IRQHandler
    {0x8055781, 234, 0},  //Reset_Handler
    {0x80556d9, 4, 0},  //UART5_IRQHandler
    {0x80583c5, 58, 0},  //vPortSVCHandler_C
    {0x80568df, 430, 0},  //xTaskRemoveFromEventList
    {0x8055691, 4, 0},  //TIM4_IRQHandler
    {0x805570d, 4, 0},  //DMA2_Channel1_IRQHandler
    {0x80556b1, 4, 0},  //I2C1_EV_IRQHandler
    {0x805565d, 4, 0},  //DMA1_Channel6_IRQHandler
    {0x80556ed, 4, 0},  //TIM16_IRQHandler
    {0x80556d5, 4, 0},  //UART4_IRQHandler
    {0x8055719, 4, 0},  //DMA2_Channel4_IRQHandler
    {0x80555cd, 4, 0},  //SecureFault_Handler
    {0x8056ab1, 224, 0},  //xTaskCheckForTimeOut
    {0x805568d, 4, 0},  //TIM3_IRQHandler
    {0x80555f9, 4, 0},  //RCC_IRQHandler
    {0x8055681, 4, 0},  //TIM1_TRG_COM_IRQHandler
    {0x8055649, 4, 0},  //DMA1_Channel1_IRQHandler
    {0x8055725, 4, 0},  //DMA2_Channel7_IRQHandler
    {0x8055fcf, 16, 0},  //vTaskSuspendAll
    {0x8057b43, 72, 0},  //uxListRemove
    {0x8055c45, 42, 0},  //verify_benchmark
    {0x805577d, 4, 0},  //OTFDEC1_IRQHandler
    {0x8055665, 4, 0},  //DMA1_Channel8_IRQHandler
    {0x805636b, 202, 0},  //vTaskSwitchContext
    {0x805685b, 132, 0},  //vTaskPlaceOnEventListRestricted
    {0x80555f1, 4, 0},  //FLASH_IRQHandler_S
    {0x805569d, 4, 0},  //TIM7_IRQHandler
    {0x8055709, 4, 0},  //SDMMC1_IRQHandler
    {0x8055695, 4, 0},  //TIM5_IRQHandler
    {0x8055775, 4, 0},  //UCPD1_IRQHandler
    {0x80556e9, 4, 0},  //TIM15_IRQHandler
    {0x805572d, 4, 0},  //I2C3_EV_IRQHandler
    {0x80582f5, 24, 0},  //vPortYield
    {0x8055a83, 26, 0},  //benchmark
    {0x80555d9, 4, 0},  //PVD_PVM_IRQHandler
    {0x80556c5, 4, 0},  //SPI2_IRQHandler
    {0x805884d, 164, 0},  //memset
    {0x80555c1, 4, 0},  //MemManage_Handler
    {0x8055987, 140, 0},  //main
    {0x8055639, 4, 0},  //EXTI14_IRQHandler
    {0x805562d, 4, 0},  //EXTI11_IRQHandler
    {0x8057ad9, 106, 0},  //vListInsert
    {0x8058741, 32, 0},  //SVC_Handler
    {0x805571d, 4, 0},  //DMA2_Channel5_IRQHandler
    {0x80556fd, 4, 0},  //CRS_IRQHandler
    {0x8056e89, 120, 0},  //xTimerCreateTimerTask
    {0x8055659, 4, 0},  //DMA1_Channel5_IRQHandler
    {0x8055611, 4, 0},  //EXTI4_IRQHandler
    {0x8057ca7, 166, 0},  //xQueueGenericCreate
    {0x80551f5, 2, 0},  //SystemInit
    {0x8055745, 4, 0},  //RNG_IRQHandler
    {0x8055881, 40, 0},  //spin_100000
    {0x8055c1f, 38, 0},  //initialise_benchmark
    {0x80560f7, 628, 0},  //xTaskResumeAll
    {0x8056435, 158, 0},  //vTaskStartScheduler
    {0x8055651, 4, 0},  //DMA1_Channel3_IRQHandler
    {0x80556f5, 4, 0},  //COMP_IRQHandler
    {0x805567d, 4, 0},  //TIM1_UP_IRQHandler
    {0x80555d5, 4, 0},  //WWDG_IRQHandler
    {0x8055761, 4, 0},  //I2C4_EV_IRQHandler
    {0x8056b91, 14, 0},  //vTaskMissedYield
    {0x80556dd, 4, 0},  //LPUART1_IRQHandler
    {0x8055721, 4, 0},  //DMA2_Channel6_IRQHandler
    {0x8055671, 4, 0},  //FDCAN1_IT0_IRQHandler
    {0x8055689, 4, 0},  //TIM2_IRQHandler
    {0x8055ab7, 204, 0},  //Sum
    {0x8058175, 180, 0},  //vQueueAddToRegistry
    {0x8056571, 648, 0},  //xTaskIncrementTick
    {0x80586df, 14, 0},  //vClearInterruptMask
    {0x805561d, 4, 0},  //EXTI7_IRQHandler
    {0x8055679, 4, 0},  //TIM1_BRK_IRQHandler
    {0x805566d, 4, 0},  //DAC_IRQHandler
    {0x8055605, 4, 0},  //EXTI1_IRQHandler
    {0x80555e1, 4, 0},  //RTC_IRQHandler_S
    {0x8057b8b, 284, 0},  //xQueueGenericReset
    {0x8055741, 4, 0},  //AES_IRQHandler
    {0x80558a9, 96, 0},  //testThread2
    {0x8055c6f, 104, 0},  //xTaskCreate
    {0x80556cd, 4, 0},  //USART2_IRQHandler
    {0x8055765, 4, 0},  //DFSDM1_FLT0_IRQHandler
    {0x80556bd, 4, 0},  //I2C2_ER_IRQHandler
    {0x805564d, 4, 0},  //DMA1_Channel2_IRQHandler
    {0x80556a1, 4, 0},  //TIM8_BRK_IRQHandler
    {0x8056b9f, 56, 0},  //xTaskGetSchedulerState
    {0x80555ed, 4, 0},  //FLASH_IRQHandler
    {0x805586b, 22, 0},  //r9Init
    {0x8055b83, 92, 0},  //Initialize
    {0x80555c5, 4, 0},  //BusFault_Handler
    {0x80556c9, 4, 0},  //USART1_IRQHandler
    {0x8055629, 4, 0},  //EXTI10_IRQHandler
    {0x80583ff, 266, 0},  //pxPortInitialiseStack
    {0x8055759, 4, 0},  //SPI3_IRQHandler
    {0x8058925, 18, 0},  //trampoline_B_A
    {0x80556b5, 4, 0},  //I2C1_ER_IRQHandler
    {0x8055701, 4, 0},  //FMC_IRQHandler
    {0x805830d, 40, 0},  //vPortEnterCritical
    {0x8055619, 4, 0},  //EXTI6_IRQHandler
    {0x80556e1, 4, 0},  //LPTIM1_IRQHandler
    {0x805575d, 4, 0},  //I2C4_ER_IRQHandler
    {0x8055779, 4, 0},  //ICACHE_IRQHandler
    {0x80555e9, 4, 0},  //TAMP_IRQHandler_S
    {0x8055735, 4, 0},  //SAI1_IRQHandler
    {0x805574d, 4, 0},  //HASH_IRQHandler
    {0x8055715, 4, 0},  //DMA2_Channel3_IRQHandler
};
uint32_t trampoline_A_B_addr=0x8058913;
uint32_t trampoline_B_A_addr=0x8058925;
