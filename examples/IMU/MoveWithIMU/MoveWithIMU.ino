#include <EasyKids3in1.h>

/* 
Connect IMU - BNO055

<<<<< Command >>>>>
  IMUsetup(); // IMU Setup
  resetAngle(); // Reset Gyro Direction
  getAngle(); // Get Gyro Direction (float)

  forwardIMU(Speed, KP, KD); 
  backwardIMU(Speed, KP, KD); 
  slideLeftIMU(Speed, KP, KD); 
  slideRightIMU(Speed, KP, KD); 

  spinLeftIMU(Speed, Angle); 
  spinRightIMU(Speed, Angle); 

  forwardTimerIMU(Speed, KP, KD, Timer); 
  backwardTimerIMU(Speed, KP, KD, Timer); 
  slideLeftTimerIMU(Speed, KP, KD, Timer); 
  slideRightTimerIMU(Speed, KP, KD, Timer); 
*/

void setup() {
  EasyKids_Setup();
  IMUsetup(); // IMU Setup
}

void loop() {
  forwardTimerIMU(50, 1.0, 0.1, 1000); 
  spinLeftIMU(30, 90); 
  slideRightTimerIMU(50, 1.0, 0.1, 1000); 
  delay(5000);
}

