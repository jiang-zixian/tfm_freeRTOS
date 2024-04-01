#ifndef RELOCATION_H
#define RELOCATION_H
#include "stm32l562xx.h"
typedef struct {
    uint32_t addr;
    uint32_t value;
    uint32_t type;
} relocation_info_t;

extern uint32_t          table_size;
extern relocation_info_t relocation_info[];
#endif
