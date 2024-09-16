///*
// * outputDriverDeclarations.h
// *
// *  Created on: Sep 10, 2024
// *      Author: townl
// */
//
//
#ifndef SRC_OUTPUTDRIVERDECLARATIONS_H_
#define SRC_OUTPUTDRIVERDECLARATIONS_H_
#include "main.h"
#include "queueDeclarations.h"
#include "inputDriverDeclarations.h"
#include "basicGPIOClass.h"

//Counter Class
class Counter {
private:
	uint8_t count; //current value of counter
	queue *queueInstance;

public:
	Counter(queue *mainQueueI);
	void update(); //get value from queue, change count
	uint8_t get_count(); //return where the counter is at now
};

//Output Driver Class
class OutputDriver {

private:
	Counter counter; //counter that exists only within this driver instance

	//pointers to the segments
	GPIO_Output *A;
	GPIO_Output *B;
	GPIO_Output *C;
	GPIO_Output *D;
	GPIO_Output *E;
	GPIO_Output *F;
	GPIO_Output *G;

public:
	OutputDriver(queue *mainQueueI, GPIO_Output *AI, GPIO_Output *BI,
			GPIO_Output *CI, GPIO_Output *DI, GPIO_Output *EI, GPIO_Output *FI,
			GPIO_Output *GI);
	void display(); //update the 7 segment display

};
#ifdef testingOutput
void test_Display(GPIO_Output *A, GPIO_Output *B,
		GPIO_Output *C, GPIO_Output *D, GPIO_Output *E, GPIO_Output *F,
		GPIO_Output *G);
#endif

#endif /* SRC_OUTPUTDRIVERDECLARATIONS_H_ */
