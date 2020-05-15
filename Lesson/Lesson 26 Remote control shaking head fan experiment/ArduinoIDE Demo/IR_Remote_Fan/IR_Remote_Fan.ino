#include "IR_remote.h"
#include <Servo.h>
Servo myservo; 
int servopin = 7;// Set the servo interface to 7
int MotorPin = 10;// Set the motor interface to 10
int flag = 0;// Set the flag

IRremote ir(12);// Set the infrared receiving interface to 12

unsigned char keycode;

void setup()
{
    Serial.begin(9600);// Set the serial port baud rate to 9600
    ir.begin();
    myservo.attach(7); 
    myservo.write(90);
    delay(1000);
    pinMode(MotorPin, OUTPUT);
    digitalWrite(MotorPin, 0);
}

void loop()
{
   byte ir_key = ir.getCode();
   switch (ir.getIrKey(ir_key)) {// Determine which button is pressed and execute the corresponding program
    case IR_KEYCODE_OK:
          Serial.println("IR_KEYCODE_OK key");
          flag = !flag;
          digitalWrite(MotorPin, flag);// Control the motor
          Serial.println(flag);
          break;
    case IR_KEYCODE_LEFT:
          myservo.write(0);// Control the steering gear to turn to 0 degree
          Serial.println("IR_KEYCODE_OK left");
          break;
    case IR_KEYCODE_RIGHT:
          myservo.write(180);//Control the steering gear to turn 180 degrees
          Serial.println("IR_KEYCODE_OK right");
          break;
   }
   delay(110);
}
