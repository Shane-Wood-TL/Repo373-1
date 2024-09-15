#include "inputDriverDeclarations.h"

StateMachine::StateMachine() :
		pState(false) {
} //set the present state to false

//Update the state with the current pin value
bool StateMachine::detectFEdge(bool state) {
	bool cState = state;  // Current state
	bool FEdgeDetected; //value to store state machine result

	if (pState == true and cState == false) { //falling =past high, present low
		FEdgeDetected = true; //the 1 case where a falling edge is detected
	} else {
		FEdgeDetected = false; //all other cases are not a falling edge
	}
	pState = cState; //update the past state to the current state
	return FEdgeDetected;
}

InputDriver::InputDriver(queue *queue1, int32_t *valToEnq1, GPIO_Input *input1) :
		queueInstance(queue1), valToEnq(valToEnq1), input(input1) { //pass values as addresses and ensure no new objects are created
} //(no local instances of these classes or things are not going to work

//check for falling edges and enqueue value
void InputDriver::checkAndEnqueue() {
	bool data = false; //assume the common case; no input is detected
	input->readPin(data);
	if (stateMachine.detectFEdge(data)) {
		queueInstance->enqueue(*valToEnq); //place value on the queue
	}
	return;
}

//original gabe code
/*attempt 2
 * class StateMachine
{
public:
    //intialization of state
    StateMachine() : pState(false), cState(false) {}

    //Update the state with the current pin value
    bool detectFEdge(bool state)
    {
        cState = state;
        bool FEdgeDetected = (pState == true && cState == false);
        pState = cState;
        return FEdgeDetected;
    }

private:
    bool pState;  // Previous state
    bool cState;  // Current state
};

class InputDriver
{
private:
    queue queueInstance;        // Pointer to the queue
    uint32_t valToEnq;          // Numerical value to enqueue
    GPIO_Input* input;          //GPIO input
    bool data;                   //
    StateMachine* stateMachine; // State machine instance

public:

    InputDriver(queue queue1, uint32_t valToEnq1, GPIO_Input input1, StateMachine stateMachine1, bool data1)
    {
        queueInstance = queue1;
        valToEnq = valToEnq1;
        input = input1;
        data = data1;
        stateMachine = stateMachine1;
    }

    //check for falling edges and enqueue value
    void checkAndEnqueue()
    {
        input->readPin(data);
        if (stateMachine->detectFEdge(data))
        {
            queueInstance->enqueue(valToEnq);
        }
    }

};

attempt 1
#include <iostream>

using namespace std;


class StateMachine
{
public:
    //intialization of state
    StateMachine() : pState(false), cState(false) {}

    //Update the state with the current pin value
    bool detectFEdge(bool state)
    {
        cState = state;
        bool FEdgeDetected = (pState == true && cState == false);
        pState = cState;
        return FEdgeDetected;
    }

private:
    bool pState;  // Previous state
    bool cState;  // Current state
};


class InputDriver
{
public:

    InputDriver(Queue* queue, uint32_t valToEnq, uint32_t pinNum, GPIO_Port_type port, Statemachine* stateMachine )
    {
        this.queue = queue;
        this.valToENq = valToEnql;
        this.pinNum = pinNum;
        this.port = port;
        this.stateMachine = stateMachine;
    }

    //check for falling edges and enqueue value
    void checkAndEnqueue()
    {
        uint32_t data = port->IDR &(1 << pinNum);
        if (stateMachine->detectFEdge(data))
        {
            queue->push(valToEnq);
        }
    }

private:
    Queue* queue;                 // Pointer to the queue
    uint32_t valToEnq;         // Numerical value to enqueue
    uint32_t pinNum;                 // GPIO pin number
    // GPIO_Port_type port;
    StateMachine* stateMachine;  // State machine instance
};

int main()
{
    return 0;
}
 */
