#include "mysql_user.h"
#include <stdio.h>
//��������
char					mysql_ch[2];		//�����ַ�����
MYSQL				mysql;				//����mysql����
MYSQL_RES*	result;				//������������
MYSQL_ROW	row;					//�����б���
MysqlResult*	pMysqlResult; //����ṹָ��

void MysqlInit(MYSQL* mysql)
{
	mysql_library_init(0, NULL, NULL);
	mysql_init(mysql);  //��ʼ��mysql�ṹ
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
	mysql_free_result(result);    //�ͷŽ����
	mysql_close(mysql);          //�ͷ�����
}


void MysqlGetResult(MysqlResult* myResult)
{
	myResult->result = mysql_store_result(&mysql); //��ý����
	myResult->rowNum = mysql_num_rows(result);  //�������
	myResult->row = mysql_fetch_row(result);       //��ȡ���������  
}

void MysqlEnd()
{
	mysql_library_end();
}