#!/bin/bash

TEST_TARGET_ARG="$1"
#MNT_DIR_NUM="$2"
CURRENT_DIR=/home/jiangzixian/tfm_freeRTOS_dwt
STM32_Programmer_CLI_PATH=/mnt/f/"Program Files"/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin

# 检查当前目录下是否存在 build, build_ns, build_s 文件夹
if [[ ! -d "build" && ! -d "build_ns" && ! -d "build_s" ]]; then
  # 如果不存在，则创建这些文件夹
  mkdir build build_ns build_s
  echo "mkdir the folders"
else
  echo "folders exist"
fi

cd build &&
sudo rm CMakeCache.txt&&sudo cmake .. -DTFM_PLATFORM=stm/aslr_freertos_nsapp -DBL2=OFF -DNS=OFF -DNS_APP=ON -DTFM_TOOLCHAIN_FILE=../toolchain_GNUARM_Yes.cmake -DFREERTOS_PORT=GCC_ARM_CM33_NTZ_NONSECURE -DFREERTOS_HEAP=4 -DTEST_TARGET="${TEST_TARGET_ARG}" -DENABLE_RE=ON&&sudo make -j &&

cd "${CURRENT_DIR}"/build/bin &&
readelf -s ns_app.elf | grep FUNC > "${CURRENT_DIR}"/platform/ext/target/stm/aslr_freertos_nsapp/loader/script/func_info.txt &&
readelf -r ns_app.elf > "${CURRENT_DIR}"/platform/ext/target/stm/aslr_freertos_nsapp/loader/script/relocation.txt &&
readelf -s ns_app.elf > "${CURRENT_DIR}"/platform/ext/target/stm/aslr_freertos_nsapp/loader/script/symbol_table.txt &&

cd "${CURRENT_DIR}"/loder_script &&
sudo ./loader_v2.py &&

cd "${CURRENT_DIR}"/build_ns &&

sudo rm CMakeCache.txt &&sudo cmake .. -DTFM_PLATFORM=stm/aslr_freertos_nsapp -DBL2=OFF -DNS=OFF -DNS_APP=ON -DTFM_TOOLCHAIN_FILE=../toolchain_GNUARM_Yes.cmake -DFREERTOS_PORT=GCC_ARM_CM33_NTZ_NONSECURE -DFREERTOS_HEAP=4 -DTEST_TARGET="${TEST_TARGET_ARG}" -DENABLE_RE=OFF&&sudo make -j &&

cd "${CURRENT_DIR}"/build_s &&

sudo rm CMakeCache.txt &&sudo cmake .. -DTFM_PLATFORM=stm/aslr_freertos_nsapp -DBL2=OFF -DNS=OFF -DNS_APP=ON -DTFM_TOOLCHAIN_FILE=../toolchain_GNUARM_No.cmake -DFREERTOS_PORT=GCC_ARM_CM33_NTZ_NONSECURE -DFREERTOS_HEAP=4 -DTEST_TARGET="${TEST_TARGET_ARG}" -DENABLE_RE=OFF&&sudo make -j &&

llvm-objdump -s -d "${CURRENT_DIR}"/build_ns/bin/ns_app.elf > "${CURRENT_DIR}"/build_ns/bin/ns_app.asm &&
llvm-objdump -s -d "${CURRENT_DIR}"/build_s/bin/tfm_s.elf > "${CURRENT_DIR}"/build_s/bin/tfm_s.asm &&

"${STM32_Programmer_CLI_PATH}"/"STM32_Programmer_CLI.exe" -c port=swd -e all -d "${CURRENT_DIR}"/build_s/bin/tfm_s.elf -d "${CURRENT_DIR}"/build_ns/bin/ns_app.elf





