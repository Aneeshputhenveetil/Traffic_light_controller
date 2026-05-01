#include "Scheduler.h"


Task_t task[]=
{
  {100, 0, task1},
  {500, 0, task2},
  {1000, 0, task3}
};


static uint8_t led_flag1 = 0;
static uint8_t led_flag2 = 0;
static uint8_t led_flag3 = 0;


void Scheduler_Run(uint32_t current_time)
{
  for (int i = 0;i< 3; i++)
  {
    if((current_time - task[i].last_run) >=  task[i].period)
    {
      task[i].last_run = current_time;
      task[i].function();
    }
  }
}

void task1(void)
{
      if(led_flag1)
    {
      led_flag1 = 0;
      digitalWrite(LED_RED, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else
    {
      led_flag1 = 1;
      digitalWrite(LED_RED, LOW);    // turn the LED off by making the voltage LOW
    }
}

void task2(void)
{
    if(led_flag2)
    {
      led_flag2 = 0;
      digitalWrite(LED_YELLOW, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else
    {
      led_flag2 = 1;
      digitalWrite(LED_YELLOW, LOW);    // turn the LED off by making the voltage LOW
    }
}

void task3(void)
{
    if(led_flag3)
    {
      led_flag3 = 0;
      digitalWrite(LED_GREEN, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else
    {
      led_flag3 = 1;
      digitalWrite(LED_GREEN, LOW);    // turn the LED off by making the voltage LOW
    }
}
