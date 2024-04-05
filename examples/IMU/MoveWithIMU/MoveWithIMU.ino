#include <EasyKids3in1.h>

/* 
Connect IMU - BNO055

<<<<< Command >>>>>
  EasyKidsIMUsetup(); // IMU Setup
  resetGyro(); // Reset Gyro Direction
  getProcessedGyro(); // Get Gyro Direction (float)

  forwardTimeIMU(Speed, Timer, KP, KD); 
  backwardTimeIMU(Speed, Timer, KP, KD); 
  spinLeftIMU(Speed, Angle); 
  spinRightIMU(Speed, Angle); 
  slideLeftIMU(Speed, Timer, KP, KD); 
  slideRightIMU(Speed, Timer, KP, KD); 
*/

void setup() {
  EasyKids_Setup();
  EasyKidsIMUsetup(); // IMU Setup
}

void loop() {
  forwardTimeIMU(50, 1000, 1.0, 0.1); 
  spinLeftIMU(30, 90); 
  slideRightIMU(50, 1000, 1.0, 0.1); 
  delay(5000);
}

