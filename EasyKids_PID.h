int valSensor0 = 0;
int valSensor1 = 0;
int valSensor2 = 0;
int valSensor3 = 0;
int valSensor4 = 0;
int valSensor5 = 0;
int valSensor6 = 0;

int rightMotor;
int leftMotor;
int NumSensor = 7;
bool invertedLine = false;
int Pin_Setup[7] = {0, 1, 2, 3, 4, 5, 6};
int Sensor_Min[] = {10, 10, 10, 10, 10, 10, 10};
int Sensor_Max[] = {4000, 4000, 4000, 4000, 4000, 4000, 4000};

float KP;
float KD;
uint16_t setPoint = (NumSensor - 1) * 100 / 2;
uint32_t lastPosition = (NumSensor - 1) * 100 / 2;
float errors = 0;
float output = 0;
float derivative;
float previous_error = setPoint;

void setSensorMin(int s0, int s1, int s2, int s3, int s4 = 10, int s5 = 10, int s6 = 10)
{
    Sensor_Min[0] = s0;
    Sensor_Min[1] = s1;
    Sensor_Min[2] = s2;
    Sensor_Min[3] = s3;
    Sensor_Min[4] = s4;
    Sensor_Min[5] = s5;
    Sensor_Min[6] = s6;
}

void setSensorMax(int s0, int s1, int s2, int s3, int s4 = 10, int s5 = 10, int s6 = 10)
{
    Sensor_Max[0] = s0;
    Sensor_Max[1] = s1;
    Sensor_Max[2] = s2;
    Sensor_Max[3] = s3;
    Sensor_Max[4] = s4;
    Sensor_Max[5] = s5;
    Sensor_Max[6] = s6;
}

void sensorNum(int num)
{
    NumSensor = num;
    setPoint = (NumSensor - 1) * 100 / 2;
    lastPosition = (NumSensor - 1) * 100 / 2;
    pwmMotor.setPWMFreq(1000);
}

void whiteLine() { invertedLine = true; }
void blackLine() { invertedLine = false; }

int readline()
{
    int onLine = 0; // Check if robot still on line (Atleast 1 sensor)
    long avg = 0;
    long sum = 0;
    for (int i = 0; i < NumSensor; i++)
    {
        long value = 0;

        if (invertedLine)
        { // White line
            value = map(analog(Pin_Setup[i]), Sensor_Min[i], Sensor_Max[i], 100, 1);
        }
        else
        { // Black line
            value = map(analog(Pin_Setup[i]), Sensor_Min[i], Sensor_Max[i], 1, 100);
        }
        value = clamp(value, 1, 100);

        // Serial.println(value);
        if ((value < 50 && !invertedLine) || (value > 50 && invertedLine)) // 50 is middle value
        {                                                            // More than 800 = White
            onLine = 1;
            avg += value * (i * 100);
            sum += value;
        }
    }
    // Serial.println(" ");

    if (onLine == 0)
    {
        if (((lastPosition <= ((NumSensor - 1) * 100) / 2) && invertedLine) || // White line
            ((lastPosition >= ((NumSensor - 1) * 100) / 2) && !invertedLine))  // Black line
        {
            lastPosition = (NumSensor - 1) * 100; // Middle value
        }
        else
        {
            lastPosition = 0;
        }
    }
    else
    {
        lastPosition = (avg / sum);
    }
    return round(((NumSensor - 1) * 100) - lastPosition);
}

void trackPID(int min_speed, float iKP, float iKD)
{
    KP = iKP / 10;
    KD = iKD / 10;

    errors = (readline() - setPoint);
    Serial.println(readline());
    derivative = (errors - previous_error);
    output = (KP * errors) + (KD * derivative);
    previous_error = errors;
    leftMotor = clamp(min_speed + output, -100, 100);
    rightMotor = clamp(min_speed - output, -100, 100);

    motor(2, leftMotor);
    motor(3, rightMotor);
}

void lineFollowTime(int speed, float iKP, float iKD, int setTime)
{

    long timeSince = 0;
    timeSince = millis();
    while ((millis() - timeSince) < setTime)
    {
        trackPID(speed, iKP, iKD);
    }
    motor(2, 0);
    motor(3, 0);
}

void lineFollowCross(int setSpeed, float iKP, float iKD)
{
    int rightVal = analog(Pin_Setup[0]);
    int leftVal = analog(Pin_Setup[NumSensor - 1]);

    int avgRightVal = (Sensor_Max[0] + Sensor_Min[0]) / 2;
    int avgLeftVal = (Sensor_Max[NumSensor - 1] + Sensor_Min[NumSensor - 1]) / 2;

    if (invertedLine)
    {
        while (rightVal < avgRightVal || leftVal < avgLeftVal)
        {
            rightVal = analog(Pin_Setup[0]);
            leftVal = analog(Pin_Setup[NumSensor - 1]);
            trackPID(setSpeed, iKP, iKD);
        }
    }
    else
    {
        while (rightVal > avgRightVal || leftVal > avgLeftVal)
        {
            rightVal = analog(Pin_Setup[0]);
            leftVal = analog(Pin_Setup[NumSensor - 1]);
            trackPID(setSpeed, iKP, iKD);
        }
    }
    motor(2, 0);
    motor(3, 0);
}

void lineFollowFork(int setSpeed, float iKP, float iKD)
{
    int outerRightVal = analog(Pin_Setup[0]);
    int outerLeftVal = analog(Pin_Setup[NumSensor - 1]);

    int avgOuterRightVal = (Sensor_Max[0] + Sensor_Min[0]) / 2;
    int avgOuterLeftVal = (Sensor_Max[NumSensor - 1] + Sensor_Min[NumSensor - 1]) / 2;

    if (invertedLine)
    {
        while (outerRightVal < avgOuterRightVal || outerLeftVal < avgOuterLeftVal)
        {
            outerRightVal = analog(Pin_Setup[0]);
            outerLeftVal = analog(Pin_Setup[NumSensor - 1]);

            trackPID(setSpeed, iKP, iKD);
        }
    }
    else
    {
        while (outerRightVal > avgOuterRightVal || outerLeftVal > avgOuterLeftVal)
        {
            outerRightVal = analog(Pin_Setup[0]);
            outerLeftVal = analog(Pin_Setup[NumSensor - 1]);

            trackPID(setSpeed, iKP, iKD);
        }
    }
    motor(2, 0);
    motor(3, 0);
}

void lineFollow90Left(int setSpeed, float iKP, float iKD)
{
    int leftVal = analog(Pin_Setup[NumSensor - 2]);
    int leftestVal = analog(Pin_Setup[NumSensor - 1]);

    int avgLeftVal = (Sensor_Max[NumSensor - 2] + Sensor_Min[NumSensor - 2]) / 2;
    int avgLeftestVal = (Sensor_Max[NumSensor - 1] + Sensor_Min[NumSensor - 1]) / 2;

    while (leftVal > avgLeftVal || leftestVal > avgLeftestVal)
    {
        leftVal = analog(Pin_Setup[NumSensor - 2]);
        leftestVal = analog(Pin_Setup[NumSensor - 1]);

        trackPID(setSpeed, iKP, iKD);
    }
    motor(2, 0);
    motor(3, 0);
}

void lineFollow90Right(int setSpeed, float iKP, float iKD)
{
    int rightVal = analog(Pin_Setup[NumSensor - 2]);
    int rightestVal = analog(Pin_Setup[NumSensor - 1]);

    int avgRightVal = (Sensor_Max[NumSensor - 2] + Sensor_Min[NumSensor - 2]) / 2;
    int avgRightestVal = (Sensor_Max[NumSensor - 1] + Sensor_Min[NumSensor - 1]) / 2;

    while (rightVal > avgRightVal || rightestVal > avgRightestVal)
    {
        rightVal = analog(Pin_Setup[NumSensor - 2]);
        rightestVal = analog(Pin_Setup[NumSensor - 1]);
        trackPID(setSpeed, iKP, iKD);
    }
    motor(2, 0);
    motor(3, 0);
}

void lineFollowTurnLeft(int speedM)
{
    motor(2, -speedM);
    motor(3, speedM);
    delay(20);
    do
    {
        motor(2, -speedM);
        motor(3, speedM);
    } while (analog(Pin_Setup[NumSensor - 1]) > (Sensor_Max[NumSensor - 1] + Sensor_Min[NumSensor - 1]) / 2);
    motor(2, 0);
    motor(3, 0);
}

void lineFollowTurnRight(int speedM)
{
    motor(2, speedM);
    motor(3, -speedM);
    delay(20);
    do
    {
        motor(2, speedM);
        motor(3, -speedM);
    } while (analog(Pin_Setup[0]) > (Sensor_Max[0] + Sensor_Min[0]) / 2);
    motor(2, 0);
    motor(3, 0);
}

void readSensor()
{
    displayClear();
    while (1)
    {
        display.setTextFont(GLCD);
        display.setTextSize(2);
        display.setCursor(15, 5);
        display.setTextColor(0xF81F);
        display.print("Read Sensor 0 - 6");

        // ------- Sensor 0 -------
        display.setTextFont(GLCD);
        display.setTextSize(2);
        display.setCursor(20, 30);
        display.setTextColor(0x0);
        display.print("Sensor(0) = ");
        display.print(valSensor0);
        valSensor0 = analog(0);
        display.setTextSize(2);
        display.setCursor(20, 30);
        display.setTextColor(0x07FF);
        display.print("Sensor(0) = ");
        display.print(valSensor0);

        // ------- Sensor 1 -------
        display.setTextFont(GLCD);
        display.setTextSize(2);
        display.setCursor(20, 60);
        display.setTextColor(0x0);
        display.print("Sensor(1) = ");
        display.print(valSensor1);
        valSensor1 = analog(1);
        display.setTextSize(2);
        display.setCursor(20, 60);
        display.setTextColor(0x07FF);
        display.print("Sensor(1) = ");
        display.print(valSensor1);

        // ------- Sensor 2 -------
        display.setTextFont(GLCD);
        display.setTextSize(2);
        display.setCursor(20, 90);
        display.setTextColor(0x0);
        display.print("Sensor(2) = ");
        display.print(valSensor2);
        valSensor2 = analog(2);
        display.setTextSize(2);
        display.setCursor(20, 90);
        display.setTextColor(0x07FF);
        display.print("Sensor(2) = ");
        display.print(valSensor2);

        // ------- Sensor 3 -------
        display.setTextFont(GLCD);
        display.setTextSize(2);
        display.setCursor(20, 120);
        display.setTextColor(0x0);
        display.print("Sensor(3) = ");
        display.print(valSensor3);
        valSensor3 = analog(3);
        display.setTextSize(2);
        display.setCursor(20, 120);
        display.setTextColor(0x07FF);
        display.print("Sensor(3) = ");
        display.print(valSensor3);

        // Serial
        Serial.print("Sensor 0 = ");
        Serial.print(valSensor0);
        Serial.print("| Sensor 1 = ");
        Serial.print(valSensor1);
        Serial.print("| Sensor 2 = ");
        Serial.print(valSensor2);
        Serial.print("| Sensor 3 = ");
        Serial.print(valSensor3);

        if (NumSensor > 4)
        {
            // ------- Sensor 4 -------
            display.setTextFont(GLCD);
            display.setTextSize(2);
            display.setCursor(20, 150);
            display.setTextColor(0x0);
            display.print("Sensor(4) = ");
            display.print(valSensor4);
            valSensor4 = analog(4);
            display.setTextSize(2);
            display.setCursor(20, 150);
            display.setTextColor(0x07FF);
            display.print("Sensor(4) = ");
            display.print(valSensor4);

            // Serial
            Serial.print("| Sensor 4 = ");
            Serial.print(valSensor4);
        }

        if (NumSensor > 5)
        {
            // ------- Sensor 5 -------
            display.setTextFont(GLCD);
            display.setTextSize(2);
            display.setCursor(20, 180);
            display.setTextColor(0x0);
            display.print("Sensor(5) = ");
            display.print(valSensor5);
            valSensor5 = analog(5);
            display.setTextSize(2);
            display.setCursor(20, 180);
            display.setTextColor(0x07FF);
            display.print("Sensor(5) = ");
            display.print(valSensor5);

            // Serial
            Serial.print("| Sensor 5 = ");
            Serial.print(valSensor5);
        }

        if (NumSensor > 6)
        {
            // ------- Sensor 6 -------
            display.setTextFont(GLCD);
            display.setTextSize(2);
            display.setCursor(20, 210);
            display.setTextColor(0x0);
            display.print("Sensor(6) = ");
            display.print(valSensor6);
            valSensor6 = analog(6);
            display.setTextSize(2);
            display.setCursor(20, 210);
            display.setTextColor(0x07FF);
            display.print("Sensor(6) = ");
            display.print(valSensor6);

            // Serial
            Serial.print("| Sensor 6 = ");
            Serial.println(valSensor6);
        }
        delay(50);
    }
}