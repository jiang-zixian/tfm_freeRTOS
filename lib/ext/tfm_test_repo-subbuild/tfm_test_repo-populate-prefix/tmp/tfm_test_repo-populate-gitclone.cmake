
if(NOT "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-gitinfo.txt" IS_NEWER_THAN "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --progress "https://git.trustedfirmware.org/TF-M/tf-m-tests.git" "tfm_test_repo-src"
    WORKING_DIRECTORY "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://git.trustedfirmware.org/TF-M/tf-m-tests.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout 7cf20ef --
  WORKING_DIRECTORY "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '7cf20ef'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-gitinfo.txt"
    "/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-gitclone-lastrun.txt'")
endif()

