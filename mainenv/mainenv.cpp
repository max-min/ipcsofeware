#include "main_env.h"
#include "param_env.h"
#include "net_env.h"
#include "log_env.h"
#include "time_env.h"
#include "timer_env.h"
#include "serv_env.h"
#include "other_env.h"
#include "codes_env.h"
#include "alarm_env.h"




CMainEnv* CMainEnv::m_cMainEnvIns = NULL;

CMainEnv::CMainEnv()
{
}

CMainEnv::~CMainEnv()
{
}


CMainEnv* CMainEnv::GetInstance()
{
	if( m_cMainEnvIns == NULL )
	{
		m_cMainEnvIns = new CMainEnv;
	}

	return m_cMainEnvIns;
}

void CMainEnv::ReleaseInstance()
{
	if( m_cMainEnvIns != NULL )
	{
		delete m_cMainEnvIns;
		m_cMainEnvIns = NULL;
	}
}

void CMainEnv::InitEnvPoint()
{
	// param
	m_envList.push_back(CParamEnv::GetInstance());
	// net 
	m_envList.push_back(CNetEnv::GetInstance());
	// log 
	m_envList.push_back(CLogEnv::GetInstance());
	// rtc time  
	m_envList.push_back(CTimeEnv::GetInstance());
	// timer  
	m_envList.push_back(CTimerEnv::GetInstance());
	// codec server 
	m_envList.push_back(CCodecEnv::GetInstance());
	// alarm server 
	m_envList.push_back(CAlarmEnv::GetInstance());
	// net server 
	m_envList.push_back(CServEnv::GetInstance());
	// other server
	m_envList.push_back(COthersEnv::GetInstance());						
}

void CMainEnv::startMainEnv()
{

	std::list<CEnv*>::iterator pos = m_envList.begin();
	while( pos != m_envList.end())
	{
		CEnv *posEnv = *pos;
		posEnv->startEnv();
		pos++;
	}
}


void CMainEnv::stopMainEnv()
{
	std::list<CEnv*>::iterator pos = m_envList.begin();
	while( pos != m_envList.end())
	{
		CEnv *posEnv = *pos;
		posEnv->stopEnv();
		pos++;
	}

	m_envList.clear();
}






