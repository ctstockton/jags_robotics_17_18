#ifndef _AUTONOMOUS_H_
#define _AUTONOMOUS_H_

#if(ROBOT == JAWS)

#define AUTONOMOUS_NONE -1
#define AUTONOMOUS_SKILLS 0
#define AUTONOMOUS_LEFT_1 1
#define AUTONOMOUS_RIGHT_1 2

int AUTONOMOUS_CHOSEN;

int AUTONOMOUS_ERROR;
//List of all autonomous functions are/or routines
void Skills();
void AutonomousLeft1();
void AutonomousRight1();
#endif
#if(ROBOT == JAGS)

#endif
#endif //_AUTONOMOUS_H_ end declaration if
