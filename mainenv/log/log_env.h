#ifndef __LOG_ENV_H__
#define __LOG_ENV_H__

#include "env.h"

class CNetEnv:public CEnv
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
	

	
}




#endif // log_env.h
