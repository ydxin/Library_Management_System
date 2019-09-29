#ifndef  _MYSQL_USER_H_
#define _MYSQL_USER_H_
#include <Windows.h>
#include "mysql.h"
#pragma comment(lib,"libmysql.lib")

typedef struct MysqlResult
{
	MYSQL_RES* result;		//��������ݼ�
	int					rowNum; //����
	MYSQL_ROW	row;			//���ݼ���

}MysqlResult;

extern char					mysql_ch[2];				//�����ַ�����
extern char					mysql_cmd[100];		//����sql�������
extern MYSQL				mysql;						//����mysql����
extern MYSQL_RES*	result;						//������������
extern MYSQL_ROW	row;							//�����б���
extern MysqlResult*	pMysqlResult;			//����ṹָ��

void MysqlInit(MYSQL* mysql);
void MysqlEnd();
void MysqlConnect(MYSQL *mysql);
void MysqlQuery(MYSQL* mysql,char *sql_cmd);
void MysqlGetResult(MysqlResult* myResult);
void MysqlRelease(MYSQL* mysql, MYSQL_RES* result);
#endif // ! _MYSQL_USER_H_
