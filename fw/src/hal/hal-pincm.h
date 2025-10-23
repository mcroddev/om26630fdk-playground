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

#pragma once

#include "types.h"

enum hal_pinsel_reg {
	HAL_PINSEL_REG_PINSEL0 = 0x4002C000,
	HAL_PINSEL_REG_PINSEL1 = 0x4002C004,
	HAL_PINSEL_REG_PINSEL2 = 0x4002C008,
	HAL_PINSEL_REG_PINSEL3 = 0x4002C00C,
	HAL_PINSEL_REG_PINSEL4 = 0x4002C010,
	HAL_PINSEL_REG_PINSEL7 = 0x4002C01C,
	HAL_PINSEL_REG_PINSEL8 = 0x4002C020,
	HAL_PINSEL_REG_PINSEL9 = 0x4002C024,
	HAL_PINSEL_REG_PINSEL10 = 0x4002C028
};

enum hal_pinmode_reg {
	HAL_PINMODE_REG_PINMODE0 = 0x4002C040,
	HAL_PINMODE_REG_PINMODE1 = 0x4002C044,
	HAL_PINMODE_REG_PINMODE2 = 0x4002C048,
	HAL_PINMODE_REG_PINMODE3 = 0x4002C04C,
	HAL_PINMODE_REG_PINMODE4 = 0x4002C050
};

enum hal_pinmode_resistor {
	HAL_PINMODE_RESISTOR_PULL_UP,
	HAL_PINMODE_RESISTOR_REPEATER,
	HAL_PINMODE_RESISTOR_NONE,
	HAL_PINMODE_RESISTOR_PULL_DOWN
};

enum hal_pinsel_func {
	HAL_PINSEL_FUNC_GPIO = 0,

	HAL_PINSEL_FUNC_P_0_15_SCK0 = 2,
	HAL_PINSEL_FUNC_P_0_16_SSEL0 = 2,
	HAL_PINSEL_FUNC_P_0_17_MISO0 = 2,
	HAL_PINSEL_FUNC_P_0_18_MOSI0 = 2,

	HAL_PINSEL_FUNC_P_0_29_USB_D_POS = 1,
	HAL_PINSEL_FUNC_P_0_30_USB_D_NEG = 1,

	HAL_PINSEL_FUNC_P_1_27_CLKOUT = 1,

	HAL_PINSEL_FUNC_P_2_9_USB_CON = 1
};

void hal_pincm_set_func(enum hal_pinsel_reg reg, u32 pinsel_mask,
			enum hal_pinsel_func func);

void hal_pincm_set_resistor(enum hal_pinmode_reg reg, u32 pinmode_mask,
			    enum hal_pinmode_resistor resistor);