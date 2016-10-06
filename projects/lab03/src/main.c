/*
 * Simple program to flash the LEDs 
 *
 * Implemented using a time-triggered scheduler.
 *
 * DK - 08-March-2011
 */


#include <stdbool.h>
#include <stdint.h>
#include <bsp.h>
#include <leds.h>
#include <scheduler.h>

void linkLedToggleTask(void);
void connectLedToggleTask(void);

int main () {
  
  /* Initialise the board support package */
  
  /* Initialise the scheduler. 1 ms tick (see ttSchedConfig.h) */
  
  /* Add tasks to the scheduler table */
  
  /* Start the scheduler */

  while (true) {
    /* Main loop -- dispatch tasks */
  }
}


void linkLedToggleTask(void) {
    /* toggle the link led */
}

void connectLedToggleTask(void) {
    /* toggle the connect led */
}

