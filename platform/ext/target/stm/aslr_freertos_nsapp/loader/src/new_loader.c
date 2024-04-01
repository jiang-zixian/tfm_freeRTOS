#include "loader.h"
// #include "func_info.h"
#include "func.h"
#include "func_info.h"
#include "relocation.h"
#include "stm32l562xx.h"
#include "stm32l5xx_hal_flash.h"
#include "sys/_stdint.h"
#include "target/stm/aslr_freertos_nsapp/loader/func_info.h"
#define ENCODE_KEY 0x00000001

// int is_matched(uint32_t ar[], uint32_t val, int len) {
//     for (int i = 0; i < len; i++) {
//         if (ar[i] == val) {
//             return i;
//         }
//     }
//     return -1;
// }

// int index = is_matched(ldr_list, src + i * 4, sizeof(ldr_list) / 4);
// if (index != -1) {
//     *(uint32_t*)(dst + ldr_list[index + 1] - src) -=
//         (uint32_t)dst - (uint32_t)src;
// }

void copy_text2ram(uint32_t dst, uint32_t src, uint32_t len) {
    HAL_FLASH_Unlock();
    len /= 4;
    uint32_t i = 0;
    while (i < len) {
        *(uint32_t*)(dst + i * 4) = *(uint32_t*)(src + i * 4);
        ++i;
    }
    HAL_FLASH_Lock();
}

// judge whether the address is in the range of b
int in_range(uint32_t pos) {
    for (uint32_t i = 0; i < func_info_size; ++i) {
        if (pos >= func_info[i].addr && pos < func_info[i].addr + func_info[i].size) {
            return func_info[i].region;
        }
    }
    return -1;
}

uint32_t address_calculate(uint32_t pos, uint32_t val) {
    uint32_t first_top_5 = 0x1f;
    uint32_t second_top_5 = 0x1e;
    val = val - 1;
    pos = pos + 4;
    uint32_t new_offset = val - pos;
    return (uint32_t)((first_top_5 << 27) | (((new_offset & 0xfff) >> 1) << 16) | (second_top_5 << 11) | ((new_offset >> 12) & 0x7ff));
}

uint32_t func_pointer_address_calculate(uint32_t val, int offset) {
    uint32_t first = (val >> 16) & 0xffff;
    uint32_t second = val & 0xffff;
    uint32_t first_top_5 = (first >> 11) & 0x1f;
    uint32_t first_bottom_11 = first & 0x7ff;
    uint32_t second_top_5 = (second >> 11) & 0x1f;
    uint32_t second_bottom_11 = second & 0x7ff;
    uint32_t new_offset =
        (uint32_t)(((int)(((second_bottom_11 << 12) | (first_bottom_11 << 1))
                          << 9)
                    >> 9)
                   + offset);
    uint32_t addr1 =
        (uint32_t)((first_top_5 << 27) | (((new_offset & 0xfff) >> 1) << 16) | (second_top_5 << 11) | ((new_offset >> 12) & 0x7ff));
    return addr1 ^ ENCODE_KEY;
}

void relocate(uint32_t offset) {
    // *((uint32_t*)0x80636ee) = 1;
    for (int i = 1; i < table_size; ++i) {
        if (relocation_info[i].type == 0) {
            *((uint32_t*)(relocation_info[i].addr + offset)) += offset;
        } else if (relocation_info[i].type == 1) {
            *((uint32_t*)(relocation_info[i].addr + offset)) -= offset;
        }
    }
}

uint32_t movw_calculate(uint32_t ori_val, uint32_t addr) {
    addr = addr & 0xffff;
    ori_val = ori_val & 0x0f00f0f0;
    if ((addr & 0xf00) >= 0x800) {
        addr = addr - 0x800;
        ori_val = ori_val | 0x00000600;
    } else {
        ori_val = ori_val | 0x00000200;
    }

    uint32_t new_val = ori_val | ((addr & 0xf00) << 20) | ((addr & 0xff) << 16) | ((addr & 0xf000) >> 12);
    return new_val;
}

uint32_t movt_calculate(uint32_t ori_val, uint32_t addr) {
    addr = (addr >> 16) & 0xffff;
    ori_val = ori_val & 0x0f00f0f0;
    if ((addr & 0xf00) >= 0x800) {
        addr = addr - 0x800;
        ori_val = ori_val | 0x00000600;
    } else {
        ori_val = ori_val | 0x00000200;
    }

    uint32_t new_val = ori_val | ((addr & 0xf00) << 20) | ((addr & 0xff) << 16) | ((addr & 0xf000) >> 12);
    return new_val;
}

void relocation(uint32_t offset_a, uint32_t offset_b) {
    *((uint32_t*)(relocation_info[0].addr + offset_a)) =
        relocation_info[0].value;
    for (int i = 1; i < table_size; ++i) {
        // which range of the identifier
        if (relocation_info[i].type == 0) { // exception entry
            if (in_range(relocation_info[i].value) == 0) {
                *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                    relocation_info[i].value + offset_a;
            } else {
                *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                    relocation_info[i].value + offset_b;
            }
        } else if (relocation_info[i].type == 1) { // func pointer

        } else if (relocation_info[i].type == 2) { // data under function

        } else if (relocation_info[i].type == 3) { // data of some info, like "heap"

        } else if (relocation_info[i].type == 4) { // func call
            if (in_range(relocation_info[i].addr) == 0) {
                if (i == 142) {
                    int a = i;
                    a += 1;
                }
                if (in_range(relocation_info[i].value) == 1) {
                    *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                        address_calculate(relocation_info[i].addr,
                                          relocation_info[i].value + offset_b - offset_a);
                } else {
                    *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                        address_calculate(relocation_info[i].addr,
                                          relocation_info[i].value);
                }
            } else if (in_range(relocation_info[i].addr) == 1) {
                if (in_range(relocation_info[i].value) == 0) {
                    *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                        address_calculate(relocation_info[i].addr,
                                          relocation_info[i].value + offset_a - offset_b);
                } else {
                    *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                        address_calculate(relocation_info[i].addr,
                                          relocation_info[i].value);
                }
            }
        } else if (relocation_info[i].type == 5) { // absoultably address: movw
            if (in_range(relocation_info[i].addr) == 0) {
                if (in_range(relocation_info[i].value) == 1) {
                    *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                        movw_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_b);
                } else if (in_range(relocation_info[i].value) == 0) {
                    *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                        movw_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_a);
                }
            } else if (in_range(relocation_info[i].addr) == 1) {
                if (in_range(relocation_info[i].value) == 0) {
                    *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                        movw_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_a);
                } else if (in_range(relocation_info[i].value) == 1) {
                    *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                        movw_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_b);
                }
            }

        } else if (relocation_info[i].type == 6) { // absoulately address: mowt
            if (in_range(relocation_info[i].addr) == 0) {
                if (in_range(relocation_info[i].value) == 1) {
                    *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                        movt_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_b);
                } else if (in_range(relocation_info[i].value) == 0) {
                    *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                        movt_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_a);
                }
            } else if (in_range(relocation_info[i].addr) == 1) {
                if (in_range(relocation_info[i].value) == 0) {
                    *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                        movt_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_a);
                } else if (in_range(relocation_info[i].value) == 1) {
                    *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                        movt_calculate(*((uint32_t*)(relocation_info[i].addr)),
                                       relocation_info[i].value + offset_b);
                }
            }
        } else {
        }
    }
}