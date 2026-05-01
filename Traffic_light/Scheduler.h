#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Arduino.h"
#include <stdint.h>

#define LED_RED 14
#define LED_YELLOW 15
#define LED_GREEN 16


void task1(void);
void task2(void);
void task3(void);

typedef struct
{
  uint32_t period;
  uint32_t last_run;
  void (*function)(void);
}Task_t;

void Scheduler_Run(uint32_t current_time);


#endif
