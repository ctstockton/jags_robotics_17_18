/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */
#if(ROBOT == JAWS)

int SUBTASK = 0;
#define SUB_TASK_PRELOAD_STACK 1


void subTasks(void * parameters)
{
	while(true)
	{
		switch(SUBTASK)
		case 1 :
		
		SUBTASK = 0;
		break;
		delay(20);
	}
}

void operatorControl()
{
	//taskDelete(_lift);

	//init vars
	int leftPower, rightPower;

	TaskHandle _subTasks = taskCreate(subTasks, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	taskSuspend(_subTasks);

	while (true)
	{
		/*
		//Drive control
		*/
		rightPower = joystickGetAnalog(1, 3); // vertical axis on left joystick
		leftPower  = joystickGetAnalog(1, 2); // horizontal axis on left joystick
		if(abs(leftPower)>15 || abs(rightPower)>15)//to prevent creeping
		{
			motorSet(LEFT_FRONT_MOTOR, -leftPower);
			motorSet(LEFT_BACK_MOTOR, -leftPower);
			motorSet(RIGHT_BACK_MOTOR, rightPower);
			motorSet(RIGHT_FRONT_MOTOR, rightPower);
		}
		else
		{
			stopDrive();
		}

		/*
		//Lift control
		*/
		if(joystickGetDigital(1, 8, JOY_UP))
			setLift(127);//vertical axis on right joystick
		else if(joystickGetDigital(1, 8, JOY_DOWN))
			setLift(-127);
		else
			setLift(0);

		/*
		//Intake
		*/
		if(joystickGetDigital(1, 5, JOY_UP))
			intake(127);
		else if(joystickGetDigital(1, 5, JOY_DOWN))
			intake(-127);
		else
			intake(15);

		/*
		//MG lift
		*/
		if(joystickGetDigital(1, 6, JOY_UP))
			MGlift(-127);
		else if(joystickGetDigital(1, 6, JOY_DOWN))
			MGlift(127);
		else
			MGlift(0);

		/*
		//SubTasks
		*/
		if(joystickGetDigital(1, 7, JOY_LEFT))
		{
			SUBTASK = SUB_TASK_PRELOAD_STACK;
		}

		delay(20);
	}
}
#endif
/*--------------------------------------------------------------------------------------------------*/
#if(ROBOT == JAGS)
void operatorControl()
{
	//finished with lcd menu
	//taskDelete(_LCDRunTime);
	//taskDelete(_lift);
	//taskDelete(_intakeShift);

	//init vars
	int leftPower, rightPower;

	int liftPower;
	while (true) {
		/*
		//Drive control
		*/
		//getting joysticks
		leftPower = joystickGetAnalog(1, 3); // vertical axis on left joystick
		rightPower  = joystickGetAnalog(1, 2); // horizontal axis on left joystick

		if(abs(leftPower)>15 || abs(rightPower)>15)//to prevent creeping
		{
			motorSet(LEFT_FRONT_MOTOR, leftPower);
			motorSet(LEFT_BACK_MOTOR, leftPower);
			motorSet(LEFT_MID_1_MOTOR, leftPower);
			motorSet(LEFT_MID_2_MOTOR, leftPower);
			motorSet(RIGHT_BACK_MOTOR, -rightPower);
			motorSet(RIGHT_FRONT_MOTOR, -rightPower);
			motorSet(RIGHT_MID_1_MOTOR, -rightPower);
			motorSet(RIGHT_MID_2_MOTOR, -rightPower);
		}
		else
		{
			stopDrive();
		}
	}
}
#endif
