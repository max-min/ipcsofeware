
#include <stdio.h>
#include "mainenv.h"

#include "log_env.h"

int main(void)
{	
	LOG_COMM_FATAL(" the server will be start \n");
	LOG_COMM_ERROR(" the server will be start \n");
	LOG_COMM_INFO(" the server will be start \n");
	LOG_COMM_DEBUG(" the server will be start\n");
	CMainEnv::GetInstance()->InitEnvPoint();
	CMainEnv::GetInstance()->startMainEnv();

	while(1)
	{
		char c = getchar();
		if( c == 'q' || c == 'e')
		{
			CMainEnv::GetInstance()->stopMainEnv();

			CMainEnv::ReleaseInstance();
		}
	}
}
