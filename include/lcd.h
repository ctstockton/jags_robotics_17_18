#ifndef _LCD_H_
#define _LCD_H_

//define screens
#define MENU_MAIN 0
#define MENU_BATTERIES 1
#define MENU_AUTO_MAIN 2
#define MENU_AUTO_SKILLS 3
#define MENU_AUTO_LEFT_1 4
#define MENU_AUTO_RIGHT_1 5

void runLCDMenu();//meant to run as a thread
void flashLCDBacklight();//meant to run as a thread

#endif //_LCD_H_
