
#include "log_env.h"



CLogEnv* CLogEnv::m_cLogEnvIns = NULL;

CLogEnv::CLogEnv()
{
}

CLogEnv::~CLogEnv()
{
}

CLogEnv* CLogEnv::GetInstance();
{
	if( m_cLogEnvIns == NULL)
	{
		m_cLogEnvIns = new CLogEnv;
	}

	return m_cLogEnvIns;
}


void CLogEnv::ReleaseInstance()
{
	if( m_cLogEnvIns != NULL )
	{
		delete m_cLogEnvIns;
		m_cLogEnvIns = NULL;
	}
}

void CLogEnv::startEnv()
{

	
}


void CLogEnv::stopEnv()
{

}
