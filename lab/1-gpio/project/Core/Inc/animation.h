/*
 * animation.h
 *
 *  Created on: Oct 28, 2024
 *      Author: vityaman
 */

#ifndef INC_ANIMATION_H_
#define INC_ANIMATION_H_

#include <stdint.h>

#include "coroutine.h"

coroutine_declare(uint32_t, animation, uint32_t overflows; uint32_t i);

#endif /* INC_ANIMATION_H_ */
