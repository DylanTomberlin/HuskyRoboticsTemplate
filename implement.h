/* File: implement.h
 * Repo: HuskyRoboticsTemplate
 * Authors: Dylan Tomberlin
 * Description: Functions that should be implemented on a
 * per board/ per application basis
 */
#pragma once

#include "HindsightCAN/CANPacket.h"

void scheduleInitialTasks();

//Used to schedule board specific tasks
void interpretBoardCANPacket(CANPacket *receivedPacket);
