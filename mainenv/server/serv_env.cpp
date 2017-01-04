#include "serv_env.h"
#include "log_env.h"


CServEnv* CServEnv::m_cServEnvIns = NULL;

CServEnv::CServEnv()
{
}

CServEnv::~CServEnv()
{
}

CServEnv* CServEnv::GetInstance()
{
	if( m_cServEnvIns == NULL)
	{
		m_cServEnvIns = new CServEnv;
	}

	return m_cServEnvIns;
}


void CServEnv::ReleaseInstance()
{
	if( m_cServEnvIns != NULL )
	{
		delete m_cServEnvIns;
		m_cServEnvIns = NULL;
	}
}

void CServEnv::startEnv()
{

	LOG_SERV_FATAL(" ************************************* \n");
	LOG_SERV_FATAL(" ******** SERV Env is start ********** \n");
	LOG_SERV_FATAL(" ************************************* \n");
	
}


void CServEnv::stopEnv()
{

}

