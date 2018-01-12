#include "main.h" //to include API and lcd.h

int LCDButtWaitReturn()
{
  while(!lcdReadButtons(uart2))
  {
    wait(20);
  }
  int button = lcdReadButtons(uart2);
  while(lcdReadButtons(uart2))
  {
    wait(20);
  }
  return button;
}

//function for running the LCD autonomous menu error backlight flash
void LCDMenu(void * parameters)//called as a thread in init.c
{
  lcdClear(uart2);//just in case
  lcdSetText(uart2, 1, "    LCD Menu    ");
  lcdSetText(uart2, 2, "Starting Up     ");
  delay(250);
  lcdSetText(uart2, 2, "Starting Up.    ");
  delay(250);
  lcdSetText(uart2, 2, "Starting Up..   ");
  delay(250);
  lcdSetText(uart2, 2, "Starting Up...  ");
  delay(250);
  lcdSetText(uart2, 2, "Starting Up.... ");
  delay(250);
  lcdSetText(uart2, 2, "Starting Up.....");

  //declare local var
  int currentScreen = 0;
  int autonomousPick;
  int buttonPressed = 0;

  while(true)
  {
    switch(currentScreen)
    {
      case MENU_MAIN ://////////////////////////////////////////////////////////
      lcdSetText(uart2, 1, "    Main Menu   ");
      lcdSetText(uart2, 2, "<Battery   Auto>");
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_BATTERIES;
      else if(buttonPressed == LCD_BTN_CENTER)
        currentScreen = MENU_MAIN;
      else if(buttonPressed == LCD_BTN_RIGHT)
        currentScreen = MENU_AUTO_MAIN;
      break;
      case MENU_BATTERIES ://///////////////////////////////////////////////////
      while(!lcdReadButtons(uart2))
      {
        lcdSetText(uart2, 1, "Batteries: Back>");
        lcdPrint(uart2, 2, "Batt: %1.3f V", (double)powerLevelMain() / 1000);
        wait(20);
      }
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_BATTERIES;
      else if(buttonPressed == LCD_BTN_CENTER)
        currentScreen = MENU_BATTERIES;
      else if(buttonPressed == LCD_BTN_RIGHT)
        currentScreen = MENU_MAIN;
      break;
      case MENU_AUTO_MAIN ://///////////////////////////////////////////////////
      lcdSetText(uart2, 1, "Autonomous  Menu");
      lcdSetText(uart2, 2, "Left Skill Right");
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_MAIN;
      else if(buttonPressed == LCD_BTN_CENTER)
        currentScreen = MENU_MAIN;
      else if(buttonPressed == LCD_BTN_RIGHT)
        currentScreen = MENU_MAIN;
      break;
      default ://///////////////////////////////////////////////////////////////
      lcdSetText(uart2, 1, "           Main Menu");
      lcdSetText(uart2, 2, "<Battery Autonomous>");
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_BATTERIES;
      else if(buttonPressed == LCD_BTN_CENTER)
        currentScreen = MENU_MAIN;
      else if(buttonPressed == LCD_BTN_RIGHT)
        currentScreen = MENU_AUTO_MAIN;
      break;
    }
  }
}

/*void flashLCDBacklight()//called as a thread when the robot need attention
{
  if(!backLight)//if backlight is off, turn on
  {
    lcdSetBacklight(uart2, true);
    backLight = true;
  }
  else if(backLight)//if backlight is on, turn off
  {
    lcdSetBacklight(uart2, false);
    backLight = false;
  }
}*/
