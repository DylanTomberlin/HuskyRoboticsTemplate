
/* File: CANinterpretter.c
 * Repo: HuskyRoboticsTemplate
 * Authors: Dylan Tomberlin
 * Description: Task which takes the info from CAN packets and uses
 *              it to schedule other tasks.
 */

#include "CANinterpretter.h"
#include "CANCommon.h"

uint8_t CANInterpretCB(void *CANInterpretDataPtr)
{
    CANPacket *receivedPacket = &((CANInterpretData*) CANInterpretDataPtr)->receivedPacket;
    //TODO: NULL check, but what behavior do we do? Just return?
    
    //TODO: Not sure if we really need these, maybe a good sanity check for hardware filters
    //      to make sure we're not interpretting messages for other device types?
    uint8_t packetPriority              = GetPacketPriority(receivedPacket);
    uint8_t packetDeviceGroup           = GetDeviceGroupCode(receivedPacket);
    uint8_t packetDeviceSerialNumber    = GetDeviceSerialNumber(receivedPacket);

    uint8_t packetID = GetPacketID(receivedPacket);

    //Common mode packets are 0x30... 0x3f, TODO make consts
    if(packetID >= 0x30)
    {
        switch (packetID)
        {
        case ID_ESTOP:
            /* code */
            //Schedule EStop Task, highest priority
            break;
        case ID_HEARTBEAT:
            //schedule heartbeat
            break;
        case ID_FAIL_REPORT:
            //schedule fail report
            break;
        case ID_OVRD_PROTECTION:
            //schedule override protection
            break;
            //TODO, chip type should be a telemetry point
        case ID_CHIP_TYPE_PULL:
            //schedule chip type pull task 
            //(will be chip type report) 
            break;
        case ID_CHIP_TYPE_REP:
            //schedule 
            break;
        case ID_TELEMETRY_TIMING:
            //schedule telemetery timing task
            break;
        case ID_TELEMETRY_REPORT:
            //schedule telemetry report task
            break;
        case ID_LED_COLOR:
            //schedule set LED color task
            break;
        default:
            break;
        }
    } else
    {
        void interpretBoardCANPacket(CANPacket *receivedPacket);
    }
    //Clear all exsisting data in data struct
    receivedPacket->id = 0;
    *((uint64_t*)(receivedPacket->data)) = 0; //Set entire data array to zero
    receivedPacket->dlc = 0;
    return 0;
}