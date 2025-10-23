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

set(SRCS
	main.c
	board/board.c
	board/board-clk.c
	board/nfc/clrc663-spi-impl.c
	board/nfc/gpio.c
	board/nfc/nfc.c
	board/nfc/spi.c
	drivers/clrc663/clrc663.c
	drivers/clrc663/clrc663-cmd.c
	drivers/clrc663/clrc663-spi.c
	hal/hal-gpio.c
	hal/hal-pincm.c
	hal/hal-spi.c
	hal/hal-startup.c
	hal/hal-sysctl.c
)

set(HDRS
	compiler.h
	types.h
	util.h
	board/board.h
	board/board-clk.h
	board/nfc/gpio.h
	board/nfc/nfc.h
	board/nfc/spi.h
	drivers/clrc663/clrc663.h
	drivers/clrc663/clrc663-cmd.h
	hal/hal-gpio.h
	hal/hal-nvic.h
	hal/hal-pincm.h
	hal/hal-spi.h
	hal/hal-sysctl.h
	hal/hal-util.h
)
add_executable(om26630fdk-playground-fw ${SRCS} ${HDRS})

target_include_directories(om26630fdk-playground-fw PRIVATE .)

toolchain_set_linker_script(
	om26630fdk-playground-fw
	${CMAKE_SOURCE_DIR}/linker-script.ld
)

toolchain_print_target_size(om26630fdk-playground-fw)