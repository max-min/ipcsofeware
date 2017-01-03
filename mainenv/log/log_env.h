#ifndef __LOG_ENV_H__
#define __LOG_ENV_H__


#include "env.h"

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
