/*
 * animation.c
 *
 *  Created on: Oct 28, 2024
 *      Author: vityaman
 */

#include "animation.h"

#include "coroutine.h"
#include "stm32f427xx.h"
#include "stm32f4xx_hal.h"

#define wait coroutine_yield

enum {
  DELAY = 1000,
};

typedef enum {
  GREEN = GPIO_PIN_13,
  YELLOW = GPIO_PIN_14,
  RED = GPIO_PIN_15,
} Color;

typedef enum {
  ON = GPIO_PIN_SET,
  OFF = GPIO_PIN_RESET,
} State;

static void light(Color color, State state) {
  HAL_GPIO_WritePin(GPIOD, color, state);
}

coroutine_define(uint32_t, animation) {
  coroutine_start(overflows, i);

  light(GREEN, OFF);
  light(RED, OFF);
  wait(DELAY);

  light(GREEN, ON);
  light(RED, ON);
  wait(DELAY);

  light(GREEN, OFF);
  light(RED, OFF);
  wait(DELAY);

  for (i = 0; i < overflows; ++i) {
    light(GREEN, ON);
    wait(DELAY);
    light(GREEN, OFF);
    wait(DELAY);
  }

  coroutine_finish(0, overflows, i);
}
