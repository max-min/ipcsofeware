#ifndef __TIMER_ENV_H__
#define __TIMER_ENV_H__

#include "env.h"


class CTimerEnv:public CEnv
{
	public:
		static CTimerEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CTimerEnv();
		virtual ~CTimerEnv();
		static CTimerEnv* m_cTimerEnvIns;
	public:
		void startEnv();
		void stopEnv();
	

	
}



#endif // timer_env.h
