#ifndef  _PUBLIC_
#define _PUBLIC_
#include <Windows.h>
#include "mysql.h"
/*******宏  定  义*******/
#define DEBUG_NUM			3

#define VERTICAL				0
#define HORIZONTAL			1
#define GAME_FRAME_X	30		//全局游戏X轴坐标
#define GAME_FRAME_Y		3	//全局游戏Y轴坐标


typedef enum WordColor
{
	BLACK,
	DEEP_BLUE,
	DEEP_GREEN,
	DEEP_BLUE_GREEN,
	DEEP_RED,
	PURPLE,
	DULL_YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_BLUE_GREEN,
	RED,
	PINK,
	YELLOW,
	LIGHT_WHITE
}WordColor;



/*定义存储火车信息的结构体*/
typedef struct Books
{
	char num[20];				/*列车号*/
	char name[20];			/*出发城市*/
	char author[20];			/*目的城市*/
	char publisher[20];		/*发车时间*/
}Books;

/*定义火车信息链表的结点结构*/
typedef struct LinkBooks
{
	Books data;
	struct LinkBooks* next;
}LinkBooks,*pLinkBooks;

extern pLinkBooks pBooks;
extern CONSOLE_SCREEN_BUFFER_INFO conPoint;
void Color(int c);
void GotoXY(int x, int y);
void GetXY(CONSOLE_SCREEN_BUFFER_INFO* p);
void DrawLine(int x, int y, int len, int isHorizontal);
#endif // ! _PUBLIC_
