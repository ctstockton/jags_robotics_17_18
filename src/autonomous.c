#include "main.h" //to include API and autonomous.h

void Skills()
{
  //skill autonomous
}

void LeftAutonomous1()
{

}

void RightAutonomous1()
{
int Quad_Right = 0;
imeReset(RIGHT_DRIVE_QUAD_TOP);
while(Quad_Right < 400)
{
Quad_Right = encoderGet(RBDriveEncoder);
motorSet(2,220);
motorSet(3,220);
}

}
