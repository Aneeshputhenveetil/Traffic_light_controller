#include "Timer.h"
#include "Arduino.h"

static uint32_t millis_counter = 0;

void Timer_Init(void)
{
    cli(); // Disable global interrupts

  // Reset Timer1
  TCCR1A = 0;
  TCCR1B = 0;

  // Set CTC mode (Clear Timer on Compare Match)
  TCCR1B |= (1 << WGM12);

  // Set prescaler = 64
  TCCR1B |= (1 << CS11) | (1 << CS10);

  // Set compare match value for 1ms
  OCR1A = 249;

  // Enable Timer1 compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei(); // Enable global interrupts
}

uint32_t Timer_Get_Millis(void)
{
  return millis_counter;
}

void Timer_ISR (void)
{
  millis_counter++;
}

ISR(TIMER1_COMPA_vect)
{
  Timer_ISR();
}
