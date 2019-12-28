#include <Servo.h>
Servo myservo;
int ServoPin = 13;
char inByte = 0;
int angle = 0;
String temp = "";//Temporary character variables, or use it for the cache
void setup()
{
  Serial.begin(9600);  //Set the baud rate
  pinMode(ServoPin, OUTPUT);
  myservo.attach(ServoPin);
}
void loop()
{
  while (Serial.available() > 0) //Determine whether the serial data
  {
    inByte = Serial.read();//Read data, the serial port can only read 1 character
    temp += inByte;//The characters read into temporary variables inside the cache, Continue to determine the serial port there is no data, know all the data read out
  }

  if (temp != "")// Determine whether the temporary variable is empty
  {
    angle = temp.toInt();    //Convert variable string type to integer
    Serial.print("Servo degree: ");
    Serial.println(angle);
    //Control the servo to rotate the corresponding angle.
  }
  temp = "";//Please see temporary variables
  myservo.write(angle);
  delay(100);//Delayed 100 milliseconds

}
