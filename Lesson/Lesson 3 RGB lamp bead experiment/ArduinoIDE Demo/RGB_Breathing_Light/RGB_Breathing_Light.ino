/*
 * /***********************************************************************
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
 * or FI
 * [Title]: RGB breathing light
 * [Diagram]
 *         Arduino PIN 11   ===================  RGB pin1 red
 *         Arduino PIN 10  ===================   RGB pin3 green
 *         Arduino PIN 9  ===================    RGB pin4 blue
 *         Arduino +5     ===================   RGB pin2  VCC
 *
 */
#define RGB_RED    11
#define RGB_GREEN  10
#define RGB_BLUE   9

void setup()
{
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);
}

void loop()
{
    int i;
    for(i=255;i>0;i--)
    {
        analogWrite(RGB_RED,i);
        analogWrite(RGB_GREEN,255);
        analogWrite(RGB_BLUE,255);
        delay(4);
    }
    delay(500);           //turn the RGB LED red smoth

    for(i=255;i>0;i--)
    {
        analogWrite(RGB_RED,255);
        analogWrite(RGB_GREEN,i);
        analogWrite(RGB_BLUE,255);
        delay(4);
    }
    delay(500);           //turn the RGB LED green smoth
  
   for(i=255;i>0;i--)
    {
        analogWrite(RGB_RED,255);
        analogWrite(RGB_GREEN,255);
        analogWrite(RGB_BLUE,i);
        delay(4);
    }
    delay(500);           //turn the RGB LED blue smoth
}

