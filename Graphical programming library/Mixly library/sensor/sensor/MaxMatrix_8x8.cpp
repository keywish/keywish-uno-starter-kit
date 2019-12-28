/*
 * MaxMatrix_8x8
 * Version 1.0 Feb 2013
 * Copyright 2013 Oscar Kin-Chung Au
 */


#include "Arduino.h"
#include "MaxMatrix_8x8.h"

MaxMatrix_8x8::MaxMatrix_8x8(byte col[8], byte row[8])
{
	  byte i;
    Serial.println("MaxMatrix_8x8\n");
    for (i = 0; i < 8; i++)
    { 
        col_pin[i] = col[i];
        row_pin[i] = row[i];
        pinMode(row_pin[i] , OUTPUT );
        pinMode(col_pin[i] , OUTPUT );
    }
    clearMatrix();
}

void MaxMatrix_8x8::init()
{
	// empty registers, turn all LEDs off
	clearMatrix();
}

void MaxMatrix_8x8::clearMatrix()
{
	  byte i;
    for (i = 0; i < 8; i++)
    {
		    buffer[i] = 0;
        digitalWrite(row_pin[i],LOW);
        digitalWrite(col_pin[i],LOW);
    }
}

void MaxMatrix_8x8::setDot(byte col, byte row, byte value)
{
    bitWrite(buffer[col], row, value);
}

void MaxMatrix_8x8::scan()
{
    byte i, j;
     for (j = 0; j < 8; j++)
     {
        for (i = 0; i < 8; i++)
        {
            if (bitRead(buffer[j], i))
            digitalWrite(row_pin[i], LOW);
            else
            digitalWrite(row_pin[i], HIGH);
        }
        digitalWrite(col_pin[j], HIGH);
        delay(2);
        digitalWrite(col_pin[j], LOW);
    }
}

void MaxMatrix_8x8::writeFull(unsigned long value) {
    for (int r = 0; r < 5; r++){
        for (int c = 0; c < 6; c++) {
            setDot(6-c, 6-r, (1L & (value >> r*6+c)));
        }
    }
      for ( byte j = 0; j < 8; j++) {

        Serial.println(buffer[j], BIN);
      }
}

unsigned long int MaxMatrix_8x8::getMouthShape(int number) {
  unsigned long int types []= {zero_code,one_code,two_code,three_code,four_code,five_code,six_code,seven_code,eight_code,
  nine_code,smile_code,happyOpen_code,happyClosed_code,heart_code,bigSurprise_code,smallSurprise_code,tongueOut_code,
  vamp1_code,vamp2_code,lineMouth_code,confused_code,diagonal_code,sad_code,sadOpen_code,sadClosed_code,
  okMouth_code, xMouth_code,interrogation_code,thunder_code,culito_code,angry_code};

  return types[number];
}
