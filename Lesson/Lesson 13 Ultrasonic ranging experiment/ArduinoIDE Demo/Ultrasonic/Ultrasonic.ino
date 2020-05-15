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
 * [Title]
 * [Diagram]
 *         Arduino PIN 2   ===================  TrigPin
 *         Arduino PIN 3   ===================  EchoPin
 */
const int TrigPin = 2; // define TrigPin to pin 2
const int EchoPin = 3;  // Define EchoPin to pin 3
float distance;
void setup()
{
    Serial.begin(9600); // Set the serial port baud rate to 9600
    pinMode(TrigPin, OUTPUT); // Set the TrigPin pin to output mode
    pinMode(EchoPin, INPUT); // Set the EchoPin pin to output mode
    Serial.println("Ultrasonic sensor:");  // Print character Ultrasonic sensor:
}
void loop()
{
    digitalWrite(TrigPin, LOW); // Set the TrigPin pin to low level
    delayMicroseconds(2); // Delay 2 microseconds
    digitalWrite(TrigPin, HIGH);   // Set the TrigPin pin to high level
    delayMicroseconds(10); // Delay 10 microseconds
    digitalWrite(TrigPin, LOW);  // Set the TrigPin pin to low level
    distance = pulseIn(EchoPin, HIGH) / 58.00; // Calculate distance
    Serial.print("distance is :");  // print character distance is:
    Serial.print(distance); // print distance value
    Serial.print("cm"); // print character cm
    Serial.println();
    delay(1000); // Delay 1 second
}
