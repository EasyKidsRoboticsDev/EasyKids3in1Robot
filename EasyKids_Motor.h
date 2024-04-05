#include "Adafruit_PWMServoDriverE.h"
#include "Wire.h"

Adafruit_PWMServoDriver pwmMotor = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwmServo = Adafruit_PWMServoDriver(0x41);
bool sharedAddress = true;

void motorSetup()
{
  Wire.begin();
  delay(500);
  Wire.beginTransmission(0x41);
  int error = Wire.endTransmission();
  if (error == 0) { sharedAddress = false; }

  pwmMotor.begin();
  if(sharedAddress)
  {
    pwmMotor.setPWMFreq(50);
    pwmMotor.setPWM(0, 0, 0);
    pwmMotor.setPWM(1, 0, 0);
    pwmMotor.setPWM(2, 0, 0);
    pwmMotor.setPWM(3, 0, 0);
    pwmMotor.setPWM(4, 0, 0);
    pwmMotor.setPWM(5, 0, 0);
    pwmMotor.setPWM(6, 0, 0);
    pwmMotor.setPWM(7, 0, 0);
  }
  else
  {
    pwmServo.begin();
    pwmMotor.setPWMFreq(1000);
    pwmServo.setPWMFreq(50);
    pwmMotor.setPWM(0, 0, 0);
    pwmMotor.setPWM(1, 0, 0);
    pwmMotor.setPWM(2, 0, 0);
    pwmMotor.setPWM(3, 0, 0);
    pwmMotor.setPWM(4, 0, 0);
    pwmMotor.setPWM(5, 0, 0);
    pwmMotor.setPWM(6, 0, 0);
    pwmMotor.setPWM(7, 0, 0);
  }
}

// ------ Function Motor ------
void motor(int num, int speedM)
{
   int mapSpeed;
    if (num == 1 && speedM > 0)
    {
      mapSpeed = map(speedM, 0, 100, 0, 4095);
      pwmMotor.setPWM(0, mapSpeed, 0);
      pwmMotor.setPWM(1, 0, 4095);
    }
    else if (num == 1 && speedM < 0)
    {
      mapSpeed = map(speedM, 0, -100, 0, 4095);
      pwmMotor.setPWM(0, 0, 4095);
      pwmMotor.setPWM(1, mapSpeed, 0);
    }
    else if (num == 1 && speedM == 0)
    {
      pwmMotor.setPWM(0, 0, 4095);
      pwmMotor.setPWM(1, 0, 4095);
    }
    else if (num == 2 && speedM > 0)
    {
      mapSpeed = map(speedM, 0, 100, 0, 4095);
      pwmMotor.setPWM(2, mapSpeed, 0);
      pwmMotor.setPWM(3, 0, 4095);
    }
    else if (num == 2 && speedM < 0)
    {
      mapSpeed = map(speedM, 0, -100, 0, 4095);
      pwmMotor.setPWM(2, 0, 4095);
      pwmMotor.setPWM(3, mapSpeed, 0);
    }
    else if (num == 2 && speedM == 0)
    {
      pwmMotor.setPWM(2, 0, 4095);
      pwmMotor.setPWM(3, 0, 4095);
    }
    else if (num == 3 && speedM > 0)
    {
      mapSpeed = map(speedM, 0, 100, 0, 4095);
      pwmMotor.setPWM(4, mapSpeed, 0);
      pwmMotor.setPWM(5, 0, 4095);
    }
    else if (num == 3 && speedM < 0)
    {
      mapSpeed = map(speedM, 0, -100, 0, 4095);
      pwmMotor.setPWM(4, 0, 4095);
      pwmMotor.setPWM(5, mapSpeed, 0);
    }
    else if (num == 3 && speedM == 0)
    {
      pwmMotor.setPWM(4, 0, 4095);
      pwmMotor.setPWM(5, 0, 4095);
    }
    else if (num == 4 && speedM > 0)
    {
      mapSpeed = map(speedM, 0, 100, 0, 4095);
      pwmMotor.setPWM(6, mapSpeed, 0);
      pwmMotor.setPWM(7, 0, 4095);
    }
    else if (num == 4 && speedM < 0)
    {
      mapSpeed = map(speedM, 0, -100, 0, 4095);
      pwmMotor.setPWM(6, 0, 4095);
      pwmMotor.setPWM(7, mapSpeed, 0);
    }
    else if (num == 4 && speedM == 0)
    {
      pwmMotor.setPWM(6, 0, 4095);
      pwmMotor.setPWM(7, 0, 4095);
    }
}

void forward(int speedM){
  motor(1,speedM);
  motor(2,speedM);
  motor(3,speedM);
  motor(4,speedM);
}

void backward(int speedM){
  motor(1,-speedM);
  motor(2,-speedM);
  motor(3,-speedM);
  motor(4,-speedM);
}

void turnLeft(int speedM){
  motor(1,0);
  motor(2,0);
  motor(3,speedM);
  motor(4,speedM);
}

void turnRight(int speedM){
  motor(1,speedM);
  motor(2,speedM);
  motor(3,0);
  motor(4,0);
}

void spinLeft(int speedM){
  motor(1,-speedM);
  motor(2,-speedM);
  motor(3,speedM);
  motor(4,speedM);
}

void spinRight(int speedM){
  motor(1,speedM);
  motor(2,speedM);
  motor(3,-speedM);
  motor(4,-speedM);
}

void slideRight(int speedM){
  motor(1,speedM);
  motor(2,-speedM);
  motor(3,-speedM);
  motor(4,speedM);
}

void slideLeft(int speedM){
  motor(1,-speedM);
  motor(2,speedM);
  motor(3,speedM);
  motor(4,-speedM);
}

// ------ Function MotorStopAll ------
void motorStopAll()
{
  pwmMotor.setPWM(0, 0, 4095);
  pwmMotor.setPWM(1, 0, 4095);
  pwmMotor.setPWM(2, 0, 4095);
  pwmMotor.setPWM(3, 0, 4095);
  pwmMotor.setPWM(4, 0, 4095);
  pwmMotor.setPWM(5, 0, 4095);
  pwmMotor.setPWM(6, 0, 4095);
  pwmMotor.setPWM(7, 0, 4095);
}

// ------ Function Servo ------
void servo(int pin, uint16_t degree)
{
  uint16_t mapServo = map(degree, 0, 180, 102, 512);
  if(sharedAddress)
  {
    if (pin == 1)
    {
      pwmMotor.setPWM(8, 0, mapServo);
    }
    else if (pin == 2)
    {
      pwmMotor.setPWM(9, 0, mapServo);
    }
    else if (pin == 3)
    {
      pwmMotor.setPWM(10, 0, mapServo);
    }
    else if (pin == 4)
    {
      pwmMotor.setPWM(11, 0, mapServo);
    }
    else if (pin == 5)
    {
      pwmMotor.setPWM(12, 0, mapServo);
    }
    else if (pin == 6)
    {
      pwmMotor.setPWM(13, 0, mapServo);
    }
  }
  else
  {
    if (pin == 1)
    {
      pwmServo.setPWM(8, 0, mapServo);
    }
    else if (pin == 2)
    {
      pwmServo.setPWM(9, 0, mapServo);
    }
    else if (pin == 3)
    {
      pwmServo.setPWM(10, 0, mapServo);
    }
    else if (pin == 4)
    {
      pwmServo.setPWM(11, 0, mapServo);
    }
    else if (pin == 5)
    {
      pwmServo.setPWM(12, 0, mapServo);
    }
    else if (pin == 6)
    {
      pwmServo.setPWM(13, 0, mapServo);
    }
  }
}

 
