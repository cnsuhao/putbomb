#include "GameLayer.h"
#include "GameData.h"
char* GameLayer::getTilePathByType(const TileType& t)const 
{
	switch(t)
	{
	case TileTypePerson:
		{
			return "tilePerson.jpg";
		}
		break;
	case TileTypeIron:
		{
			return "tileIron.jpg";
		}
		break;
	case TileTypeTile:
		{
			return "tileTile.jpg";
		}
		break;
	}
	return NULL;
}
GameLayer* GameLayer::create(char(* p)[50],const int row,const int col)
{
	GameLayer* layer=new GameLayer();
	if(layer->initWithMatrix(p,row,col))
	{
		return layer;
	}
	return NULL;
}
bool GameLayer::initWithMatrix(char(* p)[50],const int row,const int col)
{
	if(!CCLayer::init())return false;
	srand(time(0));
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
				char * path=getTilePathByType((TileType)p[i][j]);
				if(path==NULL)continue;
				cocos2d::CCSprite* tileSprite=cocos2d::CCSprite::create(path);
				tileSprite->setPosition(ccpAdd(ccp(j*TILE_WITH+TILE_WITH/2,i*TILE_HEIGHT+TILE_HEIGHT/2),ccp(50,50)));
				this->addChild(tileSprite);
		}
	}
	return true;
}