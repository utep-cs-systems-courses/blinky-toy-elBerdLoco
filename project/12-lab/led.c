#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  P1OUT |= LEDS;
}


void led_update(){
  if (switch1_down & SW1) {
    P1OUT |= LEDS;
    P1OUT &= ~LED_RED;
  }
  else if(switch2_down & SW2){
    P1OUT |= LEDS;
    P1OUT &= ~LED_GREEN;
  }
}

