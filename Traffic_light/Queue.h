#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdint.h>

typedef enum{
  EVENT_NONE,
  EVENT_BUTTON_PRESS
}Event_Type_t;


typedef struct{
  Event_Type_t event;
  uint8_t data;
}Event_t;

#define QUEUE_SIZE 8

void Queue_Init(void);
uint8_t Queue_Push(Event_t evt);
uint8_t Queue_Pop(Event_t *evt);
uint8_t Queue_IsEmpty();




#endif
