#include "IR_remote.h"
#include <Servo.h>
Servo myservo; 
int servopin = 7;
int MotorPin = 10;
int flag = 0;

IRremote ir(12);

unsigned char keycode;

void setup()
{
    Serial.begin(9600);
    ir.begin();
    myservo.attach(7); 
    myservo.write(90);
    pinMode(MotorPin, OUTPUT);
    digitalWrite(MotorPin, 0);
}

void loop()
{
   byte ir_key = ir.getCode();
   //Serial.println(ir_key);
   switch (ir.getIrKey(ir_key)) {
    case IR_KEYCODE_OK:
          Serial.println("IR_KEYCODE_OK key");
          flag = !flag;
          digitalWrite(MotorPin, flag);
          break;
    case IR_KEYCODE_LEFT:
          myservo.write(0);
          break;
    case IR_KEYCODE_RIGHT:
          myservo.write(180);
          break;
   }
   delay(110);
}
