#!/bin/bash
STM32_Programmer_CLI_PATH="/mnt/f/'Program Files'/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin"
STM32_GDB_server_PATH="/mnt/f/gdb-server/bin"
Build_PATH="build"
for arg in "$@"; do
    if [[ "$arg" == "-c" ]] || [[ "$arg" == "--compile" ]]; then
        cmake --build build_re
        python3 loder_script/loader_v2.py
        cmake --build build
        echo "Compile done"
        break
    fi
done
for arg in "$@"; do
    if [[ "$arg" == "-d" ]] || [[ "$arg" == "--download" ]]; then
        eval $STM32_Programmer_CLI_PATH/"STM32_Programmer_CLI.exe" -c port=swd -e all -d $Build_PATH/bin/tfm_s.elf -d $Build_PATH/bin/ns_app.hex
        echo "Download done"
        break
    fi
done
for arg in "$@"; do
    if [[ "$arg" == "-gs" ]] || [[ "$arg" == "--gdbserver" ]]; then
        cd $STM32_GDB_server_PATH
        ./ST-LINK_gdbserver.exe -d
        cd -
        break
    fi
done