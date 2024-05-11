#include <EasyKids3in1.h>

/* 
Connect Analog 7 Sensor >>> A6 A5 A4 A3 A2 A1 A0 
Connect Motor Left  >>> M1
Connect Motot Right >>> M2

<<<<< Command >>>>>
  readSensor();

  // Select line type
  blackLine();
  whiteLine();

  // sensorNum(amount) --> 4-7 sensors
  // Exception: 2-3 sensors is possible but only the 
  // lineFollow and lineFollowTimer function works.

  // Example: 5 Sensors
  sensorNum(4);
  setSensorMin(s0, s1, s2, s3);
  setSensorMax(s0, s1, s2, s3);

  // Example: 6 Sensors
  SensorNum(6);
  setSensorMin(s0, s1, s2, s3, s4, s5);
  setSensorMax(s0, s1, s2, s3, s4, s5);

  lineFollow(Speed, KP, KD);
  lineFollowTimer(Speed, KP, KD, Time(ms)); 
  lineFollowCross(Speed, KP, KD); 
  lineFollowFork(Speed, KP, KD); 
  lineFollow90Left(Speed, KP, KD); 
  lineFollow90Right(Speed, KP, KD); 
  lineFollowTurnLeft(Speed); 
  lineFollowTurnRight(Speed); 
*/

void setup() {
  EasyKids_Setup();

  sensorNum(7); // For 7 Sensors
  blackLine(); // Black Line

  setSensorMin(975, 900, 385, 1229, 912, 723, 688);  // Black Line Value >>> A0 A1 A2 A3 A4 A5 A6
  setSensorMax(4023, 3875, 2380, 4065, 4023, 3460, 3226);  // White Line Value >>> A0 A1 A2 A3 A4 A5 A6

  
}

void loop() {

  // readSensor();  //Show Value 7 Sensor via LCD Display

  waitForStart(); 
  beep(); 

  lineFollowTimer(20, 1.0, 1.0, 1000); //lineFollowTime (Speed, KP, KD, Time(ms));
  lineFollowCross(30, 1.0, 1.0); //lineFollowCross(Speed, KP, KD);
  lineFollowTimer(35, 1.0, 1.0, 5000); //lineFollowTime (Speed, KP, KD, Time(ms));
  lineFollowTurnLeft(30);// lineTurnLeft(Speed);
 
}

