#include <EasyKids3in1.h>

void setup() {
  EasyKids_Setup();
  EasyKidsIMUsetup(); // IMU Setup
}

void loop() {
  // resetGyro(); // Reset Gyro Direction
  Serial.println(getProcessedGyro()); // Get Gyro Direction
  delay(100);
}
