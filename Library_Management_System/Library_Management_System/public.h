#ifndef  _PUBLIC_
#define _PUBLIC_
#include <Windows.h>
#include "mysql.h"
/*******��  ��  ��*******/
#define DEBUG_NUM			3

#define VERTICAL				0
#define HORIZONTAL			1
#define GAME_FRAME_X	30		//ȫ����ϷX������
#define GAME_FRAME_Y		3	//ȫ����ϷY������


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



/*����洢����Ϣ�Ľṹ��*/
typedef struct Books
{
	char num[20];				/*�г���*/
	char name[20];			/*��������*/
	char author[20];			/*Ŀ�ĳ���*/
	char publisher[20];		/*����ʱ��*/
}Books;

/*�������Ϣ����Ľ��ṹ*/
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
