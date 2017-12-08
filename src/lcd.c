#include "main.h" //to include API and lcd.h

//function for running the LCD autonomous menu error backlight flash
void runLCDMenu()
{

}

bool backLight;

void flashLCDBacklight()
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
