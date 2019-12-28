#include<Servo.h>
const int soundTriggerPin = 2;
const int soundEchoPin = 3;
const int motorSignalPin = 7;
const int startingAngle = 15;
const int minimumAngle = 15;
const int maximumAngle = 165;
const int rotationSpeed = 1;
Servo motor;
void setup(void) 
{
    pinMode(soundTriggerPin, OUTPUT);
    pinMode(soundEchoPin, INPUT);
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
    }}
int CalculateDistance(void)
{
    //digitalWrite(soundTriggerPin, LOW);
    //delayMicroseconds(2);
    digitalWrite(soundTriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(soundTriggerPin, LOW);
      long duration = pulseIn(soundEchoPin, HIGH);
    float distance = duration * 0.017F;
    return int(distance);
}
void SerialOutput(const int angle, const int distance)
{
    String angleString = String(angle);
    String distanceString = String(distance);
    Serial.println(angleString + "," + distanceString);
}

