#include "main_design.h"
#include "public.h"
#include "main_window.h"
#include "mysql_user.h"
#include <stdio.h>
void Close()
{
	exit(0);
}

int  DrawHeader()
{
	int oldx = 0;
	int oldy = 0;
	int retx = 0;
	Color(WHITE);
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
	char* temp= "select * from tb_books";
	system("cls");
	USER_PMYSQL_RESULT = MysqlInit(&mysql, USER_PMYSQL_RESULT);  //初始化mysql结构
	if (MysqlConnect(&USER_MYSQL, USER_PMYSQL_RESULT) == FAILED)
	{
		getch();
		exit(0);
	}
	if (MysqlQuery(&USER_MYSQL, USER_PMYSQL_RESULT, temp) == FAILED)
	{
		MysqlRelease(&mysql, pMysqlResult,RELEASE_MYSQL);
		return;
	}
	if (MysqlGetResult(&USER_MYSQL, USER_PMYSQL_RESULT) == FAILED)
	{
		MysqlRelease(&mysql, pMysqlResult,RELEASE_ALL);
		return;
	}
	GotoXY(GAME_FRAME_X, GAME_FRAME_Y);
	int x = DrawHeader();
	GetXY(&conPoint);
	int y = conPoint.dwCursorPosition.Y;
	while (USER_PMYSQL_RESULT->row
		=  mysql_fetch_row(pMysqlResult->result))     //获取结果集的行  )
	{
		//输出这行记录
		DrawInfo( x,  y+=2,USER_PMYSQL_RESULT->row);
	}
	GetXY(&conPoint);
	GotoXY(x, y +=2);
	printf("Enter any key to return ! ");
	MysqlRelease(&mysql,pMysqlResult, RELEASE_ALL);
	getch();
}



void DrawInfo(int x, int y, MYSQL_ROW	 row)
{
	Color(RED);
	//print the word
	int temp = x;
	GotoXY(x, y);
	printf("%s", row[0]);
	GotoXY(x += HEAD_INTERVAL, y);
	printf("%s", row[1]);
	GotoXY(x += HEAD_INTERVAL, y);
	printf("%s", row[2]);
	GotoXY(x += HEAD_INTERVAL, y);
	printf("%s", row[3]);
	GotoXY(x += HEAD_INTERVAL, y);
	//print the line 
	DrawLine(temp, y+1, HEAD_LENGTH, HORIZONTAL);
}

void InsertInfo()
{
	system("cls");
	unsigned int  exitFlag = 0;
	unsigned int continueFlag = 0;
	USER_PMYSQL_RESULT = MysqlInit(&mysql, USER_PMYSQL_RESULT);  //初始化mysql结构
	if (MysqlConnect(&USER_MYSQL, USER_PMYSQL_RESULT) == FAILED)
	{
		getch();
		exit(0);
	}
	while (!exitFlag)
	{
		continueFlag = 0;
		if (MysqlQuery(&USER_MYSQL, USER_PMYSQL_RESULT, "select * from tb_books") == FAILED)
		{
			MysqlRelease(&mysql, pMysqlResult, RELEASE_MYSQL);
			return;
		}
		if (MysqlGetResult(&USER_MYSQL, USER_PMYSQL_RESULT) == FAILED)
		{
			MysqlRelease(&mysql, pMysqlResult, RELEASE_ALL);
			return;
		}
		printf("**********************************");
		printf("\nPlease input the book id ： ");
		scanf("%s", &pBooks->data.num);
		while (USER_PMYSQL_RESULT->row
			= mysql_fetch_row(USER_PMYSQL_RESULT->result))
		{
			if (!strcmp(pBooks->data.num, USER_PMYSQL_RESULT->row[0]))
			{
				printf("\nThe book is existed ! \n");
				continueFlag = 1;	
				int n = 0;
				printf("\nDo you want to return ? [y/n]  : ");
				scanf("%s", &n);
				if (n == 'y')
				{
					continueFlag = 1;
					exitFlag = 1;
					break;
				}
			}
		}
		if (continueFlag)
			continue;
		char*  temp = "insert into tb_books (ID,bookname,author,publisher) values ('";
		int n=0;
		printf("\nInput the book name :   ");
		scanf("%s", pBooks->data.name);
		printf("\nInput the author :   ");
		scanf("%s", pBooks->data.author);
		printf("\nInput the publisher :   ");
		scanf("%s", pBooks->data.publisher);
		strcat(mysql_cmd, temp);
		strcat(mysql_cmd, pBooks->data.num);
		strcat(mysql_cmd, "','");
		strcat(mysql_cmd, pBooks->data.name);
		strcat(mysql_cmd, "','");
		strcat(mysql_cmd, pBooks->data.author);
		strcat(mysql_cmd, "','");
		strcat(mysql_cmd, pBooks->data.publisher);
		strcat(mysql_cmd, "')");
		MysqlQuery(&USER_MYSQL, USER_PMYSQL_RESULT, mysql_cmd);
		printf("\nDo you want to return ? [y/n]  : ");
		scanf("%s", &n);
		if (n == 'y')
			exitFlag = 1;
		else
			continue;
	}
	printf("Enter any key to return ! ");
	MysqlRelease(&mysql, pMysqlResult, RELEASE_ALL);
	getch();
}

void ModifyInfo()
{
	char* temp = "select * from tb_books where id=";
	MysqlMain(temp);
	if (USER_PMYSQL_RESULT->rowNums != NULL)
	{
		int x = DrawHeader();
		GetXY(&conPoint);
		int y = conPoint.dwCursorPosition.Y;
		while (USER_PMYSQL_RESULT->row
			= mysql_fetch_row(USER_PMYSQL_RESULT->result))
		{
			DrawInfo(x, y += 2, USER_PMYSQL_RESULT->row);
		}
		printf("\nInput the book name :   ");
		scanf("%s", pBooks->data.name);
		printf("\nInput the author :   ");
		scanf("%s", pBooks->data.author);
		printf("\nInput the publisher :   ");
		scanf("%s", pBooks->data.publisher);
		temp = "update tb_books set bookname= '";
		memset(mysql_cmd, 0, sizeof(mysql_cmd));
		strcat(mysql_cmd, temp);
		strcat(mysql_cmd, pBooks->data.name);
		strcat(mysql_cmd, "',author='");
		strcat(mysql_cmd, pBooks->data.author);
		strcat(mysql_cmd, "',publisher='");
		strcat(mysql_cmd, pBooks->data.publisher);
		strcat(mysql_cmd, "' where id= ");
		strcat(mysql_cmd, pBooks->data.num);
		MysqlQuery(&USER_MYSQL, USER_PMYSQL_RESULT, mysql_cmd);
		printf("Enter any key to return ! ");
		MysqlRelease(&mysql, pMysqlResult, RELEASE_ALL);
		getch();
	}
	else
	{
		getch();
		printf("\nNo record find ! \n");
	}

}


void SearchInfo()
{
	char* temp = "select * from tb_books where id=";
	MysqlMain(temp);
	if (USER_PMYSQL_RESULT->rowNums != NULL)
	{
		int x = DrawHeader();
		GetXY(&conPoint);
		int y = conPoint.dwCursorPosition.Y;
		USER_PMYSQL_RESULT->row = mysql_fetch_row(USER_PMYSQL_RESULT->result);
		DrawInfo(x, y += 2, USER_PMYSQL_RESULT->row);
		printf("\nSearch success !\n");
		printf("Enter any key to return ! ");
		MysqlRelease(&mysql, pMysqlResult, RELEASE_ALL);
		getch();

	}
	else
	{
		getch();
		printf("\nNo record find ! \n");
	}

}


void DeleteInfo()
{
	char* temp = "select * from tb_books where id=";
	MysqlMain(temp);
	if (USER_PMYSQL_RESULT->rowNums != NULL)
	{
		int x = DrawHeader();
		GetXY(&conPoint);
		int y = conPoint.dwCursorPosition.Y;
		USER_PMYSQL_RESULT->row = mysql_fetch_row(USER_PMYSQL_RESULT->result);
		DrawInfo(x, y += 2, USER_PMYSQL_RESULT->row);
		printf("\nEnter any key to return ! \n");
		temp = "delete from tb_books where ID= ";
		memset(mysql_cmd, 0, sizeof(mysql_cmd));
		strcat(mysql_cmd, temp);
		strcat(mysql_cmd, pBooks->data.num);
		if (MysqlQuery(&USER_MYSQL, USER_PMYSQL_RESULT, mysql_cmd) == FAILED)
		{
			MysqlRelease(&mysql, pMysqlResult, RELEASE_MYSQL);
			return;
		}
		printf("\nDelete success !\n");
		printf("Enter any key to return ! ");
		MysqlRelease(&mysql, pMysqlResult, RELEASE_ALL);
		getch();
	}
	else
	{
		getch();
		printf("\nNo record find ! \n");
	}
	
}

void MysqlMain(char* temp)
{
	system("cls");
	USER_PMYSQL_RESULT = MysqlInit(&mysql, USER_PMYSQL_RESULT);  //初始化mysql结构
	if (MysqlConnect(&USER_MYSQL, USER_PMYSQL_RESULT) == FAILED)
	{
		getch();
		exit(0);
	}
	printf("**********************************");
	printf("\nPlease input the book id which you want to ： ");
	scanf("%s", &pBooks->data.num);
	strcat(mysql_cmd, temp);
	strcat(mysql_cmd, pBooks->data.num);
	if (MysqlQuery(&USER_MYSQL, USER_PMYSQL_RESULT, mysql_cmd) == FAILED)
	{
		MysqlRelease(&mysql, pMysqlResult, RELEASE_MYSQL);
		return;
	}
	if (MysqlGetResult(&USER_MYSQL, USER_PMYSQL_RESULT) == FAILED)
	{
		MysqlRelease(&mysql, pMysqlResult, RELEASE_ALL);
		return;
	}
}