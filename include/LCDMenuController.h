#ifndef LCD_CONTROLLER_H
#define LCD_CONTROLLER_H

#include <Arduino.h>
#include <LcdMenu.h>
#include <Config.h>
#include <display/LiquidCrystal_I2CAdapter.h>
#include <renderer/CharacterDisplayRenderer.h>
#include <MenuScreen.h>
#include <ItemToggle.h>

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_WIDTH, LCD_HEIGHT);
LiquidCrystal_I2CAdapter lcdAdapter(&lcd);
CharacterDisplayRenderer renderer(&lcdAdapter, LCD_WIDTH, LCD_HEIGHT);
LcdMenu menu(renderer);

class LCDMenuController
{
public:
	LCDMenuController();
	void init();
private:
	void toggleBacklight(bool isOn);
};

#endif