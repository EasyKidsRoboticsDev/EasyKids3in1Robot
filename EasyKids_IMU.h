#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Wire.h>

Adafruit_BNO055 bno;
sensors_event_t orientationData;
float resetValue, currentOrientation = 0;
bool resetIMU = false;

void EasyKidsIMUsetup() { //******///
  /* Initialise the sensor */
  bno = Adafruit_BNO055(55, 0x28, &Wire);
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
  }
  delay(1000);
}

int clamp(int value, int lowerLim, int HigherLim)
{
  return max(min(value, HigherLim), lowerLim);
}


float getProcessedGyro()
{
  delay(10); // To avoid getting readings too fast

  bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  float orientate = orientationData.orientation.x;

  // Convert range from [0, 360] to [-180, 180]
  if(orientate > 180) {  orientate -= 360; }

  // Reset flag
  if(resetIMU) {
    resetIMU = false;
    resetValue = orientate;
  }

  // Add ResetValue Factor
  orientate -= resetValue;

  // Converting values that go outside the Range
  if(orientate < -180)
  {
   orientate += 360;
  }
  else if(orientate > 180)
  {
    orientate -= 360;
  }

  return orientate;
}

void resetGyro()
{           
  resetIMU = true;
  getProcessedGyro();
}

void forwardTimeIMU(int speed, float timer, float kP, float kD)
{
  float lastError = 0.0;
  float timeSince = millis();
  int pidOutput = 0;
  resetGyro();

  while(millis() - timeSince < timer)
  {
    currentOrientation = getProcessedGyro(); 
    Serial.println(currentOrientation);

    pidOutput = clamp(int(kP * currentOrientation + kD * (currentOrientation - lastError)), -speed, speed);
    lastError = currentOrientation;

    motor(1, speed - pidOutput);
    motor(2, speed - pidOutput);

    motor(3, speed + pidOutput);
    motor(4, speed + pidOutput);
  }
  motorStopAll();
}

void backwardTimeIMU(int speed, float timer, float kP, float kD)
{
  float lastError = 0.0;
  float timeSince = millis();
  int pidOutput = 0;
  resetGyro();

  while(millis() - timeSince < timer)
  {
    currentOrientation = getProcessedGyro(); 
    Serial.println(currentOrientation);

    pidOutput = clamp(int(kP * currentOrientation + kD * (currentOrientation - lastError)), -speed, speed);
    lastError = currentOrientation;

    motor(1, -speed - pidOutput);
    motor(2, -speed - pidOutput);

    motor(3, -speed + pidOutput);
    motor(4, -speed + pidOutput);
  }
  motorStopAll();
}

void spinLeftIMU(int speed, int angleSetPoint)
{
  float error = 1000.0;
  angleSetPoint = -clamp(angleSetPoint, 0, 180);
  resetGyro(); 

  while(abs(error) > 1)
  {
    currentOrientation = getProcessedGyro();   
    error = angleSetPoint - currentOrientation;
    if(abs(error) < 30) { speed = 10; }

    motor(1, -speed);
    motor(2, -speed);

    motor(3, speed);
    motor(4, speed);
  }

  currentOrientation = getProcessedGyro();  
  error = angleSetPoint - currentOrientation;
  while(abs(error) > 1)
  {
    currentOrientation = getProcessedGyro();   
    error = angleSetPoint - currentOrientation;

    motor(1, 10);
    motor(2, 10);

    motor(3, -10);
    motor(4, -10);
  }

  Serial.println(error);
  motorStopAll();
}

void spinRightIMU(int speed, int angleSetPoint)
{
  float error = 1000.0;
  angleSetPoint = clamp(angleSetPoint, 0, 180);
  resetGyro(); 

  while(abs(error) > 1)
  {
    currentOrientation = getProcessedGyro();   
    error = angleSetPoint - currentOrientation;
    if(abs(error) < 30) { speed = 10; }

    motor(1, speed);
    motor(2, speed);

    motor(3, -speed);
    motor(4, -speed);
  }

  currentOrientation = getProcessedGyro();  
  error = angleSetPoint - currentOrientation;
  while(abs(error) > 1)
  {
    currentOrientation = getProcessedGyro();   
    error = angleSetPoint - currentOrientation;

    motor(1, -10);
    motor(2, -10);

    motor(3, 10);
    motor(4, 10);
  }

  Serial.println(error);
  motorStopAll();
}

void slideRightIMU(int speed, float timer, float kP, float kD)
{
  float lastError = 0.0;
  float timeSince = millis();
  int pidOutput = 0;
  resetGyro();

  while(millis() - timeSince < timer)
  {
    currentOrientation = getProcessedGyro(); 
    Serial.println(currentOrientation);

    pidOutput = clamp(int(kP * currentOrientation + kD * (currentOrientation - lastError)), -speed, speed);
    lastError = currentOrientation;

    motor(1, speed - pidOutput);
    motor(2, -speed - pidOutput);

    motor(3, -speed + pidOutput);
    motor(4, speed + pidOutput);

  }
  motorStopAll();
}

void slideLeftIMU(int speed, float timer, float kP, float kD)
{
  float lastError = 0.0;
  float timeSince = millis();
  int pidOutput = 0;
  resetGyro();

  while(millis() - timeSince < timer)
  {
    currentOrientation = getProcessedGyro(); 
    Serial.println(currentOrientation);

    pidOutput = clamp(int(kP * currentOrientation + kD * (currentOrientation - lastError)), -speed, speed);
    lastError = currentOrientation;

    motor(1, -speed - pidOutput);
    motor(2, speed - pidOutput);

    motor(3, speed + pidOutput);
    motor(4, -speed + pidOutput);

  }
  motorStopAll();
}


