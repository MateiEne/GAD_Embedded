ISR(TIMER1_COMPA_vect) {
  // command buzzer
  tone(PD7, 587.33); // D5
}

void setup() {
  // buzzer setup
  DDRD |= (1 << PD7); // set buzzer as OUTPUT
  
  // initialize timer
  cli();

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 31249; // compare match register 16Mhz / 256 / 2Hz-1
  TCCR1B |= (1 << WGM12); // CTC mode
  TCCR1B |= (1 << CS12); // 256 prescaler
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

  sei();
}

void loop() {
  // put your main code here, to run repeatedly:

}
