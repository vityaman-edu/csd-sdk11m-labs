/*
 * MonotonicClock.cpp
 *
 *  Created on: Oct 28, 2024
 *      Author: vityaman
 */

#include "MonotonicClock.hpp"

#include <cstdint>

#include "stm32f4xx_hal.h"

uint32_t MonotonicClock::Ticks() {
  return HAL_GetTick();
}

uint32_t MonotonicClock::Frequency() {
  return HAL_GetTickFreq();
}
