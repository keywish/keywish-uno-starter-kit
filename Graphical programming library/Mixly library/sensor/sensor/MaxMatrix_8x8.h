/*
 * MaxMatrix_8x8
 * Version 1.0 Feb 2013
 * Copyright 2013 Oscar Kin-Chung Au
 */

#ifndef _MaxMatrix_8x8_H_
#define _MaxMatrix_8x8_H_

#include "Arduino.h"
#include "Mouths.h"

class MaxMatrix_8x8
{
  private:

    byte buffer[8];
    byte col_pin[8], row_pin[8];
    void reload();
	
  public:
    MaxMatrix_8x8(byte col[8], byte row[8]);
    void scan();
    void init();
    void clearMatrix();
    void setDot(byte col, byte row, byte value);
    void writeFull(unsigned long value);
    unsigned long int getMouthShape(int number);
};

#endif
