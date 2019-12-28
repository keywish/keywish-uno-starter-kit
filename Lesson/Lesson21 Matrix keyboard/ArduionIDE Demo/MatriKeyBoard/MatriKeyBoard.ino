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
 * [Title] arduino matri keypad detect
 * [Diagram]
 *         Arduino PIN 4   ===================  Matril keypad 1
 *         Arduino PIN 5   ===================  Matril keypad 2
 *         Arduino PIN 6   ===================  Matril keypad 3
 *         Arduino PIN 7   ===================  Matril keypad 4
 *         Arduino PIN 8   ===================  Matril keypad 5
 *         Arduino PIN 9   ===================  Matril keypad 6
 *         Arduino PIN 10  ===================  Matril keypad 7
 *         Arduino PIN 11  ===================  Matril keypad 8
*/

#include "Keypad.h"

#define   ROW_1   4
#define   ROW_2   5
#define   ROW_3   6
#define   ROW_4   7
#define   COL_1   8
#define   COL_2   9
#define   COL_3   10
#define   COL_4   11

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//connect to the row pinouts of the keypad
byte rowPins[ROWS] = {ROW_1, ROW_2, ROW_3, ROW_4};
//connect to the column pinouts of the keypad
byte colPins[COLS] = {COL_1, COL_2, COL_3, COL_4};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
    int i ;
    for(i=0 ; i< ROWS ; i++)
    {
        pinMode(rowPins[i],OUTPUT);
        pinMode(colPins[i],OUTPUT);
    }
    Serial.begin(115200);
}

void loop(){
    char customKey = customKeypad.getKey();
    if (customKey){
        Serial.println(customKey);
    }
}
