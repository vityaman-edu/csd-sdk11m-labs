/*
 * debounce.h
 *
 *  Created on: Nov 18, 2024
 *      Author: vityaman
 */

#ifndef INC_DEBOUNCE_H_
#define INC_DEBOUNCE_H_

#include "coroutine.h"

#include <stdbool.h>
#include <stdint.h>

enum debounce_state_t {
  DEBOUNCE_NOT_CLIKED,
  DEBOUNCE_SHORT_CLIKED,
  DEBOUNCE_LONG_CLIKED,
};

typedef bool (*debounce_is_pressed_t)();

typedef uint32_t (*debounce_now_t)();

coroutine_declare(enum debounce_state_t, debounce,
                  debounce_is_pressed_t is_pressed;
                  debounce_now_t now; uint32_t pressed_ticks);

#endif /* INC_DEBOUNCE_H_ */
