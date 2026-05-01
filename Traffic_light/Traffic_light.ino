/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#define LED_RED 14
#define LED_YELLOW 15
#define LED_GREEN 16

#include "Timer.h"
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
  Timer_Init();
}


static uint32_t current_time = 0;

static uint32_t led_count = 0;
static uint8_t led_flag = 0;

static uint32_t led_count1 = 0;
static uint8_t led_flag1 = 0;

static uint32_t led_count2 = 0;
static uint8_t led_flag2 = 0;

static uint32_t led_count3 = 0;
static uint8_t led_flag3 = 0;


// the loop function runs over and over again forever
void loop() {
  current_time = Timer_Get_Millis();
  
  if((current_time - led_count1) >= 100)
  {
    led_count1 = current_time;
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

  if((current_time - led_count2) >= 100)
  {
    led_count2 = current_time;
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


    if((current_time - led_count3) >= 500)
  {
    led_count3 = current_time;
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

  
}
