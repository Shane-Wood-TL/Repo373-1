#include "main.h"
#include <cstdint>
#include "stm32l4xx_hal.h"

#include "basicGPIOClass.h"
#include "inputDriverDeclarations.h"
#include "queueDeclarations.h"
#include "outputDriverDeclarations.h"

#include "memoryBarrier.h"


//make this main linkable to the c main
extern "C" void cpp_main(void);

//both inputs are set to pullups
#define pullup true




void cpp_main(void) {
	//GPIO_Input(GPIO_TypeDef *port, uint64_t pinCast, bool pullup);
//
	GPIO_Input upButton(GPIOA, GPIO_PIN_6, pullup); //the button used to increase the counter
	GPIO_Input downButton(GPIOA, GPIO_PIN_4, pullup); //the button used to decrease the counter


//
	queue mainQueue; //the queue that everything else uses
//
	//input driver values
	int32_t increaseAmount = 1; //value to increase by
	int32_t decreaseAmount = -1; //value to decrease by

	//InputDriver(queue *queue1, uint32_t valToEnq1, GPIO_Input *input1, StateMachine *stateMachine1);
	InputDriver upButtonDriver(&mainQueue, &increaseAmount, &upButton); //up button driver (with internal state machine
	InputDriver downButtonDriver(&mainQueue, &decreaseAmount, &downButton); //down button driver (with internal state machine
//
//	// all output pins for seven segment displays
//	//GPIO_Output(GPIO_TypeDef *port, uint8_t pin);
	GPIO_Output segmentA(GPIOB, GPIO_PIN_7);
	GPIO_Output segmentB(GPIOB, GPIO_PIN_6);
	GPIO_Output segmentC(GPIOB, GPIO_PIN_1);
	GPIO_Output segmentD(GPIOA, GPIO_PIN_8);
	GPIO_Output segmentE(GPIOA, GPIO_PIN_11);
	GPIO_Output segmentF(GPIOB, GPIO_PIN_5);
	GPIO_Output segmentG(GPIOB, GPIO_PIN_4);

	//OutputDriver(queue *mainQueue, GPIO_Output *A, GPIO_Output *B,
	//GPIO_Output *C, GPIO_Output *D, GPIO_Output *E, GPIO_Output *F, GPIO_Output *G)
	//pass all segments to the output driver
	OutputDriver outputDriverInstance(&mainQueue, &segmentA, &segmentB,
			&segmentC, &segmentD, &segmentE, &segmentF, &segmentG);

	//simple memory barrier to catch memory issues (indexing past where another objects were allocated to)
	uint32_t memoryBarrier[32] = {1,11,111,1111,1,11,111,1111, 1,11,111,1111,1,11,111,1111, 1,11,111,1111,1,11,111,1111, 1,11,111,1111,1,11,111,1111};
	memoryChecker mainMemoryChecker(memoryBarrier);





	while (1) {
		upButtonDriver.checkAndEnqueue(); //check for up input, falling edge, handle enqueueing
		downButtonDriver.checkAndEnqueue(); //check for down input, falling edge, handle enqueueing
		outputDriverInstance.display(); //check / update the display, handle dequeueing

		mainMemoryChecker.checkMemory(); //checks memory barrier for a broken pattern


	}
}

