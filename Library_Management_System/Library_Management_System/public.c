#include "public.h"
#include <Windows.h>//����dos���棨��ȡ����̨������λ�á�����������ɫ��
#include <stdio.h>
/*******��  ��  ȫ  ��  ��  ��*******/
int step = 0;				//��ִ�в���
int score = 0;			//�洢��Ϸ����
long int Time;			//��Ϸ����ʱ��
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