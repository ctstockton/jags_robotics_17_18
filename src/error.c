#include "main.h"//and error.h

void lcdBacklightFlash(void * parameters)
{
  while(true)
  {
    lcdSetBacklight(uart2, true);
    delay(250);
    lcdSetBacklight(uart2, false);
    delay(250);
  }
}

void errorCheck(void * parameters)
{
  bool error;
  _lcdBacklightFlash = taskCreate(lcdBacklightFlash, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_LOWEST);
  taskSuspend(_lcdBacklightFlash);
  lcdSetBacklight(uart2, false);
  while(true)
  {
    error = (bool)(powerLevelMain()/1000 < 7.1);
    if(error)
    {
      taskResume(_lcdBacklightFlash);
    }
    else if(!error)
    {
      taskSuspend(_lcdBacklightFlash);
      lcdSetBacklight(uart2, false);
    }
    wait(20);
  }
}
