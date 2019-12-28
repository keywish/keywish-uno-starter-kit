int blueled=11;
int redled=10;
int yellowled=9;
int greenled=8;

int bluepin =7;
int redpin=6;
int yellowpin=5;
int greenpin=4;

int blue;
int red;
int yellow;
int green;

void setup()
{
pinMode(blueled,OUTPUT);
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);

pinMode(bluepin,INPUT);
pinMode(greenpin,INPUT);
pinMode(redpin,INPUT);
pinMode(yellowpin,INPUT);


}
void loop()
{
 blue=digitalRead(bluepin);
if(blue==LOW)
{ digitalWrite(blueled,LOW);}
else
{ digitalWrite(blueled,HIGH);}

red=digitalRead(redpin);
if(red==LOW)
{ digitalWrite(redled,LOW);}
else
{ digitalWrite(redled,HIGH);}

yellow=digitalRead(yellowpin);
if(yellow==LOW)
{ digitalWrite(yellowled,LOW);}
else
{ digitalWrite(yellowled,HIGH);}

green=digitalRead(greenpin);
if(green==LOW)
{ digitalWrite(greenled,LOW);}
else
{ digitalWrite(greenled,HIGH);}



}
 
