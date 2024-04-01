# -------------------------------------------------------------------------------
# Copyright (c) 2020, Arm Limited. All rights reserved.
# Copyright (c) 2021 STMicroelectronics. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
# -------------------------------------------------------------------------------

cmake_policy(SET CMP0076 NEW)

set(STM32L563E_DK_DIR ${CMAKE_CURRENT_LIST_DIR})
set(STM_COMMON_DIR ${STM32L563E_DK_DIR}/../common)
set(COMMON_DIR ${STM32L563E_DK_DIR}/../../../common)
set(TOP_DIR ${STM32L563E_DK_DIR}/../../../../..)
set(ASLR_DIR ${STM32L563E_DK_DIR}/aslr)
set(NS_APP_DIR ${STM32L563E_DK_DIR}/nsapp)

# NSAPP
add_executable(ns_app)

target_compile_options(ns_app
    PUBLIC
    -fno-jump-tables
    # -fPIE
)

# def for stm32l5xx
include(${STM_COMMON_DIR}/stm32l5xx/CMakeLists.txt)

# NSAPP
target_sources(tfm_s
    PRIVATE
    ${STM_COMMON_DIR}/stm32l5xx/Device/Source/startup_stm32l5xx_s.c
)

set_target_properties(ns_app PROPERTIES
    SUFFIX ".axf"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(ENABLE_RE)
    target_link_options(ns_app
        PRIVATE

        # -fPIE
        -r
        -e Reset_Handler
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/ns_app.map>
        $<$<C_COMPILER_ID:Clang>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/ns_app.map>
        $<$<C_COMPILER_ID:ARMClang>:--map>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/ns_app.map>
    )
else()
    target_link_options(ns_app
        PRIVATE

        # -fPIE
        $<$<C_COMPILER_ID:GNU>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/ns_app.map>
        $<$<C_COMPILER_ID:Clang>:-Wl,-Map=${CMAKE_BINARY_DIR}/bin/ns_app.map>
        $<$<C_COMPILER_ID:ARMClang>:--map>
        $<$<C_COMPILER_ID:IAR>:--map\;${CMAKE_BINARY_DIR}/bin/ns_app.map>
    )
endif()

add_convert_to_bin_target(ns_app)
target_include_directories(ns_app
    PUBLIC
    ${STM32L563E_DK_DIR}/include
    ${NS_APP_DIR}/include
)
target_link_libraries(ns_app
    PUBLIC
    platform_common_interface
    platform_region_defs
)
target_sources(ns_app
    PRIVATE
    ${STM_COMMON_DIR}/stm32l5xx/Device/Source/startup_stm32l5xx_ns.c
    ${NS_APP_DIR}/src/main_ns.c
)

# loader
target_include_directories(platform_s
    PUBLIC
    ${STM32L563E_DK_DIR}/loader/include
    ${STM32L563E_DK_DIR}/loader
)

target_sources(platform_s
    PRIVATE

    # ${STM32L563E_DK_DIR}/loader/func_info.c
    ${STM32L563E_DK_DIR}/loader/src/func.c
    ${STM32L563E_DK_DIR}/loader/src/relocation.c
    ${STM32L563E_DK_DIR}/loader/src/divide.c

    # ${STM32L563E_DK_DIR}/loader/src/loader.c
    ${STM32L563E_DK_DIR}/loader/src/new_loader.c
    ${STM32L563E_DK_DIR}/loader/src/dwt.c

)

# FreeRTOS
add_subdirectory(FreeRTOS)
target_link_libraries(ns_app
    PUBLIC
    freertos_kernel
)

# test
set(TEST_TARGET "" CACHE STRING "Test target to build")

# 分割字符串 _
string(REPLACE "_" ";" TEST_TARGET_LIST ${TEST_TARGET})
list(GET TEST_TARGET_LIST 0 FIRST_PART)

# 添加测试
add_subdirectory(${FIRST_PART})

if(BL2)
    target_sources(bl2
        PRIVATE
        ${STM_COMMON_DIR}/stm32l5xx/Device/Source/startup_stm32l5xx_bl2.c
        ${STM_COMMON_DIR}/stm32l5xx/bl2/low_level_ospi_device.c
        ${STM_COMMON_DIR}/hal/CMSIS_Driver/low_level_ospi_flash.c
        ${STM_COMMON_DIR}/stm32l5xx/hal/Src/stm32l5xx_hal_ospi.c
        ${STM_COMMON_DIR}/hal/Components/mx25lm51245g/mx25lm51245g.c
        ${STM32L563E_DK_DIR}/src/stm32l562e_discovery_ospi.c
    )
    target_include_directories(bl2
        PRIVATE
        ${STM_COMMON_DIR}/Components/mx25lm51245g
    )
endif()

# # copytext
# target_include_directories(platform_s
# PUBLIC
# ${STM32L563E_DK_DIR}/ota
# ${STM32L563E_DK_DIR}/copytext
# )
# target_sources(platform_s
# PRIVATE
# ${STM32L563E_DK_DIR}/ota/flash.c
# ${STM32L563E_DK_DIR}/ota/port.c
# ${STM32L563E_DK_DIR}/ota/rand.c
# ${STM32L563E_DK_DIR}/ota/loader.c
# ${STM32L563E_DK_DIR}/copytext/copytext.c
# ${STM32L563E_DK_DIR}/copytext/extracted_info.c
# )
target_include_directories(ns_app
    PUBLIC
    ${STM32L563E_DK_DIR}/copytext
)

target_sources(ns_app
    PRIVATE
    ${STM32L563E_DK_DIR}/copytext/extracted_info.c
)
install(FILES ${STM32L563E_DK_DIR}/include/flash_layout.h
    ${STM32L563E_DK_DIR}/include/region_defs.h
    DESTINATION ${CMAKE_BINARY_DIR})
set(BL2_FILE_TO_PREPROCESS ${CMAKE_CURRENT_BINARY_DIR}/image_macros_to_preprocess_bl2.c)
file(WRITE ${BL2_FILE_TO_PREPROCESS} ${BL2_PREPROCESSING})
install(FILES ${BL2_FILE_TO_PREPROCESS}
    DESTINATION ${CMAKE_BINARY_DIR})
