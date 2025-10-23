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

#include "hal-sysctl.h"
#include "types.h"

enum hal_spi_instance {
	// clang-format off

	HAL_SPI_INSTANCE_SPI0,
	HAL_SPI_INSTANCE_SPI1

	// clang-format on
};

enum hal_spi_data_size {
	HAL_SPI_DATA_SIZE_4BIT = 3,
	HAL_SPI_DATA_SIZE_5BIT = 4,
	HAL_SPI_DATA_SIZE_6BIT = 5,
	HAL_SPI_DATA_SIZE_7BIT = 6,
	HAL_SPI_DATA_SIZE_8BIT = 7,
	HAL_SPI_DATA_SIZE_9BIT = 8,
	HAL_SPI_DATA_SIZE_10BIT = 9,
	HAL_SPI_DATA_SIZE_11BIT = 10,
	HAL_SPI_DATA_SIZE_12BIT = 11,
	HAL_SPI_DATA_SIZE_13BIT = 12,
	HAL_SPI_DATA_SIZE_14BIT = 13,
	HAL_SPI_DATA_SIZE_15BIT = 14,
	HAL_SPI_DATA_SIZE_16BIT = 15
};

enum hal_spi_cfg_moto_spi_cpol {
	/** SSP controller maintains the bus clock low between frames. */
	HAL_SPI_CFG_MOTO_SPI_CPOL_LOW,

	/** SSP controller maintains the bus clock high between frames. */
	HAL_SPI_CFG_MOTO_SPI_CPOL_HIGH
};

enum hal_spi_cfg_moto_spi_cpha {
	/**
	 * SSP controller captures serial data on the first clock transition of
	 * the frame, that is, the transition away from the inter-frame state
	 * of the clock line.
	 */
	HAL_SPI_CFG_MOTO_SPI_CPHA_FIRST,

	/**
	 * SSP controller captures serial data on the second clock transition of
	 * the frame, that is, the transition back to the inter-frame state of
	 * the clock line.
	 */
	HAL_SPI_CFG_MOTO_SPI_CPHA_SECOND
};

struct hal_spi_cfg_moto_master {
	enum hal_sysctl_pclksel_clk clk_speed;
	enum hal_spi_data_size data_size;
	enum hal_spi_cfg_moto_spi_cpol cpol;
	enum hal_spi_cfg_moto_spi_cpha cpha;
	u8 prescaler;
	u8 serial_clk_rate;
};

void hal_spi_init_moto_master(enum hal_spi_instance inst,
			      const struct hal_spi_cfg_moto_master *cfg);

void hal_spi_tx_blocking_u8(enum hal_spi_instance inst, const u8 *src,
			    u32 src_size);

void hal_spi_tx_rx_blocking_u8(enum hal_spi_instance inst, const u8 *src,
			       u8 *dst, u32 size);