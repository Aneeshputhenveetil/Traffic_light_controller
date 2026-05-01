#include "Scheduler.h"
#include "Timer.h"


Task_t task[]=
{
  {10, 0, 1, light_task},
  {20, 0, 1, button_task},
};

TraficState_t state = STATE_RED;
Task_Delay_t light_delay = {0, 0};


void Scheduler_Run(uint32_t current_time)
{
  for (int i = 0;i< NUM_TASK; i++)
  {
    if((current_time - task[i].last_run) >=  task[i].period)
    {
      task[i].last_run = current_time;
      task[i].function();
    }
  }
}

void light_task(void)
{
  switch(state)
  {
    case STATE_RED:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      if(Task_Delay(&light_delay, 5000))
      {
        state = STATE_RED_YELLOW;
      }
    break;
    case STATE_RED_YELLOW:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, LOW);
      if(Task_Delay(&light_delay, 2000))
      {
        state = STATE_GREEN;
      }
    break;
    case STATE_GREEN:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, HIGH);
      if(Task_Delay(&light_delay, 5000))
      {
        state = STATE_YELLOW;
      }
    break;
    case STATE_YELLOW:
       digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, LOW);
      if(Task_Delay(&light_delay, 2000))
      {
        state = STATE_RED;
      }
    break;
  }


}

void button_task(void)
{
//  if(Task_Delay(&delay2, 500))
//  {
//    digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW));  // toggle LED
//  }
}
