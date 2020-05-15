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
int  ADPIN  = A0 ; // The sensor is connected to A0 port
int  LEDPIN = 11 ; // The led light is connected to 11 ports
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
    pinMode(LEDPIN,OUTPUT); // Set the led interface to output mode
    Serial.begin(9600);    // Set the serial port baud rate to 9600
}
void loop()
{
    value =  analogRead(ADPIN);
    voltage = ( ( float )value )/1023 ;
    value =   voltage * 256 ;            // Use the formula to calculate the Value
    analogWrite(LEDPIN,value);    
    Serial.println(value); // Print Value
    Serial.println(voltage ); // print voltage value
    delay(1000); // 1 second delay
}
