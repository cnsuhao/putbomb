#pragma once
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
//获得炸弹
#define  OPRATION_GET_NORMAL_BOMB 0X01
//获得定时炸弹
#define  OPRATION_GET_TIMER_BOMB 0x10
//获得能量药水
#define  OPRATION_GET_POWER 0X07
//获得冰块
#define	 OPRATION_GET_ICE 0X08
//获得火焰
#define  OPRATION_GET_FIRE 0x09
//获得鞋子
#define  OPRATION_GET_GIFT_SHOES 0X11
//获得手榴弹
#define  OPRATION_GET_HAND_BOMB 0X12
//获得踢球的技能
#define  OPRATION_GET_HIT_GIFT 0X13
//获得毒药水
#define  OPRATION_GET_VIRUS 0x14

//放置普通炸弹
#define  OPRATION_PUT_NORMAL_BOMB 0X01
//放置定时炸弹
#define  OPRATION_PUT_TIMER_BOMB 0x02
//放火冻人
#define  OPRATION_PUT_FIRE 0x03
//放冰喷人
#define  OPRATION_PUT_ICE 0X04
//踢普通炸弹
#define  OPRATION_HIT_NORMAL_BOMB 0x05

typedef enum TileType{TileTypeIron=1,TileTypeTile,TileTypePerson}TileType;

#define TILE_WITH 32
#define TILE_HEIGHT 34

//
#define  PERSON_LEFT_DOWN 0x101
#define  PERSON_LEFT_UP 0x102
#define  PERSON_RIGHT_DOWN 0X103
#define  PERSON_RIGHT_UP 0X104

struct GameDataDiagram
{
	BYTE who;
	WORD posX;
	WORD posY;
	BYTE opration;
	GameDataDiagram(BYTE w,WORD x,WORD y,BYTE op);
};

class GameData
{
public :
	static char(*(getGameMapMatrix()))[50]; 
	static void setMatrixValue(const int & row,const int & col,const int & value);
	static char getMatrixValue(const int & row,const int & col);
private:
	static char m_Matrix[30][50];
};