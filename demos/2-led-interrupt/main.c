//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;

  P1OUT |= LED_RED;             //Added
  
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

char greenOn = 0;
int secondCount = 0;
//If green on, then red should be bright
//if green off, then red should be dim

void toggle_green(){
  greenOn = !greenOn;
  if (greenOn){
    P1OUT |= LED_GREEN | LED_RED;
  }else  
    P1OUT &= ~LED_GREEN;
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  
  if ((++secondCount) == 250){ /*once per second*/
    secondCount = 0;
    toggleGreen();
  }
  /* every 1/250 sec */
  if (!greenOn){                /*frash red on and off quickly*/ 
    
  }
}

