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
 * [Title]    lcd1602 8line mode.
 * [Diagram]
 *         Arduino PIN 2   ===================  lcd1602 pin 7(D0)
 *         Arduino PIN 3   ===================  lcd1602 pin 8(D1)
 *         Arduino PIN 4   ===================  lcd1602 pin 9(D2)
 *         Arduino PIN 5   ===================  lcd1602 pin 10(D3)
 *         Arduino PIN 6   ===================  lcd1602 pin 11(D4)
 *         Arduino PIN 7   ===================  lcd1602 pin 12(D5)
 *         Arduino PIN 8   ===================  lcd1602 pin 13(D6)
 *         Arduino PIN 9   ===================  lcd1602 pin 14(D7)
 *         Arduino PIN 10  ===================  lcd1602 pin 4(RS)
 *         Arduino PIN 11  ===================  lcd1602 pin 5(RW)
 *         Arduino PIN 12  ===================  lcd1602 pin 6(E)
 *         Arduino 3.3v    ===================  lcd1602 pin 15(A)
 *         Arduino GND     ===================  lcd1602 pin 16(K)
 *         Arduino GND     ===================  lcd1602 pin 1(VSS)
 *         Arduino 5V      ===================  lcd1602 pin 2(VDD)
 *         lcd1602 pin 3(VO)   ===  variable resistor(10k) ===  GND
 */

#define    DB0   2   // lcd1602 DB0
#define    DB1   3   // lcd1602 DB1
#define    DB2   4   // lcd1602 DB2
#define    DB3   5   // lcd1602 DB3
#define    DB4   6   // lcd1602 DB4
#define    DB5   7   // lcd1602 DB5
#define    DB6   8   // lcd1602 DB6
#define    DB7   9   // lcd1602 DB7

#define    LCD1602_RS   10
#define    LCD1602_RW   11
#define    LCD1602_E    12

const char LCD1602_DB[8] = { DB0 , DB1 , DB2 , DB3 , DB4 , DB5 , DB6 , DB7 } ;
void lcd1602_write_cmd(unsigned char cmd)
{
     int i ;
     for ( i = 0 ; i < 8 ; i++ )
     {
         digitalWrite( LCD1602_DB[i] ,cmd & ( 1 << i ));         //cmd hung on data pin
     }
     digitalWrite(LCD1602_RW , LOW ) ;     // write data
     digitalWrite(LCD1602_RS , LOW) ;     // cmd mode
     digitalWrite(LCD1602_E , LOW ) ;     // write data
     delayMicroseconds(1);
     digitalWrite(LCD1602_E, HIGH) ;       // enable
     delay(10);
     digitalWrite(LCD1602_E,LOW);
     delay(10);
}

void lcd1602_write_data(unsigned char dat)
{
     int i ;
     digitalWrite(LCD1602_RS , HIGH) ;     // data mode
     digitalWrite(LCD1602_RW , LOW ) ;     // write data
     for ( i = 0 ; i < 8 ; i++ )
     {
         digitalWrite( LCD1602_DB[i] ,dat & ( 1 << i ));         //cmd hung on data pin
     }
     digitalWrite(LCD1602_E, LOW) ;       // enable
     delay(10);
     digitalWrite(LCD1602_E, HIGH) ;       // enable
     delay(10);
     digitalWrite(LCD1602_E,LOW);
     delay(10);
}
void lcd1602_disp_str(int line , unsigned char *str)
{
    unsigned char addr ;
    if( line == 1 )
    {
        addr = 0x80 ;
    }else if( line == 2 )
    {
       addr = 0xc0 ;
    }
    lcd1602_write_cmd( addr ) ;
    while( *str++ != 0 )
    {
        lcd1602_write_data(*str);
    }
}
void lcd1602_init(void)
{
    lcd1602_write_cmd(0x38);  //CMD6 8-bit  ，2 line，5x7 word size
    delay(64);
    lcd1602_write_cmd(0x06);  //CMD3 input mode auto increase， no shift
    delay(20);
    lcd1602_write_cmd(0x0E);  //CM4  display setting  open lcd
    delay(20);
    lcd1602_write_cmd(0x01);  //CMD1 clean screen
    delay(100);
    lcd1602_write_cmd(0x80);  //CMD1 clean screen
    delay(100);
}
void setup() {
    // put your setup code here, to run once:
    int i = 0 ;
    Serial.begin(115200);

    for( i = 0 ; i < 8 ; i++)
    {
        pinMode(LCD1602_DB[i] , OUTPUT );
    }
    pinMode(LCD1602_RS,OUTPUT);
    pinMode(LCD1602_RW,OUTPUT);
    pinMode(LCD1602_E,OUTPUT);
    delay(100);
    Serial.println("Start display \n");
    lcd1602_init();
    Serial.println("Serial init end \n");
}

void loop() {
  // put your main code here, to run repeatedly:
    lcd1602_disp_str(1 ,(unsigned char *)"  Hello Ardunio !");
    lcd1602_disp_str(2 ,(unsigned char *)"  Hello Keywish !");
    Serial.println("lcd 1602 \n");
    while(1);
}
