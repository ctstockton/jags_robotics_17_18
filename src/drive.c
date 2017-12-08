#include "main.h" //to include API and drive.h

//functions from drive.h go in here

void stopDrive()
{
  //stop all motors for drive
  motorStop(LEFT_FRONT_MOTOR);
  motorStop(LEFT_BACK_MOTOR);
  motorStop(RIGHT_BACK_MOTOR);
  motorStop(RIGHT_FRONT_MOTOR);
}

void setDriveForTime(int leftPower, int rightPower, int time)
{
  //set left and right drive for some power for some time then stop
  motorSet(LEFT_FRONT_MOTOR, leftPower);
  motorSet(LEFT_BACK_MOTOR, leftPower);
  motorSet(RIGHT_BACK_MOTOR, rightPower);
  motorSet(RIGHT_FRONT_MOTOR, rightPower);
  delay(time);
  stopDrive();
}

void setDrive(int leftPower, int rightPower)
{
  //set all drive motors to some power
  motorSet(LEFT_FRONT_MOTOR, leftPower);
  motorSet(LEFT_BACK_MOTOR, leftPower);
  motorSet(RIGHT_BACK_MOTOR, rightPower);
  motorSet(RIGHT_FRONT_MOTOR, rightPower);
}
