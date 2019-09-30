#ifndef  _MYSQL_USER_H_
#define _MYSQL_USER_H_
#include <Windows.h>
#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

#define SUCCESS				0
#define FAILED					1
#define RELEASE_ALL			0
#define RELEASE_RESULT	1
#define RELEASE_MYSQL	2
typedef struct MysqlResult
{
	MYSQL_RES*		result;						//������������
	MYSQL_ROW		row;							//�����б���
	my_ulonglong		rowNums;				//��������
}MysqlResult;


extern	char				  mysql_cmd[500];		//�����ַ�����
extern	MysqlResult* pMysqlResult;
extern	MYSQL			  mysql;

#define USER_MYSQL					mysql
#define USER_PMYSQL_RESULT pMysqlResult

MysqlResult* MysqlInit(MYSQL* mysql, MysqlResult* pMysqlResult);
int	MysqlConnect(MYSQL* mysql, MysqlResult* pMysqlResult);
int	MysqlQuery(MYSQL* mysql, MysqlResult* pMysqlResult, char* sql_cmd);
void MysqlRelease(MYSQL* mysql, MysqlResult* pMysqlResult, int cmd);
int MysqlGetResult(MYSQL* mysql, MysqlResult* myResult);
void MysqlEnd(MYSQL* mysql, MysqlResult* myResult);

#endif // ! _MYSQL_USER_H_
