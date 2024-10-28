/*
 * MonotonicClock.hpp
 *
 *  Created on: Oct 28, 2024
 *      Author: vityaman
 */

#ifndef MONOTONICCLOCK_H_
#define MONOTONICCLOCK_H_

#include <cstdint>

class MonotonicClock final {
public:
  static uint32_t Ticks();
  static uint32_t Frequency();

private:
  MonotonicClock() = default;
};

#endif /* MONOTONICCLOCK_H_ */
