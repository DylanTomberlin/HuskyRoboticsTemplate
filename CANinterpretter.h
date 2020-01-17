/* File: CANinterpretter.h
 * Repo: HuskyRoboticsTemplate
 * Authors: Dylan Tomberlin
 * Description: Task which takes the info from CAN packets and uses
 *              it to schedule other tasks.
 */
#pragma once

#include "HindsightCAN/CANPacket.h"
#include "SimpleRTOS/Task.h"
#include "PortHuskyRoboticsTemplate.h"

//Task for retrieving CAN packets after interrupt
//This data may be chip dependent because of how CAN packet info is accessed
typedef struct
{
    CAN_RECEIVE_DATA
    CANPacket receivedPacket;
} CANReceiveData;
uint8_t CANReveiveCB(void *CANReveiveDataPtr);

//Task for using packet info to schedule other tasks
typedef struct
{
    CANPacket *receivedPacket;
} CANInterpretData;
uint8_t CANInterpretCB(void *CANInterpretDataPtr);