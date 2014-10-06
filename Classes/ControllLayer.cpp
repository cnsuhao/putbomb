#include "controlllayer.h"
#include"SneakyInput/SneakyButton.h"
#include "SneakyInput/SneakyButtonSkinnedBase.h"
#include"SneakyInput/SneakyJoystick.h"
#include "SneakyInput/SneakyJoystickSkinnedBase.h"
#include "ControllDelegate.h"
bool ControllLayer::init()
{
	if(!CCLayer::init())return false;
	winsize=CCEGLView::sharedOpenGLView()->getFrameSize();
	CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(this,0,false);

	 touchButon=CCMenuItemImage::create("icon_touch.png","icon_touch_down.png",NULL,NULL,NULL);
	 CCMenu* menu=CCMenu::create(touchButon,0);
	this->addChild(menu);
	menu->setPosition(winsize.width-100,100);

	touchStick=SneakyJoystick::create();
	touchStick->initWithRect(CCRectMake(0,0,50,0));
	touchStick->setAutoCenter(true);
	touchStick->setHasDeadzone(true);
	touchStick->setDeadRadius(20);
	skinBase=SneakyJoystickSkinnedBase::create();
	//skinBase->init();
	CCSprite* backGroundSprite=CCSprite::create("icon_touch.png");
	CCSprite* thumbSprite=CCSprite::create("icon_touch_down.png");
	skinBase->setBackgroundSprite(backGroundSprite);
	skinBase->setThumbSprite(thumbSprite);
	thumbSprite->setScale(0.5);
	skinBase->setPosition(100,100);
	skinBase->setJoystick(touchStick);
	this->addChild(skinBase);
	
	pDelegate=0;

	return true;
}
void ControllLayer::setDelegate(ControllDelegate* dg)
{
	this->pDelegate=dg;
}
void ControllLayer::update(float t)
{
	//  getVelocity()到的数值很小 需要放大 
	if(!pDelegate)return ;
	CCPoint poi = ccpMult(touchStick->getVelocity(), 50);
	//right
	if(touchButon->isSelected())
	{
		pDelegate->onTouchFire();
	}
	if ((poi.x  >  0)  && (poi.x - poi.y) >0 && (poi.x + poi.y) > 0)
	{
		pDelegate->onTouchRight();
	}
	//left
	else if ( (poi.x < 0)  && (poi.x + poi.y) < 0 &&(poi.x - poi.y) < 0) 
	{
		pDelegate->onTouchLeft();
	}
	//up
	else if ((poi.y > 0) &&(poi.y - poi.x) > 0 &&(poi.y + poi.x) >0 )
	{
		pDelegate->onTouchUp();
	}
	//down
	else if ((poi.y < 0) &&(poi.y - poi.x) < 0 && (poi.y + poi.x) < 0) 
	{
		pDelegate->onTouchDown();
	}
}

bool ControllLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint point=pTouch->getLocation();


	return true;
}
void ControllLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

	
}
void ControllLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
}
void ControllLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

	
}
void ControllLayer::onEnter()
{
	CCLayer::onEnter();
	registerWithTouchDispatcher();
}
void ControllLayer::onExit()
{
	CCLayer::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

