/***********************************************************************
         __                                                          _
        / /        _____  __    __  _          _   (_)   ________   | |
       / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
      / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
     / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
    / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
   /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|


   KeyWay Tech firmware

   Copyright (C) 2015-2020

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation, in version 3.
   learn more you can see <http://www.gnu.org/licenses/>.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.


   [Title]    Temperature-Humidity Sensor
*/
#include <Wire.h>
#include"dht11.h"
#include "LiquidCrystal_I2C.h"

#define    DHT11PIN     8
dht11 DHT11;
LiquidCrystal_I2C lcd(0x27, 16, 2);// 0x27 is the I2C bus address for an unmodified backpack
void setup() {
  pinMode(DHT11PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  lcd.setCursor(0, 0);
  lcd.print("Tep: ");
  lcd.print((float)DHT11.temperature, 2);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print((float)DHT11.humidity, 2);
  lcd.print("%");
  delay(200);
}
