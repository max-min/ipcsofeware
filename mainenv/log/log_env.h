#ifndef __LOG_ENV_H__
#define __LOG_ENV_H__


#include "env.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>



#define FATAL_LEVEL 0
#define ERROR_LEVEL 1
#define WARN_LEVEL  2
#define DEBUG_LEVEL 3
#define INFO_LEVEL  4


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

#define DBG_SRV_INFO(pFmt, ...) \
	do{\
		fprintf(stderr, "[%s/%d]:"pFmt, __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}while(0)


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
	
	private:
//		FILE* m_logFd;
	
};


#endif // log_env.h
