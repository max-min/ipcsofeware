#ifndef __PARAM_ENV_H__
#define __PARAM_ENV_H__


//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
#include "env.h"

class CParamEnv:public CEnv
{
	public:
		static CParamEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CParamEnv();
		virtual ~CParamEnv();
		static CParamEnv* m_cParamEnvIns;
	public:
		void startEnv();
		void stopEnv();
	
	private:
//		FILE* m_paramFd;
	
};

#endif // param_env.h
