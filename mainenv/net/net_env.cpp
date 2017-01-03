#include "net_env.h"



CNetEnv* CNetEnv::m_cNetEnvIns = NULL;

CNetEnv::CNetEnv()
{
}

CNetEnv::~CNetEnv()
{
}

CNetEnv* CNetEnv::GetInstance();
{
	if( m_cNetEnvIns == NULL)
	{
		m_cNetEnvIns = new CNetEnv;
	}

	return m_cNetEnvIns;
}


void CNetEnv::ReleaseInstance()
{
	if( m_cNetEnvIns != NULL )
	{
		delete m_cNetEnvIns;
		m_cNetEnvIns = NULL;
	}
}

void CNetEnv::startEnv()
{

	
}


void CNetEnv::stopEnv()
{

}

