#include "TouchButton.h"

bool TouchButton::init()
{
	if(!CCMenu::init())return false;
	this->scheduleUpdate();
	return true;
}
void TouchButton::init()