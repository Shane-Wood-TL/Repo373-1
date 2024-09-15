/*
 * inputDriverDeclarations.h
 *
 *  Created on: Sep 10, 2024
 *      Author: ShaneWood
 */

#ifndef SRC_INPUTDRIVERDECLARATIONS_H_
#define SRC_INPUTDRIVERDECLARATIONS_H_
#include <cstdint>
#include "main.h"
#include "queueDeclarations.h"
#include "basicGPIOClass.h"

class StateMachine {
private:
	//member variables
	bool pState;  // Previous state

public:
	//member functions
	StateMachine(); //no parameters for constructor
	bool detectFEdge(bool state);
};

class InputDriver {
private:
	//member variables
	queue *queueInstance;        // Pointer to the queue
	int32_t *valToEnq;          // Numerical value to enqueue
	GPIO_Input *input;          //GPIO input
	StateMachine stateMachine; // State machine instance

public:
	//member functions
	InputDriver(queue *queue1, int32_t *valToEnq1, GPIO_Input *input1);
	void checkAndEnqueue(); //check for falling edges and enqueue value
};

#endif /* SRC_INPUTDRIVERDECLARATIONS_H_ */
