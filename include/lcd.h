#ifndef _LCD_H_
#define _LCD_H_

#include "main.h"

TaskHandle _LCDRunTime;

//define screens
#define MENU_MAIN 0
#define MENU_BATTERIES1 1
#define MENU_BATTERIES2 2
#define MENU_AUTO_MAIN 3
#define MENU_AUTO_SKILLS 4
#define MENU_AUTO_LEFT_1 5
#define MENU_AUTO_RIGHT_1 6

#define MENU_AUTO_CHOSEN 10

int LCDButtWaitReturn();

void LCDMenu(void * parameters);//meant to run as a thread
//void flashLCDBacklight();//meant to run as a thread

#endif //_LCD_H_
