/*
 * basicGPIOClass.h
 *
 *  Created on: Sep 11, 2024
 *      Author: townl
 */

#ifndef SRC_BASICGPIOCLASS_H_
#define SRC_BASICGPIOCLASS_H_
#include "main.h"
#include "stm32l4xx_ll_gpio.h"
#include "stm32l4xx_ll_bus.h"

class GPIO_Input {
private:
	GPIO_TypeDef *port; //port to use
	uint32_t pinCast; //pint to use GPIO_PIN_n
	bool pullup;
public:
	GPIO_Input(GPIO_TypeDef *portI, uint32_t pinCastI, bool pullupI);
	void readPin(bool &value);
};

class GPIO_Output {
private:
	GPIO_TypeDef *port; //port to use
	uint32_t pinCast;  //pin to use
public:
	GPIO_Output(GPIO_TypeDef *portI, uint32_t pinCastI);
	void writePin(bool setHigh);
};

#endif /* SRC_BASICGPIOCLASS_H_ */
