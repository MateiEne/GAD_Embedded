void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << PB5);

  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0 = 0;

  TCCR0A |= 1 << COM0A0;
  TCCR0A |= 1 << WGM01;

  OCR0A = 0x80;
  TCCR0B = 3 << CS00;

  Serial.begin(96000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (TCNT0 == OCR0A) {
    Serial.println("intrat");

    TIFR0 ^= (1 << OCF0A);

    PORTB |= (1 << PB5);
  }

  PORTB &= ~(1 << PB5);
}

// void setup()
// {
//   DDRD |= (1 <<PD6);
//   TCCR0A =0;
//   TCCR0B = 0;
//   TCNT0 = 0;

//   TCCR0A |= (1 <<COM0A0);
//   TCCR0B |= (1 <<WGM01);

//   OCR0A = 0x80;
//   TCCR0B |= (3<<CS00);
//   Serial.begin(9600);
// }

// void loop()
// {
//   if((TIFR0 & (1 << OCF0A)) != 0) // Verifica daca s-a produs evenimentul
//   {
//     Serial.println("A intrat");
//     PORTD ^= (1 << PD6); // Aprinde becul
//     TIFR0 |= (1 << OCF0A); // Reseteaza flag-ul de comparatie
//   }
// }
