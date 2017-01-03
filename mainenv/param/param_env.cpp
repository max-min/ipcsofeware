#include "param_env.h"



CParamEnv* CParamEnv::m_cNetEnvIns = NULL;

CParamEnv::CParamEnv()
{
}

CParamEnv::~CParamEnv()
{
}

CParamEnv* CParamEnv::GetInstance();
{
	if( m_cParamEnvIns == NULL)
	{
		m_cParamEnvIns = new CParamEnv;
	}

	return m_cParamEnvIns;
}


void CParamEnv::ReleaseInstance()
{
	if( m_cParamEnvIns != NULL )
	{
		delete m_cParamEnvIns;
		m_cParamEnvIns = NULL;
	}
}

void CParamEnv::startEnv()
{

	
}


void CParamEnv::stopEnv()
{

}

