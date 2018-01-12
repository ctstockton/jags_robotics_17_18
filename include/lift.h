#ifndef _LIFT_H_
#define _LIFT_H_

#include "main.h"

//declare task name
TaskHandle _lift;

//declare preset heights
#define LIFT_TO_BOTTOM 927
#define LIFT_TO_TOP 1850

int LIFT_TARGET;
//List of all function to be declared

//beginner list
void setLiftForTime(int power, int time);

//normal list
void setLift(int power);
void stopLift();

//lift task function
void liftTask(void * parameters);

#endif //_LIFT_H_ end declaration if
