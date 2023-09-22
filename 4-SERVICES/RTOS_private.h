/*******************************************************************/
/*Author : Anas Hamed                                              */
/*Version: V01                                                     */
/*Date   : 8/26/2023 m-d-y                                         */
/*******************************************************************/

#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

#define NULL    (void*)0

typedef struct 
{
    u16 periodicity;
    void (*funcPtr)(void);
    u16 firstDelay;
    u8 state;
}TASK;

static TASK RTOS_tasks[NUMBER_OF_TASKS] = { NULL };

static u8 RTOS_deleted_tasks =1;


void SCHEDULER ()
{
for (u8 i = 0; i < NUMBER_OF_TASKS; i++)
{
    if ((RTOS_tasks[i].funcPtr !=NULL) && (RTOS_tasks[i].state == TASK_READY))
    {
        if (RTOS_tasks[i].firstDelay == 0)
        {

            RTOS_tasks[i].firstDelay = RTOS_tasks[i].periodicity-1;
            RTOS_tasks[i].funcPtr();

        }

        else 
        {
            RTOS_tasks[i].firstDelay --;
        }
        
    }

    else if (RTOS_tasks[i].state == TASK_SUSBENDED)
    {
        
    }

    // else if (RTOS_tasks[i].state == TASK_DELETE)
    // {
        
    //      static edit_tasks = [NUMBER_OF_TASKS - RTOS_deleted_tasks];
    //     for (u8 j = 0; j < NUMBER_OF_TASKS ; j++)
    //     {
    //         if (j == i)
    //         {

    //         continue;

    //         }
            
    //         edit_tasks[j] = RTOS_tasks[j];

        
    //     }

    //     RTOS_deleted_tasks++;
        
    // }

    else
    {
	    /*Do nothing*/
	}
    
    
    
}


}

#endif
