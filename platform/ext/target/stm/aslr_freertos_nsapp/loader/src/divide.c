#include "divide.h"
#include "func.h"

void divide() {
    // return;
    for (uint32_t i = 0; i < func_info_size; ++i) {
        if (((func_info[i].addr >> 1) & 1) == 1) {
            func_info[i].region = 1;
        }
        // // if(func_info[i].addr==0x8058661/*SVC_Handler*/||
        // // func_info[i].addr==0x805876d/*memset*/||
        // // func_info[i].addr==0x8058611/*PendSV_Handler*/||
        // // func_info[i].addr==0x8055c31/*prvCreateTask*/||
        // // func_info[i].addr==0x8056ae1/*prvInitialiseNewTask*/||
        // // func_info[i].addr==0x80585cb/*vStartFirstTask*/){
        // //     func_info[i].region = 0;
        // // }
        // if(func_info[i].addr==0x8058451/*SVC_Handler*/||
        // func_info[i].addr==0x805855d/*memset*/||
        // func_info[i].addr==0x8058401/*PendSV_Handler*/||
        // func_info[i].addr==0x8055a1d/*prvCreateTask*/||
        // func_info[i].addr==0x80568cd/*prvInitialiseNewTask*/||
        // func_info[i].addr==0x80583b7/*vStartFirstTask*/){
        //     func_info[i].region = 0;
        // }
        
    }
}