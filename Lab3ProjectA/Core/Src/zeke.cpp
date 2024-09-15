#include "outputDriverDeclarations.h"

//Counter Class
Counter::Counter(queue *mainQueueI) :
		queueInstance(mainQueueI) {
	count = 0;
}

void Counter::update() {
	int32_t value = 0; //value from queue
	if (queueInstance->dequeue(&value)) { //if there is a value in the queue

		//checking for count going out of range
		if (value == -1 and count <= 0) { //decreasing when at 0
			count = 0; //hard wall at 0
		} else if (value == 1 and count >= 9) { //increasing when at 9
			count = 9; //hard wall at 9
		} else {
			count += value; //change count as expected
		}
	}
	return;
}

uint8_t Counter::get_count() {
	return count; //return the current count value
}

//Output Driver Class

OutputDriver::OutputDriver(queue *mainQueueI, GPIO_Output *AI, GPIO_Output *BI,
		GPIO_Output *CI, GPIO_Output *DI, GPIO_Output *EI, GPIO_Output *FI,
		GPIO_Output *GI) :
		counter(mainQueueI), A(AI), B(BI), C(CI), D(DI), E(EI), F(FI), G(GI) {
}

void OutputDriver::display() {
	//get the current count value
	counter.update();
	switch (counter.get_count()) {
	case 0: //write 0 to the the display
		A->writePin(true);
		B->writePin(true);
		C->writePin(true);
		D->writePin(true);
		E->writePin(true);
		F->writePin(true);
		G->writePin(false);
		break;

	case 1: //write 1 to the the display
		A->writePin(false);
		B->writePin(true);
		C->writePin(true);
		D->writePin(false);
		E->writePin(false);
		F->writePin(false);
		G->writePin(false);
		break;

	case 2: //write 2 to the the display
		A->writePin(true);
		B->writePin(true);
		C->writePin(false);
		D->writePin(true);
		E->writePin(true);
		F->writePin(false);
		G->writePin(true);
		break;

	case 3: //write 3 to the the display
		A->writePin(true);
		B->writePin(true);
		C->writePin(true);
		D->writePin(true);
		E->writePin(false);
		F->writePin(false);
		G->writePin(true);
		break;

	case 4: //write 4 to the the display
		A->writePin(false);
		B->writePin(true);
		C->writePin(true);
		D->writePin(false);
		E->writePin(false);
		F->writePin(true);
		G->writePin(true);
		break;

	case 5: //write 5 to the the display
		A->writePin(true);
		B->writePin(false);
		C->writePin(true);
		D->writePin(true);
		E->writePin(false);
		F->writePin(true);
		G->writePin(true);
		break;

	case 6: //write 6 to the the display
		A->writePin(true);
		B->writePin(false);
		C->writePin(true);
		D->writePin(true);
		E->writePin(true);
		F->writePin(true);
		G->writePin(true);
		break;

	case 7: //write 7 to the the display
		A->writePin(true);
		B->writePin(true);
		C->writePin(true);
		D->writePin(false);
		E->writePin(false);
		F->writePin(false);
		G->writePin(false);
		break;

	case 8: //write 8 to the the display
		A->writePin(true);
		B->writePin(true);
		C->writePin(true);
		D->writePin(true);
		E->writePin(true);
		F->writePin(true);
		G->writePin(true);
		break;

	case 9: //write 9 to the the display
		A->writePin(true);
		B->writePin(true);
		C->writePin(true);
		D->writePin(false);
		E->writePin(false);
		F->writePin(true);
		G->writePin(true);
		break;
	default:
		//something has went very wrong if it gets here
		NVIC_SystemReset(); //reset the uC
		break;
	}
	return;
}






//Original zeke's code


/*
 *
 * Attempt 3
 *
 *
 * class Counter
{
    public:
        Counter()
        {
            count = 0;
        }

        void update()
        {
            uint32_t value;
            if (queue.dequeue(&value))
            {
                count += value;
            }
        }

        int get_count()
        {
            return count;
        }

    private:
        int count;
        Queue queue;
};


//Output Driver Class
class OutputDriver
{
    public:
        OutputDriver(Counter& c) : counter(c) {}

        void GPIO_Output(GPIO_TypeDef port, uint8_t pin)
        {
            this -> port = port;
            this -> pin = pin;
        }

        void writePin(bool setHigh)
        {
            if(setHigh == true)
            {
                port -> ODR |= (1 << pin);
            }
            else
            {
                port -> ODR &= (0 << pin);
            }
        }

        void displayCount()
        {
            counter.update();
            uint32_t value = counter.get_count();
        }

    private:
        GPIO_TypeDefport;
        uint8_t pin;
        Counter& counter;
};

//Counter Class
class Counter
{
    public:
        Counter()
        {
            count = 0;
        }

        void update(int value)
        {
            count += value;
        }

        int get_count()
        {
            return count;
        }

    private:
        int count;
};


//Attempt 2
 *
 *
 *
//Output Driver Class
class OutputDriver
{
    public:
        OutputDriver() {}

        void GPIO_Output(GPIO_TypeDef port, uint8_t pin)
        {
            this -> port = port;
            this -> pin = pin;
        }

        void writePin(bool setHigh)
        {
            if(setHigh == true)
            {
                port -> ODR |= (1 << pin);
            }
            else
            {
                port -> ODR &= (0 << pin);
            }
        }

    private:
        GPIO_TypeDefport;
        uint8_t pin;
};



//attempt 1
 * #include <iostream>
using namespace std;


//Counter Class
class Counter
{
    public:
        Counter()
        {
            count = 0;
        }

        void update(int value)
        {
            count += value;
        }

        int get_count()
        {
            return count;
        }

    private:
        int count;
};


//Output Driver Class
class OutputDriver
{
    public:
        OutputDriver() {}

    void display(int count)
    {
        switch(count)
        {
            case 0:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_1);
                setPin(GPIOA, GPIO_PIN_8);
                setPin(GPIOA, GPIO_PIN_11);
                setPin(GPIOB, GPIO_PIN_5);
                break;

            case 1:
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_1);
                break;

            case 2:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_4);
                setPin(GPIOA, GPIO_PIN_11);
                setPin(GPIOA, GPIO_PIN_8);
                break;

            case 3:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_4);
                setPin(GPIOB, GPIO_PIN_1);
                setPin(GPIOA, GPIO_PIN_8);
                break;

            case 4:
                setPin(GPIOB, GPIO_PIN_5);
                setPin(GPIOB, GPIO_PIN_4);
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_1);
                break;

            case 5:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_5);
                setPin(GPIOB, GPIO_PIN_4);
                setPin(GPIOB, GPIO_PIN_1);
                setPin(GPIOA, GPIO_PIN_8);
                break;

            case 6:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_1);
                setPin(GPIOA, GPIO_PIN_8);
                setPin(GPIOA, GPIO_PIN_11);
                setPin(GPIOB, GPIO_PIN_5);
                setPin(GPIOB, GPIO_PIN_4);
                break;

            case 7:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_1);
                break;

            case 8:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_1);
                setPin(GPIOB, GPIO_PIN_5);
                setPin(GPIOA, GPIO_PIN_8);
                setPin(GPIOA, GPIO_PIN_11);
                setPin(GPIOB, GPIO_PIN_4);
                break;

            case 9:
                setPin(GPIOB, GPIO_PIN_7);
                setPin(GPIOB, GPIO_PIN_6);
                setPin(GPIOB, GPIO_PIN_1);
                setPin(GPIOB, GPIO_PIN_4);
                setPin(GPIOB, GPIO_PIN_5);
                break;
        }
    }

    private:
        void setPin(GPIO typedef* GPIO, GPIO_Pin)
        {
            switch(pin)
            {
                // Inputs
                case 1:  // A5 = PA6
                    GPIO = GPIOA;
                    GPIO_Pin = GPIO_PIN_6;
                    break;

                case 2:  // A4 = PA5
                    GPIO = GPIOA;
                    GPIO_Pin = GPIO_PIN_5;
                    break;

                // Outputs
                case 3:  // D4 = PB7 -> Segment A
                    GPIO = GPIOB;
                    GPIO_Pin = GPIO_PIN_7;
                    break;

                case 4:  // D5 = PB6 -> Segment B
                    GPIO = GPIOB;
                    GPIO_Pin = GPIO_PIN_6;
                    break;

                case 5:  // D6 = PB1 -> Segment C
                    GPIO = GPIOB;
                    GPIO_Pin = GPIO_PIN_1;
                    break;

                case 6:  // D9 = PA8 -> Segment D
                    GPIO = GPIOA;
                    GPIO_Pin = GPIO_PIN_8;
                    break;

                case 7:  // D10 = PA11 -> Segment E
                    GPIO = GPIOA;
                    GPIO_Pin = GPIO_PIN_11;
                    break;

                case 8:  // D11 = PB5 -> Segment F
                    GPIO = GPIOB;
                    GPIO_Pin = GPIO_PIN_5;
                    break;

                case 9:  // D12 = PB4 -> Segment G
                    GPIO = GPIOB;
                    GPIO_Pin = GPIO_PIN_4;
                    break;

                default:
                    return;
            }

            // Set the GPIO pin to HIGH or LOW
            HAL_GPIO_TogglePin(GPIO, GPIO_Pin);
        }
};
*/

