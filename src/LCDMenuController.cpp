#include <LCDMenuController.h>

// Declare the call back function
void toggleBacklight(bool isOn);

// clang-format off
MENU_SCREEN(mainScreen, mainItems,
  ITEM_BASIC("Start service"),
  ITEM_BASIC("Connect to WiFi"),
  ITEM_TOGGLE("Backlight", toggleBacklight),
  ITEM_BASIC("Blink SOS"),
  ITEM_BASIC("Blink random"));

LCDMenuController::LCDMenuController()
{
}

void LCDMenuController::init()
{
	renderer.begin();
	delay(10);
	menu.setScreen(mainScreen);
}

void LCDMenuController::toggleBacklight(bool isOn)
{

}
