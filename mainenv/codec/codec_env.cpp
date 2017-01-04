#include "codec_env.h"



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

	
}


void CCodecEnv::stopEnv()
{

}
