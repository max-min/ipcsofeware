

#include <stdarg.h>
#include "log_env.h"



CLogEnv* CLogEnv::m_cLogEnvIns = NULL;

CLogEnv::CLogEnv()
{
}

CLogEnv::~CLogEnv()
{
}

CLogEnv* CLogEnv::GetInstance()
{
	if( m_cLogEnvIns == NULL)
	{
		m_cLogEnvIns = new CLogEnv;
	}

	return m_cLogEnvIns;
}


void CLogEnv::ReleaseInstance()
{
	if( m_cLogEnvIns != NULL )
	{
		delete m_cLogEnvIns;
		m_cLogEnvIns = NULL;
	}
}

void CLogEnv::startEnv()
{
	LOG_COMM_FATAL(" ************************************* \n");
	LOG_COMM_FATAL(" ********* Log Env is start ********** \n");
	LOG_COMM_FATAL(" ************************************* \n");
#if SIMULATOR_FLAG
//	m_logFd = open("ipcsoftware.log", "w+");
#else 
#endif 

	m_cLogEnvStr[NET_ENV]   = "NetEnv";
	m_cLogEnvStr[ALARM_ENV] = "AlarmEnv";
	m_cLogEnvStr[CODEC_EN]  = "CodecEnv";
	m_cLogEnvStr[PARAM_ENV] = "ParamEnv";
	m_cLogEnvStr[SERV_ENV]  = "ServEnv";
	m_cLogEnvStr[TIME_ENV]  = "TimeEnv";
	m_cLogEnvStr[TIMER_ENV] = "TimerEnv";
	m_cLogEnvStr[COMM_ENV]  = "CommEnv";
}


void CLogEnv::stopEnv()
{
#if SIMULATOR_FLAG
//		close(m_logFd);
#else 
#endif 

}


void CLogEnv::printf_list(const char* pFmt, ...)
{
	va_list ap;
	va_start(ap, pFmt);

	char *p = (char *)pFmt;
	for( p; (*p) != '\0'; p++)
	{
		if((*p) == '%')
		{
			putchar(*p);
			continue;
		}

		p++;
		if( (*p) == '\0')
		{
			break;
		}
		switch(*p)
		{
			case '%':
				putchar('%');
				break;
			case 'd':
				{
					int iParam = va_arg(ap, int);
					printf("%d", iParam);
				}
				break;
			case 'c':
				{
					int cParam = va_arg(ap, int);
					printf("%c",cParam);
				}
				break;
			case 'f':
				{
					float fParam = va_arg(ap, double);
					printf("%f", fParam);
				}
				break;
		}
	}
}

bool CLogEnv::GetLogEnvFlag(LOGENV enEnv)
{
	switch(enEnv)
	{
		case NET_ENV:
			return (NET_LOG_FLAG == 1)? true : false;
		case ALARM_ENV:
			return (ALARM_LOG_FLAG == 1)? true : false;
		case CODEC_EN:
			return (CODEC_LOG_FLAG == 1)? true : false;
		case PARAM_ENV:
			return (PARAM_LOG_FLAG == 1)? true : false;
		case SERV_ENV:
			return (SERVER_LOG_FLAG == 1)? true : false;
		case TIME_ENV:
			return (COMM_LOG_FLAG == 1)? true : false;
		case TIMER_ENV:
			return (COMM_LOG_FLAG == 1)? true : false;
		case COMM_ENV:
			return (COMM_LOG_FLAG == 1 ||COMM_LOG_FLAG == 1)? true : false;
		default:
			return false;
	}
}

