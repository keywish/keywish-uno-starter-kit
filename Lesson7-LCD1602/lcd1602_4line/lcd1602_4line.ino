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
 * [Title]    lcd1602 display string .
 * [Diagram]

 *         Arduino PIN 6   ===================  lcd1602 pin 11
 *         Arduino PIN 7   ===================  lcd1602 pin 12
 *         Arduino PIN 8   ===================  lcd1602 pin 13
 *         Arduino PIN 9   ===================  lcd1602 pin 14
 *         Arduino PIN 10  ===================  lcd1602 pin 4
 *         Arduino PIN 11  ===================  lcd1602 pin 5
 *         Arduino PIN 12  ===================  lcd1602 pin 6
 */

#define    DB4   6   // lcd1602 DB4
#define    DB5   7   // lcd1602 DB5
#define    DB6   8   // lcd1602 DB6
#define    DB7   9   // lcd1602 DB7

#define    LCD1602_RS   10
#define    LCD1602_RW   11
#define    LCD1602_E    12

const char LCD1602_DB[4] = { DB4 , DB5 , DB6 , DB7 } ;
void lcd1602_write_cmd(unsigned char cmd)
{
    int i ;
    int tmp = cmd & 0xF0 ;               //get cmd high 4bit
    for( i = 0 ; i < 4 ; i++ )
    {
       digitalWrite( LCD1602_DB[i] ,tmp & ( 1 << i ));         //cmd hung on data pin
    }
    digitalWrite(LCD1602_RS , LOW) ;      // cmd mode
    digitalWrite(LCD1602_RW , LOW ) ;     // write data
    digitalWrite(LCD1602_E, HIGH) ;       // enable
    delay(10);
    digitalWrite(LCD1602_E,LOW);
    delay(10) ;

    int tmp = (cmd & 0x0F) << 4 ;               //get cmd high 4bit
    for( i = 0 ; i < 4 ; i++ )
    {
       digitalWrite( LCD1602_DB[i] ,tmp & ( 1 << i ));         //cmd hung on data pin
    }
    digitalWrite(LCD1602_RS , LOW) ;      // cmd mode
    digitalWrite(LCD1602_RW , LOW ) ;     // write data
    digitalWrite(LCD1602_E, HIGH) ;       // enable
    delay(10);
    digitalWrite(LCD1602_E,LOW);
    delay(10) ;
}

void lcd1602_write_data(unsigned char dat)
{
    int i ;
    int temp = dat&0xF0;
    for ( i = 0 ; i < 4 ; i++ )
    {
        digitalWrite( LCD1602_DB[i] ,temp & ( 1 << i ));         //cmd hung on data pin
    }
    digitalWrite(LCD1602_RS , HIGH) ;     // data mode
    digitalWrite(LCD1602_RW , LOW ) ;     // write data
    digitalWrite(LCD1602_E, HIGH) ;       // enable
    delay(10);
    digitalWrite(LCD1602_E,LOW);
    delay(10) ;
    temp = (dat&0x0F)<< 4;
    for ( i = 0 ; i < 4 ; i++ )
    {
        digitalWrite( LCD1602_DB[i] ,temp & ( 1 << i ));         //cmd hung on data pin
    }
    digitalWrite(LCD1602_RS , HIGH) ;     // data mode
    digitalWrite(LCD1602_RW , LOW ) ;     // write data
    digitalWrite(LCD1602_E, HIGH) ;       // enable
    delay(10);
    digitalWrite(LCD1602_E,LOW);
    delay(10) ;
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
    lcd1602_write_cmd(0x38);  //CMD6 8-bit  ，2 line display，5x7 word size
    delay(20);
    lcd1602_write_cmd(0x06);  //CMD3 input mode auto increase， no shift
    delay(20);
    lcd1602_write_cmd(0x0E);  //CM4  display setting  open lcd
    delay(20);
    lcd1602_write_cmd(0x01);  //CMD1 clean screen
    delay(100);
}

void setup() {
    // put your setup code here, to run once:
    int i = 0 ;
    Serial.begin(115200);

    for( i = 0 ; i < 4 ; i++)
    {
        pinMode(LCD1602_DB[i] , OUTPUT );
    }
    pinMode(LCD1602_RS,OUTPUT);
    pinMode(LCD1602_RW,OUTPUT);
    pinMode(LCD1602_E,OUTPUT);
    delay(100);
    lcd1602_init();
    Serial.println("Start display \n");
}

void loop() {
  // put your main code here, to run repeatedly:
    lcd1602_disp_str(1 ," Hello Ardunio ! ");
    lcd1602_disp_str(2 ," made by keywish! ");
    while(1);
}
