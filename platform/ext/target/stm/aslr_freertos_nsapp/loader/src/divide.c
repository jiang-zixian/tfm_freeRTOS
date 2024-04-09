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
        
        //memset里貌似有读lr的操作，memset之前应该也不能蹦床（本人没试过memset之前有蹦床会怎么样）
        if(func_info[i].addr==0x805859d/*memset*/||
        func_info[i].addr==0x8055a1d/*prvCreateTask*/||
        func_info[i].addr==0x8056907/*prvInitialiseNewTask*/){
            func_info[i].region = 0;
        }

        
    }
}