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
class Counter
{
	private:
        uint8_t count;
        int32_t value;
        queue *queueInstance;

    public:
        Counter(queue *queueInstance)
        {
        	this->queueInstance = queueInstance;
            count = 0;
        }

        void update();
        int get_count();
};


//Output Driver Class
class OutputDriver
{

	private:
    	GPIO_Output *A;
    	GPIO_Output *B;
    	GPIO_Output *C;
    	GPIO_Output *D;
    	GPIO_Output *E;
    	GPIO_Output *F;
    	GPIO_Output *G;

    	Counter counter;

    public:
	OutputDriver(queue *mainQueue, GPIO_Output *A,GPIO_Output *B,GPIO_Output *C,GPIO_Output *D,GPIO_Output *E,GPIO_Output *F,GPIO_Output *G)
	        :counter(mainQueue){
	            this->A = A;
	            this->B = B;
	            this->C = C;
	            this->D = D;
	            this->E = E;
	            this->F = F;
	            this->G = G;
	        }

        void display();

};

#endif /* SRC_OUTPUTDRIVERDECLARATIONS_H_ */
