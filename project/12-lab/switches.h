#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES 15 /* 1 + 2 + 4 + 8 */		

extern int switches;
extern char switch1_down;
extern char switch2_down;
extern char switch3_down;
extern char switch4_down;

void switch_init();
void switch_interrupt_handler();

#endif // included
