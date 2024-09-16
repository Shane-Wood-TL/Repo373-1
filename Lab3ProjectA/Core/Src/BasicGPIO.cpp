/*
 * BasicGPIO.cpp
 *
 *  Created on: Sep 11, 2024
 *      Author: townl
 */
#include "basicGPIOClass.h"


GPIO_Input::GPIO_Input(GPIO_TypeDef *portI, uint32_t pinCastI, bool pullupI) :
		port(portI), pinCast(pinCastI), pullup(pullupI) {
} //set the member variables up given the parameters

void GPIO_Input::readPin(bool &value) { //read the input, change the value stored at value
	if (pullup) { //pull ups flip the inputs; high = no input, low = input
		value = !(LL_GPIO_IsInputPinSet(port, pinCast));
	} else {
		//high = true, low = false
		value = (LL_GPIO_IsInputPinSet(port, pinCast));
	}
	return;
}

GPIO_Output::GPIO_Output(GPIO_TypeDef *portI, uint32_t pinCastI) :
		port(portI), pinCast(pinCastI) {
}  //set the member variables up given the parameters

void GPIO_Output::writePin(bool setHigh) {
	if (setHigh == true) {  //if set high
		LL_GPIO_SetOutputPin(port,pinCast); //set pin high
		//bit banging was not working predictably when debugging, switched to using HAL
		//port->ODR |= (1 << pin); //write a 1 to the pin using bit banging
	} else {
		LL_GPIO_ResetOutputPin(port,pinCast);//set pin low
		//port->ODR &= (0 << pin); //write a 0 to the pin(low) using bit banging
	}
	return;
}
