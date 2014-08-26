#pragma once
#include "ControllDelegate.h"
class GamePlayer;
class GameController:public ControllDelegate
{
public:
	virtual void onTouchUp();
	virtual void onTouchDown();
	virtual void onTouchLeft();
	virtual void onTouchRight();
	virtual void onTouchFire();
private:
	GamePlayer* m_pPlayer;
};

