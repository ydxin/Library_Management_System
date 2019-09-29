#include <stdio.h>
#include "public.h"
#include "main_window.h"
#include "mysql_user.h"
int main()
{
	pLinkInit();
	MysqlInit(&mysql);  //初始化mysql结构
	MysqlConnect(&mysql);
	//Menu();
	getch();
	return 0;
}