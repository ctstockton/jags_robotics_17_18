#ifndef _DRIVE_H_
#define _DRIVE_H_

//List of all functions to be declared
#define ENCODER_TOL 30

//beginner list
void setDriveForTime(int left, int right, int time);
void setStrafeForTime(int front, int back, int time);

//normal list
void setDrive(int left, int right);
void setStrafe(int front, int back);
void stopDrive();

//drive functions
void driveStraight(int distance, int power, int timeout);
void strafeStraight(int distance, int power, int timeout);
void tankTurn(int distance, int power, int timeout);

#endif //_DRIVE_H_ end declaration if
