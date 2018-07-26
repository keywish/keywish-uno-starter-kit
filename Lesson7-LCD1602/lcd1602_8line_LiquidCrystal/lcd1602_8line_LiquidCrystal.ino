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
 * [Title]    lcd1602 8line mode
 * [Diagram]
 *         Arduino PIN 2   ===================  lcd1602 pin 7
 *         Arduino PIN 3   ===================  lcd1602 pin 8
 *         Arduino PIN 4   ===================  lcd1602 pin 9
 *         Arduino PIN 5   ===================  lcd1602 pin 10
 *         Arduino PIN 6   ===================  lcd1602 pin 11
 *         Arduino PIN 7   ===================  lcd1602 pin 12
 *         Arduino PIN 8   ===================  lcd1602 pin 13
 *         Arduino PIN 9   ===================  lcd1602 pin 14
 *         Arduino PIN 10  ===================  lcd1602 pin 4
 *         Arduino PIN 11  ===================  lcd1602 pin 5
 *         Arduino PIN 12  ===================  lcd1602 pin 6
 */

#define    DB0   2   // lcd1602 DB0
#define    DB1   3   // lcd1602 DB1
#define    DB2   4   // lcd1602 DB2
#define    DB3   5   // lcd1602 DB3
#define    DB4   6   // lcd1602 DB4
#define    DB5   7   // lcd1602 DB5
#define    DB6   8   // lcd1602 DB6
#define    DB7   9   // lcd1602 DB7

#define    LCD1602_RS   10
#define    LCD1602_RW   11
#define    LCD1602_E    12

#include<LiquidCrystal.h>
LiquidCrystal lcd(LCD1602_RS,LCD1602_RW,D0,D1,D2,D3,D4,D5,D6,D7);        　　 //init lcd data pin and control pin
void setup(){
    lcd.begin(16,2);                              　　   //8-bit  ，2 line display
}
 void loop(){
     lcd.clear();                                　　　　//clean
     lcd.setCursor(5,0);
     lcd.print("Hello Ardunio ! ");
     delay(10);
     lcd.setCursor(2,1);
     lcd.print("made by keywish!");
     while(1);
 }
