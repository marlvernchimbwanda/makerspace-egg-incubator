#include "EggTurner.h"
#include "Arduino.h"
extern GravityRtc gravityRtc;

EggTurner::EggTurner(){
  
  
  pinMode(MotorPinA, OUTPUT);
  pinMode(speed, OUTPUT);
}


void EggTurner::turnLeft(){
  digitalWrite(MotorPinA, LOW);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
}

void EggTurner::turnLCentre(){
  digitalWrite(MotorPinA, HIGH);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
  
}

void EggTurner::turnRight(){
  digitalWrite(MotorPinA, HIGH);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
}

void EggTurner::turnRCentre(){
  digitalWrite(MotorPinA, LOW);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
  
}

void EggTurner::turnMotor() {
  turnLeft();
  //delay(500);
  turnLCentre();
  delay(1200);
  turnRight();
  //delay(500);
  turnRCentre();
  
}

void EggTurner::turnEggs(){
  gravityRtc.read();
  if(gravityRtc.minute==02){
    if(gravityRtc.second>=15 && gravityRtc.second<=45){
      turnMotor();
    }  
  }
}
