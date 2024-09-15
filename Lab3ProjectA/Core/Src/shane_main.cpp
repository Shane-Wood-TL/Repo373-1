/*
 * cpp_main.cpp
 *
 *  Created on: Sep 3, 2024
 *      Author: townl
 */

#include "queueDeclarations.h"

queue::queue() :
		tail(0) {

} //basic constructor, sets up tail value

//adds messages to queue
bool queue::enqueue(int32_t msg) {
	if (tail < Q_SIZE) { //if there is space
		queueList[tail] = msg; //add message to end of queue
		tail += 1; //prepare to add the next value by changing the tail
		return true; //return true as the value was added
	} else { //no space in queue
		return false; //return false, value is not added
	}
}

//remove messages from queue (FIFO)
bool queue::dequeue(int32_t *msg) {
	if (tail == 0) { //if there are no messages return false
		return false;
	}
	*msg = (queueList[0]); //set the value of message to the value that will be removed

	for (uint8_t i = 0; i < tail - 1; i++) { //make each index n-1 so that that 0th index is replaced
		queueList[i] = queueList[i + 1]; //q[0] = q[1], q[1] = q[2], etc
	}
	tail -= 1; //since a value was removed the tail needs to be decreased
	return true; //return true if the value was removed as intented
}


#ifdef testingQueue
void generalTestQueue(void) {
	//function to test queue behavior without a specific size
	queue mainQueue;
	int32_t value = 0;
	int8_t functionSucessful = 1;
	uint16_t valueAdded = 0;
	//test empty queue
	//test cases are set to QSIZE = 4

	//Empty Queue, functionSucessful should be 0;
	functionSucessful = mainQueue.dequeue(&value);

	//functionSucessful should be 0

	//filling queue
	for (uint8_t i = 0; i < Q_SIZE; i++) {
		valueAdded = 10 * (i + 1); //adds 10, 20, 30, up to Q_SIZE
		functionSucessful = mainQueue.enqueue(valueAdded);
		//function successful should be 1
	}

	//emptying queue
	for (uint8_t i = 0; i < Q_SIZE; i++) {
		functionSucessful = mainQueue.dequeue(&value); //removes values
		//value should be 10,20,30.....
		//function successful should be 1
	}

	//value should not change
	functionSucessful = mainQueue.dequeue(&value);
	////function successful should be 0, queue is empty

	//Overfilling Queue:
	for (uint8_t i = 0; i < Q_SIZE + 1; i++) {
		valueAdded = 10 * (i + 1); //adds 10,20,30,40
		functionSucessful = mainQueue.enqueue(valueAdded);
		if (functionSucessful != 1 and i == Q_SIZE) {
			break; //queue is full and returns 0 at full
		} //should break / become 0 as it is being overfilled
	}

	//emptying queue
	for (uint8_t i = 0; i < Q_SIZE; i++) {
		functionSucessful = mainQueue.dequeue(&value); //remove all values
		//value should be 10,20,30....
		//fcuntionSuccessful should stay at 1
	}
	return;
}

void specificTestQueue(void) {
	//tests the queue class with a specific size of 4 (Q_SIZE needs to be at least 3 for this to function at intended)
	queue mainQueue;
	int32_t value = 0;
	int8_t functionSucessful = 1;
	uint16_t valueAdded = 11;
	uint16_t toWrite = 11;

	uint8_t valuesToAdd = 3;
	uint8_t valuesToRemove = 2;
	uint8_t valuesToAdd2 = 1;

	// //Adding and removing
	// //example of adding 3 numbers, removing 2, adding 1 more
	for (uint8_t i = 0; i < valuesToAdd; i++) {
		functionSucessful = mainQueue.enqueue(toWrite); //adds 11,22,33 to queue
		toWrite += valueAdded;
	}

	//Partially Emptying Queue by 2
	for (uint8_t i = 0; i < valuesToRemove; i++) {
		functionSucessful = mainQueue.dequeue(&value); // value should be 11,22
	}

	//Adding 1 more value(s)
	for (uint8_t i = 0; i < valuesToAdd2; i++) {
		functionSucessful = mainQueue.enqueue(toWrite); //adds 44
		toWrite += valueAdded;
	}

	//Removing the 2 remaining values
	for (uint8_t i = 0; i < (valuesToAdd - valuesToRemove + valuesToAdd2);
			i++) {
		functionSucessful = mainQueue.dequeue(&value); //removes 33,44
	}
	return;
}
#endif //testingQueue
