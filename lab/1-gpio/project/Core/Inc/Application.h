/*
 * Application.h
 *
 *  Created on: Sep 30, 2024
 *      Author: vityaman
 */

#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void* application_ptr_t;

void OnUpdate(application_ptr_t application);

#ifdef __cplusplus
}
#endif

#endif /* INC_APPLICATION_H_ */
