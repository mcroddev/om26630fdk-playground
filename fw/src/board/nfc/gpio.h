#pragma once

#include "hal/gpio.h"

// clang-format off

#define GPIO_PIN_LPC_SCK	(&GPIO_PIN_P_0_15)
#define GPIO_PIN_LPC_SSEL	(&GPIO_PIN_P_0_16)
#define GPIO_PIN_LPC_MISO	(&GPIO_PIN_P_0_17)
#define GPIO_PIN_LPC_MOSI	(&GPIO_PIN_P_0_18)
#define GPIO_PIN_CLRC_RST	(&GPIO_PIN_P_2_5)

// clang-format on

void nfc_gpio_init(void);