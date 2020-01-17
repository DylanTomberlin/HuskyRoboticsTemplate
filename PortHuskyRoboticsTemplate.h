/* File: CANinterpretter.h
 * Repo: HuskyRoboticsTemplate
 * Authors: Dylan Tomberlin
 * Description: Chip Specific implementation details for
 *             Husky Robotics Template library 
 */

#pragma once

#ifdef CHIP_TYPE
 #if CHIP_TYPE==CHIP_TYPE_xxx
  #define CAN_RECEIVE_DATA 
  //Define data to put into CANReceiveData struct for specific chip
 #endif
#endif