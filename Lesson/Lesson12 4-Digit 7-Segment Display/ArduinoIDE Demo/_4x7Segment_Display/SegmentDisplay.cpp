#include "SegmentDisplay.h"

SegmentDisplay::SegmentDisplay(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t h)
{
    mode = SEGMENT_DISPLY_1BIT;
    dight_pin[0] = a;
    dight_pin[1] = b;
    dight_pin[2] = c;
    dight_pin[3] = d;
    dight_pin[4] = e;
    dight_pin[5] = f;
    dight_pin[6] = g;
    dight_pin[7] = h;
    dight_display[0] = DIGHT_NUMBLE(0);
    dight_display[1] = DIGHT_NUMBLE(1);
    dight_display[2] = DIGHT_NUMBLE(2);
    dight_display[3] = DIGHT_NUMBLE(3);
    dight_display[4] = DIGHT_NUMBLE(4);
    dight_display[5] = DIGHT_NUMBLE(5);
    dight_display[6] = DIGHT_NUMBLE(6);
    dight_display[7] = DIGHT_NUMBLE(7);
    dight_display[8] = DIGHT_NUMBLE(8);
    dight_display[9] = DIGHT_NUMBLE(9);

    for (int i = 0; i < 8; i++) {
        pinMode(dight_pin[i], OUTPUT);  //set all led diplay array pin output mode
        digitalWrite(dight_pin[i], LOW);
    }
}

SegmentDisplay::SegmentDisplay(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t h, uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4)
{
    mode = SEGMENT_DISPLY_4BIT;
    dight_pin[0] = a;
    dight_pin[1] = b;
    dight_pin[2] = c;
    dight_pin[3] = d;
    dight_pin[4] = e;
    dight_pin[5] = f;
    dight_pin[6] = g;
    dight_pin[7] = h;
    dight_display[0] = DIGHT_NUMBLE(0);
    dight_display[1] = DIGHT_NUMBLE(1);
    dight_display[2] = DIGHT_NUMBLE(2);
    dight_display[3] = DIGHT_NUMBLE(3);
    dight_display[4] = DIGHT_NUMBLE(4);
    dight_display[5] = DIGHT_NUMBLE(5);
    dight_display[6] = DIGHT_NUMBLE(6);
    dight_display[7] = DIGHT_NUMBLE(7);
    dight_display[8] = DIGHT_NUMBLE(8);
    dight_display[9] = DIGHT_NUMBLE(9);

    dight_select_pin[0] = d1;
    dight_select_pin[1] = d2;
    dight_select_pin[2] = d3;
    dight_select_pin[3] = d4;

    for (int i = 0; i < 8; i++) {
        pinMode(dight_pin[i], OUTPUT);  //set all led diplay array pin output mode
        digitalWrite(dight_pin[i], LOW);
    }
    for (int i = 0; i < 4; i++) {
        pinMode(dight_select_pin[i], OUTPUT);  //set all led diplay array pin output mode
        digitalWrite(dight_select_pin[i], LOW);
    }
}

void SegmentDisplay::TurnOffAllLed(void)
{
    for (int i = 0; i < 8; i++)
    digitalWrite(dight_pin[i], HIGH);
    if (mode == SEGMENT_DISPLY_4BIT) {
        for (int i = 0; i < 4; i++)
        digitalWrite(dight_select_pin[i], LOW);
    }
}
void SegmentDisplay::numble2dis(int numble)
{
    int numble_bit = 0;
    int bit_base = 1000;
    for (numble_bit = 0; numble_bit < 4; numble_bit++ )
    {
        if (numble/bit_base != 0)
        {
            display_array[numble_bit] = numble/bit_base;    // integer date convert to ASCII
            numble = numble%bit_base;
        }else
        {
            display_array[numble_bit] = 0;                 // led display none
        }
        bit_base = bit_base / 10;
    }
}

void SegmentDisplay::DisplayChar(byte n)
{
    byte ch = dight_display[n];
    if (n < 10) {
        for (byte i = 0; i < 8; i++) {
            if (ch & (1 << i)) {
                digitalWrite(dight_pin[i], HIGH);
            } else {
                digitalWrite(dight_pin[i], LOW);
            }
        }
    }
}

void SegmentDisplay::DisplayChar(int n)
{
    if (mode == SEGMENT_DISPLY_4BIT) {
        numble2dis(n);
        for(int i = 0; i < 4; i++) {
            DisplayChar((byte)display_array[i]);
            digitalWrite(dight_select_pin[i], HIGH);
            delay(5);
            digitalWrite(dight_select_pin[i], LOW); // you must turn off
        }
    }
}

void SegmentDisplay::DisplayChar(byte sel, byte n)
{
    byte ch = dight_display[n];
    for (byte i = 0; i < 8; i++) {
        if (ch & (1 << i)) {
            digitalWrite(dight_pin[i], HIGH);
        } else {
            digitalWrite(dight_pin[i], LOW);
        }
    }
    digitalWrite(dight_select_pin[sel] ,HIGH );
}
