/**********************************************
 * HelloWorld
 * 
 * www.yfrobot.com
 **********************************************/

#include <Wire.h> 
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
    lcd.init();                      // initialize the lcd
    // Print a message to the LCD.
    lcd.backlight();
    lcd.setCursor(2,0); // go to start of 2nd line
    lcd.print("Hello, world!");
    lcd.setCursor(4,1); // go to start of 2nd line
    lcd.print("keywish");
}

void loop()
{
}
