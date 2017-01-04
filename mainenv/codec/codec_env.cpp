#include "codec_env.h"
#include "log_env.h"



CCodecEnv* CCodecEnv::m_cCodecEnvIns = NULL;

CCodecEnv::CCodecEnv()
{
}

CCodecEnv::~CCodecEnv()
{
}

CCodecEnv* CCodecEnv::GetInstance()
{
	if( m_cCodecEnvIns == NULL)
	{
		m_cCodecEnvIns = new CCodecEnv;
	}

	return m_cCodecEnvIns;
}


void CCodecEnv::ReleaseInstance()
{
	if( m_cCodecEnvIns != NULL )
	{
		delete m_cCodecEnvIns;
		m_cCodecEnvIns = NULL;
	}
}

void CCodecEnv::startEnv()
{
	LOG_CODEC_FATAL(" ************************************* \n");
	LOG_CODEC_FATAL(" ******** Codec Env is start ********* \n");
	LOG_CODEC_FATAL(" ************************************* \n");

}


void CCodecEnv::stopEnv()
{

}
