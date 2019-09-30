#include <stdio.h>
#include "public.h"
#include "main_window.h"
#include "mysql_user.h"

int main()
{

	//Init 
	pLinkInit();
	USER_PMYSQL_RESULT=MysqlInit(&USER_MYSQL, USER_PMYSQL_RESULT);  //初始化mysql结构
	//Menu//菜单
	while (1)
	{
		MainMenu();
	}
	return 0;
}