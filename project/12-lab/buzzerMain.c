#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

int main(void) {
    configureClocks();

    switch_init();
    led_init();
    buzzer_init();
    buzzer_set_period(1000);	/* start buzzing!!! 2MHz/1000 = 2kHz*/


    or_sr(0x18);          // CPU off, GIE on
}
