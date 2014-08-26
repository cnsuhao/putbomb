#pragma once
class ControllDelegate
{
public:
	virtual void onTouchUp()=0;
	virtual void onTouchDown()=0;
	virtual void onTouchLeft()=0;
	virtual void onTouchRight()=0;
	virtual void onTouchFire()=0;
private:
};