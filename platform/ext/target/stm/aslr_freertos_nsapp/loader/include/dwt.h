/*
 * dwt.h
 *
 *  Created on: Feb 29, 2024
 *      Author: zhang
 */

#ifndef INC_DWT_H_
#define INC_DWT_H_

#include "stm32l562xx.h"
#include "sys/_stdint.h"

//=============================================================================
// DWT
//=============================================================================

#define DWT_FUNCTION_MATCH_I (0x2U)
#define DWT_FUNCTION_MATCH_IL (0x3U)
#define DWT_FUNCTION_MATCH_D_RW (0x4U) // r & w 都会触发
#define DWT_FUNCTION_MATCH_D_W (0x5U)  // w 触发
#define DWT_FUNCTION_MATCH_D_R (0x6U)  // r 触发
#define DWT_FUNCTION_MATCH_DL (0x7U)

struct DWTComparatorPair {
    volatile uint32_t comp0;
    volatile uint32_t comp1;
    volatile uint32_t func0;
    volatile uint32_t func1;
};

void DWT_enable(uint32_t base1, uint32_t end1, uint32_t base2, uint32_t end2);

#endif /* INC_DWT_H_ */
