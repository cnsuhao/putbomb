#pragma once
#include "cocos2d.h"
enum TileType;
class GameLayer:public cocos2d::CCLayer
{
public:
	bool initWithMatrix(char(* p)[50],const int row,const int col);
	static GameLayer* create (char(* p)[50],const int row,const int col);
private:
	char* getTilePathByType(const TileType& t)const;
};

