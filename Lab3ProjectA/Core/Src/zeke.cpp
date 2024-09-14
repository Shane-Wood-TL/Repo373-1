#include "outputDriverDeclarations.h"
#include "main.h"
#include "queueDeclarations.h"
//Counter Class


//Counter Class
        void Counter::update()
        {
            if (queueInstance->dequeue(&value))
            {
            	if(value == -1 and count == 0){
            		count = 0;
            	}else if (value == 1 and count == 9){
            		count = 9;
            	}else{
                count += value;
            	}
            }
        }

        int Counter::get_count()
        {
            return count;
        }



//Output Driver Class
void OutputDriver::display()
    {
        switch(counter.get_count())
        {
            case 0:
            	A->writePin(true);
            	B->writePin(true);
            	C->writePin(true);
            	D->writePin(true);
            	E->writePin(true);
            	F->writePin(true);
            	G->writePin(false);
                break;

            case 1:
            	A->writePin(false);
            	B->writePin(true);
            	C->writePin(true);
            	D->writePin(false);
            	E->writePin(false);
            	F->writePin(false);
            	G->writePin(false);
                break;

            case 2:
            	A->writePin(true);
            	B->writePin(true);
            	C->writePin(false);
            	D->writePin(true);
            	E->writePin(true);
            	F->writePin(false);
            	G->writePin(true);
                break;

            case 3:
            	A->writePin(true);
            	B->writePin(true);
            	C->writePin(true);
            	D->writePin(true);
            	E->writePin(false);
            	F->writePin(false);
            	G->writePin(true);
                break;

            case 4:
            	A->writePin(false);
            	B->writePin(true);
            	C->writePin(true);
            	D->writePin(false);
            	E->writePin(false);
            	F->writePin(true);
            	G->writePin(true);
                break;

            case 5:
            	A->writePin(true);
            	B->writePin(false);
            	C->writePin(true);
            	D->writePin(true);
            	E->writePin(false);
            	F->writePin(true);
            	G->writePin(true);
                break;

            case 6:
            	A->writePin(true);
            	B->writePin(false);
            	C->writePin(true);
            	D->writePin(true);
            	E->writePin(true);
            	F->writePin(true);
            	G->writePin(true);
                break;

            case 7:
            	A->writePin(true);
            	B->writePin(true);
            	C->writePin(true);
            	D->writePin(false);
            	E->writePin(false);
            	F->writePin(false);
            	G->writePin(false);
                break;

            case 8:
            	A->writePin(true);
            	B->writePin(true);
            	C->writePin(true);
            	D->writePin(true);
            	E->writePin(true);
            	F->writePin(true);
            	G->writePin(true);
                break;

            case 9:
            	A->writePin(true);
            	B->writePin(true);
            	C->writePin(true);
            	D->writePin(false);
            	E->writePin(false);
            	F->writePin(true);
            	G->writePin(true);
                break;

            default:
                break;
        }
    }

