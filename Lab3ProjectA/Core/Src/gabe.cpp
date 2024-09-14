#include "main.h"
#include "queueDeclarations.h"
#include "BasicGPIOClass.h"
#include "inputDriverDeclarations.h"


    //Update the state with the current pin value
bool StateMachine::detectFEdge(bool state)
{
        cState = state;
        bool FEdgeDetected;
        if(pState == true and cState == false){
        	FEdgeDetected = true;
        }else{
        	FEdgeDetected = false;
        }
        pState = cState;
        return FEdgeDetected;
}


//check for falling edges and enqueue value
void InputDriver::checkAndEnqueue()
    {
        input->readPin(data);
        if (stateMachine.detectFEdge(data))
        {
            queueInstance->enqueue(*valToEnq);
        }
    }

