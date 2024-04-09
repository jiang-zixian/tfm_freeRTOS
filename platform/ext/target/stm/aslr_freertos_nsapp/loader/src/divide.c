#include "divide.h"
#include "func.h"

void divide() {
    // return;
    for (uint32_t i = 0; i < func_info_size; ++i) {
        if (((func_info[i].addr >> 1) & 1) == 1) {
            func_info[i].region = 1;
        }
        if(func_info[i].addr==0x8058671/*SVC_Handler*/||
        func_info[i].addr==0x805877d/*memset*/||
        func_info[i].addr==0x8058621/*PendSV_Handler*/||
        func_info[i].addr==0x8055c31/*prvCreateTask*/||
        func_info[i].addr==0x8056ae1/*prvInitialiseNewTask*/||
        func_info[i].addr==0x80585d1/*vStartFirstTask*/){
            func_info[i].region = 0;
        }
    }
}