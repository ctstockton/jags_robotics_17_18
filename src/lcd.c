#include "main.h" //to include API and lcd.h

//function for running the LCD autonomous menu error backlight flash
void runLCDMenu()//called as a thread in init.c
{
  lcdClear(uart1);//just in case
  lcdSetText(uart1, 1, "    LCD Menu    ");
  lcdSetText(uart1, 2, "Starting Up");
  delay(250);
  lcdSetText(uart1, 2, "Starting Up.");
  delay(250);
  lcdSetText(uart1, 2, "Starting Up..");
  delay(250);
  lcdSetText(uart1, 2, "Starting Up...");
  delay(250);
  lcdSetText(uart1, 2, "Starting Up....");
  delay(250);
  lcdSetText(uart1, 2, "Starting Up.....");
  
}

bool backLight;

void flashLCDBacklight()//called as a thread when the robot need attention
{
  if(!backLight)//if backlight is off, turn on
  {
    lcdSetBacklight(uart1, true);
    backLight = true;
  }
  else if(backLight)//if backlight is on, turn off
  {
    lcdSetBacklight(uart1, false);
    backLight = false;
  }
}
