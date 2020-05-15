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

*/
#include <Servo.h>
   Servo myservo; // Define servo objects, up to eight
   int pos = 0;   // Define the turning position of the servo
   void setup()
   {
      myservo.attach(7);  // Set the servo control pin
   }
   void loop()
  {
      // Rotate the servo from 0 to 180 with a delay of 15 ms each
      for(pos = 0; pos < 180; pos += 1)  
     {  
        myservo.write(pos);  
        delay(15);
      }
     // Rotate the servo from 180 to 0 with a delay of 15 ms each
      for(pos = 180; pos>=1; pos-=1)
      {                              
        myservo.write(pos);
        delay(15);
      }
  }
