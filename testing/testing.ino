void setup() {
  DDRB |= (1 << PB5); // sets PB5 as OUTPUT

  Serial.begin(9600);
}

void loop() {
  PORTB |= (1 << PB5); // sets PB5 (13 on arduino) to HIGH
  Serial.println(PORTB);
  
  delay(2000);

  PORTB &= ~(1 << PB5); // sets PB5 (13 on arduino) to LOW  
  Serial.println(PORTB);

  delay(1000);
}