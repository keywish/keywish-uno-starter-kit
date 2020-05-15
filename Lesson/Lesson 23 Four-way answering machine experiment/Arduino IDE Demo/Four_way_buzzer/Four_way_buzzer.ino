int blueled=11;       // Set blue_led to pin11
int redled=10;   // Set red_led to pin10
int yellowled=9;  // Set yellow_led to pin9
int greenled=8;   // Set green_led to pin8

int bluebutton =7;     // Set blue_button to pin7
int redbutton=6;         // Set red_button to pin6
int yellowbutton=5;   // Set yellow_button to pin5
int greenbutton=4;  // Set green_button to pin4

int blue;
int red;
int yellow;
int green;

void setup()
{
  // Set the blue_led, red_led, yellow_led, green_led interface as output mode
pinMode(blueled,OUTPUT); 
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);
// Set the blue_led, red_led, yellow_led, green_led interface as output mode
pinMode(bluebutton,INPUT);
pinMode(greenbutton,INPUT);
pinMode(redbutton,INPUT);
pinMode(yellowbutton,INPUT);


}
void loop()
{
  blue=digitalRead(bluebutton);    // Read the bluebutton value
    if(blue==HIGH)      // Determine whether the bluebutton is pressed
    {             // light blueled and turn off other lights
      digitalWrite(blueled,HIGH);
      digitalWrite(redled,LOW);
      digitalWrite(yellowled,LOW);
      digitalWrite(greenled,LOW);
    }
  red=digitalRead(redbutton);// Read the redbutton value
    if(red==HIGH)     // Determine whether the redbutton is pressed
    {       // light redled and turn off other lights
      digitalWrite(blueled,LOW);
      digitalWrite(redled,HIGH);
      digitalWrite(yellowled,LOW);
      digitalWrite(greenled,LOW);;
    }
  yellow=digitalRead(yellowbutton);  // Read the yellowbutton value
    if(yellow==HIGH)     // Determine whether the yellowbutton is pressed
    {     // light yellowled and turn off other lights
      digitalWrite(blueled,LOW);
      digitalWrite(redled,LOW);
      digitalWrite(yellowled,HIGH);
      digitalWrite(greenled,LOW);
    }
  green=digitalRead(greenbutton);   // Read the greenbutton value
    if(green==HIGH)    // Determine whether the greenbutton is pressed
    {       // light greenled and turn off other lights
      digitalWrite(blueled,LOW);
      digitalWrite(redled,LOW);
      digitalWrite(yellowled,LOW);
      digitalWrite(greenled,HIGH); 
    }
}
 
