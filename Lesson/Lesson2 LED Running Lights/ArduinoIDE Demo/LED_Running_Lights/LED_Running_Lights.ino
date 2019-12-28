
int led_array[8] = { 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 } ;
int flash_speed = 500 ;

/* flash led form left to right one by one */
void led_flash(void)
{
    int i ;
    for( i = 0 ; i < 8 ; i++ )
    {
        digitalWrite(led_array[i],LOW);
        delay(flash_speed);
        digitalWrite(led_array[i],HIGH);
    }
}

/* turn on all led form left to right */
void led_turn_on(void)
{
    int i ;
    for( i = 0 ; i < 8 ; i++ )
    {
        digitalWrite(led_array[i],LOW);
        delay(flash_speed);
    }
}

/* turn off all led  */
void led_turn_off(void)
{
    int i ;
    for( i = 0 ; i < 8 ; i++ )
    {
        digitalWrite(led_array[i],HIGH);
        delay(flash_speed);
    }
}
void setup() {
  // put your setup code here, to run once:
    int i ;
    Serial.begin(9600);
    for( i = 0 ; i < 8 ; i++ )
    {
        pinMode(led_array[i],OUTPUT);
        digitalWrite(led_array[i],HIGH);    // set led control pin defalut HIGH turn off all LED
    }
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("start flash led !");
    led_flash();
	  led_turn_off();
    led_turn_on();
}
