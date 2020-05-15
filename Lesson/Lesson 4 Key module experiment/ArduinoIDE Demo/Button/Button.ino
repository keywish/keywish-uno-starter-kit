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
 * [Title]    keypad control led light
 * [diagram]
 *         Arduino PIN 11  ===================  led control gpio
 *         Arduino PIN 7   ===================  keypad pin
 */

void setup()
{
    pinMode(11,OUTPUT);          // Initialize the LED pin output
    pinMode(7,INPUT);          // Initialize key pin input
    digitalWrite(11,LOW);
    
}
void loop()
{
      if (digitalRead(7) == LOW)
        {
          delay(20);         // Delay to eliminate button jitter
          if (digitalRead(7) == LOW)
            {
                digitalWrite(11, LOW);  // If key DigitalRead (7) is not pressed, turn off the LED
              }
            else
            {
                digitalWrite(11, HIGH); // If key DigitalRead (7) is pressed, turn on the LED
              }
          }
  }
