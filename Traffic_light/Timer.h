#ifndef TIMER_H_
#define TIMER_H_

#include<stdint.h>

typedef struct{
  uint32_t start_time;
  uint32_t running;
}Task_Delay_t;

void Timer_Init(void);
void Timer_ISR (void);
uint8_t Task_Delay(Task_Delay_t *task_delay, uint32_t delay_time);
uint32_t Timer_Get_Millis(void);

#endif
