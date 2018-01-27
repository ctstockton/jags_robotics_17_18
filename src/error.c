#include "main.h"//and error.h

void lcdBacklightFlash(void * parameters)
{
  while(true)
  {
    lcdSetBacklight(uart2, true);//set on
    delay(250);
    lcdSetBacklight(uart2, false);//set off
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
    error = (bool)((double)powerLevelMain()/1000 < 7.100);
    if(error)
    {
      taskResume(_lcdBacklightFlash);
    }
    else if(!error)
    {
      taskSuspend(_lcdBacklightFlash);
      lcdSetBacklight(uart2, false);//set off incase it was on
    }
    delay(20);
  }
}

void autoCheck(void * parameters)
{
  while(true)
  {
    if(AUTONOMOUS_ERROR)
    {
      //Delete auton tasks
      taskDelete(_lift);
    }
    delay(20);
  }
}
