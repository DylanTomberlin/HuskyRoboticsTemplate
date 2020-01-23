/* File: TasksCommonMode.c
 * Repo: HuskyRoboticsTemplate
 * Authors: Dylan Tomberlin
 * Description: tasks which are triggered by specific CAN packets
 */

#include "TasksCommonMode.h"
#include "SimpleRTOS/Task.h"
#include "stddef.h"

DataEStop DataEStopPtr;
Task TaskEStop;

void initTasksCommonMode()
{
    TaskEStop.callBackPtr=CB_EStop;
    TaskEStop.queueNext = NULL;
    TaskEStop.priority = 1;
    TaskEStop.scheduledTime = 0;
    //TODO: do we need to do something different in order to void* cast
    TaskEStop.dataPtr = (void*) DataEStopPtr;
}