/* File: main.c
 * Authors: Dylan Tomberlin
 * Description:
 */

#include "SimpleRTOS/Scheduler.h"
#include "SimpleRTOS/Port.h"
#include "implement.h"

void main(void)
{
    //Init
    setUpHardwareTimer(1000); //Tick once per ms
    scheduleInitialTask();       
    //Loop
    while(1)
    {
        schedulerRun();
        sleepUntilInterrupt();
    }
}