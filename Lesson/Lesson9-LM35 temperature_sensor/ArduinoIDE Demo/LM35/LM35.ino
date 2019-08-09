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
 * [Title]    Read current temprature and output by arduino uno serial port
 * [diagram]
 *            Arduino  pin0  ===================   LM35 numble2 wire
 *
 */
int Temp_Pin = A0;              // analog pin line LM35 numble 2 wire
int val;
int dat;
float voltage = 0.0 ;
void setup()
{
    Serial.begin(115200);       //init serial Baud rate 115200
}
void loop()
{
    val = analogRead(Temp_Pin);         //  read analog raw data
    voltage = ( ( float )val )/1023 ;
    voltage = voltage * 5 ;              // convert analog value to real voltage
    dat =  voltage * 100;                // convert voltage to temprature
    Serial.print("Current Temp : ");
    Serial.print(dat);
    Serial.println("C");
    delay(500);                          // Delay 0.5 s
}
