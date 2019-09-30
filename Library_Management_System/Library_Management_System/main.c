#include <stdio.h>
#include "public.h"
#include "main_window.h"
#include "mysql_user.h"

int main()
{

	//Init 
	pLinkInit();
	//Menu
	while (1)
	{
		MainMenu();
	}
	return 0;
}