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


/**************************
 *
 * 
 **************************/
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
#define NET_LOG_FLAG       0
#define ALARM_LOG_FLAG     0
#define CODEC_LOG_FLAG     0
#define COMM_LOG_FLAG      0
#define PARAM_LOG_FLAG     1
#define SERVER_LOG_FLAG    1


// __FILENAME__ is full path this is just get the file name 
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

// common
#if COMM_LOG_FLAG 
#define LOG_COMM_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[COMM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_COMM_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[COMM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_COMM_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[COMM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_COMM_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[COMM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}
#else 
#define LOG_COMM_FATAL(pFmt, ...) 
#define LOG_COMM_ERROR(pFmt, ...) 
#define LOG_COMM_INFO(pFmt, ...) 
#define LOG_COMM_DEBUG(pFmt, ...) 

#endif 
// end 


// alarm 
#if ALARM_LOG_FLAG
#define LOG_ALARM_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[ALARM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_ALARM_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[ALARM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_ALARM_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[ALARM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_ALARM_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[ALARM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}
#else 
#define LOG_ALARM_FATAL(pFmt, ...) 
#define LOG_ALARM_ERROR(pFmt, ...) 
#define LOG_ALARM_INFO(pFmt, ...) 
#define LOG_ALARM_DEBUG(pFmt, ...) 
#endif 
// end 


// net 
#if NET_LOG_FLAG 
#define LOG_NET_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[NET/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_NET_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[NET/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_NET_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[NET/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_NET_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[NET/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}
#else 
#define LOG_NET_FATAL(pFmt, ...) 
#define LOG_NET_ERROR(pFmt, ...) 
#define LOG_NET_INFO(pFmt, ...) 
#define LOG_NET_DEBUG(pFmt, ...) 
#endif 
// end 

// server
#if SERVER_LOG_FLAG 
#define LOG_SERV_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[SERV/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_SERV_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[SERV/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_SERV_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[SERV/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_SERV_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[SERV/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}
#else 
#define LOG_SERV_FATAL(pFmt, ...) 
#define LOG_SERV_ERROR(pFmt, ...) 
#define LOG_SERV_INFO(pFmt, ...) 
#define LOG_SERV_DEBUG(pFmt, ...) 
#endif 
// end 

// codec
#if CODEC_LOG_FLAG 
#define LOG_CODEC_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[CODEC/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_CODEC_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[CODEC/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_CODEC_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[CODEC/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_CODEC_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[CODEC/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}
#else 
#define LOG_CODEC_FATAL(pFmt, ...) 
#define LOG_CODEC_ERROR(pFmt, ...) 
#define LOG_CODEC_INFO(pFmt, ...) 
#define LOG_CODEC_DEBUG(pFmt, ...) 
#endif 
// end 

// param
#if PARAM_LOG_FLAG 
#define LOG_PARAM_FATAL(pFmt, ...) \
	if( LOG_Flag >= FATAL_LEVEL )\
	{\
		fprintf(stderr, L_RED "[PARAM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_PARAM_ERROR(pFmt, ...) \
	if( LOG_Flag >= ERROR_LEVEL )\
	{\
		fprintf(stderr, RED "[PARAM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_PARAM_INFO(pFmt, ...) \
	if( LOG_Flag >= INFO_LEVEL )\
	{\
		fprintf(stderr, L_BLACK "[PARAM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}

#define LOG_PARAM_DEBUG(pFmt, ...) \
	if( LOG_Flag >= DEBUG_LEVEL )\
	{\
		fprintf(stderr, L_GREEN "[PARAM/%s/%d]:"pFmt NONE,  __FILENAME__, __LINE__, ##__VA_ARGS__);\
		fflush(stderr);\
	}
#else 
#define LOG_PARAM_FATAL(pFmt, ...) 
#define LOG_PARAM_ERROR(pFmt, ...) 
#define LOG_PARAM_INFO(pFmt, ...) 
#define LOG_PARAM_DEBUG(pFmt, ...) 
#endif 
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
