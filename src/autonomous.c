#include "main.h" //to include API and autonomous.h

void Skills()
{
  //skill autonomous
  driveStraight(3000, 127, 20000);
  delay(500);
  driveStraight(3000, -127, 20000);
  delay(500);
  setStrafeForTime(127, 127, 1000);
  delay(500);
  driveStraight(7000, 127, 8000);
  delay(500);
}

void AutonomousLeft1()
{
  driveStraight(2000, 127, 10000);
  delay(5000);
  driveStraight(1000, -127, 10000);
}

void AutonomousRight1()
{

}
