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
#if X86_COMM  
//	m_paramFd = open("param_conf.xml", "rw+")
	loadXmlConf();
#else 
//	m_paramFd = open("param.conf", "rw+");
#endif 
	
}


void CParamEnv::stopEnv()
{

//	close(m_paramFd);
}


void CParamEnv::loadXmlConf()
{
	TiXmlDocument conf("param_conf.xml");
	
	if( !conf.load())
	{
		LOG_PARAM_ERROR("load x86 param_conf.xml failed\n");
		return ;
	}
		
	TiXmlElement* root = conf.RootElement(); 	
	
	TiXmlNode* confEle = root->FirstChild("config");
	if( confEle)
	{
		TiXmlNode* logEle = confEle->FirstChild("log");	
		if( logEle)
		{
			logEle->FirstChild()->ToElement()->GetText();	
		}
	}
}
