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


#include "IRremote.h"                    // 引用 IRRemote 函式库
const int buttonPin = 4;                 // 按键(pushbutton)接在 pin 4
int buttonState = 0;                     // 按键状态
IRsend irsend;                          // 定义 IRsend 物件来发射红外线讯号

void setup()
{
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);             // 把 buttonPin 设置成 输入
}
                             
void loop()
{
  	// 读取按键状态
  	buttonState = digitalRead(buttonPin);
  	// 检查按键是否被按下
  	// 有的话 buttonState 会是高电平输出
  	if (buttonState == HIGH) {
  	    // 发射红外线讯号
        Serial.println("button");
    		irsend.sendNEC(0x4CB3817E, 32);   // 这个编码即你按的键（接pin4）的编码，可以随意更改，如果要控制其他设备，只需将此编码改为相应编码就行
  	}
    delay(200);
}
