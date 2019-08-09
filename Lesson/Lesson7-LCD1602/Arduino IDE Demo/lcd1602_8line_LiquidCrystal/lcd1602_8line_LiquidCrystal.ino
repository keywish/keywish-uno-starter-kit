/*
  LiquidCrystal Library - Autoscroll

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch demonstrates the use of the autoscroll()
 and noAutoscroll() functions to make new text scroll or not.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalAutoscroll

*/
#define    DB0   2   // lcd1602 DB0
#define    DB1   3   // lcd1602 DB1
#define    DB2   4   // lcd1602 DB2
#define    DB3   5   // lcd1602 DB3
#define    DB4   6   // lcd1602 DB4
#define    DB5   7   // lcd1602 DB5
#define    DB6   8   // lcd1602 DB6
#define    DB7   9    // lcd1602 DB7

#define    LCD1602_RS   10  
#define    LCD1602_RW   11 
#define    LCD1602_E    12

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

LiquidCrystal lcd(LCD1602_RS,LCD1602_RW,LCD1602_E,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to (0,0):
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Hello Ardunio ! ");
    delay(10); 
    lcd.setCursor(2,1);
    lcd.print(" keywish! ");
   while(1);
  }
