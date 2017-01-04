#include "timer_env.h"
#include "log_env.h"

CTimerEnv* CTimerEnv::m_cTimerEnvIns = NULL;

CTimerEnv::CTimerEnv()
{
}

CTimerEnv::~CTimerEnv()
{
}

CTimerEnv* CTimerEnv::GetInstance()
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

void* threadfunc(void* handle)
{
	CTimerEnv* pTimer = (CTimerEnv*)handle;
	
	if( pTimer != NULL )
	{
		pTimer->timerLoop();
	}
	
	return NULL;
}

void CTimerEnv::startEnv()
{
	
	LOG_COMM_FATAL(" ************************************* \n");
	LOG_COMM_FATAL(" ********* Timer Env is start ********** \n");
	LOG_COMM_FATAL(" ************************************* \n");

	//pt_mutex_init(&timer_lock);
	//pthread_cond_init(&timer_cond);
	
	int ret = pthread_create(&m_pthreadId, NULL, threadfunc, (void*)this);
	if( ret != 0)
	{
	}
}


void CTimerEnv::stopEnv()
{
	//pthread_mutex_destroy(timer_lock);
	//pthread_cond_destroy(timer_cond)
}

void CTimerEnv::timerLoop()
{

}

long CTimerEnv::createTimer(int timesec)
{

}

void CTimerEnv::cancelTimer(long timeid)
{
}


