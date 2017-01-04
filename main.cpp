
#include <stdio.h>
#include <stdlib.h>
#include "mainenv.h"


int main(void)
{	
	CMainEnv::GetInstance()->InitEnvPoint();
	CMainEnv::GetInstance()->startMainEnv();

	while(1)
	{
		int c = fgetc(stdin);
		fflush(stdout);	
		if( c == 'q' || c == 'e')
		{
			CMainEnv::GetInstance()->stopMainEnv();
			CMainEnv::ReleaseInstance();
			exit(0);
		}
	}
}
