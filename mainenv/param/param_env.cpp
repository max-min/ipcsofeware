#include "param_env.h"
#include "log_env.h"



CParamEnv* CParamEnv::m_cParamEnvIns = NULL;

CParamEnv::CParamEnv()
{
//	m_paramFd = NULL;
}

CParamEnv::~CParamEnv()
{
}

CParamEnv* CParamEnv::GetInstance()
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
	LOG_PARAM_FATAL(" ************************************* \n");
	LOG_PARAM_FATAL(" ******** Param Env is start ********* \n");
	LOG_PARAM_FATAL(" ************************************* \n");
#if SIMULATOR_FLAG 
//	m_paramFd = open("param.conf", "rw+")
#else 
//	m_paramFd = open("param.conf", "rw+");
#endif 
	
}


void CParamEnv::stopEnv()
{

//	close(m_paramFd);
}

