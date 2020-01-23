/* File: TasksCommonMode.h
 * Repo: HuskyRoboticsTemplate
 * Authors: Dylan Tomberlin
 * Description: tasks which are triggered by specific CAN packets
 */

#pragma once

#include <stdint.h>
void initTasksCommonMode();

//Task for completing an emergency stop
typedef struct
{
    uint8_t senderSerial;
    uint8_t senderGroup;
    uint8_t errorCode;

} DataEStop;
uint8_t CB_EStop(void *DataEStopPtr);

//Heartbeat packet task
typedef struct
{
    uint8_t senderSerial;
    uint8_t senderGroup;
    uint8_t leniencyCode;
    uint32_t systemTimeStamp;
} DataHeartBeat;
uint8_t CB_HeartBeat(void *DataHeartBeatPtr);

//Failure report task
typedef struct
{
    uint8_t senderSerial;
    uint8_t senderGroup;
    uint8_t failedPacketID;
} DataFailureReport;
uint8_t CB_FailureReport(void *DataFailureReportPtr);

//Override Protection task
typedef struct
{
} DataOverrideProtection;
uint8_t CB_OverrideProtection(void *DataOverrideProtectionPtr);

//RGB Color task
typedef struct
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t LEDAddress;
} DataRGBColor;
uint8_t CB_RGBColor(void *DataRGBColorPtr);

//Chip type (pull) task
//TODO: fix issues in CAN standard
typedef struct
{

} DataChipType;
uint8_t CB_ChipType(void *DataChipTypePtr);

//Telemetry timing task
typedef struct
{
   uint8_t TTC;//Telemetry type code 
   uint32_t ms;//Milliseconds between each 
} DataTelemetryTiming;
uint8_t CB_TelemetryTiming(void *DataTelemetryTimingPtr);

//Telemetry Pull task
typedef struct
{
    uint8_t senderSerial;
    uint8_t senderGroup;
    uint8_t TTC;//Telemetery Type code
} DataTelemetryPull;
uint8_t CB_TelemetryPull(void *DataTelemetryPullPtr);

//Telemetry Report Task (gets scheduled by timing and pull tasks)
typedef struct
{
    uint32_t ms; //repeat every, 0 for no repeat
    //TODO: what other data do we need here?
} DataTelemetryReport;
uint8_t CB_TelemetryReport(void *DataTelemetryReportPtr);

//Task Priorities
//Todo, should probably be defined in a single file to avoid collisions
#define TASK_PRIO_ESTOP     1
#define TASK_PRIO_xxx       2
