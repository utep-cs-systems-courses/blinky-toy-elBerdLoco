#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

int main(void) {
  static int pitch = 2000;
  
  configureClocks();
  
  switch_init();
  led_init();
  buzzer_init();
  buzzer_set_period(pitch);	/* start buzzing!!! 2MHz/1000 = 2kHz. The lower the number the */
                                /* higher the pitch, the higher the number the lower the pitch */
  led_update;
  enableWDTInterrupts();
  or_sr(0x18);          // CPU off, GIE on
}
