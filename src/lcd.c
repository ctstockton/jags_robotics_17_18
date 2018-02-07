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
  int buttonPressed = 0;

  //declare no autonomous first
  AUTONOMOUS_CHOSEN = AUTONOMOUS_NONE;

  while(true)
  {
    switch(currentScreen)
    {
      case MENU_MAIN ://////////////////////////////////////////////////////////
      lcdSetText(uart2, 1, "    Main Menu   ");
      lcdSetText(uart2, 2, "<Battery   Auto>");
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_BATTERIES1;
      else if(buttonPressed == LCD_BTN_CENTER)
        currentScreen = MENU_MAIN;
      else if(buttonPressed == LCD_BTN_RIGHT)
        currentScreen = MENU_AUTO_MAIN;
      break;
      case MENU_BATTERIES1 :////////////////////////////////////////////////////
      while(!lcdReadButtons(uart2))
      {
        lcdSetText(uart2, 1, "Batteries: Back>");
        lcdPrint(uart2, 2, "Batt: %1.3f V", (double)powerLevelMain() / 1000);
        wait(20);
      }
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_BATTERIES1;
      else if(buttonPressed == LCD_BTN_CENTER)
        currentScreen = MENU_BATTERIES2;
      else if(buttonPressed == LCD_BTN_RIGHT)
        currentScreen = MENU_MAIN;
      break;
      case MENU_BATTERIES2 :
      while(!lcdReadButtons(uart2))
      {
        lcdSetText(uart2, 1, "Sensors:   Back>");
        lcdPrint(uart2, 2, "L Potent: %4d", analogRead(LIFT_POTENTIOMETER));
        wait(20);
      }
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_BATTERIES1;
      else if(buttonPressed == LCD_BTN_CENTER)
        currentScreen = MENU_BATTERIES2;
      else if(buttonPressed == LCD_BTN_RIGHT)
        currentScreen = MENU_MAIN;
      break;
      case MENU_AUTO_MAIN ://///////////////////////////////////////////////////
      lcdSetText(uart2, 1, "Autonomous  Menu");
      lcdSetText(uart2, 2, "Left Skill Right");
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
      {
        currentScreen = MENU_AUTO_CHOSEN;
        AUTONOMOUS_CHOSEN = AUTONOMOUS_LEFT_1;
      }
      else if(buttonPressed == LCD_BTN_CENTER)
      {
        currentScreen = MENU_AUTO_CHOSEN;
        AUTONOMOUS_CHOSEN = AUTONOMOUS_SKILLS;
      }
      else if(buttonPressed == LCD_BTN_RIGHT)
      {
        currentScreen = MENU_AUTO_CHOSEN;
        AUTONOMOUS_CHOSEN = AUTONOMOUS_RIGHT_1;
      }
      break;
      case MENU_AUTO_CHOSEN :///////////////////////////////////////////////////
      lcdSetText(uart2, 1, "   Autonomous   ");
      if(AUTONOMOUS_CHOSEN == AUTONOMOUS_LEFT_1)
        lcdSetText(uart2, 2, "Left1           ");
      else if(AUTONOMOUS_CHOSEN == AUTONOMOUS_SKILLS)
        lcdSetText(uart2, 2, "Skills          ");
      else if (AUTONOMOUS_CHOSEN == AUTONOMOUS_RIGHT_1)
        lcdSetText(uart2, 2, "Right1          ");
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed)
      {
        currentScreen = MENU_MAIN;
        AUTONOMOUS_CHOSEN = AUTONOMOUS_NONE;//no autonomous
      }
      break;
      default ://///////////////////////////////////////////////////////////////
      lcdSetText(uart2, 1, "           Main Menu");
      lcdSetText(uart2, 2, "<Battery Autonomous>");
      buttonPressed = LCDButtWaitReturn();
      if(buttonPressed == LCD_BTN_LEFT)
        currentScreen = MENU_BATTERIES1;
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
