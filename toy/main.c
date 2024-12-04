#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h" // added
#include "lcddraw.h" // added
//#include "piano_images.h" // added
void wdt_init() {
  configureClocks();         /* Setup master oscillator, CPU & peripheral clocks */
}

void main(void) {
  //lcd_init(); // added lcd initialization
  switch_init();
  led_init();
  buzzer_init();  // Initialize the buzzer
  wdt_init();
  lcd_init();
  or_sr(0x18); /* CPU off, GIE on */
}
