/*
 * count2.c
 *
 *  Created on: Nov 18, 2024
 *      Author: vityaman
 */
#include "count2.h"

#include "assert.h"

void count2_init(count2_t *self) { self->value = 0; }

void count2_add(count2_t *self) { self->value += 1; }

void count2_sub(count2_t *self) {
  if (self->value == 0) {
    return;
  }
  self->value -= 1;
}

uint8_t count2_value(const count2_t *self) { return self->value % 4; }

uint32_t count2_overflows(const count2_t *self) { return self->value / 4; }

bool count2_bit(const count2_t *self, int bit) {
  assert(bit == 0 || bit == 1);
  return (count2_value(self) >> bit) % 2 == 1;
}
