#include <stdio.h>
#include "public.h"
#include "main_window.h"
#include "mysql_user.h"
int main()
{
	pLinkInit();
	MysqlInit(&mysql);  //��ʼ��mysql�ṹ
	MysqlConnect(&mysql);
	//Menu();
	getch();
	return 0;
}