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

#include "hal-gpio.h"
#include "hal-sysctl.h"

// clang-format off

const struct hal_gpio_pin HAL_GPIO_PIN_P_0_15 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL0,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE0,
	.fiodir_reg		= HAL_GPIO_REG_FIO0DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO0SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO0CLR,
	.fio_bit		= BIT_15,
	.pinsel_pinmode_mask	= BIT_31 | BIT_30
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_0_16 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL1,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE1,
	.fiodir_reg		= HAL_GPIO_REG_FIO0DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO0SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO0CLR,
	.fio_bit		= BIT_16,
	.pinsel_pinmode_mask	= BIT_1 | BIT_0
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_0_17 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL1,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE1,
	.fiodir_reg		= HAL_GPIO_REG_FIO0DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO0SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO0CLR,
	.fio_bit		= BIT_17,
	.pinsel_pinmode_mask	= BIT_3 | BIT_2
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_0_18 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL1,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE1,
	.fiodir_reg		= HAL_GPIO_REG_FIO0DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO0SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO0CLR,
	.fio_bit		= BIT_18,
	.pinsel_pinmode_mask	= BIT_5 | BIT_4
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_0_29 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL1,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE1,
	.fiodir_reg		= HAL_GPIO_REG_FIO0DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO0SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO0CLR,
	.fio_bit		= BIT_29,
	.pinsel_pinmode_mask	= BIT_27 | BIT_26
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_0_30 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL1,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE1,
	.fiodir_reg		= HAL_GPIO_REG_FIO0DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO0SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO0CLR,
	.fio_bit		= BIT_30,
	.pinsel_pinmode_mask	= BIT_28 | BIT_29
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_1_27 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL3,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE3,
	.fiodir_reg		= HAL_GPIO_REG_FIO1DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO1SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO1CLR,
	.fio_bit		= BIT_27,
	.pinsel_pinmode_mask	= BIT_23 | BIT_22
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_2_5 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL4,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE4,
	.fiodir_reg		= HAL_GPIO_REG_FIO2DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO2SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO2CLR,
	.fio_bit		= BIT_5,
	.pinsel_pinmode_mask	= BIT_11 | BIT_10
};

const struct hal_gpio_pin HAL_GPIO_PIN_P_2_9 = {
	.pinsel_reg		= HAL_PINSEL_REG_PINSEL4,
	.pinmode_reg		= HAL_PINMODE_REG_PINMODE4,
	.fiodir_reg		= HAL_GPIO_REG_FIO2DIR,
	.fioset_reg		= HAL_GPIO_REG_FIO2SET,
	.fioclr_reg		= HAL_GPIO_REG_FIO2CLR,
	.fio_bit		= BIT_9,
	.pinsel_pinmode_mask	= BIT_19 | BIT_18
};

// clang-format on

static void clear_pin_fiomask(void)
{
	mmio_write32(HAL_GPIO_REG_FIO0MASK, 0x00000000);
	mmio_write32(HAL_GPIO_REG_FIO1MASK, 0x00000000);
	mmio_write32(HAL_GPIO_REG_FIO2MASK, 0x00000000);
	mmio_write32(HAL_GPIO_REG_FIO3MASK, 0x00000000);
	mmio_write32(HAL_GPIO_REG_FIO4MASK, 0x00000000);
}

static void
set_gpio_pin_initial_state(const struct hal_gpio_pin *const pin,
			   const enum hal_gpio_pin_initial_state initial_state)
{
	if (initial_state == HAL_GPIO_PIN_INITIAL_STATE_LOW)
		hal_gpio_pin_set_low(pin);
	else if (initial_state == HAL_GPIO_PIN_INITIAL_STATE_HIGH)
		hal_gpio_pin_set_high(pin);
	else
		UNREACHABLE;
}

void hal_gpio_init(void)
{
	hal_sysctl_peripheral_power_enable(HAL_SYSCTL_PCONP_BIT_PCGPIO);
	clear_pin_fiomask();
}

void hal_gpio_pin_init(const struct hal_gpio_pin *const pin,
		       const struct hal_gpio_pin_cfg *const cfg)
{
	if (cfg->pin_func == HAL_PINSEL_FUNC_GPIO) {
		if (cfg->dir == HAL_GPIO_PIN_DIR_INPUT)
			mmio_clr32(pin->fiodir_reg, pin->fio_bit);
		else if (cfg->dir == HAL_GPIO_PIN_DIR_OUTPUT) {
			mmio_set32(pin->fiodir_reg, pin->fio_bit);
			set_gpio_pin_initial_state(pin, cfg->initial_state);
		} else {
			UNREACHABLE;
		}
	}

	hal_pincm_set_func(pin->pinsel_reg, pin->pinsel_pinmode_mask,
			   cfg->pin_func);

	hal_pincm_set_resistor(pin->pinmode_reg, pin->pinsel_pinmode_mask,
			       cfg->resistor);
}