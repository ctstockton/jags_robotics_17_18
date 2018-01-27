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
  motorSet(RIGHT_BACK_MOTOR, -rightPower);
  motorSet(RIGHT_FRONT_MOTOR, -rightPower);
  delay(time);
  stopDrive();
}

void setStrafeForTime(int frontPower, int backPower, int time)
{
  motorSet(LEFT_FRONT_MOTOR, frontPower);
  motorSet(LEFT_BACK_MOTOR, -backPower);
  motorSet(RIGHT_BACK_MOTOR, -backPower);
  motorSet(RIGHT_FRONT_MOTOR, frontPower);
  delay(time);
  stopDrive();
}

void setDrive(int leftPower, int rightPower)
{
  //set all drive motors to some power
  motorSet(LEFT_FRONT_MOTOR, leftPower);
  motorSet(LEFT_BACK_MOTOR, leftPower);
  motorSet(RIGHT_BACK_MOTOR, -rightPower);
  motorSet(RIGHT_FRONT_MOTOR, -rightPower);
}

void setStrafe(int frontPower, int backPower)
{
  motorSet(LEFT_FRONT_MOTOR, frontPower);
  motorSet(LEFT_BACK_MOTOR, -backPower);
  motorSet(RIGHT_BACK_MOTOR, -backPower);
  motorSet(RIGHT_FRONT_MOTOR, frontPower);
}

void driveStraight(int distance, int power, int timeout)
{
  if(!AUTONOMOUS_ERROR)
  {
    int beginning = millis();
    int end = beginning + timeout;

    encoderReset(LFDriveEncoder);
    encoderReset(RBDriveEncoder);

    while((abs(encoderGet(LFDriveEncoder))<distance && abs(encoderGet(RBDriveEncoder))<distance) && (int)millis() < end)
    {
      if(abs(encoderGet(LFDriveEncoder)<abs(encoderGet(RBDriveEncoder))))
        setDrive(power, power*0.95);
      else if(abs(encoderGet(LFDriveEncoder)>abs(encoderGet(RBDriveEncoder))))
        setDrive(power*0.95, power);
      else
        setDrive(power, power);
      delay(20);
    }
    stopDrive();
    if((int)millis() > end)
      AUTONOMOUS_ERROR = true;
  }
}

void strafeStraight(int distance, int power, int timeout)
{
  if(!AUTONOMOUS_ERROR)
  {
    int beginning = millis();
    int end = beginning + timeout;

    encoderReset(LFDriveEncoder);
    encoderReset(RBDriveEncoder);

    while((abs(encoderGet(LFDriveEncoder))<distance && abs(encoderGet(RBDriveEncoder))<distance) || (int)millis() < end)
    {
      if(abs(encoderGet(LFDriveEncoder)<abs(encoderGet(RBDriveEncoder))))
        setStrafe(power, power*0.95);
      else if(abs(encoderGet(LFDriveEncoder)>abs(encoderGet(RBDriveEncoder))))
        setStrafe(power*0.95, power);
      else
        setStrafe(power, power);
      delay(20);
    }
    stopDrive();
    if((int)millis() < end)
      AUTONOMOUS_ERROR = true;
  }
}
