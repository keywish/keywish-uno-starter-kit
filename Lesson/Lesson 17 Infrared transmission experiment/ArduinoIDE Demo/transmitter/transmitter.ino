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
 * [Title]      Infrared transmitter module
 * [Diagram]
 *         Arduino PIN 3    ===================  Infrared transmitter module pin S
 *         Arduino PIN GND  ===================  Infrared transmitter module pin -
 *         Arduino PIN +5V  ===================  Infrared transmitter module pin2
 */


#include "IRremote.h"                    // Reference IRRemote library
const int buttonPin = 4;                 // Push button is connected to pin 4
int buttonState = 0;                    // Button status
IRsend irsend;                          // Define IRsend object to emit infrared signal
void setup()
{
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);              // Set buttonPin to input
}
                             
void loop()
{
  	// read key status
  	buttonState = digitalRead(buttonPin);
  // Check if the button is presse
  	// If there is, buttonState will be high level output
  	if (buttonState == HIGH) {
  	    // 发射红外线讯号
        Serial.println("button");
    		irsend.sendNEC(0x4CB3817E, 32);   // This code is the code of the key you pressed (connected to pin4), you can change it at will
  	}
    delay(200);
}
