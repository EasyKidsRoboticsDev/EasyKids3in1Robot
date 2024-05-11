#include <EasyKids3in1.h>

void setup() {
  EasyKids_Setup();
  IMUsetup(); // IMU Setup
}

void loop() {
  // resetGyro(); // Reset Gyro Direction
  Serial.println(getAngle()); // Get Gyro Direction
  delay(100);
}
