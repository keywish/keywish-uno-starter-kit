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
 * [Title]    product two frequeces sound
 * [diagram]
 *           Arduino  pin8  ===================   buzzer positive wire
 *
 */
int buzzer = 9;

void setup()
{
    pinMode(buzzer, OUTPUT);
}

void loop() 
{
    for (int i=0; i<800; i++)  // 1k HZ
    {
        //设置频率声音
        digitalWrite(buzzer, HIGH);  
        delay(0.5);
        digitalWrite(buzzer, LOW);
        delay(0.5);
    }
    delay(1000);
    for (int i=0;i<800;i++)   // 250 HZ
    {
        //设置频率声音
        digitalWrite(buzzer, HIGH);  
        delay(2);
        digitalWrite(buzzer, LOW);
        delay(2);
    }
    delay(1000);
}

