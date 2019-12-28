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
 * [Title]     Adjust LED Brightness by photoconductive resistance
 * [diagram]
 *            Arduino  pin0  ===================   photoconductive
 *
 */
int  ADPIN  = A0  ;
int  LEDPIN = 11 ;
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
    pinMode(LEDPIN,OUTPUT);
    Serial.begin(9600);    //Serial Baud rate is 115200
}
void loop()
{
    value =  analogRead(ADPIN);
    voltage = ( ( float )value )/1023 ;
    Serial.println("voltage =");
    Serial.println(voltage );
    value = (int)voltage * 256 ;  //convert voltage to value
    Serial.println(" value =");
    Serial.println(value );
    analogWrite(LEDPIN,value);
    
    delay(1000);
}
