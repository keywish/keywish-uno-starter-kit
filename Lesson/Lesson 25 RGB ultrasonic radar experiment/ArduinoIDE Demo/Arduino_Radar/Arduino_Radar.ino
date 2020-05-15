#include<Servo.h>

const int SignalPin = 3;
const int motorSignalPin = 7;
const int startingAngle = 15;
const int minimumAngle = 15;
const int maximumAngle = 165;
const int rotationSpeed = 1;

unsigned long Time_Echo_us = 0;
Servo motor;

void setup(void) 
{
    motor.attach(motorSignalPin);
    Serial.begin(9600);
}
void loop(void)
{
    static int motorAngle = startingAngle;
    static int motorRotateAmount = rotationSpeed;
    motor.write(motorAngle);
    delay(30);
    SerialOutput(motorAngle, CalculateDistance());    
    motorAngle += motorRotateAmount;
    if(motorAngle <= minimumAngle || motorAngle >= maximumAngle) {
        motorRotateAmount = -motorRotateAmount;
    }
}

int CalculateDistance(void)
{
    float distance;
    pinMode(SignalPin, OUTPUT);
    digitalWrite(SignalPin, LOW);
    delayMicroseconds(2);
    digitalWrite(SignalPin, HIGH);
    delayMicroseconds(20);
    digitalWrite(SignalPin, LOW);
    pinMode(SignalPin, INPUT);
    Time_Echo_us = pulseIn(SignalPin, HIGH);
    if ((Time_Echo_us < 60000) && (Time_Echo_us > 1)) {
        distance = Time_Echo_us / 58.00;
        Serial.print("distance is :");
        Serial.print(distance);
        Serial.print("cm");
        Serial.println();  
    }
    return int(distance);
}
void SerialOutput(const int angle, const int distance)
{
    String angleString = String(angle);
    String distanceString = String(distance);
    Serial.println(angleString + "," + distanceString);
}
