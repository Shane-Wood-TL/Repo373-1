/*
 * testCases.cpp
 *
 *  Created on: Sep 15, 2024
 *      Author: townl
 */

#include "inputDriverDeclarations.h"
#include "basicGPIOClass.h"
#include "outputDriverDeclarations.h"
#include "queueDeclarations.h"


//#define testingInput
//#define testingOutput
//#define testingQueue


//to test input this needs to go above the while(1) loop
#ifdef testingInput
	GPIO_Input testPinIn(GPIOA,LL_GPIO_PIN_3,pullup);
		GPIO_Output testPinOut(GPIOA,LL_GPIO_PIN_1);
		testPinOut.writePin(true); //write pin high = no input
		int32_t testInt = 0;
		StateMachine testStateMachine;
		InputDriver testButtonDriver(&mainQueue, &testInt, &testPinIn); //up button driver (with internal state machine
#endif




//to test as labeled; these need to go into the while 1 loop
#ifdef testingOutput
		//function to test display + timer
		test_Display(&segmentA,&segmentB,&segmentC,&segmentD,&segmentE,&segmentF,&segmentG);
#endif

#ifdef testingQueue
		//functions to test queues
		generalTestQueue(void); //test case of queue (empty, filling, overfilling)
		specificTestQueue(void); //test case of queue more realistic to intended operation
#endif

#ifdef testingInput
		//max speed is around 80 kHz with LL and 2 kHz with HAL, used AD2 to test
		//code to test input + falling edge
				bool testPin = false;
				testPinIn.readPin(testPin);


				if (testStateMachine.detectFEdge(testPin)){
					testPinOut.writePin(true);
				}else{
					testPinOut.writePin(false);
				}
#endif


//
////All of these can be called in the while 1 loop
//after copied to main.cpp (above main to ensure they are called)

				//needed to test display
//void test_Display(GPIO_Output *A, GPIO_Output *B,
//		GPIO_Output *C, GPIO_Output *D, GPIO_Output *E, GPIO_Output *F,
//		GPIO_Output *G){
//		queue counterQueueTest;
//
//		OutputDriver outputDriverInstance(&counterQueueTest, A, B,
//					C, D, E, F, G);
//		//count past the limit to show that is stops at 9
//		for(uint8_t i = 0; i <= 12; i++){
//			counterQueueTest.enqueue(1); //add one
//			outputDriverInstance.display(); //display value will increase by 1 every second
//				HAL_Delay(1000); //these delays somehow dont cause a watchdog violation
//		}
//
//		//trys to count lower than 0, does not
//		for(uint8_t i = 0; i <= 12; i++){
//					counterQueueTest.enqueue(-1); //decrease by 1
//						outputDriverInstance.display();//display value will decrease by 1 every second
//						HAL_Delay(1000);
//				}
//}
//
//
//

				//needed to test queue
//void generalTestQueue(void) {
//	//function to test queue behavior without a specific size
//	queue mainQueue;
//	int32_t value = 0;
//	int8_t functionSucessful = 1;
//	uint16_t valueAdded = 0;
//	//test empty queue
//	//test cases known results are set to QSIZE = 4
//
//	//Empty Queue, functionSucessful should be 0, it is
//	//breakpoints can be used on every line with functionSucessful to determine
//	//if it is working as intended;
//	functionSucessful = mainQueue.dequeue(&value);
//
//	//functionSucessful should be 0, which it is (breakpoint)
//
//	//filling queue
//	for (uint8_t i = 0; i < Q_SIZE; i++) {
//		valueAdded = 10 * (i + 1); //adds 10, 20, 30, up to Q_SIZE
//		functionSucessful = mainQueue.enqueue(valueAdded);
//		//function successful should be 1, which they are if a breakpoint is used here
//	}
//
//	//emptying queue
//	for (uint8_t i = 0; i < Q_SIZE; i++) {
//		functionSucessful = mainQueue.dequeue(&value); //removes values
//		//value should be 10,20,30.....
//		//function successful should be 1, which they are if a breakpoint is used here
//	}
//
//	//value should not change
//	functionSucessful = mainQueue.dequeue(&value);
//	////function successful should be 0, queue is empty,
//
//	//Overfilling Queue:
//	for (uint8_t i = 0; i < Q_SIZE + 1; i++) {
//		valueAdded = 10 * (i + 1); //adds 10,20,30,40
//		functionSucessful = mainQueue.enqueue(valueAdded);
//		if (functionSucessful != 1 and i == Q_SIZE) {
//			break; //queue is full and returns 0 at full
//		} //should break / become 0 as it is being overfilled, which is does once the tail is at Q_size
//	}
//
//	//emptying queue
//	for (uint8_t i = 0; i < Q_SIZE; i++) {
//		functionSucessful = mainQueue.dequeue(&value); //remove all values
//		//value should be 10,20,30.... (breakpoint agress)
//		//fcuntionSuccessful should stay at 1 (which it also does)
//	}
//	return;
//}
//
				//needed to test queue
//void specificTestQueue(void) {
//	//tests the queue class with a specific size of 4 (Q_SIZE needs to be at least 3 for this to function at intended)
//	queue mainQueue;
//	int32_t value = 0;
//	int8_t functionSucessful = 1;
//	uint16_t valueAdded = 11;
//	uint16_t toWrite = 11;
//
//	uint8_t valuesToAdd = 3;
//	uint8_t valuesToRemove = 2;
//	uint8_t valuesToAdd2 = 1;
//
//	// //Adding and removing
//	// //example of adding 3 numbers, removing 2, adding 1 more
//	for (uint8_t i = 0; i < valuesToAdd; i++) {
//		functionSucessful = mainQueue.enqueue(toWrite); //adds 11,22,33 to queue, functionsucessful stays at 1
//		toWrite += valueAdded; //ensures unique values are added
//	}
//
//	//Partially Emptying Queue by 2
//	for (uint8_t i = 0; i < valuesToRemove; i++) {
//		functionSucessful = mainQueue.dequeue(&value); // value should be 11,22; breakpoint matches
//	}
//
//	//Adding 1 more value(s)
//	for (uint8_t i = 0; i < valuesToAdd2; i++) {
//		functionSucessful = mainQueue.enqueue(toWrite); //adds 44 to the tail, sucess (breakpoint)
//		toWrite += valueAdded; //not used here, but more values could be added rather than just 1
//	}
//
//	//Removing the 2 remaining values
//	for (uint8_t i = 0; i < (valuesToAdd - valuesToRemove + valuesToAdd2); //removes the last 2 values based on # of added ones
//			i++) {
//		functionSucessful = mainQueue.dequeue(&value); //removes 33,44, function Successful stays at 1, all works as intended
//	}
//	functionSucessful =- functionSucessful; //does nothing, gets rid of warning saying that variable is not used (do not matter as this is a test)
//	return;
//}


