/*
 * dwt.c
 *
 *  Created on: Feb 29, 2024
 *      Author: zhang
 */

#include "dwt.h"

void DWT_enable(uint32_t begin, uint32_t end) {
    //	/* Check ROM table for DWT and ITM implementation */
    //	assert(ROMDWT_DWT_IMPL && "DWT not implemented!");
    //	assert(ROMITM_ITM_IMPL && "ITM not implemented!");
    DWT->COMP0 = begin;
    DWT->FUNCTION0 = (1U << DWT_FUNCTION_ACTION_Pos) | (DWT_FUNCTION_MATCH_D_W << DWT_FUNCTION_MATCH_Pos);
    DWT->COMP1 = end;
    DWT->FUNCTION1 = (1U << DWT_FUNCTION_ACTION_Pos) | (DWT_FUNCTION_MATCH_DL << DWT_FUNCTION_MATCH_Pos);
    /* Enable DWT, ITM, and Debug Exception globally */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk | CoreDebug_DEMCR_MON_EN_Msk;
}
