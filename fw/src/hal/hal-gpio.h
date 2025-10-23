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

#include "compiler.h"
#include "hal-pincm.h"
#include "hal-util.h"
#include "types.h"

enum hal_gpio_pin_dir {
	HAL_GPIO_PIN_DIR_AUTO,
	HAL_GPIO_PIN_DIR_OUTPUT,
	HAL_GPIO_PIN_DIR_INPUT
};

enum hal_gpio_pin_initial_state {
	HAL_GPIO_PIN_INITIAL_STATE_AUTO,
	HAL_GPIO_PIN_INITIAL_STATE_LOW,
	HAL_GPIO_PIN_INITIAL_STATE_HIGH
};

enum hal_gpio_reg_fiomask {
	HAL_GPIO_REG_FIO0MASK = 0x2009C010,
	HAL_GPIO_REG_FIO1MASK = 0x2009C030,
	HAL_GPIO_REG_FIO2MASK = 0x2009C050,
	HAL_GPIO_REG_FIO3MASK = 0x2009C070,
	HAL_GPIO_REG_FIO4MASK = 0x2009C090
};

enum hal_gpio_reg_fiodir {
	HAL_GPIO_REG_FIO0DIR = 0x2009C000,
	HAL_GPIO_REG_FIO1DIR = 0x2009C020,
	HAL_GPIO_REG_FIO2DIR = 0x2009C040,
	HAL_GPIO_REG_FIO3DIR = 0x2009C060,
	HAL_GPIO_REG_FIO4DIR = 0x2009C080
};

enum hal_gpio_reg_fioset {
	HAL_GPIO_REG_FIO0SET = 0x2009C018,
	HAL_GPIO_REG_FIO1SET = 0x2009C038,
	HAL_GPIO_REG_FIO2SET = 0x2009C058,
	HAL_GPIO_REG_FIO3SET = 0x2009C078,
	HAL_GPIO_REG_FIO4SET = 0x2009C098
};

enum hal_gpio_reg_fioclr {
	HAL_GPIO_REG_FIO0CLR = 0x2009C01C,
	HAL_GPIO_REG_FIO1CLR = 0x2009C03C,
	HAL_GPIO_REG_FIO2CLR = 0x2009C05C,
	HAL_GPIO_REG_FIO3CLR = 0x2009C07C,
	HAL_GPIO_REG_FIO4CLR = 0x2009C09C
};

struct hal_gpio_pin {
	const enum hal_pinsel_reg pinsel_reg;
	const enum hal_pinmode_reg pinmode_reg;
	const enum hal_gpio_reg_fiodir fiodir_reg;
	const enum hal_gpio_reg_fioset fioset_reg;
	const enum hal_gpio_reg_fioclr fioclr_reg;
	const u32 fio_bit;
	const u32 pinsel_pinmode_mask;
};

struct hal_gpio_pin_cfg {
	enum hal_pinmode_resistor resistor;
	enum hal_pinsel_func pin_func;
	enum hal_gpio_pin_dir dir;
	enum hal_gpio_pin_initial_state initial_state;
};

void hal_gpio_init(void);

void hal_gpio_pin_init(const struct hal_gpio_pin *pin,
		       const struct hal_gpio_pin_cfg *cfg);

ALWAYS_INLINE void hal_gpio_pin_set_low(const struct hal_gpio_pin *const pin)
{
	mmio_write32(pin->fioclr_reg, pin->fio_bit);
}

ALWAYS_INLINE void hal_gpio_pin_set_high(const struct hal_gpio_pin *const pin)
{
	mmio_write32(pin->fioset_reg, pin->fio_bit);
}

ALWAYS_INLINE void hal_gpio_pin_toggle(const struct hal_gpio_pin *const pin)
{
	u32 FIOSET = mmio_read32(pin->fioset_reg);

	if (FIOSET & pin->fio_bit) {
		u32 FIOCLR = mmio_read32(pin->fioclr_reg);
		FIOCLR |= pin->fio_bit;
		mmio_write32(pin->fioclr_reg, FIOCLR);
	} else {
		FIOSET |= pin->fio_bit;
		mmio_write32(pin->fioset_reg, FIOSET);
	}
}

extern const struct hal_gpio_pin HAL_GPIO_PIN_P_0_15;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_0_16;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_0_17;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_0_18;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_0_29;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_0_30;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_1_27;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_2_5;
extern const struct hal_gpio_pin HAL_GPIO_PIN_P_2_9;