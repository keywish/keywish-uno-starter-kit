/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]      SW520D Ball Switch
 * [Diagram]
 *         Arduino PIN A5   ===================  SW520D PIN 1
 *         Arduino PIN GND  ===================  SW520D PIN 2
 *         Arduino PIN A5   ===================  10kΩresistor PIN 1
 *         Arduino PIN 5V   ===================  10kΩresistor PIN 2
 *         Arduino PIN 12   ===================  LED PIN +
 *         Arduino PIN GND  ===================  LED PIN -
 *         Arduino PIN 13   ===================  LED PIN +
 *         Arduino PIN GND  ===================  LED PIN -
 */
int Led=12;// Define the LED interface
int Buzzer_pin=13;
int buttonpin=11; // Define tilt switch sensor interface
int val=0;// Define the numeric variable val 
void setup() 
{  
  pinMode(Led,OUTPUT);// Define LED as output interface
  pinMode(Buzzer_pin,OUTPUT);
  pinMode(buttonpin,INPUT);// Define tilt switch sensor as input interface
  Serial.begin(9600);
}  
void loop() 
{  
  val=digitalRead(buttonpin);// The value of the digital interface is read and assigned to val
  Serial.println(val);
  if(val==0)// When the tilt switch sensor detects a signal, the LED flashes
     { 
       digitalWrite(Led,HIGH); 
      digitalWrite(Buzzer_pin,HIGH);
      delay(1000);
     } 
  else 
     {  
       digitalWrite(Led,LOW); 
       digitalWrite(Buzzer_pin,LOW);
        delay(1000);
     } 
}
