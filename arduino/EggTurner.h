#pragma once
#include "GravityRtc.h"

class EggTurner{
  const int MotorPinA = 4; // direction motor 1 (Channel A)
  const int speed = 5; // for motor 1 (channel A)
  
  
public:
  EggTurner();
  
  void turnLeft();

  void turnLCentre();

  void turnRight();

  void turnRCentre();

  void turnMotor();
  
  void turnEggs();
  
};
