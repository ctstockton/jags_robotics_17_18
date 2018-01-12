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
  motorSet(RIGHT_LIFT_MOTOR, -power);
  delay(time);
  stopLift();
}

void setLift(int power)
{
  //set all motors to some lift power
  motorSet(LEFT_LIFT_MOTOR, power);
  motorSet(RIGHT_LIFT_MOTOR, -power);
}

void liftTask(void * parameters)
{
  float np = 0.40;
  float ni = 0.017;
  float nd = 0.27;
  int error = 0;
  float derivative = 0;
  int previousError = 0;
  float errorSum = 0;
  int motorPower = 0;

  while(true)
  {
    error = LIFT_TARGET - analogRead(LEFT_LIFT_POTENTIOMETER);
    derivative = abs(error - previousError)/0.02;//ticks per sec
    motorPower = (error*np+errorSum*ni+derivative*nd);
    setLift(motorPower);
    previousError = error;
    errorSum += error*0.02;//0.02 is for the Riemann Sum

    //lcdSetText(uart2, 1, "Err: Int: Deriv:");//for debug
    //lcdPrint(uart2, 2, "%3d %3.1f %2.1f",error,errorSum,derivative);//for debug
    delay(20);
  }
}
