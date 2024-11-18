/*
 * count2.h
 *
 *  Created on: Nov 18, 2024
 *      Author: vityaman
 */

#ifndef INC_COUNT2_H_
#define INC_COUNT2_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint32_t value;
} count2_t;

void count2_init(count2_t *self);

void count2_add(count2_t *self);
void count2_sub(count2_t *self);

uint8_t count2_value(const count2_t *self);
uint32_t count2_overflows(const count2_t *self);
bool count2_bit(const count2_t *self, int bit);

#endif /* INC_COUNT2_H_ */
