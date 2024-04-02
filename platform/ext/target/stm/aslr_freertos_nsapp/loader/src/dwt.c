/*
 * dwt.c
 *
 *  Created on: Feb 29, 2024
 *      Author: zhang
 */

#include "dwt.h"
#include "sys/_stdint.h"

void DWT_enable(uint32_t begin1, uint32_t end1, uint32_t begin2, uint32_t end2) {
    //	/* Check ROM table for DWT and ITM implementation */
    //	assert(ROMDWT_DWT_IMPL && "DWT not implemented!");
    //	assert(ROMITM_ITM_IMPL && "ITM not implemented!");
    DWT->COMP0 = begin1;
    DWT->FUNCTION0 = (1U << DWT_FUNCTION_ACTION_Pos) | (DWT_FUNCTION_MATCH_D_RW << DWT_FUNCTION_MATCH_Pos);
    DWT->COMP1 = end1;
    DWT->FUNCTION1 = (1U << DWT_FUNCTION_ACTION_Pos) | (DWT_FUNCTION_MATCH_DL << DWT_FUNCTION_MATCH_Pos);
    DWT->COMP2 = begin2;
    DWT->FUNCTION2 = (1U << DWT_FUNCTION_ACTION_Pos) | (DWT_FUNCTION_MATCH_D_RW << DWT_FUNCTION_MATCH_Pos);
    DWT->COMP3 = end2;
    DWT->FUNCTION3 = (1U << DWT_FUNCTION_ACTION_Pos) | (DWT_FUNCTION_MATCH_DL << DWT_FUNCTION_MATCH_Pos);
    /* Enable DWT, ITM, and Debug Exception globally */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk | CoreDebug_DEMCR_MON_EN_Msk;
}
