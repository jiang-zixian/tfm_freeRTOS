/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    GPIO/GPIO_IOToggle_TrustZone/Secure/Src/stm32l5xx_it.c
 * @author  MCD Application Team
 * @brief   Secure Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "stm32l5xx_it.h"
#include "main.h"
#include "stm32l5xx/hal/Inc/stm32l5xx_hal_rng.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "aslr_queue.h"
#include "aslr_stack.h"
#include "funcs.h"
#include "aslr_heap.h"
#include "mpu_aslr.h"
#include "ins_tool.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern RNG_HandleTypeDef hrng;
/* USER CODE BEGIN EV */
// typedef funcptr funcptr_NS;
// funcptr_NS pSecureFaultCallback;
// extern funcptr_NS pSecureErrorCallback;

/* USER CODE END EV */
/********************ASLR DEPLOYMENT CODE****************/

#define secureportREAD_MSP_NS_aslr(msp_ns) \
    __asm volatile("mrs %0, msp_ns"        \
                   : "=r"(msp_ns))
#define secureportREAD_PSP_NS_aslr(psp_ns) \
    __asm volatile("mrs %0, psp_ns"        \
                   : "=r"(psp_ns))

#define PRINTF_ADDRESS_ASLR 0x8e9a // the function entry address of printf
#define REWRITE_ADJUST_ASLR 1
extern FUNCS_INFO funcs[];
extern int        funcs_num;
extern stack_info stack_funcs;
extern QueueInfo  funcs_queue;
/**
 * Generate the base_address for function loading.
 **/
void exception_reconstruct_aslr(uint32_t* msp, uint32_t new_address);

uint8_t* address_malloc_aslr(size_t size);
int      address_free_aslr(uint8_t* free_address);

/*******************************************************/

func_node_t* function_exist_aslr(uint32_t func_address);

//@func
// This function is responsiable for TODO
int func_evict_one_aslr();

//@func
// This function is used to rewrite the calling address in the caller function
// so that the caller can call the target function from the RAM instead of the flash.
int rewrite_function_aslr(uint32_t new_address, uint32_t lr);
// /******************************************************************************/
// /*           Cortex Processor Interruption and Exception Handlers          */
// /******************************************************************************/
// /**
//  * @brief This function handles Non maskable interrupt.
//  */
// void NMI_Handler(void)
// {
// 	/* USER CODE BEGIN NonMaskableInt_IRQn 0 */

// 	/* USER CODE END NonMaskableInt_IRQn 0 */
// 	/* USER CODE BEGIN NonMaskableInt_IRQn 1 */

// 	/* USER CODE END NonMaskableInt_IRQn 1 */
// }

// Debug variables;
uint32_t*      msp;
uint32_t       interrupt_ret;
uint32_t       lr;
uint32_t       top;
uint32_t*      initial_msp_s;
uint32_t       interrupt_ret;
uint32_t       initial_msp_ns;
rewrite_info_t ri_start = {
    .next = NULL};

// evaluation varibales
#define _EVALUATION
uint32_t n_redirect;
uint32_t n_evict;
uint32_t n_load;
uint32_t n_excp;

uint8_t flag_a40c, flag_901c, flag_9b7a;

void HardFault_Handler_aslr(void) {
#ifdef _EVALUATION
    n_excp++;
#endif
    // int offset = 6;
    uint32_t ulControlValue;
    __asm volatile("MRS %0, control_ns"
                   : "=r"(ulControlValue));
    if (ulControlValue & 0x02) { // 使用 psp
        initial_msp_s = __get_PSP();
        secureportREAD_PSP_NS_aslr(msp);
    } else {
        initial_msp_s = __get_MSP();
        secureportREAD_MSP_NS_aslr(msp);
    }
    //	uint32_t ulLRValue;
    //	__asm volatile("mov %0, lr" : "=r" (ulLRValue) );
    //	if (((ulLRValue >> 3) & 1) == 0 || ((ulLRValue >> 2)&1) == 0) {
    //		initial_msp_s=__get_MSP();
    //		secureportREAD_MSP_NS_aslr(msp);
    //	}
    //	else {
    //		initial_msp_s = __get_PSP();
    //		secureportREAD_PSP_NS_aslr(msp);
    //	}
    // msp += offset;
    interrupt_ret = (uint32_t) * (msp + 6); // return address value
    lr = (uint32_t) * (msp + 5);
    if (interrupt_ret == 0x080577c4) {
        __NOP();
    }
    if (initial_msp_ns == 0)
        initial_msp_ns = (uint32_t)msp + 0x20;

    func_node_t* new_address = function_exist_aslr(interrupt_ret);
    if (new_address)
        6 {
#ifdef _EVALUATION
            n_redirect++;
#endif
            // rewrite here
            if ((lr & 0xff000000) != 0xff000000) {
                if (interrupt_ret == 0x8a94) {
                    rewrite_function_v2_aslr(new_address->load_address, lr);
                    // *(initial_msp_s+0xe)=new_address->load_address+1;
                } else {
                    rewrite_function_v2_aslr(new_address->load_address, lr);
                }
            }
            exception_reconstruct_aslr(msp, new_address->load_address);
            return;
        }
    if (interrupt_ret >= NS_MPU_START_ASLR && interrupt_ret <= NS_MPU_END_ASLR) {
        int idx = -1;
        for (int i = 0; i < funcs_num; i++) {
            if (interrupt_ret == funcs[i].start_address) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            uint32_t size = funcs[idx].size;

            func_node_t func_node = {
                .load_address = address_malloc_aslr(size),
                .size = size,
                .func_address = funcs[idx].start_address,
                .call_frame_size = funcs[idx].call_frame_size,
                .ref = 0};
            if (func_node.load_address == NULL) {
#ifdef _EVALUATION
                n_evict++;
#endif
                func_evict_one_aslr();
                func_node.load_address = address_malloc_aslr(size);
            }
            while (func_node.load_address == NULL)
                ;
#ifdef _EVALUATION
            n_load++;
#endif
            while (queue_insert_aslr(&funcs_queue, func_node))
                ;
            load_func_aslr(func_node.load_address, funcs[idx].start_address, size);
            exception_reconstruct_aslr(msp, func_node.load_address);
            return;
        }
    }
    while (1) {
        __NOP();
    }
}

int load_func_aslr(uint8_t* load_address, uint8_t* func_address, uint32_t size) {
    while (size > 0) {
        *load_address++ = *func_address++;
        // Add 1 to counter before the function complete to notify the memory managerment to clean the function
        size--;
    }
}

int funcs_flush_aslr() {
    uint32_t return_address = lr & 0xfffffffe;
    uint32_t index_msp = (uint32_t)msp + 0x20;

    while (index_msp != initial_msp_ns) {
        int      queue_size = queue_sum_aslr();
        uint32_t index_queue = funcs_queue.front;

        if (interrupt_ret == 0x9c02) {
            __NOP();
        }

        while (queue_size > 0) {
            queue_size--;
            uint32_t size = funcs_queue.queue_array[index_queue].size;
            uint32_t load_address = funcs_queue.queue_array[index_queue].load_address;
            if ((return_address - load_address - 1) <= size) {
                funcs_queue.queue_array[index_queue].ref = 1;
                index_msp += funcs_queue.queue_array[index_queue].call_frame_size;

                if (funcs_queue.queue_array[index_queue].func_address == PRINTF_ADDRESS_ASLR) {
                    return_address = *((uint32_t*)(index_msp - 20));
                    break;
                }
                return_address = *((uint32_t*)(index_msp - 4));
                break; // indicate that the funcs will be cleaned.
            }
            index_queue = (index_queue + 1) % MAX_SIZE_QUEUE_ASLR;
            while (queue_size == 0) {
                __NOP();
            }
        }
    }
}

int func_evict_one_aslr() {
    clean_rewrite_info_aslr();
    funcs_flush_aslr();
    int queue_size = queue_sum_aslr();
    while (queue_size--) {
        int      index = funcs_queue.front;
        uint32_t ref = funcs_queue.queue_array[index].ref;

        if (ref == 1) {
            func_node_t f = funcs_queue.queue_array[index];
            f.ref = 0;
            while (queue_insert_aslr(&funcs_queue, f) != 0)
                ;
            while (queue_delete_aslr(&funcs_queue) != 0)
                ;
        } else {
            while (queue_delete_aslr(&funcs_queue) != 0)
                ;
            uint8_t* free_address = funcs_queue.queue_array[index].load_address;
            address_free_aslr(free_address);
        }
    }
}

void clean_rewrite_info_aslr() {
    rewrite_info_t* ri_index = &ri_start;
    while (ri_index->next != NULL) {
        rewrite_info_t* temp = ri_index->next;
        ri_index = ri_index->next;
        uint16_t* index_address = (uint16_t*)(temp->ra.address);
        *(index_address - 1) = temp->ra.value0;
        *(index_address - 2) = temp->ra.value1;
        *(index_address - 3) = temp->ra.value2;
        *(index_address - 4) = temp->ra.value3;
        free(temp);
    }
    ri_start.next = NULL;
}

uint8_t* address_malloc_aslr(size_t size) {
    uint8_t* load_address = pvPortMalloc_aslr(size);
    // printf("loadaddress: %x\r\n",load_address);
    return load_address;
}
int address_free_aslr(uint8_t* free_address) {
    vPortFree_aslr(free_address);

    return 0;
}

void exception_reconstruct_aslr(uint32_t* msp, uint32_t new_address) {
    *(msp + 6) = new_address;
}

int rewrite_function_v2_aslr(uint32_t new_address, uint32_t lr) {
    uint16_t* index_addr = (uint8_t*)((lr & 0xfffffffe) - 2);
    uint32_t  rd = rd_recognize_aslr(*(uint16_t*)index_addr);
    index_addr -= 1;
    int      res = is_ldr_aslr(rd, *index_addr);
    uint32_t imm = -1;
    if (res == 0) {
        imm = ldr_get_imm_aslr(*index_addr);
        imm *= 4;
        uint32_t rewrite_addr = ((uint32_t)index_addr + imm + 2);
        if (rewrite_addr % 4 != 0)
            rewrite_addr += 2;
        *((uint32_t*)rewrite_addr) = (new_address | 0x1);
    }
}

int rewrite_function_aslr(uint32_t new_address, uint32_t lr) {
    uint16_t new_low_imm, new_high_imm, pre_low_imm, pre_high_imm;
    new_address = new_address | 0x1; // we must ensure that the address value is odd
    new_low_imm = new_address & 0x0000ffff;
    new_high_imm = new_address >> 16;
    uint32_t  new_movt, new_movw, pre_movt, pre_movw, rd;
    uint16_t* index_addr = (uint8_t*)((lr & 0xfffffffe) - 2);
    rd = rd_recognize(*(uint16_t*)index_addr);

    // recognize if the two instruction before blx is movw,movt assigning to the rd register

    uint32_t pre_address = interrupt_ret;
    pre_address = pre_address | 0x1; // we must ensure that the address value is odd
    pre_low_imm = pre_address & 0x0000ffff;
    pre_high_imm = pre_address >> 16;
    pre_movt = movt_transfer(pre_high_imm, rd);
    pre_movw = movw_transfer(pre_low_imm, rd);
    // i is the iterator parameter that can backtrace the movw movt instructions
    int i = REWRITE_ADJUST_ASLR;

    while (i--) {
        uint16_t movt_low_value = *(index_addr - 1);
        uint16_t movt_high_value = *(index_addr - 2);
        uint16_t movw_low_value = *(index_addr - 3);
        uint16_t movw_high_value = *(index_addr - 4);
        if ((pre_movt & 0x0000ffff) == movt_low_value && (pre_movt >> 16) == movt_high_value && (pre_movw & 0x0000ffff) == movw_low_value && (pre_movw >> 16) == movw_high_value) {
            rewrite_info_t* ri_index = &ri_start;
            while ((ri_index->next) != NULL) {
                ri_index = ri_index->next;
            }
            rewrite_info_t* ri_new = malloc(sizeof(rewrite_info_t));
            ri_new->next = NULL;
            ri_new->ra.address = index_addr;
            ri_new->ra.value0 = movt_low_value;
            ri_new->ra.value1 = movt_high_value;
            ri_new->ra.value2 = movw_low_value;
            ri_new->ra.value3 = movw_high_value;
            ri_index->next = ri_new;
            new_movt = movt_transfer(new_high_imm, rd);
            new_movw = movw_transfer(new_low_imm, rd);
            index_addr -= 1;
            *index_addr = (uint16_t)(new_movt & 0xffff);
            index_addr -= 1;
            *index_addr = (uint16_t)(new_movt >> 16);
            index_addr -= 1;
            *index_addr = (uint16_t)(new_movw & 0xffff);
            index_addr -= 1;
            *index_addr = (uint16_t)(new_movw >> 16);
            return 0;
        }
        index_addr--;
    }
    return -1;
}

func_node_t* function_exist_aslr(uint32_t func_address) {
    int front = funcs_queue.front;
    int rear = funcs_queue.rear;
    while (((rear + 1) % MAX_SIZE_QUEUE_ASLR) != front) {
        if (funcs_queue.queue_array[front].func_address == func_address) {
            func_node_t* res = &(funcs_queue.queue_array[front]);
            return res;
        }
        front = (front + 1) % MAX_SIZE_QUEUE_ASLR;
    }
    return 0;
}

// /**
//  * @brief This function handles Memory management fault.
//  */

// /**
//  * @brief This function handles Prefetch fault, memory access fault.
//  */
// void BusFault_Handler(void)
// {
// 	/* USER CODE BEGIN BusFault_IRQn 0 */

// 	/* USER CODE END BusFault_IRQn 0 */
// 	while (1)
// 	{
// 		/* USER CODE BEGIN W1_BusFault_IRQn 0 */
// 		/* USER CODE END W1_BusFault_IRQn 0 */
// 	}
// }

// /**
//  * @brief This function handles Undefined instruction or illegal state.
//  */
// void UsageFault_Handler(void)
// {
// 	/* USER CODE BEGIN UsageFault_IRQn 0 */

// 	/* USER CODE END UsageFault_IRQn 0 */
// 	while (1)
// 	{
// 		/* USER CODE BEGIN W1_UsageFault_IRQn 0 */
// 		/* USER CODE END W1_UsageFault_IRQn 0 */
// 	}
// }

// /**
//  * @brief This function handles Secure fault.
//  */
// void SecureFault_Handler(void)
// {
// 	/* USER CODE BEGIN SecureFault_IRQn 0 */
// 	funcptr_NS callback_NS; // non-secure callback function pointer

// 	if (pSecureFaultCallback != (funcptr_NS)NULL)
// 	{
// 		/* return function pointer with cleared LSB */
// 		callback_NS = (funcptr_NS)cmse_nsfptr_create(pSecureFaultCallback);

// 		callback_NS();
// 	}
// 	else
// 	{
// 		/* USER CODE END SecureFault_IRQn 0 */
// 		while (1)
// 		{
// 			/* USER CODE BEGIN W1_SecureFault_IRQn 0 */
// 		}
// 		/* USER CODE END W1_SecureFault_IRQn 0 */
// 	}
// }

// /**
//  * @brief This function handles System service call via SWI instruction.
//  */
// void SVC_Handler(void)
// {
// 	/* USER CODE BEGIN SVCall_IRQn 0 */

// 	/* USER CODE END SVCall_IRQn 0 */
// 	/* USER CODE BEGIN SVCall_IRQn 1 */

// 	/* USER CODE END SVCall_IRQn 1 */
// }

// /**
//  * @brief This function handles Debug monitor.
//  */
void DebugMon_Handler(void) {
    /* USER CODE BEGIN DebugMonitor_IRQn 0 */
    while (1) {
    }

    /* USER CODE END DebugMonitor_IRQn 0 */
    /* USER CODE BEGIN DebugMonitor_IRQn 1 */

    /* USER CODE END DebugMonitor_IRQn 1 */
}

// /**
//  * @brief This function handles Pendable request for system service.
//  */
// void PendSV_Handler(void)
// {
// 	/* USER CODE BEGIN PendSV_IRQn 0 */
// 	while (1)
// 	{
// 	}

// 	/* USER CODE END PendSV_IRQn 0 */
// 	/* USER CODE BEGIN PendSV_IRQn 1 */

// 	/* USER CODE END PendSV_IRQn 1 */
// }

// /**
//  * @brief This function handles System tick timer.
//  */
// void SysTick_Handler(void)
// {
// 	/* USER CODE BEGIN SysTick_IRQn 0 */

// 	/* USER CODE END SysTick_IRQn 0 */
// 	HAL_IncTick();
// 	/* USER CODE BEGIN SysTick_IRQn 1 */
// 	HAL_SYSTICK_Callback();
// 	/* USER CODE END SysTick_IRQn 1 */
// }

/******************************************************************************/
/* STM32L5xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l5xx.s).                    */
/******************************************************************************/

// /**
//  * @brief This function handles Global TrustZone controller global interrupt.
//  */
// void GTZC_IRQHandler(void)
// {
// 	/* USER CODE BEGIN GTZC_IRQn 0 */
// 	funcptr_NS callback_NS; // non-secure callback function pointer
// 	/* USER CODE END GTZC_IRQn 0 */
// 	HAL_GTZC_IRQHandler();
// 	/* USER CODE BEGIN GTZC_IRQn 1 */
// 	if (pSecureErrorCallback != (funcptr_NS)NULL)
// 	{
// 		/* return function pointer with cleared LSB */
// 		callback_NS = (funcptr_NS)cmse_nsfptr_create(pSecureErrorCallback);

// 		callback_NS();
// 	}
// 	else
// 	{
// 		/* Something went wrong in test case */
// 		while (1)
// 			;
// 	}
// 	/* USER CODE END GTZC_IRQn 1 */
// }

// /**
//  * @brief This function handles RNG global interrupt.
//  */
// void RNG_IRQHandler(void)
// {
// 	/* USER CODE BEGIN RNG_IRQn 0 */

// 	/* USER CODE END RNG_IRQn 0 */
// 	HAL_RNG_IRQHandler(&hrng);
// 	/* USER CODE BEGIN RNG_IRQn 1 */

// 	/* USER CODE END RNG_IRQn 1 */
// }

// /* USER CODE BEGIN 1 */

// /* USER CODE END 1 */
// /************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
