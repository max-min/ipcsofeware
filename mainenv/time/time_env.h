#ifndef __TIME_ENV_H__
#define __TIME_ENV_H__

#include "env.h"


class CTimeEnv:public CEnv
{
	public:
		static CTimeEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CTimeEnv();
		virtual ~CTimeEnv();
		static CTimeEnv* m_cTimeEnvIns;
	public:
		void startEnv();
		void stopEnv();
	

	
}


#endif // time_env.h
