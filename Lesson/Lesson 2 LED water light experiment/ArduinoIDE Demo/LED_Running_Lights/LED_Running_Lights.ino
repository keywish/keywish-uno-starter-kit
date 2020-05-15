void setup() {
  //Set LED control pin to default high level / turn off all LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT); 
}

void loop()  {
  //Open all leds from left to right
  digitalWrite(2, 0);
  delay(500);
  digitalWrite(2, 1);
  digitalWrite(3, 0);
  delay(500);
  digitalWrite(3, 1);
  digitalWrite(4, 0);
  delay(500);
  digitalWrite(4, 1);
  digitalWrite(5, 0);
  delay(500);
  digitalWrite(5, 1);
  digitalWrite(6, 0);
  delay(500);
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  delay(500);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  delay(500);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  delay(500);
  digitalWrite(9, 1);   
}

