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

#include "hal/hal-gpio.h"
#include "hal/hal-sysctl.h"

#include "board/nfc/nfc.h"
#include "board-clk.h"

void board_init(void)
{
	hal_sysctl_peripheral_power_disable(HAL_SYSCTL_PCONP_BIT_ALL_MASK);

	// ************************* ERRATA WARNING ****************************
	//
	// PCLKSELx.1: Peripheral Clock Selection Registers must be set before
	//             enabling and connecting PLL0
	//
	// Introduction: A pair of bits in the Peripheral Clock Registers
	//               (PCLKSEL0 and PCLKSEL1) controls the rate of the clock
	//               signal that will be supplied to APB0 and APB1
	//               peripherals.
	//
	// Problem: If the Peripheral Clock Registers (PCLKSEL0 and PCLKSEL1)
	//          are set or changed after PLL0 is enabled and connected, the
	//          value written into the Peripheral Clock Selection Registers
	//          may not take effect. It is not possible to change the
	//          Peripheral Clock Selection settings once PLL0 is enabled and
	//          connected.
	//
	// Work-around: Peripheral Clock Selection Registers must be set before
	//              enabling and connecting PLL0.
	//
	// ************************* ERRATA WARNING ****************************
	//
	// This means we have to configure all the peripherals first, and then
	// activate PLL0.
	hal_gpio_init();
	board_nfc_init();

	board_clk_cfg();
}