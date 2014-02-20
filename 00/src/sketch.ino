#include <avr/io.h>

void setup()
{
  DDRB = 0b00100001;  // Data Direction Register for port B
  PORTB = 0b00000000; // setting high-low values



  TCCR1B |= 1<<CS10;  // setting CS10 bit only, meaning no prescaling

  while(1)
  {
      if (TCNT1 > 2232)
      {
        TCNT1 = 0;

        PORTB ^= 0b00100001;  // xor is useful as it can toggle
                              // PINB0 is a macro for the number of shifts in
                              // order to write to PINB0
      }
        PORTB ^= 0b00100001;  // xor is useful as it can toggle
  }

}

void loop()
{
  delay(1000);
}
