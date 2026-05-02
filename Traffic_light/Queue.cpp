#include "Queue.h"
#include "Arduino.h"

static Event_t event[QUEUE_SIZE];
static uint8_t head;
static uint8_t tail;
static uint8_t count;

void Queue_Init(void){
  head = 0;
  tail = 0;
  count = 0;
}

uint8_t Queue_Push(Event_t evt){
  if(count >= QUEUE_SIZE)
  {
    return 0;
  }
  
  event[tail] = evt;
  tail = (tail + 1) % QUEUE_SIZE;
  
  cli();
  count++;
  sei();
  return 1;
}

uint8_t Queue_Pop(Event_t *evt){
  if(count == 0)
  {
    return 0;
  }
  *evt = event[head];
  head = (head+1) % QUEUE_SIZE;
  cli();
  count--;
  sei();
  return 1;
}

uint8_t Queue_IsEmpty(){
  return (count == 0);
}
