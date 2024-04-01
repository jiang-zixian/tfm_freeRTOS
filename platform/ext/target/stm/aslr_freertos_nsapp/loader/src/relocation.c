#include "relocation.h"

uint32_t table_size = 697;

relocation_info_t relocation_info[697] = {
    {0x8055000, 0x200033a0, 0},  //__StackTop
    {0x8055004, 0x8055781, 0},  //Reset_Handler
    {0x8055008, 0x80555b9, 0},  //NMI_Handler
    {0x805500c, 0x80555bd, 0},  //HardFault_Handler
    {0x8055010, 0x80555c1, 0},  //MemManage_Handler
    {0x8055014, 0x80555c5, 0},  //BusFault_Handler
    {0x8055018, 0x80555c9, 0},  //UsageFault_Handler
    {0x805501c, 0x80555cd, 0},  //SecureFault_Handler
    {0x805502c, 0x8058fa1, 0},  //SVC_Handler
    {0x8055030, 0x80555d1, 0},  //DebugMon_Handler
    {0x8055038, 0x8058f41, 0},  //PendSV_Handler
    {0x805503c, 0x8058bd9, 0},  //SysTick_Handler
    {0x8055040, 0x80555d5, 0},  //WWDG_IRQHandler
    {0x8055044, 0x80555d9, 0},  //PVD_PVM_IRQHandler
    {0x8055048, 0x80555dd, 0},  //RTC_IRQHandler
    {0x805504c, 0x80555e1, 0},  //RTC_IRQHandler_S
    {0x8055050, 0x80555e5, 0},  //TAMP_IRQHandler
    {0x8055054, 0x80555e9, 0},  //TAMP_IRQHandler_S
    {0x8055058, 0x80555ed, 0},  //FLASH_IRQHandler
    {0x805505c, 0x80555f1, 0},  //FLASH_IRQHandler_S
    {0x8055060, 0x80555f5, 0},  //SERR_IRQHandler
    {0x8055064, 0x80555f9, 0},  //RCC_IRQHandler
    {0x8055068, 0x80555fd, 0},  //RCC_IRQHandler_S
    {0x805506c, 0x8055601, 0},  //EXTI0_IRQHandler
    {0x8055070, 0x8055605, 0},  //EXTI1_IRQHandler
    {0x8055074, 0x8055609, 0},  //EXTI2_IRQHandler
    {0x8055078, 0x805560d, 0},  //EXTI3_IRQHandler
    {0x805507c, 0x8055611, 0},  //EXTI4_IRQHandler
    {0x8055080, 0x8055615, 0},  //EXTI5_IRQHandler
    {0x8055084, 0x8055619, 0},  //EXTI6_IRQHandler
    {0x8055088, 0x805561d, 0},  //EXTI7_IRQHandler
    {0x805508c, 0x8055621, 0},  //EXTI8_IRQHandler
    {0x8055090, 0x8055625, 0},  //EXTI9_IRQHandler
    {0x8055094, 0x8055629, 0},  //EXTI10_IRQHandler
    {0x8055098, 0x805562d, 0},  //EXTI11_IRQHandler
    {0x805509c, 0x8055631, 0},  //EXTI12_IRQHandler
    {0x80550a0, 0x8055635, 0},  //EXTI13_IRQHandler
    {0x80550a4, 0x8055639, 0},  //EXTI14_IRQHandler
    {0x80550a8, 0x805563d, 0},  //EXTI15_IRQHandler
    {0x80550ac, 0x8055641, 0},  //DMAMUX1_IRQHandler
    {0x80550b0, 0x8055645, 0},  //DMAMUX1_IRQHandler_S
    {0x80550b4, 0x8055649, 0},  //DMA1_Channel1_IRQHandler
    {0x80550b8, 0x805564d, 0},  //DMA1_Channel2_IRQHandler
    {0x80550bc, 0x8055651, 0},  //DMA1_Channel3_IRQHandler
    {0x80550c0, 0x8055655, 0},  //DMA1_Channel4_IRQHandler
    {0x80550c4, 0x8055659, 0},  //DMA1_Channel5_IRQHandler
    {0x80550c8, 0x805565d, 0},  //DMA1_Channel6_IRQHandler
    {0x80550cc, 0x8055661, 0},  //DMA1_Channel7_IRQHandler
    {0x80550d0, 0x8055665, 0},  //DMA1_Channel8_IRQHandler
    {0x80550d4, 0x8055669, 0},  //ADC1_2_IRQHandler
    {0x80550d8, 0x805566d, 0},  //DAC_IRQHandler
    {0x80550dc, 0x8055671, 0},  //FDCAN1_IT0_IRQHandler
    {0x80550e0, 0x8055675, 0},  //FDCAN1_IT1_IRQHandler
    {0x80550e4, 0x8055679, 0},  //TIM1_BRK_IRQHandler
    {0x80550e8, 0x805567d, 0},  //TIM1_UP_IRQHandler
    {0x80550ec, 0x8055681, 0},  //TIM1_TRG_COM_IRQHandler
    {0x80550f0, 0x8055685, 0},  //TIM1_CC_IRQHandler
    {0x80550f4, 0x8055689, 0},  //TIM2_IRQHandler
    {0x80550f8, 0x805568d, 0},  //TIM3_IRQHandler
    {0x80550fc, 0x8055691, 0},  //TIM4_IRQHandler
    {0x8055100, 0x8055695, 0},  //TIM5_IRQHandler
    {0x8055104, 0x8055699, 0},  //TIM6_IRQHandler
    {0x8055108, 0x805569d, 0},  //TIM7_IRQHandler
    {0x805510c, 0x80556a1, 0},  //TIM8_BRK_IRQHandler
    {0x8055110, 0x80556a5, 0},  //TIM8_UP_IRQHandler
    {0x8055114, 0x80556a9, 0},  //TIM8_TRG_COM_IRQHandler
    {0x8055118, 0x80556ad, 0},  //TIM8_CC_IRQHandler
    {0x805511c, 0x80556b1, 0},  //I2C1_EV_IRQHandler
    {0x8055120, 0x80556b5, 0},  //I2C1_ER_IRQHandler
    {0x8055124, 0x80556b9, 0},  //I2C2_EV_IRQHandler
    {0x8055128, 0x80556bd, 0},  //I2C2_ER_IRQHandler
    {0x805512c, 0x80556c1, 0},  //SPI1_IRQHandler
    {0x8055130, 0x80556c5, 0},  //SPI2_IRQHandler
    {0x8055134, 0x80556c9, 0},  //USART1_IRQHandler
    {0x8055138, 0x80556cd, 0},  //USART2_IRQHandler
    {0x805513c, 0x80556d1, 0},  //USART3_IRQHandler
    {0x8055140, 0x80556d5, 0},  //UART4_IRQHandler
    {0x8055144, 0x80556d9, 0},  //UART5_IRQHandler
    {0x8055148, 0x80556dd, 0},  //LPUART1_IRQHandler
    {0x805514c, 0x80556e1, 0},  //LPTIM1_IRQHandler
    {0x8055150, 0x80556e5, 0},  //LPTIM2_IRQHandler
    {0x8055154, 0x80556e9, 0},  //TIM15_IRQHandler
    {0x8055158, 0x80556ed, 0},  //TIM16_IRQHandler
    {0x805515c, 0x80556f1, 0},  //TIM17_IRQHandler
    {0x8055160, 0x80556f5, 0},  //COMP_IRQHandler
    {0x8055164, 0x80556f9, 0},  //USB_FS_IRQHandler
    {0x8055168, 0x80556fd, 0},  //CRS_IRQHandler
    {0x805516c, 0x8055701, 0},  //FMC_IRQHandler
    {0x8055170, 0x8055705, 0},  //OCTOSPI1_IRQHandler
    {0x8055178, 0x8055709, 0},  //SDMMC1_IRQHandler
    {0x8055180, 0x805570d, 0},  //DMA2_Channel1_IRQHandler
    {0x8055184, 0x8055711, 0},  //DMA2_Channel2_IRQHandler
    {0x8055188, 0x8055715, 0},  //DMA2_Channel3_IRQHandler
    {0x805518c, 0x8055719, 0},  //DMA2_Channel4_IRQHandler
    {0x8055190, 0x805571d, 0},  //DMA2_Channel5_IRQHandler
    {0x8055194, 0x8055721, 0},  //DMA2_Channel6_IRQHandler
    {0x8055198, 0x8055725, 0},  //DMA2_Channel7_IRQHandler
    {0x805519c, 0x8055729, 0},  //DMA2_Channel8_IRQHandler
    {0x80551a0, 0x805572d, 0},  //I2C3_EV_IRQHandler
    {0x80551a4, 0x8055731, 0},  //I2C3_ER_IRQHandler
    {0x80551a8, 0x8055735, 0},  //SAI1_IRQHandler
    {0x80551ac, 0x8055739, 0},  //SAI2_IRQHandler
    {0x80551b0, 0x805573d, 0},  //TSC_IRQHandler
    {0x80551b4, 0x8055741, 0},  //AES_IRQHandler
    {0x80551b8, 0x8055745, 0},  //RNG_IRQHandler
    {0x80551bc, 0x8055749, 0},  //FPU_IRQHandler
    {0x80551c0, 0x805574d, 0},  //HASH_IRQHandler
    {0x80551c4, 0x8055751, 0},  //PKA_IRQHandler
    {0x80551c8, 0x8055755, 0},  //LPTIM3_IRQHandler
    {0x80551cc, 0x8055759, 0},  //SPI3_IRQHandler
    {0x80551d0, 0x805575d, 0},  //I2C4_ER_IRQHandler
    {0x80551d4, 0x8055761, 0},  //I2C4_EV_IRQHandler
    {0x80551d8, 0x8055765, 0},  //DFSDM1_FLT0_IRQHandler
    {0x80551dc, 0x8055769, 0},  //DFSDM1_FLT1_IRQHandler
    {0x80551e0, 0x805576d, 0},  //DFSDM1_FLT2_IRQHandler
    {0x80551e4, 0x8055771, 0},  //DFSDM1_FLT3_IRQHandler
    {0x80551e8, 0x8055775, 0},  //UCPD1_IRQHandler
    {0x80551ec, 0x8055779, 0},  //ICACHE_IRQHandler
    {0x80551f0, 0x805577d, 0},  //OTFDEC1_IRQHandler
    {0x8055786, 0x200023a0, 5},  //__StackLimit
    {0x805578a, 0x200023a0, 6},  //__StackLimit
    {0x8055796, 0x200033a0, 5},  //__StackTop
    {0x805579a, 0x200033a0, 6},  //__StackTop
    {0x80557b6, 0x8059798, 5},  //__copy_table_start__
    {0x80557ba, 0x8059798, 6},  //__copy_table_start__
    {0x80557c4, 0x80597b0, 5},  //__copy_table_end__
    {0x80557c8, 0x80597b0, 6},  //__copy_table_end__
    {0x8055804, 0x80597b0, 5},  //__zero_table_start__
    {0x8055808, 0x80597b0, 6},  //__zero_table_start__
    {0x8055812, 0x80597c0, 5},  //__zero_table_end__
    {0x8055816, 0x80597c0, 6},  //__zero_table_end__
    {0x8055854, 0x80551f5, 0},  //SystemInit
    {0x8055858, 0x8055861, 0},  //r9Init
    {0x805585c, 0x80558d5, 0},  //main
    {0x80558c4, 0x8056759, 0},  //initialise_benchmark
    {0x80558c8, 0x805675d, 0},  //benchmark
    {0x80558cc, 0x8055593, 0},  //HAL_GPIO_TogglePin
    {0x80558d0, 0x8055867, 0},  //spin_100000
    {0x80558ee, 0x8055891, 5},  //testThread2
    {0x80558f2, 0x8055891, 6},  //testThread2
    {0x80558f6, 0x8059154, 5},  //.L.str
    {0x80558fa, 0x8059154, 6},  //.L.str
    {0x8055914, 0x8055921, 0},  //MX_GPIO_Init
    {0x8055918, 0x8056791, 0},  //xTaskCreate
    {0x805591c, 0x8056eb5, 0},  //vTaskStartScheduler
    {0x8055980, 0x8055567, 0},  //HAL_GPIO_WritePin
    {0x8055984, 0x80551f7, 0},  //HAL_GPIO_Init
    {0x8056784, 0x805668f, 0},  //swi10
    {0x8056788, 0x8056229, 0},  //swi50
    {0x805678c, 0x8055989, 0},  //swi120
    {0x80567ec, 0x80567f5, 0},  //prvCreateTask
    {0x80567f0, 0x80568a5, 0},  //prvAddNewTaskToReadyList
    {0x8056890, 0x8057e35, 0},  //pvPortMalloc
    {0x8056894, 0x8057e35, 0},  //pvPortMalloc
    {0x8056898, 0x80581b9, 0},  //vPortFree
    {0x805689c, 0x80590b1, 0},  //memset
    {0x80568a0, 0x8057615, 0},  //prvInitialiseNewTask
    {0x80568b0, 0x20000128, 5},  //uxCurrentNumberOfTasks
    {0x80568b4, 0x20000128, 6},  //uxCurrentNumberOfTasks
    {0x80568be, 0x20000108, 5},  //pxCurrentTCB
    {0x80568c2, 0x20000108, 6},  //pxCurrentTCB
    {0x80568ce, 0x20000108, 5},  //pxCurrentTCB
    {0x80568d2, 0x20000108, 6},  //pxCurrentTCB
    {0x80568d8, 0x20000128, 5},  //uxCurrentNumberOfTasks
    {0x80568dc, 0x20000128, 6},  //uxCurrentNumberOfTasks
    {0x80568f2, 0x2000012c, 5},  //xSchedulerRunning
    {0x80568f6, 0x2000012c, 6},  //xSchedulerRunning
    {0x8056900, 0x20000108, 5},  //pxCurrentTCB
    {0x8056904, 0x20000108, 6},  //pxCurrentTCB
    {0x8056918, 0x20000108, 5},  //pxCurrentTCB
    {0x805691c, 0x20000108, 6},  //pxCurrentTCB
    {0x805692c, 0x2000010c, 5},  //uxTaskNumber
    {0x8056930, 0x2000010c, 6},  //uxTaskNumber
    {0x8056948, 0x200002a8, 5},  //uxTopReadyPriority
    {0x805694c, 0x200002a8, 6},  //uxTopReadyPriority
    {0x805695c, 0x200002a8, 5},  //uxTopReadyPriority
    {0x8056960, 0x200002a8, 6},  //uxTopReadyPriority
    {0x8056974, 0x20000168, 5},  //pxReadyTasksLists
    {0x8056978, 0x20000168, 6},  //pxReadyTasksLists
    {0x80569cc, 0x2000012c, 5},  //xSchedulerRunning
    {0x80569d0, 0x2000012c, 6},  //xSchedulerRunning
    {0x80569dc, 0x20000108, 5},  //pxCurrentTCB
    {0x80569e0, 0x20000108, 6},  //pxCurrentTCB
    {0x8056a04, 0x8058b75, 0},  //vPortEnterCritical
    {0x8056a08, 0x805773d, 0},  //prvInitialiseTaskLists
    {0x8056a0c, 0x8058b99, 0},  //vPortExitCritical
    {0x8056a10, 0x8058b5b, 0},  //vPortYield
    {0x8056a14, 0x20000138, 5},  //pxDelayedTaskList
    {0x8056a18, 0x20000138, 6},  //pxDelayedTaskList
    {0x8056a24, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x8056a28, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8056a34, 0x20000138, 5},  //pxDelayedTaskList
    {0x8056a38, 0x20000138, 6},  //pxDelayedTaskList
    {0x8056a42, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x8056a46, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8056a6c, 0x80581b9, 0},  //vPortFree
    {0x8056a70, 0x80581b9, 0},  //vPortFree
    {0x8056a74, 0x20000130, 5},  //uxSchedulerSuspended
    {0x8056a78, 0x20000130, 6},  //uxSchedulerSuspended
    {0x8056a8e, 0x20000134, 5},  //xTickCount
    {0x8056a92, 0x20000134, 6},  //xTickCount
    {0x8056a9a, 0x20000108, 5},  //pxCurrentTCB
    {0x8056a9e, 0x20000108, 6},  //pxCurrentTCB
    {0x8056ac2, 0x20000154, 5},  //xSuspendedTaskList
    {0x8056ac6, 0x20000154, 6},  //xSuspendedTaskList
    {0x8056ad0, 0x20000108, 5},  //pxCurrentTCB
    {0x8056ad4, 0x20000108, 6},  //pxCurrentTCB
    {0x8056b0e, 0x20000108, 5},  //pxCurrentTCB
    {0x8056b12, 0x20000108, 6},  //pxCurrentTCB
    {0x8056b24, 0x2000013c, 5},  //pxOverflowDelayedTaskList
    {0x8056b28, 0x2000013c, 6},  //pxOverflowDelayedTaskList
    {0x8056b2e, 0x20000108, 5},  //pxCurrentTCB
    {0x8056b32, 0x20000108, 6},  //pxCurrentTCB
    {0x8056b40, 0x20000138, 5},  //pxDelayedTaskList
    {0x8056b44, 0x20000138, 6},  //pxDelayedTaskList
    {0x8056b4a, 0x20000108, 5},  //pxCurrentTCB
    {0x8056b4e, 0x20000108, 6},  //pxCurrentTCB
    {0x8056b5c, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x8056b60, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8056b6e, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x8056b72, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8056b84, 0x8058477, 0},  //uxListRemove
    {0x8056b88, 0x805840d, 0},  //vListInsert
    {0x8056b8c, 0x805840d, 0},  //vListInsert
    {0x8056ba6, 0x20000130, 5},  //uxSchedulerSuspended
    {0x8056baa, 0x20000130, 6},  //uxSchedulerSuspended
    {0x8056bbc, 0x20000130, 5},  //uxSchedulerSuspended
    {0x8056bc0, 0x20000130, 6},  //uxSchedulerSuspended
    {0x8056bd4, 0x20000128, 5},  //uxCurrentNumberOfTasks
    {0x8056bd8, 0x20000128, 6},  //uxCurrentNumberOfTasks
    {0x8056be8, 0x20000140, 5},  //xPendingReadyList
    {0x8056bec, 0x20000140, 6},  //xPendingReadyList
    {0x8056bfa, 0x20000140, 5},  //xPendingReadyList
    {0x8056bfe, 0x20000140, 6},  //xPendingReadyList
    {0x8056c90, 0x200002a8, 5},  //uxTopReadyPriority
    {0x8056c94, 0x200002a8, 6},  //uxTopReadyPriority
    {0x8056ca4, 0x200002a8, 5},  //uxTopReadyPriority
    {0x8056ca8, 0x200002a8, 6},  //uxTopReadyPriority
    {0x8056cbc, 0x20000168, 5},  //pxReadyTasksLists
    {0x8056cc0, 0x20000168, 6},  //pxReadyTasksLists
    {0x8056d14, 0x20000108, 5},  //pxCurrentTCB
    {0x8056d18, 0x20000108, 6},  //pxCurrentTCB
    {0x8056d28, 0x200002ac, 5},  //xYieldPendings
    {0x8056d2c, 0x200002ac, 6},  //xYieldPendings
    {0x8056d48, 0x200002b8, 5},  //xPendedTicks
    {0x8056d4c, 0x200002b8, 6},  //xPendedTicks
    {0x8056d66, 0x200002ac, 5},  //xYieldPendings
    {0x8056d6a, 0x200002ac, 6},  //xYieldPendings
    {0x8056d88, 0x200002b8, 5},  //xPendedTicks
    {0x8056d8c, 0x200002b8, 6},  //xPendedTicks
    {0x8056d9a, 0x200002ac, 5},  //xYieldPendings
    {0x8056d9e, 0x200002ac, 6},  //xYieldPendings
    {0x8056db0, 0x20000108, 5},  //pxCurrentTCB
    {0x8056db4, 0x20000108, 6},  //pxCurrentTCB
    {0x8056dd4, 0x8058b75, 0},  //vPortEnterCritical
    {0x8056dd8, 0x8056a15, 0},  //prvResetNextTaskUnblockTime
    {0x8056ddc, 0x8056fdd, 0},  //xTaskIncrementTick
    {0x8056de0, 0x8058b5b, 0},  //vPortYield
    {0x8056de4, 0x8058b99, 0},  //vPortExitCritical
    {0x8056de8, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8056df2, 0x20000130, 5},  //uxSchedulerSuspended
    {0x8056df6, 0x20000130, 6},  //uxSchedulerSuspended
    {0x8056e00, 0x200002ac, 5},  //xYieldPendings
    {0x8056e04, 0x200002ac, 6},  //xYieldPendings
    {0x8056e0e, 0x200002ac, 5},  //xYieldPendings
    {0x8056e12, 0x200002ac, 6},  //xYieldPendings
    {0x8056e1c, 0x200002a8, 5},  //uxTopReadyPriority
    {0x8056e20, 0x200002a8, 6},  //uxTopReadyPriority
    {0x8056e30, 0x20000168, 5},  //pxReadyTasksLists
    {0x8056e34, 0x20000168, 6},  //pxReadyTasksLists
    {0x8056e5e, 0x20000168, 5},  //pxReadyTasksLists
    {0x8056e62, 0x20000168, 6},  //pxReadyTasksLists
    {0x8056e8e, 0x20000108, 5},  //pxCurrentTCB
    {0x8056e92, 0x20000108, 6},  //pxCurrentTCB
    {0x8056e9c, 0x200002a8, 5},  //uxTopReadyPriority
    {0x8056ea0, 0x200002a8, 6},  //uxTopReadyPriority
    {0x8056eb0, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8056ede, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x8056ee2, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8056eec, 0x2000012c, 5},  //xSchedulerRunning
    {0x8056ef0, 0x2000012c, 6},  //xSchedulerRunning
    {0x8056ef8, 0x20000134, 5},  //xTickCount
    {0x8056efc, 0x20000134, 6},  //xTickCount
    {0x8056f1c, 0x8059160, 5},  //uxTopUsedPriority
    {0x8056f20, 0x8059160, 6},  //uxTopUsedPriority
    {0x8056f2c, 0x8056f41, 0},  //prvCreateIdleTasks
    {0x8056f30, 0x8057881, 0},  //xTimerCreateTimerTask
    {0x8056f34, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8056f38, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8056f3c, 0x8058d99, 0},  //xPortStartScheduler
    {0x8056f5c, 0x8059164, 5},  //.L.str
    {0x8056f60, 0x8059164, 6},  //.L.str
    {0x8056f8e, 0x80577e5, 5},  //prvIdleTask
    {0x8056f92, 0x80577e5, 6},  //prvIdleTask
    {0x8056f9c, 0x200002b4, 5},  //xIdleTaskHandles
    {0x8056fa0, 0x200002b4, 6},  //xIdleTaskHandles
    {0x8056fd8, 0x8056791, 0},  //xTaskCreate
    {0x8056fe6, 0x20000130, 5},  //uxSchedulerSuspended
    {0x8056fea, 0x20000130, 6},  //uxSchedulerSuspended
    {0x8056ff8, 0x20000134, 5},  //xTickCount
    {0x8056ffc, 0x20000134, 6},  //xTickCount
    {0x8057012, 0x20000138, 5},  //pxDelayedTaskList
    {0x8057016, 0x20000138, 6},  //pxDelayedTaskList
    {0x805702a, 0x20000138, 5},  //pxDelayedTaskList
    {0x805702e, 0x20000138, 6},  //pxDelayedTaskList
    {0x8057036, 0x2000013c, 5},  //pxOverflowDelayedTaskList
    {0x805703a, 0x2000013c, 6},  //pxOverflowDelayedTaskList
    {0x8057046, 0x200002bc, 5},  //xNumOfOverflows
    {0x805704a, 0x200002bc, 6},  //xNumOfOverflows
    {0x8057060, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x8057064, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8057074, 0x20000138, 5},  //pxDelayedTaskList
    {0x8057078, 0x20000138, 6},  //pxDelayedTaskList
    {0x8057084, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x8057088, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8057094, 0x20000138, 5},  //pxDelayedTaskList
    {0x8057098, 0x20000138, 6},  //pxDelayedTaskList
    {0x80570b6, 0x200002b0, 5},  //xNextTaskUnblockTime
    {0x80570ba, 0x200002b0, 6},  //xNextTaskUnblockTime
    {0x8057158, 0x200002a8, 5},  //uxTopReadyPriority
    {0x805715c, 0x200002a8, 6},  //uxTopReadyPriority
    {0x805716c, 0x200002a8, 5},  //uxTopReadyPriority
    {0x8057170, 0x200002a8, 6},  //uxTopReadyPriority
    {0x8057184, 0x20000168, 5},  //pxReadyTasksLists
    {0x8057188, 0x20000168, 6},  //pxReadyTasksLists
    {0x80571dc, 0x20000108, 5},  //pxCurrentTCB
    {0x80571e0, 0x20000108, 6},  //pxCurrentTCB
    {0x80571fc, 0x20000108, 5},  //pxCurrentTCB
    {0x8057200, 0x20000108, 6},  //pxCurrentTCB
    {0x805720c, 0x20000168, 5},  //pxReadyTasksLists
    {0x8057210, 0x20000168, 6},  //pxReadyTasksLists
    {0x8057226, 0x200002ac, 5},  //xYieldPendings
    {0x805722a, 0x200002ac, 6},  //xYieldPendings
    {0x805723e, 0x200002b8, 5},  //xPendedTicks
    {0x8057242, 0x200002b8, 6},  //xPendedTicks
    {0x8057254, 0x8056a15, 0},  //prvResetNextTaskUnblockTime
    {0x8057258, 0x8058f15, 0},  //ulSetInterruptMask
    {0x805725e, 0x20000134, 5},  //xTickCount
    {0x8057262, 0x20000134, 6},  //xTickCount
    {0x805728a, 0x20000108, 5},  //pxCurrentTCB
    {0x805728e, 0x20000108, 6},  //pxCurrentTCB
    {0x80572a8, 0x805840d, 0},  //vListInsert
    {0x80572ac, 0x8056a85, 0},  //prvAddCurrentTaskToDelayedList
    {0x80572b0, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80572d8, 0x20000108, 5},  //pxCurrentTCB
    {0x80572dc, 0x20000108, 6},  //pxCurrentTCB
    {0x8057328, 0x8056a85, 0},  //prvAddCurrentTaskToDelayedList
    {0x805732c, 0x8058f15, 0},  //ulSetInterruptMask
    {0x805738e, 0x20000130, 5},  //uxSchedulerSuspended
    {0x8057392, 0x20000130, 6},  //uxSchedulerSuspended
    {0x80573e6, 0x200002a8, 5},  //uxTopReadyPriority
    {0x80573ea, 0x200002a8, 6},  //uxTopReadyPriority
    {0x80573fa, 0x200002a8, 5},  //uxTopReadyPriority
    {0x80573fe, 0x200002a8, 6},  //uxTopReadyPriority
    {0x8057412, 0x20000168, 5},  //pxReadyTasksLists
    {0x8057416, 0x20000168, 6},  //pxReadyTasksLists
    {0x805746a, 0x20000140, 5},  //xPendingReadyList
    {0x805746e, 0x20000140, 6},  //xPendingReadyList
    {0x80574a8, 0x20000108, 5},  //pxCurrentTCB
    {0x80574ac, 0x20000108, 6},  //pxCurrentTCB
    {0x80574be, 0x200002ac, 5},  //xYieldPendings
    {0x80574c2, 0x200002ac, 6},  //xYieldPendings
    {0x80574d8, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80574e0, 0x200002bc, 5},  //xNumOfOverflows
    {0x80574e4, 0x200002bc, 6},  //xNumOfOverflows
    {0x80574ee, 0x20000134, 5},  //xTickCount
    {0x80574f2, 0x20000134, 6},  //xTickCount
    {0x805752a, 0x20000134, 5},  //xTickCount
    {0x805752e, 0x20000134, 6},  //xTickCount
    {0x8057550, 0x200002bc, 5},  //xNumOfOverflows
    {0x8057554, 0x200002bc, 6},  //xNumOfOverflows
    {0x80575b8, 0x8058b75, 0},  //vPortEnterCritical
    {0x80575bc, 0x80574dd, 0},  //vTaskInternalSetTimeOutState
    {0x80575c0, 0x8058b99, 0},  //vPortExitCritical
    {0x80575c4, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80575c8, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80575cc, 0x200002ac, 5},  //xYieldPendings
    {0x80575d0, 0x200002ac, 6},  //xYieldPendings
    {0x80575dc, 0x2000012c, 5},  //xSchedulerRunning
    {0x80575e0, 0x2000012c, 6},  //xSchedulerRunning
    {0x80575f0, 0x20000130, 5},  //uxSchedulerSuspended
    {0x80575f4, 0x20000130, 6},  //uxSchedulerSuspended
    {0x8057724, 0x80590b1, 0},  //memset
    {0x8057728, 0x80583ff, 0},  //vListInitialiseItem
    {0x805772c, 0x80583ff, 0},  //vListInitialiseItem
    {0x8057730, 0x8058c51, 0},  //pxPortInitialiseStack
    {0x8057734, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8057738, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8057756, 0x20000168, 5},  //pxReadyTasksLists
    {0x805775a, 0x20000168, 6},  //pxReadyTasksLists
    {0x8057770, 0x200002c0, 5},  //xDelayedTaskList1
    {0x8057774, 0x200002c0, 6},  //xDelayedTaskList1
    {0x805777e, 0x200002d4, 5},  //xDelayedTaskList2
    {0x8057782, 0x200002d4, 6},  //xDelayedTaskList2
    {0x805778c, 0x20000140, 5},  //xPendingReadyList
    {0x8057790, 0x20000140, 6},  //xPendingReadyList
    {0x8057798, 0x20000110, 5},  //xTasksWaitingTermination
    {0x805779c, 0x20000110, 6},  //xTasksWaitingTermination
    {0x80577a4, 0x20000154, 5},  //xSuspendedTaskList
    {0x80577a8, 0x20000154, 6},  //xSuspendedTaskList
    {0x80577b4, 0x20000138, 5},  //pxDelayedTaskList
    {0x80577b8, 0x20000138, 6},  //pxDelayedTaskList
    {0x80577be, 0x2000013c, 5},  //pxOverflowDelayedTaskList
    {0x80577c2, 0x2000013c, 6},  //pxOverflowDelayedTaskList
    {0x80577cc, 0x80583d1, 0},  //vListInitialise
    {0x80577d0, 0x80583d1, 0},  //vListInitialise
    {0x80577d4, 0x80583d1, 0},  //vListInitialise
    {0x80577d8, 0x80583d1, 0},  //vListInitialise
    {0x80577dc, 0x80583d1, 0},  //vListInitialise
    {0x80577e0, 0x80583d1, 0},  //vListInitialise
    {0x80577f2, 0x20000168, 5},  //pxReadyTasksLists
    {0x80577f6, 0x20000168, 6},  //pxReadyTasksLists
    {0x805780c, 0x8057815, 0},  //prvCheckTasksWaitingTermination
    {0x8057810, 0x8058b5b, 0},  //vPortYield
    {0x805781c, 0x20000124, 5},  //uxDeletedTasksWaitingCleanUp
    {0x8057820, 0x20000124, 6},  //uxDeletedTasksWaitingCleanUp
    {0x805782e, 0x20000110, 5},  //xTasksWaitingTermination
    {0x8057832, 0x20000110, 6},  //xTasksWaitingTermination
    {0x8057844, 0x20000128, 5},  //uxCurrentNumberOfTasks
    {0x8057848, 0x20000128, 6},  //uxCurrentNumberOfTasks
    {0x8057852, 0x20000124, 5},  //uxDeletedTasksWaitingCleanUp
    {0x8057856, 0x20000124, 6},  //uxDeletedTasksWaitingCleanUp
    {0x8057870, 0x8058b75, 0},  //vPortEnterCritical
    {0x8057874, 0x8058477, 0},  //uxListRemove
    {0x8057878, 0x8058b99, 0},  //vPortExitCritical
    {0x805787c, 0x8056a51, 0},  //prvDeleteTCB
    {0x805788e, 0x200002e8, 5},  //xTimerQueue
    {0x8057892, 0x200002e8, 6},  //xTimerQueue
    {0x805789c, 0x200002ec, 5},  //xTimerTaskHandle
    {0x80578a0, 0x200002ec, 6},  //xTimerTaskHandle
    {0x80578ac, 0x8057999, 5},  //prvTimerTask
    {0x80578b0, 0x8057999, 6},  //prvTimerTask
    {0x80578b4, 0x8059169, 5},  //.L.str
    {0x80578b8, 0x8059169, 6},  //.L.str
    {0x80578e4, 0x80578f1, 0},  //prvCheckForValidListAndQueue
    {0x80578e8, 0x8056791, 0},  //xTaskCreate
    {0x80578ec, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80578fa, 0x200002e8, 5},  //xTimerQueue
    {0x80578fe, 0x200002e8, 6},  //xTimerQueue
    {0x8057908, 0x200002fc, 5},  //xActiveTimerList1
    {0x805790c, 0x200002fc, 6},  //xActiveTimerList1
    {0x8057916, 0x20000310, 5},  //xActiveTimerList2
    {0x805791a, 0x20000310, 6},  //xActiveTimerList2
    {0x8057928, 0x200002f0, 5},  //pxCurrentTimerList
    {0x805792c, 0x200002f0, 6},  //pxCurrentTimerList
    {0x8057932, 0x200002f4, 5},  //pxOverflowTimerList
    {0x8057936, 0x200002f4, 6},  //pxOverflowTimerList
    {0x8057948, 0x200002e8, 5},  //xTimerQueue
    {0x805794c, 0x200002e8, 6},  //xTimerQueue
    {0x8057958, 0x200002e8, 5},  //xTimerQueue
    {0x805795c, 0x200002e8, 6},  //xTimerQueue
    {0x8057962, 0x8059171, 5},  //.L.str.1
    {0x8057966, 0x8059171, 6},  //.L.str.1
    {0x8057980, 0x8058b75, 0},  //vPortEnterCritical
    {0x8057984, 0x80583d1, 0},  //vListInitialise
    {0x8057988, 0x80583d1, 0},  //vListInitialise
    {0x805798c, 0x80585bd, 0},  //xQueueGenericCreate
    {0x8057990, 0x80589ed, 0},  //vQueueAddToRegistry
    {0x8057994, 0x8058b99, 0},  //vPortExitCritical
    {0x80579b8, 0x80579c5, 0},  //prvGetNextExpireTime
    {0x80579bc, 0x8057a05, 0},  //prvProcessTimerOrBlockTask
    {0x80579c0, 0x8057ab1, 0},  //prvProcessReceivedCommands
    {0x80579c8, 0x200002f0, 5},  //pxCurrentTimerList
    {0x80579cc, 0x200002f0, 6},  //pxCurrentTimerList
    {0x80579e6, 0x200002f0, 5},  //pxCurrentTimerList
    {0x80579ea, 0x200002f0, 6},  //pxCurrentTimerList
    {0x8057a44, 0x200002f4, 5},  //pxOverflowTimerList
    {0x8057a48, 0x200002f4, 6},  //pxOverflowTimerList
    {0x8057a5a, 0x200002e8, 5},  //xTimerQueue
    {0x8057a5e, 0x200002e8, 6},  //xTimerQueue
    {0x8057a90, 0x8056a75, 0},  //vTaskSuspendAll
    {0x8057a94, 0x8057c61, 0},  //prvSampleTimeNow
    {0x8057a98, 0x8056b91, 0},  //xTaskResumeAll
    {0x8057a9c, 0x8058a9d, 0},  //vQueueWaitForMessageRestricted
    {0x8057aa0, 0x8056b91, 0},  //xTaskResumeAll
    {0x8057aa4, 0x8058b5b, 0},  //vPortYield
    {0x8057aa8, 0x8056b91, 0},  //xTaskResumeAll
    {0x8057aac, 0x8057cb1, 0},  //prvProcessExpiredTimer
    {0x8057ab8, 0x200002e8, 5},  //xTimerQueue
    {0x8057abc, 0x200002e8, 6},  //xTimerQueue
    {0x8057c3c, 0x8058779, 0},  //xQueueReceive
    {0x8057c40, 0x8058477, 0},  //uxListRemove
    {0x8057c44, 0x8057c61, 0},  //prvSampleTimeNow
    {0x8057c48, 0x80581b9, 0},  //vPortFree
    {0x8057c4c, 0x8057da5, 0},  //prvInsertTimerInActiveList
    {0x8057c50, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8057c54, 0x8057da5, 0},  //prvInsertTimerInActiveList
    {0x8057c58, 0x8057d69, 0},  //prvReloadTimer
    {0x8057c5c, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8057c70, 0x200002f8, 5},  //prvSampleTimeNow.xLastTime
    {0x8057c74, 0x200002f8, 6},  //prvSampleTimeNow.xLastTime
    {0x8057c96, 0x200002f8, 5},  //prvSampleTimeNow.xLastTime
    {0x8057c9a, 0x200002f8, 6},  //prvSampleTimeNow.xLastTime
    {0x8057ca8, 0x805725d, 0},  //xTaskGetTickCount
    {0x8057cac, 0x8057d11, 0},  //prvSwitchTimerLists
    {0x8057cba, 0x200002f0, 5},  //pxCurrentTimerList
    {0x8057cbe, 0x200002f0, 6},  //pxCurrentTimerList
    {0x8057d08, 0x8058477, 0},  //uxListRemove
    {0x8057d0c, 0x8057d69, 0},  //prvReloadTimer
    {0x8057d18, 0x200002f0, 5},  //pxCurrentTimerList
    {0x8057d1c, 0x200002f0, 6},  //pxCurrentTimerList
    {0x8057d28, 0x200002f0, 5},  //pxCurrentTimerList
    {0x8057d2c, 0x200002f0, 6},  //pxCurrentTimerList
    {0x8057d44, 0x200002f0, 5},  //pxCurrentTimerList
    {0x8057d48, 0x200002f0, 6},  //pxCurrentTimerList
    {0x8057d50, 0x200002f4, 5},  //pxOverflowTimerList
    {0x8057d54, 0x200002f4, 6},  //pxOverflowTimerList
    {0x8057d64, 0x8057cb1, 0},  //prvProcessExpiredTimer
    {0x8057da0, 0x8057da5, 0},  //prvInsertTimerInActiveList
    {0x8057de0, 0x200002f4, 5},  //pxOverflowTimerList
    {0x8057de4, 0x200002f4, 6},  //pxOverflowTimerList
    {0x8057e10, 0x200002f0, 5},  //pxCurrentTimerList
    {0x8057e14, 0x200002f0, 6},  //pxCurrentTimerList
    {0x8057e2c, 0x805840d, 0},  //vListInsert
    {0x8057e30, 0x805840d, 0},  //vListInsert
    {0x8057e9c, 0x20000324, 5},  //pxEnd
    {0x8057ea0, 0x20000324, 6},  //pxEnd
    {0x8057ecc, 0x20000328, 5},  //xFreeBytesRemaining
    {0x8057ed0, 0x20000328, 6},  //xFreeBytesRemaining
    {0x8057ede, 0x2000032c, 5},  //xStart
    {0x8057ee2, 0x2000032c, 6},  //xStart
    {0x8057ef0, 0x20000334, 5},  //ucHeap
    {0x8057ef4, 0x20000334, 6},  //ucHeap
    {0x8057f02, 0x20000334, 5},  //ucHeap
    {0x8057f06, 0x20000334, 6},  //ucHeap
    {0x8057f62, 0x20000334, 5},  //ucHeap
    {0x8057f66, 0x20000334, 6},  //ucHeap
    {0x8057f74, 0x20000334, 5},  //ucHeap
    {0x8057f78, 0x20000334, 6},  //ucHeap
    {0x8057fa2, 0x20000324, 5},  //pxEnd
    {0x8057fa6, 0x20000324, 6},  //pxEnd
    {0x8057fc0, 0x20000334, 5},  //ucHeap
    {0x8057fc4, 0x20000334, 6},  //ucHeap
    {0x8057fd2, 0x20000334, 5},  //ucHeap
    {0x8057fd6, 0x20000334, 6},  //ucHeap
    {0x8058068, 0x20000328, 5},  //xFreeBytesRemaining
    {0x805806c, 0x20000328, 6},  //xFreeBytesRemaining
    {0x8058078, 0x20002334, 5},  //xMinimumEverFreeBytesRemaining
    {0x805807c, 0x20002334, 6},  //xMinimumEverFreeBytesRemaining
    {0x8058088, 0x20000328, 5},  //xFreeBytesRemaining
    {0x805808c, 0x20000328, 6},  //xFreeBytesRemaining
    {0x8058092, 0x20002334, 5},  //xMinimumEverFreeBytesRemaining
    {0x8058096, 0x20002334, 6},  //xMinimumEverFreeBytesRemaining
    {0x80580b0, 0x20002338, 5},  //xNumberOfSuccessfulAllocations
    {0x80580b4, 0x20002338, 6},  //xNumberOfSuccessfulAllocations
    {0x80580e8, 0x8056a75, 0},  //vTaskSuspendAll
    {0x80580ec, 0x805810d, 0},  //prvHeapInit
    {0x80580f0, 0x8056b91, 0},  //xTaskResumeAll
    {0x80580f4, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80580f8, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80580fc, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058100, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058104, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058108, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058114, 0x20000334, 5},  //ucHeap
    {0x8058118, 0x20000334, 6},  //ucHeap
    {0x8058138, 0x20000334, 5},  //ucHeap
    {0x805813c, 0x20000334, 6},  //ucHeap
    {0x805814c, 0x2000032c, 5},  //xStart
    {0x8058150, 0x2000032c, 6},  //xStart
    {0x8058172, 0x20000324, 5},  //pxEnd
    {0x8058176, 0x20000324, 6},  //pxEnd
    {0x805819a, 0x20002334, 5},  //xMinimumEverFreeBytesRemaining
    {0x805819e, 0x20002334, 6},  //xMinimumEverFreeBytesRemaining
    {0x80581a8, 0x20000328, 5},  //xFreeBytesRemaining
    {0x80581ac, 0x20000328, 6},  //xFreeBytesRemaining
    {0x80581da, 0x20000334, 5},  //ucHeap
    {0x80581de, 0x20000334, 6},  //ucHeap
    {0x80581ec, 0x20000334, 5},  //ucHeap
    {0x80581f0, 0x20000334, 6},  //ucHeap
    {0x8058264, 0x20000328, 5},  //xFreeBytesRemaining
    {0x8058268, 0x20000328, 6},  //xFreeBytesRemaining
    {0x8058278, 0x2000233c, 5},  //xNumberOfSuccessfulFrees
    {0x805827c, 0x2000233c, 6},  //xNumberOfSuccessfulFrees
    {0x8058298, 0x8056a75, 0},  //vTaskSuspendAll
    {0x805829c, 0x80582b1, 0},  //prvInsertBlockIntoFreeList
    {0x80582a0, 0x8056b91, 0},  //xTaskResumeAll
    {0x80582a4, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80582a8, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80582ac, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80582b8, 0x2000032c, 5},  //xStart
    {0x80582bc, 0x2000032c, 6},  //xStart
    {0x80582dc, 0x2000032c, 5},  //xStart
    {0x80582e0, 0x2000032c, 6},  //xStart
    {0x80582ee, 0x20000334, 5},  //ucHeap
    {0x80582f2, 0x20000334, 6},  //ucHeap
    {0x8058300, 0x20000334, 5},  //ucHeap
    {0x8058304, 0x20000334, 6},  //ucHeap
    {0x805836e, 0x20000324, 5},  //pxEnd
    {0x8058372, 0x20000324, 6},  //pxEnd
    {0x8058398, 0x20000324, 5},  //pxEnd
    {0x805839c, 0x20000324, 6},  //pxEnd
    {0x80583cc, 0x8058f15, 0},  //ulSetInterruptMask
    {0x805859c, 0x8058b75, 0},  //vPortEnterCritical
    {0x80585a0, 0x80583d1, 0},  //vListInitialise
    {0x80585a4, 0x80583d1, 0},  //vListInitialise
    {0x80585a8, 0x8057331, 0},  //xTaskRemoveFromEventList
    {0x80585ac, 0x8058b5b, 0},  //vPortYield
    {0x80585b0, 0x8058b99, 0},  //vPortExitCritical
    {0x80585b4, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80585b8, 0x8058f15, 0},  //ulSetInterruptMask
    {0x805864c, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058650, 0x8057e35, 0},  //pvPortMalloc
    {0x8058654, 0x8058659, 0},  //prvInitialiseNewQueue
    {0x80586a4, 0x80584c1, 0},  //xQueueGenericReset
    {0x8058758, 0x8058b75, 0},  //vPortEnterCritical
    {0x805875c, 0x8058b99, 0},  //vPortExitCritical
    {0x8058760, 0x8058b75, 0},  //vPortEnterCritical
    {0x8058764, 0x8058b99, 0},  //vPortExitCritical
    {0x8058768, 0x8057331, 0},  //xTaskRemoveFromEventList
    {0x805876c, 0x80575cd, 0},  //vTaskMissedYield
    {0x8058770, 0x8057331, 0},  //xTaskRemoveFromEventList
    {0x8058774, 0x80575cd, 0},  //vTaskMissedYield
    {0x8058908, 0x80575db, 0},  //xTaskGetSchedulerState
    {0x805890c, 0x8058b75, 0},  //vPortEnterCritical
    {0x8058910, 0x80574dd, 0},  //vTaskInternalSetTimeOutState
    {0x8058914, 0x8058b99, 0},  //vPortExitCritical
    {0x8058918, 0x8056a75, 0},  //vTaskSuspendAll
    {0x805891c, 0x8058b75, 0},  //vPortEnterCritical
    {0x8058920, 0x8058b99, 0},  //vPortExitCritical
    {0x8058924, 0x8057501, 0},  //xTaskCheckForTimeOut
    {0x8058928, 0x80586a9, 0},  //prvUnlockQueue
    {0x805892c, 0x8056b91, 0},  //xTaskResumeAll
    {0x8058930, 0x80589b9, 0},  //prvIsQueueEmpty
    {0x8058934, 0x80589b9, 0},  //prvIsQueueEmpty
    {0x8058938, 0x80586a9, 0},  //prvUnlockQueue
    {0x805893c, 0x8056b91, 0},  //xTaskResumeAll
    {0x8058940, 0x8057271, 0},  //vTaskPlaceOnEventList
    {0x8058944, 0x80586a9, 0},  //prvUnlockQueue
    {0x8058948, 0x8056b91, 0},  //xTaskResumeAll
    {0x805894c, 0x8058b5b, 0},  //vPortYield
    {0x8058950, 0x8058b99, 0},  //vPortExitCritical
    {0x8058954, 0x8058971, 0},  //prvCopyDataFromQueue
    {0x8058958, 0x8057331, 0},  //xTaskRemoveFromEventList
    {0x805895c, 0x8058b5b, 0},  //vPortYield
    {0x8058960, 0x8058b99, 0},  //vPortExitCritical
    {0x8058964, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058968, 0x8058f15, 0},  //ulSetInterruptMask
    {0x805896c, 0x8058f15, 0},  //ulSetInterruptMask
    {0x80589b4, 0x8058fc5, 0},  //memcpy
    {0x80589e4, 0x8058b75, 0},  //vPortEnterCritical
    {0x80589e8, 0x8058b99, 0},  //vPortExitCritical
    {0x8058a20, 0x20002340, 5},  //xQueueRegistry
    {0x8058a24, 0x20002340, 6},  //xQueueRegistry
    {0x8058a36, 0x20002340, 5},  //xQueueRegistry
    {0x8058a3a, 0x20002340, 6},  //xQueueRegistry
    {0x8058a4e, 0x20002340, 5},  //xQueueRegistry
    {0x8058a52, 0x20002340, 6},  //xQueueRegistry
    {0x8058a60, 0x20002340, 5},  //xQueueRegistry
    {0x8058a64, 0x20002340, 6},  //xQueueRegistry
    {0x8058a98, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058b04, 0x8058b75, 0},  //vPortEnterCritical
    {0x8058b08, 0x8058b99, 0},  //vPortExitCritical
    {0x8058b0c, 0x80572b5, 0},  //vTaskPlaceOnEventListRestricted
    {0x8058b10, 0x80586a9, 0},  //prvUnlockQueue
    {0x8058b2c, 0x20000100, 5},  //SystemCoreClock
    {0x8058b30, 0x20000100, 6},  //SystemCoreClock
    {0x8058b7c, 0x20000104, 5},  //ulCriticalNesting
    {0x8058b80, 0x20000104, 6},  //ulCriticalNesting
    {0x8058b94, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058b9c, 0x20000104, 5},  //ulCriticalNesting
    {0x8058ba0, 0x20000104, 6},  //ulCriticalNesting
    {0x8058bb2, 0x20000104, 5},  //ulCriticalNesting
    {0x8058bb6, 0x20000104, 6},  //ulCriticalNesting
    {0x8058bd0, 0x8058f2b, 0},  //vClearInterruptMask
    {0x8058bd4, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058c08, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058c0c, 0x8056fdd, 0},  //xTaskIncrementTick
    {0x8058c10, 0x8058f2b, 0},  //vClearInterruptMask
    {0x8058c48, 0x8058eb1, 0},  //vRestoreContextOfFirstTask
    {0x8058c4c, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058c7c, 0x8058d5d, 5},  //prvTaskExitError
    {0x8058c80, 0x8058d5d, 6},  //prvTaskExitError
    {0x8058d66, 0x20000104, 5},  //ulCriticalNesting
    {0x8058d6a, 0x20000104, 6},  //ulCriticalNesting
    {0x8058d90, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058d94, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058dc4, 0x20002380, 5},  //ucMaxSysCallPriority
    {0x8058dc8, 0x20002380, 6},  //ucMaxSysCallPriority
    {0x8058e1a, 0x20002384, 5},  //ulMaxPRIGROUPValue
    {0x8058e1e, 0x20002384, 6},  //ulMaxPRIGROUPValue
    {0x8058e2e, 0x20002384, 5},  //ulMaxPRIGROUPValue
    {0x8058e32, 0x20002384, 6},  //ulMaxPRIGROUPValue
    {0x8058e3a, 0x20002384, 5},  //ulMaxPRIGROUPValue
    {0x8058e3e, 0x20002384, 6},  //ulMaxPRIGROUPValue
    {0x8058e78, 0x20000104, 5},  //ulCriticalNesting
    {0x8058e7c, 0x20000104, 6},  //ulCriticalNesting
    {0x8058e98, 0x8058b15, 0},  //vPortSetupTimerInterrupt
    {0x8058e9c, 0x8058ef1, 0},  //vStartFirstTask
    {0x8058ea0, 0x8056ded, 0},  //vTaskSwitchContext
    {0x8058ea4, 0x8058d5d, 0},  //prvTaskExitError
    {0x8058ea8, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058eac, 0x8058f15, 0},  //ulSetInterruptMask
    {0x8058ee0, 0x20000108, 0},  //pxCurrentTCB
    {0x8058f64, 0x8056ded, 4},  //vTaskSwitchContext
    {0x8058f90, 0x20000108, 0},  //pxCurrentTCB
    {0x8058fc0, 0x8058c15, 0},  //vPortSVCHandler_C
};
