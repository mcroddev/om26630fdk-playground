# SPDX-License-Identifier: MIT
#
# Copyright 2025 Michael Rodriguez
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the “Software”), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR
		"In-tree builds are forbidden. Please create a separate build "
		"directory and run CMake from there.")
endif()

project(
	om26630fdk-playground-ccc
	VERSION 1.0.0.0
	DESCRIPTION "NXP OM26630FDK Playground Command & Control Center"
	HOMEPAGE_URL "https://github.com/mcroddev/om26630fdk-playground"
	LANGUAGES C CXX
)

if (CMAKE_VERSION LESS "3.26")
	# CMake versions >=3.26 set this property to ON by default.
	set(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

option(CCC_WARNINGS_ARE_ERRORS "Treat all warnings as errors" OFF)
option(CCC_ENABLE_SANITIZERS "Enable ASan and UBSan if possible" OFF)

# Note that an INTERFACE library is not a "real" library; it does not produce
# artifacts on disk nor does it require source files to be specified; in this
# case it is a way for us to set properties that get inherited by targets when
# they "link" to this library.
add_library(ccc_build_cfg_base INTERFACE)

# These flags are supported by both clang and gcc and are used regardless of the
# build type and language.
#
# Be sure to verify that this assertion holds when updating the minimum compiler
# versions, as we have no way to automate that process.
set(COMPILER_FLAGS_BASE)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	if (CMAKE_CXX_COMPILER_VERSION LESS "11.4.0")
		message(FATAL_ERROR
			"Your g++ version is too old to compile this project; "
			"please use g++ >=11.4.0 or clang >=14.0.0."
		)
	endif()

	# These flags apply if, and only if, g++ is the compiler.
	set(COMPILER_FLAGS_BASE_GCC)

	list(APPEND COMPILER_FLAGS_BASE "-ggdb3")
	list(APPEND COMPILER_FLAGS_BASE ${COMPILER_FLAGS_BASE_GCC})
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	if (CMAKE_CXX_COMPILER_VERSION LESS "14.0.0")
		message(FATAL_ERROR
			"Your clang++ version is too old to compile this "
			"project; please use g++ >=11.4.0 or clang++ >=14.0.0."
		)
	endif()
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	list(APPEND COMPILER_FLAGS_BASE "-Og")
endif()

if (CCC_ENABLE_SANITIZERS)
	list(APPEND COMPILER_FLAGS_BASE -fsanitize=address,undefined)

	target_link_options(
		ccc_build_cfg_base INTERFACE
		-fsanitize=address,undefined
	)
endif()

if (CCC_WARNINGS_ARE_ERRORS)
	list(APPEND COMPILER_FLAGS_BASE -Werror)
endif()

target_compile_options(ccc_build_cfg_base INTERFACE ${COMPILER_FLAGS_BASE})

add_subdirectory(src)