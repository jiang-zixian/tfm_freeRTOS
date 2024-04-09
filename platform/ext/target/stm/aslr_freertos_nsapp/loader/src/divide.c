#include "divide.h"
#include "func.h"

void divide() {
    // return;
    for (uint32_t i = 0; i < func_info_size; ++i) {
        if (((func_info[i].addr >> 1) & 1) == 1) {
            func_info[i].region = 1;
        }
        //要保证ns世界的reset_handler和r9Init两个函数在同一个区域,因为r9Init之前不能用trampoline
        if(func_info[i].addr==0x805586b||func_info[i].addr==0x8055781){
            func_info[i].region = 0;
        }
        
    }
}