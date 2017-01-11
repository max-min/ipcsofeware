#include "param_env.h"
#include "log_env.h"
//#include "param_struct.h"


CParamEnv* CParamEnv::m_cParamEnvIns = NULL;

CParamEnv::CParamEnv()
{
//	m_paramFd = NULL;
	m_rootEle = NULL;
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
	
	if( (!conf.LoadFile()) || (m_rootEle = conf.RootElement()) == NULL)
	{
		LOG_PARAM_ERROR("load x86 param_conf.xml failed\n");
		return ;
	}
	
	LOG_PARAM_INFO(" load param_conf.xml success. \n");
	
//	PlatformParam_S stPF;
	
//	GetPlatformParam((void*)&stPF);
}
		
void CParamEnv::loadLogConf()
{
	
	TiXmlNode* confEle = m_rootEle->FirstChild("config");
	if( confEle)
	{
		TiXmlNode* logEle = confEle->FirstChild("log");	
		if( logEle)
		{
			const char * level = logEle->FirstChild()->ToElement()->GetText();	
			LOG_PARAM_DEBUG("%s \n", level);
				
		}
	}
}

void CParamEnv::GetPlatformParam(void *param)
{
#if 0
	PlatformParam_S *pPlatformPar = (PlatformParam_S*)param;
	
	TiXmlNode* paramNode = m_rootEle->FirstChild("param");
	if( paramNode != NULL)
	{
		TiXmlNode* pfNode = paramNode->FirstChild("platform");
		if( pfNode != NULL )
		{
			for(TiXmlElement* elem = pfNode->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
			{
				 LOG_PARAM_DEBUG("%s \n", elem->GetText());
				 LOG_PARAM_DEBUG("%s \n", elem->Value());
				 LOG_PARAM_INFO("#####################\n");
			}
		}
		
	}

#endif 
}




