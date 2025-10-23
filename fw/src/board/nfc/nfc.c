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

#include "drivers/clrc663/clrc663.h"

#include "gpio.h"
#include "nfc.h"
#include "spi.h"

void board_nfc_init(void)
{
	board_nfc_gpio_init();
	board_nfc_spi_init();

	board_nfc_enable();

#ifndef NDEBUG
	const u8 ver = drv_clrc663_reg_read(DRV_CLRC663_REG_Version);
	app_assert(ver == 0x1A);
#endif // NDEBUG
}

void board_nfc_enable(void)
{
	hal_gpio_pin_set_low(GPIO_PIN_CLRC_RST);
}

void board_nfc_disable(void)
{
	hal_gpio_pin_set_high(GPIO_PIN_CLRC_RST);
}