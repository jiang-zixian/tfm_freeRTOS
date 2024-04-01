#ifndef FUNC_H
#define FUNC_H
#include "stm32l562xx.h"

typedef struct {
    uint32_t addr;
    uint32_t size;
    uint32_t region;
} func_info_t;

extern uint32_t    func_info_size;
extern func_info_t func_info[];
#endif