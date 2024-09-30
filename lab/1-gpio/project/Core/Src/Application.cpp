/*
 * Application.cpp
 *
 *  Created on: Sep 30, 2024
 *      Author: vityaman
 */

#include "Application.h"
#include "Application.hpp"

#include "stm32f427xx.h"
#include "stm32f4xx_hal.h"

void Application::OnUpdate() {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_Delay(2500);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
	HAL_Delay(500);
}

void OnUpdate(application_ptr_t self) {
	static_cast<Application*>(self)->OnUpdate();
}
