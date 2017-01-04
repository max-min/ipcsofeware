
#include "log_env.h"



CLogEnv* CLogEnv::m_cLogEnvIns = NULL;

CLogEnv::CLogEnv()
{
	m_logFd = NULL;
}

CLogEnv::~CLogEnv()
{
}

CLogEnv* CLogEnv::GetInstance();
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

	for(char *p = pFmt; (*p) != '\0'; p++)
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
				int iParam = va_arg(ap, int);
				printf("%d", iParam);
				break;
			case 'c':
				int cParam = va_arg(ap, int);
				printf("%c",cParam);
			case 'f':
				float fParam = va_arg(ap, double);
				printf("%f", fParam);
				
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
			return (TIME_LOG_FLAG == 1)? true : false;
		case TIMER_ENV:
			return (TIMER_LOG_FLAG == 1)? true : false;
		case COMM_ENV:
			return (LOG_LOG_FLAG == 1 ||OTHER_LOG_FLAG == 1)? true : false;
		default:
			return false;
	}
}
void CLogEnv::LOG_FATAL(LOGENV enEnv, const char* pFmt, ...)
{
	if( GetLogEnvFlag(enEnv)
	{
		
		if( LOG_Flag >= FATAL_LEVEL )
		{
			fprintf(stderr, RED "[%s/%s/%d]:"pFmt NONE, m_cLogEnvStr[enEnv],__FILE__, __LINE__, ##__VA_ARGS__);
			fflush(stderr);
		}
	} 
}
void CLogEnv::LOG_ERROR(LOGENV enEnv, const char* pFmt, ...)
{
	if( GetLogEnvFlag(enEnv)
	{
		
		if( LOG_Flag >= ERROR_LEVEL )
		{
			fprintf(stderr, L_RED "[%s/%s/%d]:"pFmt NONE, m_cLogEnvStr[enEnv],__FILE__, __LINE__, ##__VA_ARGS__);
			fflush(stderr);
		}
	} 
}
void CLogEnv::LOG_WARN(LOGENV enEnv, const char* pFmt, ...)
{
	if( GetLogEnvFlag(enEnv)
	{
		
		if( LOG_Flag >= WARN_LEVEL )
		{
			fprintf(stderr, YELLOW "[%s/%s/%d]:"pFmt NONE, m_cLogEnvStr[enEnv],__FILE__, __LINE__, ##__VA_ARGS__);
			fflush(stderr);
		}
	} 
}
void CLogEnv::LOG_INFO(LOGENV enEnv, const char* pFmt, ...)
{
	if( GetLogEnvFlag(enEnv)
	{
		
		if( LOG_Flag >= INFO_LEVEL )
		{
			fprintf(stderr, GREEN "[%s/%s/%d]:"pFmt NONE, m_cLogEnvStr[enEnv],__FILE__, __LINE__, ##__VA_ARGS__);
			fflush(stderr);
		}
	} 
}
void CLogEnv::LOG_DEBUG(LOGENV enEnv, const char* pFmt, ...)
{
	if( GetLogEnvFlag(enEnv)
	{
		
		if( LOG_Flag >= DEBUG_LEVEL )
		{
			fprintf(stderr, "[%s/%s/%d]:"pFmt NONE, m_cLogEnvStr[enEnv],__FILE__, __LINE__, ##__VA_ARGS__);
			fflush(stderr);
		}
	} 
}


