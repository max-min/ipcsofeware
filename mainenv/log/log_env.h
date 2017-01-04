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
	FATAL_LEVEL = 0,
	ERROR_LEVEL = 1,
	INFO_LEVEL  = 2,
	DEBUG_LEVEL = 3
		
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

// common
#define LOG_COMM_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_COMM_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_COMM_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_COMM_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

// end 


// alarm 
#define LOG_ALARM_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_ALARM_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_ALARM_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_ALARM_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

// end 

// net 
#define LOG_NET_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_NET_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_NET_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_NET_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

// end 

// server
#define LOG_SERV_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_SERV_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_SERV_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_SERV_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

// end 

// codec
#define LOG_CODEC_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_CODEC_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_CODEC_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_CODEC_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

// end 

// param
#define LOG_PARAM_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_PARAM_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_PARAM_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_PARAM_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[%s/%d]:"pFmt NONE,  __FILE__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

// end 


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
		
	private:
		void printf_list(const char* pFmt, ...);

	private:	
		std::map<LOGENV, const char*> m_cLogEnvStr;
//		FILE* m_logFd;

	
};


#endif // log_env.h
