#include "loader.h"
// #include "func_info.h"
#include "func.h"
#include "func_info.h"
#include "relocation.h"
#include "stm32l562xx.h"
#include "stm32l5xx_hal_flash.h"
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

uint32_t address_calculate(uint32_t val, int offset) {
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

void relocation(uint32_t offset_a, uint32_t offset_b) {
    for (int i = 1; i < table_size; ++i) {
        // which range of the identifier
        if (relocation_info[i].type == 0) {
            if (in_range(relocation_info[i].value) == 0) {
                *((uint32_t*)(relocation_info[i].addr + offset_a)) += offset_a;
            } else {
                *((uint32_t*)(relocation_info[i].addr + offset_a)) += offset_b;
            }
        } else if (relocation_info[i].type == 1) {
            if (in_range(relocation_info[i].addr) == 0) {
                *((uint32_t*)(relocation_info[i].addr + offset_a)) -= offset_a;
            } else {
                *((uint32_t*)(relocation_info[i].addr + offset_b)) -= offset_b;
            }
        } else if (relocation_info[i].type == 2) {
            if (in_range(relocation_info[i].addr) == 0 && in_range(relocation_info[i].value) == 1) {
                uint32_t val = *((uint32_t*)(relocation_info[i].addr + offset_a));
                *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                    address_calculate(val, offset_b - offset_a);
            } else if (in_range(relocation_info[i].addr) == 1 && in_range(relocation_info[i].value) == 0) {
                uint32_t val = *((uint32_t*)(relocation_info[i].addr + offset_b));
                *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                    address_calculate(val, offset_a - offset_b);
            }
        } else {
            //   if (in_range(relocation_info[i].addr) == 0 &&
            //       in_range(relocation_info[i].value) == 1) {
            //     int32_t val = *((uint32_t *)(relocation_info[i].addr + offset_a));
            //     val += (int32_t)(offset_b - offset_a);
            //     *((uint32_t *)(relocation_info[i].addr + offset_a)) =
            //     (uint32_t)val;
            //   } else if (in_range(relocation_info[i].addr) == 1 &&
            //              in_range(relocation_info[i].value) == 0) {
            //     int32_t val = *((uint32_t *)(relocation_info[i].addr + offset_b));
            //     val += (int32_t)(offset_a - offset_b);
            //     *((uint32_t *)(relocation_info[i].addr + offset_b)) =
            //     (uint32_t)val;
            //   }
        }

        for (int j = 0; j < sizeof(reloc_entries) / sizeof(struct reloc_entry);
             j++) {
            if (relocation_info[i].addr == reloc_entries[j].dst_addr) {
                if (in_range(relocation_info[i].addr) == 0 && in_range(relocation_info[i].value) == 1) {
                    int32_t  val = *((uint32_t*)(relocation_info[i].addr + offset_a));
                    uint32_t pc_func = reloc_entries[j].src_addr - val - 3;
                    *((uint32_t*)(relocation_info[i].addr + offset_a)) =
                        ((uint32_t)(reloc_entries[j].src_addr + offset_b) ^ ENCODE_KEY) - pc_func;
                } else if (in_range(relocation_info[i].addr) == 1 && in_range(relocation_info[i].value) == 0) {
                    int32_t  val = *((uint32_t*)(relocation_info[i].addr + offset_b));
                    uint32_t pc_func = reloc_entries[j].src_addr - val - 3;
                    *((uint32_t*)(relocation_info[i].addr + offset_b)) =
                        ((uint32_t)(reloc_entries[j].src_addr + offset_a) ^ ENCODE_KEY) - pc_func;
                }
            }
        }
    }
}