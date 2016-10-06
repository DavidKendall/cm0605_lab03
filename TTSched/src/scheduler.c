#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <intrinsics.h>
#include <iolpc2378.h>
#include <bsp.h>
#include <timers.h>
#include <scheduler.h>

static schTCB_t schTasks[TT_SCHED_MAX_TASKS];


void schInit(void) {   // initialise the scheduler
  /* Loop to set all TCBs in the task array to zeroes */
  
  /* Initialise TIMER0 to tick at tickHz and use schUpdate
   * as the interrupt handler
   */
}

void schStart(void) {           // start ticking
  /* Start TIMER0     */
  
  /* Enable interrupts */
}

void schUpdate(void) {          // update after a tick -- ISR

  /* Loop 
   * Check each entry in the task array
   *   if the entry is not empty then
   *     if the delay field for the entry is 0, increment invocations
   *       if the period is non-zero, reset the delay field to the period
   *     else
   *       decrement the delay field, not ready to run yet
   */
}

void schDispatch(void) {       // run the next task

  /* Loop
   * Check each entry in the task array
   *   if invocations > 0, run the task, decrement invocations
   *     if the period is 0 this is a one-shot task so remove it
   *     from the task array
   * End loop
   */

  /* Go to sleep */
}

void schAddTask(               // add a task to the task set
  pVoidFunc_t task,              // the task to add
  uint32_t delay,                // the delay in ms
  uint32_t period) {             // the period
  
  uint8_t i = 0;
  
  while (i < TT_SCHED_MAX_TASKS && schTasks[i].task != (pVoidFunc_t)0) {
    i += 1;
  }
  assert(i < TT_SCHED_MAX_TASKS);
  schTasks[i].task = task;
  schTasks[i].delay = delay;
  schTasks[i].period = period;
  schTasks[i].invocations = 0;
}

void schRemoveTask(            // remove a set from the task set
  uint8_t id) {                  // identifier of the task to remove
    
  assert((id < TT_SCHED_MAX_TASKS) && (schTasks[id].task != (pVoidFunc_t)0));

/* For the entry in the task array at position id,
 * set the value of all components to 0
 */
}

void schSleep(void) {         // go to sleep to save power
  PCON |= 1;
}





