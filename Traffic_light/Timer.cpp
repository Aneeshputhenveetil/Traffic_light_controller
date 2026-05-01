#include "Timer.h"
#include "Arduino.h"

static volatile uint32_t millis_counter = 0;

void Timer_Init(void)
{
  cli();                                // Disable global interrupts
  TCCR1A = 0;                           // Reset Timer1
  TCCR1B = 0;  
  TCCR1B |= (1 << WGM12);               // Set CTC mode (Clear Timer on Compare Match)
  TCCR1B |= (1 << CS11) | (1 << CS10);  // Set prescaler = 64
  OCR1A = 249;                          // Set compare match value for 1ms
  TIMSK1 |= (1 << OCIE1A);              // Enable Timer1 compare interrupt
  sei();                                // Enable global interrupts
}

uint32_t Timer_Get_Millis(void)
{
  uint32_t t;
  cli();
  t = millis_counter;
  sei();
  return t;
}

uint8_t Task_Delay(Task_Delay_t *task_delay, uint32_t delay_time)
{
  if(task_delay->running == 0)
  {
    task_delay->running = 1;
    task_delay->start_time = millis_counter;
  }
  if((millis_counter-task_delay->start_time) >= delay_time)
  {
    task_delay->start_time = millis_counter;
    return 1;
  }
  return 0;
}

void Timer_ISR (void)
{
  millis_counter++;
}

ISR(TIMER1_COMPA_vect)
{
  Timer_ISR();
}
