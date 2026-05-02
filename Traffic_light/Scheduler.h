#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Arduino.h"
#include <stdint.h>

#define NUM_TASK (sizeof(task) / sizeof(task[0]))

#define LED_RED 14
#define LED_YELLOW 15
#define LED_GREEN 16

typedef struct
{
  uint32_t period;
  uint32_t last_run;
  uint8_t priority;
  void (*function)(void);
}Task_t;

typedef enum{
  STATE_RED,
  STATE_RED_YELLOW,
  STATE_GREEN,
  STATE_YELLOW
}TraficState_t;

extern Task_t task[];           // expose the table so main can see it

void light_task(void);
void button_task(void);

void Scheduler_SortByPriority(void);
void Scheduler_Run(uint32_t current_time);

#endif
