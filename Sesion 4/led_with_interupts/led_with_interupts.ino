volatile unsigned int interval = 300;
volatile unsigned int intUltimulMoment = 0;
volatile unsigned int pcintUltimulMoment = 0;

//întreruperi externe pe PD2 (INT0) și PD4 (PCINT2_vect)
ISR(INT0_vect) {
  if (millis() > intUltimulMoment + interval) {
    intUltimulMoment = millis();
    PORTD ^= (1 << PD7);
  }
}

ISR(PCINT2_vect) {
  if (((PIND & (1 << PD4)) == 0) && (millis() > intUltimulMoment + interval)) {
    pcintUltimulMoment = millis();
    PORTD ^= (1 << PD7);
  }
}

void setup() {
  // put your setup code here, to run once:
  DDRD |= (1 << PD7);

  DDRD &= ~((1 << PD2) | (1 << PD4));
  PORTD |= ((1 << PD2) | (1 << PD4));

  cli();

  EICRA |= (1 << ISC01);
  EIMSK |= (1 << INT0);

  PCICR |= (1 << PCIE2);
  PCMSK2 |= (1 << PCINT20);

  sei();
}

void loop() {
}
