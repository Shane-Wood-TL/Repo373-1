
#ifndef SRC_QUEUEDECLARATIONS_H_
#define SRC_QUEUEDECLARATIONS_H_

#include <cstdint>

#define Q_SIZE 4


class queue{
    private:
	uint32_t tail; //last index used to store values
	int32_t queueList[Q_SIZE]; //array that contains the messages

	public:
	queue() {tail = 0;} //basic constructor, sets up tail value

	//adds messages to queue
	bool enqueue(int32_t msg);
	//remove messages from queue (FIFO)
	bool dequeue(int32_t* msg);
};

void generalTestQueue(void);
void specificTestQueue(void);

#endif /* SRC_OUTPUTDRIVERDECLARATIONS_H_ */
