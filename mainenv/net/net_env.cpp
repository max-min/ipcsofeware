#include "net_env.h"
#include "log_env.h"
#include "net_api.h"



CNetEnv* CNetEnv::m_cNetEnvIns = NULL;

CNetEnv::CNetEnv()
{
}

CNetEnv::~CNetEnv()
{
}

CNetEnv* CNetEnv::GetInstance()
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

	LOG_NET_FATAL(" ************************************* \n");
	LOG_NET_FATAL(" ********* Net Env is start ********** \n");
	LOG_NET_FATAL(" ************************************* \n");

	CNet::GetInstance()->startNetServer();
}


void CNetEnv::stopEnv()
{
	CNet::GetInstance()->stopNetServer();
}

