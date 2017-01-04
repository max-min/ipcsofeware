#include "time_env.h"
#include "log_env.h"


CTimeEnv* CTimeEnv::m_cTimeEnvIns = NULL;

CTimeEnv::CTimeEnv()
{
}

CTimeEnv::~CTimeEnv()
{
}

CTimeEnv* CTimeEnv::GetInstance()
{
	if( m_cTimeEnvIns == NULL)
	{
		m_cTimeEnvIns = new CTimeEnv;
	}

	return m_cTimeEnvIns;
}


void CTimeEnv::ReleaseInstance()
{
	if( m_cTimeEnvIns != NULL )
	{
		delete m_cTimeEnvIns;
		m_cTimeEnvIns = NULL;
	}
}

void CTimeEnv::startEnv()
{

	LOG_COMM_FATAL(" ************************************* \n");
	LOG_COMM_FATAL(" ********* Time Env is start ********** \n");
	LOG_COMM_FATAL(" ************************************* \n");
	
}


void CTimeEnv::stopEnv()
{

}

