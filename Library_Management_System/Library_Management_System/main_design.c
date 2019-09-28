#include "main_design.h"
#include "public.h"
#include "main_window.h"
void Close()
{
	exit(0);
}

int  DrawHeader()
{
	int oldx = 0;
	int oldy = 0;
	int retx = 0;
	Color(YELLOW);
	GetXY(&conPoint);
	oldx = conPoint.dwCursorPosition.X;
	oldy = conPoint.dwCursorPosition.Y;
	retx = oldx;
	//draw  the line 
	DrawLine(oldx, oldy, CHOICE_LENGTH,HORIZONTAL);
	GotoXY(oldx + HEAD_LENGTH / 2 - 5, oldy + 1);
	printf("Show the all books\n");
	DrawLine(oldx, oldy + 2, HEAD_LENGTH, HORIZONTAL);
	DrawLine(oldx, oldy + 4, HEAD_LENGTH, HORIZONTAL);
	//print the words 
	GotoXY(oldx, oldy+=3);
	printf("id");
	GotoXY(oldx += HEAD_INTERVAL, oldy);
	printf("name");
	GotoXY(oldx += HEAD_INTERVAL, oldy);
	printf("author");
	GotoXY(oldx += HEAD_INTERVAL, oldy);
	printf("publisher");
	GetXY(&conPoint);
	return retx;
}

void pLinkInit()
{
	pLinkBooks h;
	h = (pLinkBooks)malloc(sizeof(LinkBooks));
	h->next = NULL;
	pBooks = h;
}

void ShowInfo()
{
	system("cls");
	GotoXY(GAME_FRAME_X, GAME_FRAME_Y);
	int x = DrawHeader();
	GetXY(&conPoint);
	int y = conPoint.dwCursorPosition.Y ;
	pLinkBooks r = pBooks;
	if (r->next == NULL)
	{
		GotoXY(x, y +2 );
		printf("No Records Find !");
		getch();
		return;
	}
	while (r->next != NULL)
	{
		r = r->next;
		DrawInfo(x, y += 2, r);
	}
	GotoXY(x, y += 4);
	printf("Enter any key to return ! ");
	getch();
}


void DrawInfo(int x, int y, pLinkBooks ptr)
{
	Color(LIGHT_WHITE);
	//print the word
	GotoXY(x, y);
	int temp = x;
	printf("%s", ptr->data.num);
	GotoXY(x += HEAD_INTERVAL, y);
	printf("%s", ptr->data.name);
	GotoXY(x += HEAD_INTERVAL, y);
	printf("%s", ptr->data.author);
	GotoXY(x += HEAD_INTERVAL, y);
	printf("%s", ptr->data.publisher);
	GotoXY(x += HEAD_INTERVAL, y);
	//print the line 
	GotoXY(temp, y);
	DrawLine(temp, y, HEAD_LENGTH, HORIZONTAL);
}