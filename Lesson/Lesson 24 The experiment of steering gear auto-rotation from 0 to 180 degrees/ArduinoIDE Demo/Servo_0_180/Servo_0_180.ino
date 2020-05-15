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
 * [Title]    lcd1602 display string .
 * [Diagram]*/
int servopin = 7; // Set the servo interface
int pulsewidth; // Set the pulse width variable

void setup()
{
  pinMode(servopin, OUTPUT); // Set the servo interface to output mode
}
void loop()
{ // Servo from 0 degrees to 180 degrees
  for ( int angle = 0; angle < 180; angle += 2)
  {
    for (int i = 0; i < 10; i++) 
    {
     pulsewidth = (angle * 11) + 500;
    digitalWrite(servopin, HIGH);   
    delayMicroseconds(pulsewidth); 
    digitalWrite(servopin, LOW);    
    delayMicroseconds(20000 - pulsewidth);  
    }
  }
  // The servo is from 180 degrees to 0 degrees
  for ( int angle = 180; angle>0; angle -= 2)
  {
    for (int i = 0; i < 10; i++) 
    {
    pulsewidth = (angle * 11) + 500;
    digitalWrite(servopin, HIGH);   
    delayMicroseconds(pulsewidth); 
    digitalWrite(servopin, LOW);    
    delayMicroseconds(20000 - pulsewidth);  
    }
  }
}

