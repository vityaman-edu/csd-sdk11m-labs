/*
 * debounce.h
 *
 *  Created on: Nov 18, 2024
 *      Author: vityaman
 */

#ifndef INC_DEBOUNCE_H_
#define INC_DEBOUNCE_H_

#include "coroutine.h"

#include <stdint.h>

enum debounce_state_t {
  DEBOUNCE_NOT_CLIKED,
  DEBOUNCE_SHORT_CLIKED,
  DEBOUNCE_LONG_CLIKED,
};

coroutine_declare(enum debounce_state_t, debounce, int64_t pressed_ticks);

#endif /* INC_DEBOUNCE_H_ */
