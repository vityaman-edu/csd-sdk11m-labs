/*
 * Application.cpp
 *
 *  Created on: Sep 30, 2024
 *      Author: vityaman
 */

#include "Application.h"
#include "Application.hpp"

void Application::OnUpdate() {

}

void OnUpdate(application_ptr_t self) {
	static_cast<Application*>(self)->OnUpdate();
}
