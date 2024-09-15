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


