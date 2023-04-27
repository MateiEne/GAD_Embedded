#include "TimerOne.h"

void callback() {
  PORTB ^= (1 << PB5);
}

void setup() {
  DDRB |= (1 << PB5);

  Timer1.initialize(500000); // initialize timer1, and set a 1/2 second period
  Timer1.attachInterrupt(callback);
}

void loop() {
  // put your main code here, to run repeatedly:

}
