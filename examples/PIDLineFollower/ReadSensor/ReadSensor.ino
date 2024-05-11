#include <EasyKids3in1.h>

void setup() {
  EasyKids_Setup();
  sensorNum(7); // Sensor amount (4 - 7)
  blackLine(); // Black Line
  // whiteLine(); // White Line
}

void loop() {
  readSensor(); // Show Value Sensor via LCD Display
}
