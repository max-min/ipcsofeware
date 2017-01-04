
#include "alarm_env.h"
#include "log_env.h"

CAlarmEnv* CAlarmEnv::m_cAlarmEnvIns = NULL;

CAlarmEnv::CAlarmEnv()
{
}

CAlarmEnv::~CAlarmEnv()
{
}

CAlarmEnv* CAlarmEnv::GetInstance()
{
	if( m_cAlarmEnvIns == NULL)
	{
		m_cAlarmEnvIns = new CAlarmEnv;
	}

	return m_cAlarmEnvIns;
}


void CAlarmEnv::ReleaseInstance()
{
	if( m_cAlarmEnvIns != NULL )
	{
		delete m_cAlarmEnvIns;
		m_cAlarmEnvIns = NULL;
	}
}

void CAlarmEnv::startEnv()
{
	LOG_ALARM_FATAL(" ************************************* \n");
	LOG_ALARM_FATAL(" ******** Alarm Env is start ********* \n");
	LOG_ALARM_FATAL(" ************************************* \n");

	
}


void CAlarmEnv::stopEnv()
{

}
