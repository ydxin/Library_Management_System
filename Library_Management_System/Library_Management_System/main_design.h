#ifndef _MAIN_DESIGN_H_
#define _MAIN_DESIGN_H_
#include "public.h"

#define HEAD_TPYES			3
#define HEAD_LENGTH      50
#define HEAD_INTERVAL	(HEAD_LENGTH/(HEAD_TPYES+1))
#define HEAD_HEIGHT		(HEAD_INTERVAL*HEAD_TPYES)


void Close();
int  DrawHeader();
void pLinkInit();
void ShowInfo();
void DrawInfo(int x, int y, MYSQL_ROW	 row);
void MysqlMain(char* temp);
void InsertInfo();
void ModifyInfo();
void SearchInfo();
void DeleteInfo();

#endif