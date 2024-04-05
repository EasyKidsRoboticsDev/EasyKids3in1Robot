#include "EasyKids_Battery.h"
#include "EasyKids_Buzzer.h"
#include "EasyKids_IO.h"
#include "EasyKids_LCD.h"
#include "EasyKids_Motor.h"
#include "EasyKids_NeoPixel.h"
#include "EasyKids_Sonar.h"
#include "EasyKids_Switch.h"
#include "EasyKids_VR.h"
#include "EasyKids_Gamepad.h"
#include "EasyKids_IMU.h"
#include "EasyKids_PID.h"


void EasyKids_Setup(){
    Serial.begin(115200);
    display.begin();
    displayClear();
    rgb.begin();
    rgbCar.begin();
    ledSetBrightness(20);
    ledCarSetBrightness(20);
    ledFillColor(BLACK);
    ledCarFillColor(BLACK);
    pinMode(sw, INPUT);
    pinMode(BUZZER, OUTPUT);
    motorSetup();
}
