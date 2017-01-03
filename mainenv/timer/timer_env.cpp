#include "timer_env.h"

CTimerEnv* CTimerEnv::m_cTimerEnvIns = NULL;

CTimerEnv::CTimerEnv()
{
}

CTimerEnv::~CTimerEnv()
{
}

CTimerEnv* CTimerEnv::GetInstance();
{
	if( m_cTimerEnvIns == NULL)
	{
		m_cTimerEnvIns = new CTimerEnv;
	}

	return m_cTimerEnvIns;
}


void CTimerEnv::ReleaseInstance()
{
	if( m_cTimerEnvIns != NULL )
	{
		delete m_cTimerEnvIns;
		m_cTimerEnvIns = NULL;
	}
}

void CTimerEnv::startEnv()
{

	
}


void CTimerEnv::stopEnv()
{

}

