#ifndef  _MYSQL_USER_H_
#define _MYSQL_USER_H_
#include <Windows.h>
#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

typedef struct MysqlResult
{
	MYSQL_RES* result;		//结果的数据集
	int					rowNum; //行数
	MYSQL_ROW	row;			//数据集行

}MysqlResult;

extern char					mysql_ch[2];				//定义字符变量
extern char					mysql_cmd[100];		//定于sql语句数组
extern MYSQL				mysql;						//定义mysql变量
extern MYSQL_RES*	result;						//定义结果集变量
extern MYSQL_ROW	row;							//定义行变量
extern MysqlResult*	pMysqlResult;			//定义结构指针

void MysqlInit(MYSQL* mysql);
void MysqlEnd();
void MysqlConnect(MYSQL *mysql);
void MysqlQuery(MYSQL* mysql,char *sql_cmd);
void MysqlGetResult(MysqlResult* myResult);
void MysqlRelease(MYSQL* mysql, MYSQL_RES* result);
#endif // ! _MYSQL_USER_H_
