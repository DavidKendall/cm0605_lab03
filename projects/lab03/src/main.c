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
#include <buttons.h>
#include <scheduler.h>

void linkLedToggleTask(void);
void connectLedToggleTask(void);
void buttonsTask(void);

bool flashing = false;

int main () {
  
  bspInit();
  schInit();
  schAddTask(buttonsTask, 0, 100);
  schAddTask(linkLedToggleTask, 0, 250);
  schAddTask(connectLedToggleTask, 0, 500);


  schStart();
  
  while (true) {
    schDispatch();
  }
}


void linkLedToggleTask(void) {
  if (flashing) {
    ledToggle(USB_LINK_LED);
  }
}

void connectLedToggleTask(void) {
  if (flashing) {
    ledToggle(USB_CONNECT_LED);
  }
}

void buttonsTask(void) {
  if (isButtonPressed(BUT_1)) {
    flashing = true;
  } else if (isButtonPressed(BUT_2)) {
    flashing = false;
    ledSetState(USB_LINK_LED, LED_OFF);
    ledSetState(USB_CONNECT_LED, LED_OFF);
  }
}
