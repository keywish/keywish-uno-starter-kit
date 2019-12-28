#include "SegmentDisplay.h"

#define  LED_A   13       // define Arduino GPIO1 for led a
#define  LED_B   2       // define Arduino GPIO2 for led b
#define  LED_C   3       // define Arduino GPIO3 for led c
#define  LED_D   4       // define Arduino GPIO4 for led d
#define  LED_E   5       // define Arduino GPIO5 for led e
#define  LED_F   6       // define Arduino GPIO6 for led f
#define  LED_G   7       // define Arduino GPIO7 for led g
#define  LED_H   8       // define Arduino GPIO8 for led h

#define  LED_D1  9
#define  LED_D2  10
#define  LED_D3  11
#define  LED_D4  12

SegmentDisplay _4Bit_7SegmentDisplay(LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G, LED_H, LED_D1, LED_D2, LED_D3, LED_D4);
int ShowTime = 60, count = 0;

void setup()
{
    Serial.begin(9600);
    _4Bit_7SegmentDisplay.TurnOffAllLed();
}

void loop()
{
    if (count++ > 50 )
    {
        ShowTime-- ;
        count = 0 ;
        Serial.println(ShowTime);
    }
    _4Bit_7SegmentDisplay.DisplayChar((int)ShowTime);
    delay(5);
    if (ShowTime == 0) {
        _4Bit_7SegmentDisplay.TurnOffAllLed();
        while(1);
    }
}
