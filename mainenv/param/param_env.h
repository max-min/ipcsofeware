#ifndef __PARAM_ENV_H__
#define __PARAM_ENV_H__

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
	

	
}

#endif // param_env.h
