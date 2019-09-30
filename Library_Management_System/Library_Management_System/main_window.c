#include "main_window.h"
#include "main_design.h"
void MenuPlot()
{
	unsigned int x = GAME_FRAME_X;
	unsigned int y = GAME_FRAME_Y;
	Color(YELLOW);
	// draw frame line
	DrawLine(x, y , CHOICE_LENGTH, HORIZONTAL);
	DrawLine(x,y+2, CHOICE_LENGTH, HORIZONTAL);
	DrawLine(x, y + CHOICE_HEIGHT+1, CHOICE_LENGTH, HORIZONTAL);
	DrawLine(x, y + 1, CHOICE_HEIGHT, VERTICAL);
	DrawLine(x+ CHOICE_LENGTH, y + 1, CHOICE_HEIGHT, VERTICAL);
	// print the words
	GotoXY(x + CHOICE_LENGTH / 3, y + 1);
	printf("   Books System ");
	GotoXY(x + CHOICE_LENGTH / 4, y + 3);
	printf("1.Show the all books info");
	GotoXY(x + CHOICE_LENGTH / 4, y + 4);
	printf("2.Add the books info");
	GotoXY(x + CHOICE_LENGTH / 4, y + 5);
	printf("3.Modify the  books info");
	GotoXY(x + CHOICE_LENGTH / 4, y + 6);
	printf("4.Delete the  books info");
	GotoXY(x + CHOICE_LENGTH / 4, y + 7);
	printf("5.Search the  books info");
	GotoXY(x + CHOICE_LENGTH / 4, y + 8);
	printf("6.Exit the book system");
	Color(RED);
	GotoXY(x + CHOICE_LENGTH / 10, y + 10);
	printf("ENTER YOUR CHOICE (1 - 6):   ");

}

void MenuChioce()
{
	int n ;
	//n = DEBUG_NUM;
	scanf("%d", &n);
	switch (n)
	{
	case CHOICE_SHOW_INFO:
		ShowInfo();
		break;
	case CHOICE_ADD_INFO:
		InsertInfo();
		break;
	case CHOICE_MODIFY:
		ModifyInfo();
		break;
	case CHOICE_DELETE:
		DeleteInfo();
		break;
	case CHOICE_SEARCH:
		SearchInfo();
		break;
	case CHOICE_QUIT:
		Close();
		break;
	default:
		return;
	}

}

void MainMenu()
{
	system("cls");
	MenuPlot();
	MenuChioce();
}