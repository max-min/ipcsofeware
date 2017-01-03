#ifndef __TIMER_ENV_H__
#define __TIMER_ENV_H__

#include "env.h"


class COthersEnv:public CEnv
{
	public:
		static COthersEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		COthersEnv();
		virtual ~COthersEnv();
		static COthersEnv* m_cOthersEnvIns;
	public:
		void startEnv();
		void stopEnv();
	

	
};



#endif // timer_env.h
