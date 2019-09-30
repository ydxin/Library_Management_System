#include "mysql_user.h"
#include <stdio.h>
//��������
char					mysql_cmd[500] = {0};		//�����ַ�����
MysqlResult*   pMysqlResult;
MYSQL				mysql;


MysqlResult* MysqlInit(MYSQL* mysql,MysqlResult* pMysqlResult)
{
	pMysqlResult = (MysqlResult*)malloc(sizeof(MysqlResult));
	mysql_library_init(0, NULL, NULL);
	mysql_init(mysql);  //��ʼ��mysql�ṹ
	 //���ñ��뷽ʽ
	if (!mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "gbk"))//�����ַ���
		printf("Set the option success ! \n");
	else
		printf("Set the option failed ! \n");
	return pMysqlResult;
}

int  MysqlConnect(MYSQL* mysql, MysqlResult* pMysqlResult)
{
	char* host = "localhost";
	char* user = "root";
	char* password= "ydx";
	char* database= "db_books";
	unsigned int  portnum=3306;  
	if (!mysql_real_connect(mysql, host, user, password,
		database, portnum,"NULL","0"))
	{
		printf("Error %d: %s\n", mysql_errno(mysql),mysql_error(mysql));
		return FAILED;
	}
	else
	{
		printf("\nSuccess connect to the database ! \n");
		return SUCCESS;
	}
}


int MysqlQuery(MYSQL* mysql, MysqlResult* pMysqlResult,char* sql_cmd)
{
	if (mysql_query(mysql, sql_cmd))
	{
		printf("\n Query the cmd failed ! \n");
		return FAILED;
	}
	else
	{
		printf("\nSuccess query ! \n");
		return SUCCESS;
	}
}

void MysqlRelease(MYSQL* mysql, MysqlResult* pMysqlResult,int cmd)
{
	switch (cmd)
	{
	case RELEASE_ALL:
		mysql_free_result(pMysqlResult->result);    //�ͷŽ����
		mysql_close(mysql);          //�ͷ�����
		break;
	case	RELEASE_RESULT:
		mysql_free_result(pMysqlResult->result);    //�ͷŽ����
		break;
	case RELEASE_MYSQL:
		mysql_close(mysql);          //�ͷ�����
		break;
	default:
		return;
	}
}


int MysqlGetResult(MYSQL* mysql, MysqlResult* pMysqlResult)
{
	pMysqlResult->result = mysql_store_result(mysql); //��ý����
	pMysqlResult->rowNums = mysql_num_rows(pMysqlResult->result);  //�������
	if (pMysqlResult->rowNums == 0)
	{
		printf("\nNo record find ! ");
		return FAILED;
	}
	else
		return SUCCESS;
}

void MysqlEnd(MYSQL* mysql, MysqlResult* myResult)
{
	mysql_library_end();
	free(myResult);
}

