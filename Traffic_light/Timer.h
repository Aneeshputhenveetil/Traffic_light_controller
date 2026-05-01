#ifndef TIMER_H_
#define TIMER_H_

#include<stdint.h>

void Timer_Init(void);
void Timer_ISR (void);
uint32_t Timer_Get_Millis(void);


#endif
