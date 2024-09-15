/*
 * BasicGPIO.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: townl
 */
#include "basicGPIOClass.h"

GPIO_Input::GPIO_Input(GPIO_TypeDef *portI, uint16_t pinCastI, bool pullupI) :
		port(portI), pinCast(pinCastI), pullup(pullupI) {
} //set the member variables up given the parameters

void GPIO_Input::readPin(bool &value) { //read the input, change the value stored at value
	if (pullup) { //pull ups flip the inputs; high = no input, low = input
		value = !(HAL_GPIO_ReadPin(port, pinCast) == GPIO_PIN_SET);
	} else {
		//high = true, low = false
		value = (HAL_GPIO_ReadPin(port, pinCast) == GPIO_PIN_SET);
	}
	return;
}

GPIO_Output::GPIO_Output(GPIO_TypeDef *portI, uint8_t pinI) :
		port(portI), pin(pinI) {
}  //set the member variables up given the parameters

void GPIO_Output::writePin(bool setHigh) {
	if (setHigh == true) {  //if set high
		port->ODR |= (1 << pin); //write a 1 to the pin using bit banging
	} else {
		port->ODR &= (0 << pin); //write a 0 to the pin(low) using bit banging
	}
	return;
}
