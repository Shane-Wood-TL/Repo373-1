/*
 * BasicGPIO.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: townl
 */



#include "main.h"
#include "basicGPIOClass.h"

GPIO_Input::GPIO_Input(GPIO_TypeDef *port, uint16_t pinCast, bool pullup)
	: port(port), pinCast(pinCast), pullup(pullup) {
		this->port = port;
		this->pinCast = pinCast;
		this->pullup = pullup;
	}

void GPIO_Input::readPin(bool &value){
		if (pullup){
			value = !(HAL_GPIO_ReadPin(port,pinCast) == GPIO_PIN_SET);
		}else{
			value = (HAL_GPIO_ReadPin(port,pinCast) == GPIO_PIN_SET);
		}

		return;
}


GPIO_Output::GPIO_Output(GPIO_TypeDef *port, uint8_t pin){
	this->port = port;
	this->pin = pin;
}

void GPIO_Output::writePin(bool setHigh){
		if(setHigh == true){
			port->ODR |= (1 << pin);
		}else{
			port->ODR &= (0 << pin);
		}
		return;
}
