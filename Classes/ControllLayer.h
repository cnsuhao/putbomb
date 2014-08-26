#pragma once
#include"cocos2d.h"
using namespace cocos2d;

class SneakyButtonSkinnedBase;
class SneakyJoystickSkinnedBase;
class SneakyJoystick;
class SneakyButton;
class ControllDelegate;
class ControllLayer :public CCLayer
{
	SneakyButton*sneakyButton;
	SneakyJoystick*sneakStick;
public:
	bool init();
	void onEnter();
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
	void onExit();
	void update(float delta);
	void setDelegate(ControllDelegate* dg);
	CREATE_FUNC(ControllLayer);
private:
	ControllDelegate* pDelegate;
	CCMenuItemImage* touchButon;
	SneakyJoystick* touchStick;
	SneakyJoystickSkinnedBase* skinBase;
	CCSize winsize;
};

