#include "main.h" //to include API and lift.h

//functions from lift.h go in here
void stopLift()
{
  //set all lift motors
  motorStop(LEFT_LIFT_MOTOR);
  motorStop(RIGHT_LIFT_MOTOR);
}

void setLiftForTime(int power, int time)
{
  //set all motors at some lift power and for some time
  motorSet(LEFT_LIFT_MOTOR, power);
  motorSet(RIGHT_LIFT_MOTOR, power);
  delay(time);
  stopLift();
}

void setLift(int power)
{
  //set all motors to some lift power
  motorSet(LEFT_LIFT_MOTOR, power);
  motorSet(RIGHT_LIFT_MOTOR, power);
}
