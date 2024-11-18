/*
 * debounce.c
 *
 *  Created on: Nov 18, 2024
 *      Author: vityaman
 */
#include "debounce.h"

#include "coroutine.h"

#include "stm32f427xx.h"
#include "stm32f4xx_hal.h"

#include <stdbool.h>

bool is_pressed() { return !HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15); }

coroutine_define(enum debounce_state_t, debounce) {
  coroutine_start(pressed_ticks);

  pressed_ticks = 0;

  for (;;) {
    bool was_pressed = pressed_ticks != 0;
    bool now_pressed = is_pressed();

    enum debounce_state_t state = DEBOUNCE_NOT_CLIKED;

    if (!now_pressed && was_pressed) {
      if (pressed_ticks > 40000) {
        state = DEBOUNCE_LONG_CLIKED;
      } else if (pressed_ticks > 5000) {
        state = DEBOUNCE_SHORT_CLIKED;
      }
    }

    if (now_pressed) {
      pressed_ticks += 1;
    } else {
      pressed_ticks = 0;
    }

    coroutine_yield(state);
  }

  coroutine_finish(0, pressed_ticks);
}
