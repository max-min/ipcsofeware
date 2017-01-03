
#include <stdio.h>
#include "mainenv.h"


int main(void)
{	

	CMainEnv::GetInstance()->InitEnvPoint();
	CMainEnv::GetInstance()->startMainEnv();

	char c = getchar();

	if( c== 'q' || c == 'e')
	{
		CMainEnv::GetInstance()->stopMainEnv();

		CMainEnv::ReleaseInstance();
	}
}
