#include "mysql_user.h"
#include <stdio.h>
//变量定义
char					mysql_ch[2];		//定义字符变量
MYSQL				mysql;				//定义mysql变量
MYSQL_RES*	result;				//定义结果集变量
MYSQL_ROW	row;					//定义行变量
MysqlResult*	pMysqlResult; //定义结构指针

void MysqlInit(MYSQL* mysql)
{
	mysql_library_init(0, NULL, NULL);
	mysql_init(mysql);  //初始化mysql结构
}

void MysqlConnect(MYSQL* mysql)
{
	char host[10] = "127.0.0.1";
	char user[10] = "root";
	char password[10] = "ydx";
	char database[10] = "db_books";
	char portnum[10] = "3306";
	if (!mysql_real_connect(mysql, host, user, password,
		database, portnum,"NULL","0"))
	{
		printf("Can not connect %d: %s\n", mysql_errno(mysql),mysql_error(mysql));
	}
	else
	{
		printf("\nSuccess connect to the database ! \n");
	}
}


void MysqlQuery(MYSQL* mysql, char* sql_cmd)
{
	if (mysql_query(mysql, sql_cmd))
	{
		printf("\n Query the cmd failed ! ");
	}
	else
	{
		printf("\nSuccess query ! \n");
	}
}

void MysqlRelease(MYSQL* mysql, MYSQL_RES  *result)
{
	mysql_free_result(result);    //释放结果集
	mysql_close(mysql);          //释放连接
}


void MysqlGetResult(MysqlResult* myResult)
{
	myResult->result = mysql_store_result(&mysql); //获得结果集
	myResult->rowNum = mysql_num_rows(result);  //获得行数
	myResult->row = mysql_fetch_row(result);       //获取结果集的行  
}

void MysqlEnd()
{
	mysql_library_end();
}