#include <stdio.h>
#include "public.h"
#include "main_window.h"
#include "mysql_user.h"

int main()
{

	//Init 
	pLinkInit();
	USER_PMYSQL_RESULT=MysqlInit(&USER_MYSQL, USER_PMYSQL_RESULT);  //��ʼ��mysql�ṹ
	//Menu//�˵�
	while (1)
	{
		MainMenu();
	}
	return 0;
}