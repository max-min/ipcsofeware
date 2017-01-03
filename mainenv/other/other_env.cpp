#include "timer_env.h"

COthersEnv* COthersEnv::m_cOthersEnvIns = NULL;

COthersEnv::COthersEnv()
{
}

COthersEnv::~COthersEnv()
{
}

COthersEnv* COthersEnv::GetInstance();
{
	if( m_cOthersEnvIns == NULL)
	{
		m_cOthersEnvIns = new COthersEnv;
	}

	return m_cOthersEnvIns;
}


void COthersEnv::ReleaseInstance()
{
	if( m_cOthersEnvIns != NULL )
	{
		delete m_cOthersEnvIns;
		m_cOthersEnvIns = NULL;
	}
}

void COthersEnv::startEnv()
{

	
}


void COthersEnv::stopEnv()
{

}

