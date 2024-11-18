/*
 * debounce.c
 *
 *  Created on: Nov 18, 2024
 *      Author: vityaman
 */
#include "debounce.h"

#include "coroutine.h"

#include <stdbool.h>
#include <stdint.h>

enum {
  DEBOUNCE_SHORT_CLICK_DELAY = 50,
  DEBOUNCE_LONG_CLICK_DELAY = 250,
};

coroutine_define(enum debounce_state_t, debounce) {
  coroutine_start(is_pressed, now, pressed_ticks);

  pressed_ticks = 0;

  for (;;) {
    const uint32_t now_ticks = now();
    const uint32_t duration = now_ticks - pressed_ticks;

    const bool was_pressed = pressed_ticks != 0;
    const bool now_pressed = is_pressed();

    enum debounce_state_t state = DEBOUNCE_NOT_CLIKED;
    if (!now_pressed && was_pressed) {
      if (duration > DEBOUNCE_LONG_CLICK_DELAY) {
        state = DEBOUNCE_LONG_CLIKED;
      } else if (duration > DEBOUNCE_SHORT_CLICK_DELAY) {
        state = DEBOUNCE_SHORT_CLIKED;
      }
    }

    if (!now_pressed) {
      pressed_ticks = 0;
    } else if (now_pressed && !was_pressed) {
      pressed_ticks = now_ticks;
    }

    coroutine_yield(state);
  }

  coroutine_finish(0, pressed_ticks);
}
