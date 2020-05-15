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
 * [Title]     8bit Numeric led Display the numble which via a serial port input 
 * [Diagram]
 *         Arduino PIN 7   ===================  8bit Numeric led a
 *         Arduino PIN 6   ===================  8bit Numeric led b
 *         Arduino PIN 5   ===================  8bit Numeric led c
 *         Arduino PIN 11  ===================  8bit Numeric led d
 *         Arduino PIN 10  ===================  8bit Numeric led e
 *         Arduino PIN 8   ===================  8bit Numeric led f
 *         Arduino PIN 9   ===================  8bit Numeric led g
 *         Arduino PIN 4   ===================  8bit Numeric led h
 */

#include "SegmentDisplay.h"

#define  LED_A   7       // define Arduino GPIO7 for led a
#define  LED_B   6       // define Arduino GPIO6 for led b
#define  LED_C   5       // define Arduino GPIO5 for led c
#define  LED_D   10      // define Arduino GPIO11 for led d
#define  LED_E   11      // define Arduino GPIO10 for led e
#define  LED_F   8       // define Arduino GPIO8 for led f
#define  LED_G   9       // define Arduino GPIO9 for led g
#define  LED_H   4       // define Arduino GPIO4 for led h

SegmentDisplay _7SegmentDisplay(LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G, LED_H);

byte value;

void setup()
{
    Serial.begin(9600);
    _7SegmentDisplay.TurnOffAllLed();
}

void loop()
{
    //Serial.println("please input display char \n");
    while (Serial.available() > 0) //Determine whether the serial data
    {
        value = Serial.parseInt();
        Serial.println(value);
        _7SegmentDisplay.TurnOffAllLed();
        _7SegmentDisplay.DisplayChar(value);
    }
   delay(5);
}
