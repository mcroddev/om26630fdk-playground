// SPDX-License-Identifier: MIT
//
// Copyright 2025 Michael Rodriguez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "board-clk.h"
#include "hal/hal-sysctl.h"

enum {
	PLL0_CCLK_MUL = 12,
	PLL0_CCLK_DIV = 1,
	PLL0_CCLK_CCLKDIV = 3,
};

void board_clk_cfg(void)
{
	// Enable the main oscillator.
	//
	// On the OM26630FDK, there is a 12MHz crystal connected to the XTAL1
	// and XTAL2 pins.
	hal_sysctl_main_osc_enable(HAL_SYSCTL_MAIN_OSC_RANGE_1_TO_20_MHZ);

	// Configure CCLK to run at ~48MHz.
	const struct hal_sysctl_pll_cfg pll_cfg = {
		// clang-format off

		.pll_mul	= PLL0_CCLK_MUL,
		.pll_div	= PLL0_CCLK_DIV,
		.cclkcfg_div	= PLL0_CCLK_CCLKDIV,
		.osc_src	= HAL_SYSCTL_OSC_MAIN

		// clang-format on
	};
	hal_sysctl_cclk_cfg(&pll_cfg);

	// We're now running at 48MHz; adjust the flash access time.
	hal_sysctl_flash_access_time_set(HAL_SYSCTL_FLASH_ACCESS_TIME_CLK_4);
}