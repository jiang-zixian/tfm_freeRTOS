# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild

# Utility rule file for tfm_test_repo-populate.

# Include the progress variables for this target.
include CMakeFiles/tfm_test_repo-populate.dir/progress.make

CMakeFiles/tfm_test_repo-populate: CMakeFiles/tfm_test_repo-populate-complete


CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-install
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-mkdir
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-download
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-update
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-patch
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-configure
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-build
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-install
CMakeFiles/tfm_test_repo-populate-complete: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'tfm_test_repo-populate'"
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles/tfm_test_repo-populate-complete
	/usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-done

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-install: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'tfm_test_repo-populate'"
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E echo_append
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-install

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'tfm_test_repo-populate'"
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-src
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/tmp
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src
	/usr/bin/cmake -E make_directory /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp
	/usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-mkdir

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-download: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-gitinfo.txt
tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-download: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'tfm_test_repo-populate'"
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext && /usr/bin/cmake -P /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/tmp/tfm_test_repo-populate-gitclone.cmake
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext && /usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-download

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-update: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'tfm_test_repo-populate'"
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-src && /usr/bin/cmake -P /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/tmp/tfm_test_repo-populate-gitupdate.cmake

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-patch: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'tfm_test_repo-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-patch

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-configure: tfm_test_repo-populate-prefix/tmp/tfm_test_repo-populate-cfgcmd.txt
tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-configure: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-update
tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-configure: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'tfm_test_repo-populate'"
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E echo_append
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-configure

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-build: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'tfm_test_repo-populate'"
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E echo_append
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-build

tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-test: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'tfm_test_repo-populate'"
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E echo_append
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-build && /usr/bin/cmake -E touch /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-test

tfm_test_repo-populate: CMakeFiles/tfm_test_repo-populate
tfm_test_repo-populate: CMakeFiles/tfm_test_repo-populate-complete
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-install
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-mkdir
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-download
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-update
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-patch
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-configure
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-build
tfm_test_repo-populate: tfm_test_repo-populate-prefix/src/tfm_test_repo-populate-stamp/tfm_test_repo-populate-test
tfm_test_repo-populate: CMakeFiles/tfm_test_repo-populate.dir/build.make

.PHONY : tfm_test_repo-populate

# Rule to build all files generated by this target.
CMakeFiles/tfm_test_repo-populate.dir/build: tfm_test_repo-populate

.PHONY : CMakeFiles/tfm_test_repo-populate.dir/build

CMakeFiles/tfm_test_repo-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tfm_test_repo-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tfm_test_repo-populate.dir/clean

CMakeFiles/tfm_test_repo-populate.dir/depend:
	cd /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild /home/han/srtp/tfm_freertos_aslr/tfm_freeRTOS/lib/ext/tfm_test_repo-subbuild/CMakeFiles/tfm_test_repo-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tfm_test_repo-populate.dir/depend

