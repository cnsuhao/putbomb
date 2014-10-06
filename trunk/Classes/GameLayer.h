#pragma once
#include "cocos2d.h"
#include"gameData.h"
enum TileType;
class GameLayer:public cocos2d::CCLayer
{
public:
	bool initWithMatrix(char(* p)[50],const int row,const int col);
	static GameLayer* create (char(* p)[50],const int row,const int col);
private:
	char* getTilePathByType(const enum TileType& )const;
};

