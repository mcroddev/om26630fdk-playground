#pragma once

#include <hal/hal-gpio.h>

// clang-format off

#define GPIO_PIN_LPC_SCK	(&HAL_GPIO_PIN_P_0_15)
#define GPIO_PIN_LPC_SSEL	(&HAL_GPIO_PIN_P_0_16)
#define GPIO_PIN_LPC_MISO	(&HAL_GPIO_PIN_P_0_17)
#define GPIO_PIN_LPC_MOSI	(&HAL_GPIO_PIN_P_0_18)
#define GPIO_PIN_CLRC_RST	(&HAL_GPIO_PIN_P_2_5)

// clang-format on

void board_nfc_gpio_init(void);