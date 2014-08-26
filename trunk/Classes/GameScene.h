#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class GameController;
class GameScene :
	public CCScene
{
public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(GameScene);
private:
	GameController* m_pGameController;
};

