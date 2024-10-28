/*
 * coroutine.h
 *
 *  Created on: Oct 28, 2024
 *      Author: vityaman
 */

#ifndef INC_COROUTINE_H_
#define INC_COROUTINE_H_

#include "foreach.h"

#define coroutine_load(id) typeof(self->id) id = self->id;

#define coroutine_store(id) self->id = id;

#define coroutine_start(...)            \
  FOR_EACH(coroutine_load, __VA_ARGS__) \
  switch (self->label) {                \
    case 0:

#define coroutine_yield(val) \
  self->label = __LINE__;    \
  self->yield = val;         \
  goto yield;                \
  case __LINE__:

#define coroutine_finish(val, ...)         \
  default:                                 \
    self->label = -1;                      \
    self->yield = val;                     \
    goto yield;                            \
    }                                      \
  yield:                                   \
    FOR_EACH(coroutine_store, __VA_ARGS__) \
    return self->yield;

#define coroutine_declare(yield_type, name, ...)             \
  struct coroutine_##name {                                  \
    int label;                                               \
    yield_type yield;                                        \
    __VA_ARGS__;                                             \
    yield_type (*const procedure)(struct coroutine_##name*); \
  };                                                         \
                                                             \
  yield_type name(struct coroutine_##name* self)

#define coroutine_define(yield_type, name) yield_type name(struct coroutine_##name* self)

#define coroutine_create(instance, name, ...)                    \
  struct coroutine_##name instance = (struct coroutine_##name) { \
    .label = 0, .procedure = &name, __VA_ARGS__                  \
  }

#define coroutine_next(instance) instance.procedure(&instance)

#endif /* INC_COROUTINE_H_ */
