#include "Gamedata.h"
#include<string.h>

GameDataDiagram::GameDataDiagram(BYTE w,WORD x,WORD y,BYTE op):who(w),posX(x),posY(y),opration(op)
{
}

GameData::GameData()
{
	for(int i=0;i<30;i++)
		memset(Matrix[i],0,sizeof(Matrix[i]));
}
char GameData::Matrix[30][50]={{0}};
char(*(GameData::getGameMapMatrix()))[50]
{
	return Matrix;
};