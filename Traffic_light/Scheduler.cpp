#include "Scheduler.h"
#include "Timer.h"
#define PRIORITY_LOW     3
#define PRIORITY_MEDIUM  2
#define PRIORITY_HIGH    1

Task_t task[]=
{
  {20, 0, PRIORITY_MEDIUM, light_task},
  {10, 0, PRIORITY_HIGH, button_task},
};

TraficState_t state = STATE_RED;
Task_Delay_t light_delay = {0, 0};


void Scheduler_SortByPriority(void)
{
  for(int i= 1;i< NUM_TASK;i++)
  {
    Task_t tmp = task[i];
    int j = i-1;
    while(j>=0 && task[j].priority > tmp.priority)
    {
      task[j+1] = task[j];
      j--;
    }
    task[j+1] = task[j];
  }
}


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
