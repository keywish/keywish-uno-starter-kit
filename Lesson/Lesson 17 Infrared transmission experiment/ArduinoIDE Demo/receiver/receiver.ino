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
 *         Arduino PIN 11   ===================  Infrared transmitter module pin Y
 *         Arduino PIN GND  ===================  Infrared transmitter module pin G
 *         Arduino PIN +5V  ===================  Infrared transmitter module pin R
 */
// This example comes from IRremote's own example of infrared receiving module
// The modification has been made
// Change to when the button of the remote control is pressed, the light-emitting LED connected to the digital pin 4 will light up, press the button again, the LED goes out
/** 
Circuit connection
* The VOUT of the infrared receiver is connected to the digital pin 11, GND is connected to the GND of the control board, and VCC is connected to + 5V on the control board
* The LED pin is connected to digital pin 4 and returns to the GND of the control board through a 220 ohm resistor
* Effect, when the remote control presses the button, the LED will flash, and the command code of the button will appear on the serial port of the computer.
**/
#include "IRremote.h"
  
int RECV_PIN = 12; // Define the pin of infrared receiver as 12
int LED_PIN = 4;  // Define the light-emitting LED pin number 4
int a = 0;
IRrecv irrecv(RECV_PIN);
  
decode_results results;
  
void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();     // Initialize the infrared receiver
    pinMode(LED_PIN,OUTPUT); // Set the luminous LED pin number 4
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        if(results.value == 0x4CB3817E & a == 0) // The 32-bit value here must be consistent with the value transmitted by the transmitting part
        {
            digitalWrite(LED_PIN,HIGH);// LED lights up
            a=1;
        }
        else if(results.value == 0x4CB3817E & a == 1)
        {
            digitalWrite(LED_PIN,LOW);// LED off
            a=0;
        }
        irrecv.resume(); // Receive the next value
    }
    delay(120);
}
