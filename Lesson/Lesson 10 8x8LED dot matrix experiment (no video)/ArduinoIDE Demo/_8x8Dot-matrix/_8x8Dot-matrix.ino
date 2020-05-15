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
 * [Title]     8x8bit Dot-Matrix display Heart images
 * [Diagram]
 *         Arduino PIN 2   ===================  8x8bit Dot-Matrix pin 9(D0)
 *         Arduino PIN 3   ===================  8x8bit Dot-Matrix pin 14(D1)
 *         Arduino PIN 4   ===================  8x8bit Dot-Matrix pin 8(D2)
 *         Arduino PIN 5   ===================  8x8bit Dot-Matrix pin 12(D3)
 *         Arduino PIN 6   ===================  8x8bit Dot-Matrix pin 13(a)
 *         Arduino PIN 7   ===================  8x8bit Dot-Matrix pin 3(b)
 *         Arduino PIN 8   ===================  8x8bit Dot-Matrix pin 4(c)
 *         Arduino PIN 9   ===================  8x8bit Dot-Matrix pin 10(d)
 *         Arduino PIN 10  ===================  8x8bit Dot-Matrix pin 6(e)
 *         Arduino PIN 11  ===================  8x8bit Dot-Matrix pin 11(f)
 *         Arduino PIN 12  ===================  8x8bit Dot-Matrix pin 15(g)
 *         Arduino PIN 13  ===================  8x8bit Dot-Matrix pin 16(h)
 *         Arduino PIN A0  ===================  8x8bit Dot-Matrix pin 5(D7)
 *         Arduino PIN A1  ===================  8x8bit Dot-Matrix pin 2(D6)
 *         Arduino PIN A2  ===================  8x8bit Dot-Matrix pin 7(D5)
 *         Arduino PIN A3  ===================  8x8bit Dot-Matrix pin 1(D4)
 */

#include "MaxMatrix_8x8.h"
 //the pin to control ROW_
#define    ROW_0   2   // the number of the ROW_ pin 9
#define    ROW_1   3   // the number of the ROW_ pin 14
#define    ROW_2   4   // the number of the ROW_ pin 8
#define    ROW_3   5   // the number of the ROW_ pin 12
#define    ROW_4   A3   // the number of the ROW_ pin 1
#define    ROW_5   A2   // the number of the ROW_ pin 7
#define    ROW_6   A1   // the number of the ROW_ pin 2
#define    ROW_7   A0   // the number of the ROW_ pin 5
//the pin to control COL_
#define     LED_A   6  // the number of the COL_ pin 13
#define     LED_B   7  // the number of the COL_ pin 3
#define     LED_C   8  // the number of the COL_ pin 4
#define     LED_D   9  // the number of the COL_ pin 10
#define     LED_E   10  // the number of the COL_ pin 6
#define     LED_F   11  // the number of the COL_ pin 11
#define     LED_G   12  // the number of the COL_ pin 15
#define     LED_H   13  // the number of the COL_ pin 16


const byte ROW_PIN[8] = {ROW_0, ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7};
const byte COL_PIN[8] = {LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G, LED_H};

MaxMatrix *m8x8Dot; //(ROW_PIN, COL_PIN);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    m8x8Dot = new MaxMatrix(ROW_PIN, COL_PIN);
    Serial.println("Start display");
	  m8x8Dot->writeFull(m8x8Dot->getMouthShape(heart));  //选择要显示的表情
}

void loop() {
  // put your main code here, to run repeatedly:
   m8x8Dot->scan();  //不断扫描显示
}
