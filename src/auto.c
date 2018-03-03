/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost,  the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
 #if(ROBOT == JAWS)
void autonomous()
{
  //_autonomousCheck = taskCreate(autoCheck, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  /*
  \\debugging
  */
  //Skills();
  /*lcdSetBacklight(uart2, false);
  lcdSetBacklight(uart2, true);
  LIFT_TARGET = 1600;
  _lift = taskCreate(liftTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  */
  //SHIFT_TARGET = 1800;
  //_intakeShift = taskCreate(intakeShiftTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  //autonomous selection
  /*
  if(AUTONOMOUS_CHOSEN == AUTONOMOUS_SKILLS)
    Skills();
  else if(AUTONOMOUS_CHOSEN == AUTONOMOUS_LEFT_1)
    AutonomousLeft1();
  else if(AUTONOMOUS_CHOSEN == AUTONOMOUS_RIGHT_1)
    AutonomousRight1();
    */
  //taskDelete(_lift);
  //setLift(0);
  taskSuspend(_lift);
}
#endif
/*--------------------------------------------------------------------------------------------------*/
#if(ROBOT == JAGS)
void autonomous()
{
  setDriveForTime(127, 127, 1000);
  setDriveForTime(63, -63, 400);
}
#endif
