#include <EasyKids3in1.h>

void setup() {
  EasyKids_Setup();
  display3in1();
  welcomeSong();
  beep();
  JoyController_Setup();
}

void loop() {
  JoyController();
  Serial.println(joyButton);
  if (joyLX > 95) {  //AnalogLeft Move Right Value Max 100
    
  } else if (joyLX < -95) {  //AnalogLeft Move Left Value min -100

  } else if (joyRX > 95) {   //AnalogRight Move Right Value 100

  } else if (joyRX < -95) {  //AnalogRight Move Left Value -100

  } else if (joyRY > 95) {   //AnalogRight Move UP Value 100

  } else if (joyRY < -95) {  //AnalogRight Move Down Value -100

  } else if (joyLY > 95) {   //AnalogLeft Move UP Value 100

  } else if (joyLY < -95) {  //AnalogLeft Move Down Value -100

  } else if (joyCross == 1) {     //Cross Button Press = 1, Release = 0
    
  } else if (joyCircle == 1) {    //Square Button Press = 1, Release = 0
    
  } else if (joySquare == 1) {    //Circle Button Press = 1, Release = 0
    
  } else if (joyTriangle == 1) {  //Triangle Button Press = 1, Release = 0
    
  } else if (joyL1 == 1) {  //L1 Button Press = 1, Release = 0
    
  } else if (joyR1 == 1) {  //L2 Button Press = 1, Release = 0
    
  } else if (joyL2 == 1) {  //R1 Button Press = 1, Release = 0
    
  } else if (joyR2 == 1) {  //R2 Button Press = 1, Release = 0
    
  } else if (joyUp == 1) {     //PAD UP Press = 1, Release = 0
    
  } else if (joyDown == 1) {   //PAD DOWN Press = 1, Release = 0
    
  } else if (joyRight == 1) {  //PAD RIGHT Press = 1, Release = 0
    
  } else if (joyLeft == 1) {   //PAD LEFT Press = 1, Release = 0
    
  } else {  // All Release
    
  }
}
