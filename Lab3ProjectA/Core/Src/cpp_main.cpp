#include "main.h"
#include <cstdint>
#include "stm32l4xx_hal.h"

#include "basicGPIOClass.h"
#include "inputDriverDeclarations.h"
#include "queueDeclarations.h"

#include "outputDriverDeclarations.h"
extern "C" void cpp_main(void);



void cpp_main(void){
	//GPIO_Input(GPIO_TypeDef *port, uint64_t pinCast, bool pullup);
	GPIO_Input upButton(GPIOA,GPIO_PIN_6, true);
	GPIO_Input downButton(GPIOA,GPIO_PIN_4, true);

	queue mainQueue;

	//input driver values
	int32_t increaseAmount = 1; //value to increase by
	int32_t decreaseAmount = -1; //value to decrease by

	//InputDriver(queue *queue1, uint32_t valToEnq1, GPIO_Input *input1, StateMachine *stateMachine1);
	InputDriver upButtonDriver(&mainQueue,&increaseAmount,&upButton); //up button driver (with internal state machine
	InputDriver downButtonDriver(&mainQueue,&decreaseAmount,&downButton); //down button driver (with internal state machine

	// all output pins for seven segment displays
	GPIO_Output segmentA(GPIOB, 7);
	GPIO_Output segmentB(GPIOB, 6);
	GPIO_Output segmentC(GPIOB, 1);
	GPIO_Output segmentD(GPIOA, 8);
	GPIO_Output segmentE(GPIOA, 11);
	GPIO_Output segmentF(GPIOB, 5);
	GPIO_Output segmentG(GPIOB, 4);

	//OutputDriver(GPIO_TypeDef *port, uint8_t pin, Counter *c)
	//pass all segments to the output driver
	OutputDriver outputDriverInstance(&mainQueue, &segmentA, &segmentB, &segmentC,&segmentD,&segmentE,&segmentF,&segmentG);


	while(1){
		upButtonDriver.checkAndEnqueue();
		downButtonDriver.checkAndEnqueue();
		outputDriverInstance.display();
	}
}


