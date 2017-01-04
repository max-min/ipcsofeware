#ifndef __LOG_ENV_H__
#define __LOG_ENV_H__


#include "env.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <map>


#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

enum LOGLEVEL
{
	SYS_LEVEL   = 0,
	FATAL_LEVEL = 1,
	ERROR_LEVEL = 2,
	WARN_LEVEL  = 3,
	INFO_LEVEL  = 4,
	DEBUG_LEVEL = 5
		
};

enum LOGENV
{
	NET_ENV   = 0,
	ALARM_ENV = 1,
	CODEC_EN  = 2,
	PARAM_ENV = 3,
	SERV_ENV  = 4,
	TIME_ENV  = 5,
	TIMER_ENV = 6,
	COMM_ENV  = 7
};

// the flag of print the log level in the application
#define LOG_Flag 3 

// the flag of the env module
#define NET_LOG_FLAG       1
#define ALARM_LOG_FLAG     1
#define CODEC_LOG_FLAG     1
#define LOG_LOG_FLAG       1
#define OTHER_LOG_FLAG     1
#define PARAM_LOG_FLAG     1
#define SERVER_LOG_FLAG    1
#define TIME_LOG_FLAG      1
#define TIMER_LOG_FLAG     1


class CLogEnv:public CEnv
{
	public:
		static CLogEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CLogEnv();
		virtual ~CLogEnv();
		static CLogEnv* m_cLogEnvIns;
	public:
		void startEnv();
		void stopEnv();

		bool GetLogEnvFlag(LOGENV enEnv);
		void LOG_FATAL(LOGENV enEnv, const char* pFmt, ...);
		void LOG_ERROR(LOGENV enEnv, const char* pFmt, ...);
		void LOG_WARN(LOGENV enEnv, const char* pFmt, ...);
		void LOG_INFO(LOGENV enEnv, const char* pFmt, ...);
		void LOG_DEBUG(LOGENV enEnv, const char* pFmt, ...);
		
	private:
		void printf_list();

	private:	
		std::map<LOGENV, char*> m_cLogEnvStr;
//		FILE* m_logFd;

	
};


#endif // log_env.h
