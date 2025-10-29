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

set(SRCS main.cpp)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets SerialPort)
qt_standard_project_setup()

qt_add_executable(om26630fdk-playground-ccc ${SRCS})

target_link_libraries(
	om26630fdk-playground-ccc PRIVATE
	Qt6::Widgets
	Qt6::SerialPort
	ccc_build_cfg_base
)

target_include_directories(om26630fdk-playground-ccc PRIVATE .)

set_target_properties(
	om26630fdk-playground-ccc PROPERTIES
	WIN32_EXECUTABLE ON
	MACOSX_BUNDLE ON
)
