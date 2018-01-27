#ifndef _ERROR_H_
#define _ERROR_H_

#include "main.h"
//declare task handler names
TaskHandle _errorCheck;
TaskHandle _lcdBacklightFlash;
TaskHandle _autonomousCheck;
//set up the thread that checks for errors
void lcdBacklightFlash(void * parameters);
void errorCheck(void * parameters);
void autoCheck(void * parameters);
#endif //_ERROR_H_
