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
 * [Title]    Arduino Serial port printf voltage which read from continuous potentiometer
 * [diagram]
 *           Arduino PIN 0   ===================   potentiometer pin 2
 *           Arduino PIN 13  ===================   LED pin
 */
int  ADPIN  = A0 ;
int  LEDPIN = 13 ;
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
    pinMode(ADPIN,INPUT);   // define ADPIN input LEDPIN output
	  pinMode(LEDPIN,OUTPUT);
    Serial.begin(9600);    //Serial Baud rate is 115200
}
void loop()
{
    digitalWrite(LEDPIN,HIGH);          // light on led
    value =  analogRead(ADPIN);         // read analog pin raw data
    voltage = ( ( float )value )/1023 ;
    voltage = voltage * 5 ;              // convert analog raw data to real voltage = (analog/1023)*5
    Serial.print("get ad pin value ");   //printf Analog pin value
    Serial.print(value);
    Serial.println("\nvoltage =  ");
    Serial.println(voltage);
    delay(1000);
    digitalWrite(LEDPIN,LOW);             //turn off led
}
