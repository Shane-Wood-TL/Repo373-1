///*
// * SRCQUEUEDECLARATIONS_H_.h
// *
// *  Created on: Sep 10, 2024
// *      Author: townl
// */
//
//

#ifndef SRC_QUEUEDECLARATIONS_H_
#define SRC_QUEUEDECLARATIONS_H_

#include <cstdint>

#define Q_SIZE 4

//enables / disables queue testing functoins
//#define testingQueue (will add 1 warning for a unused variable; this variable can be used in the debugger to ensure all tests pass

class queue {
private:
	uint32_t tail; //index that is free to store new value
	int32_t queueList[Q_SIZE]; //array that contains the messages, size is determined by a define

public:
	queue();

	bool enqueue(int32_t msg); //adds messages to queue

	bool dequeue(int32_t *msg); //remove messages from queue (FIFO)
};

#ifdef testingQueue
void generalTestQueue(void); //test case of queue (empty, filling, overfilling)
void specificTestQueue(void); //test case of queue more realistic to intended operation
#endif //testingQueue

#endif /* SRC_OUTPUTDRIVERDECLARATIONS_H_ */
