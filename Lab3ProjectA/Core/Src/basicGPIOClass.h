/*
 * basicGPIOClass.h
 *
 *  Created on: Sep 11, 2024
 *      Author: townl
 */

#ifndef SRC_BASICGPIOCLASS_H_
#define SRC_BASICGPIOCLASS_H_
#include "main.h"


class GPIO_Input{
private:
	GPIO_TypeDef *port;
	uint16_t pinCast;
	bool pullup;
public:
	GPIO_Input(GPIO_TypeDef *port, uint16_t pinCast, bool pullup);
	void readPin(bool &value);
};



class GPIO_Output{
private:
	GPIO_TypeDef *port;
	uint8_t pin;
public:
	GPIO_Output(GPIO_TypeDef *port, uint8_t pin);
	void writePin(bool setHigh);
};


#endif /* SRC_BASICGPIOCLASS_H_ */
