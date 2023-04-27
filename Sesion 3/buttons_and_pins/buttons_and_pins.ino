unsigned long delay_curent = 1000;

void setup() {
  DDRB |= (1 << PB5);
  DDRD &= ~(1 << PD2);
  DDRD &= ~(1 << PD3);
  PORTD |= (1 << PD2) | (1 << PD3);  // pull-up activez pinii unde sunt butoanele
  Serial.begin(9600);
}

void loop() {
  // verific buton incrementare apasat
    if ((PIND & (1 << PD2)) == 0) { 
      delay_curent += 500;
      Serial.print("Delay:");
      Serial.print(delay_curent);
      Serial.println(" ms");
    }


  // buton decrementare apasat
    if ((PIND & (1 << PD3)) == 0) {
      if (delay_curent > 50) {
        delay_curent -= 500; 
        Serial.print("Delay: ");
        Serial.print(delay_curent);
        Serial.println(" ms");
      }
    }

  delay(delay_curent);
  PORTB ^= (1 << PB5); //pastrez starea 
 //cat mentin buton apasat
  //if ((millis() - delay_anterior) >= delay_curent) {
  //  delay_anterior = millis();
   // PORTB ^= (1 << ledPin); //pastrez starea 
  }