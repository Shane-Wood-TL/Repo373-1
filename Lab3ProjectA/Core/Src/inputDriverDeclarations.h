/*
 * inputDriverDeclarations.h
 *
 *  Created on: Sep 10, 2024
 *      Author: townl
 */

#ifndef SRC_INPUTDRIVERDECLARATIONS_H_
#define SRC_INPUTDRIVERDECLARATIONS_H_
#include <cstdint>
#include "main.h"
#include "queueDeclarations.h"
#include "basicGPIOClass.h"

class StateMachine
{
	private:
    bool pState;  // Previous state
    bool cState;  // Current state
public:
    //intialization of state
	StateMachine() : pState(false), cState(false) {this->pState=false; this->cState=false;}
    bool detectFEdge(bool state);
};

class InputDriver
{
private:
    queue* queueInstance;        // Pointer to the queue
    int32_t *valToEnq;          // Numerical value to enqueue
    GPIO_Input* input;          //GPIO input
    bool data;                   //
    StateMachine stateMachine; // State machine instance

public:

	InputDriver(queue *queue1, int32_t *valToEnq1, GPIO_Input *input1)
	    :queueInstance(queue1), valToEnq(valToEnq1), input(input1){
		this->queueInstance = queue1;
		this->valToEnq = valToEnq1;
		this->input = input1;
	    data = false;
	}
    //check for falling edges and enqueue value
    void checkAndEnqueue();
};

#endif /* SRC_INPUTDRIVERDECLARATIONS_H_ */
