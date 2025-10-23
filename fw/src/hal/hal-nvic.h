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
#include "hal-util.h"
#include "types.h"

enum hal_nvic_irq {
	HAL_NVIC_IRQ_WDT,
	HAL_NVIC_IRQ_T0,
	HAL_NVIC_IRQ_T1,
	HAL_NVIC_IRQ_T2,
	HAL_NVIC_IRQ_T3,
	HAL_NVIC_IRQ_UART0,
	HAL_NVIC_IRQ_UART1,
	HAL_NVIC_IRQ_UART2,
	HAL_NVIC_IRQ_UART3,
	HAL_NVIC_IRQ_PWM1,
	HAL_NVIC_IRQ_I2C0,
	HAL_NVIC_IRQ_I2C1,
	HAL_NVIC_IRQ_I2C2,
	HAL_NVIC_IRQ_SPI,
	HAL_NVIC_IRQ_SSP0,
	HAL_NVIC_IRQ_SSP1,
	HAL_NVIC_IRQ_PLL0,
	HAL_NVIC_IRQ_RTC,
	HAL_NVIC_IRQ_EINT0,
	HAL_NVIC_IRQ_EINT1,
	HAL_NVIC_IRQ_EINT2,
	HAL_NVIC_IRQ_EINT3,
	HAL_NVIC_IRQ_ADC,
	HAL_NVIC_IRQ_BOD,
	HAL_NVIC_IRQ_USB,
	HAL_NVIC_IRQ_CAN,
	HAL_NVIC_IRQ_GPDMA,
	HAL_NVIC_IRQ_I2S,
	HAL_NVIC_IRQ_ETH,
	HAL_NVIC_IRQ_RIT,
	HAL_NVIC_IRQ_MCPWM,
	HAL_NVIC_IRQ_QEI,
	HAL_NVIC_IRQ_PLL1,
	HAL_NVIC_IRQ_USBACT,
	HAL_NVIC_IRQ_CANACT
};

enum hal_nvic_iser {
	HAL_NVIC_ISER0 = 0xE000E100,
	HAL_NVIC_ISER1 = 0xE000E104,
	HAL_NVIC_ISER2 = 0xE000E108,
	HAL_NVIC_ISER3 = 0xE000E10C,
	HAL_NVIC_ISER4 = 0xE000E110,
	HAL_NVIC_ISER5 = 0xE000E114,
	HAL_NVIC_ISER6 = 0xE000E118,
	HAL_NVIC_ISER7 = 0xE000E11C,
	HAL_NVIC_ISER8 = 0xE000E120,
	HAL_NVIC_ISER9 = 0xE000E124,
	HAL_NVIC_ISER10 = 0xE000E128,
	HAL_NVIC_ISER11 = 0xE000E12C,
	HAL_NVIC_ISER12 = 0xE000E130,
	HAL_NVIC_ISER13 = 0xE000E134,
	HAL_NVIC_ISER14 = 0xE000E138,
	HAL_NVIC_ISER15 = 0xE000E13C
};

enum hal_nvic_icer {
	HAL_NVIC_ICER0 = 0xE000E180,
	HAL_NVIC_ICER1 = 0xE000E184,
	HAL_NVIC_ICER2 = 0xE000E188,
	HAL_NVIC_ICER3 = 0xE000E18C,
	HAL_NVIC_ICER4 = 0xE000E190,
	HAL_NVIC_ICER5 = 0xE000E194,
	HAL_NVIC_ICER6 = 0xE000E198,
	HAL_NVIC_ICER7 = 0xE000E19C,
	HAL_NVIC_ICER8 = 0xE000E1A0,
	HAL_NVIC_ICER9 = 0xE000E1A4,
	HAL_NVIC_ICER10 = 0xE000E1A8,
	HAL_NVIC_ICER11 = 0xE000E1AC,
	HAL_NVIC_ICER12 = 0xE000E1B0,
	HAL_NVIC_ICER13 = 0xE000E1B4,
	HAL_NVIC_ICER14 = 0xE000E1B8,
	HAL_NVIC_ICER15 = 0xE000E1BC
};

enum hal_nvic_icpr {
	HAL_NVIC_ICPR0 = 0xE000E200,
	HAL_NVIC_ICPR1 = 0xE000E204,
	HAL_NVIC_ICPR2 = 0xE000E208,
	HAL_NVIC_ICPR3 = 0xE000E20C,
	HAL_NVIC_ICPR4 = 0xE000E210,
	HAL_NVIC_ICPR5 = 0xE000E214,
	HAL_NVIC_ICPR6 = 0xE000E218,
	HAL_NVIC_ICPR7 = 0xE000E21C,
	HAL_NVIC_ICPR8 = 0xE000E220,
	HAL_NVIC_ICPR9 = 0xE000E224,
	HAL_NVIC_ICPR10 = 0xE000E228,
	HAL_NVIC_ICPR11 = 0xE000E22C,
	HAL_NVIC_ICPR12 = 0xE000E230,
	HAL_NVIC_ICPR13 = 0xE000E234,
	HAL_NVIC_ICPR14 = 0xE000E238,
	HAL_NVIC_ICPR15 = 0xE000E23C
};

ALWAYS_INLINE void hal_nvic_irq_enable(const enum hal_nvic_irq irq)
{
	const enum hal_nvic_iser iser_addr =
		HAL_NVIC_ISER0 + ((irq >> 5) * sizeof(u32));

	mmio_set32(iser_addr, UINT32_C(1) << (irq & 0x1F));
}

ALWAYS_INLINE void hal_nvic_irq_disable(const enum hal_nvic_irq irq)
{
	const enum hal_nvic_icer icer_addr =
		HAL_NVIC_ICER0 + ((irq >> 5) * sizeof(u32));

	mmio_set32(icer_addr, UINT32_C(1) << (irq & 0x1F));
}

ALWAYS_INLINE void hal_nvic_irq_clr_pending(const enum hal_nvic_irq irq)
{
	const enum hal_nvic_icpr icpr_addr =
		HAL_NVIC_ICPR0 + ((irq >> 5) * sizeof(u32));

	mmio_set32(icpr_addr, UINT32_C(1) << (irq & 0x1F));
}