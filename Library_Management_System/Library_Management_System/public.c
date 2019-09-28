#include "public.h"
#include <Windows.h>//控制dos界面（获取控制台上坐标位置、设置字体颜色）
#include <stdio.h>
/*******定  义  全  局  变  量*******/
int step = 0;				//已执行步数
int score = 0;			//存储游戏分数
long int Time;			//游戏运行时间
pLinkBooks pBooks;
CONSOLE_SCREEN_BUFFER_INFO conPoint ;

void DrawLine(int x, int y, int len, int isHorizontal)
{
	if (isHorizontal)
	{
		for (int i = 0; i < len; i++)
		{
			GotoXY(x + i, y);
			printf("-");
		}

	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			GotoXY(x, y + i);
			printf("|");
		}
	}
}

void Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

}
void GotoXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GetXY(CONSOLE_SCREEN_BUFFER_INFO* p)
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), p);
}