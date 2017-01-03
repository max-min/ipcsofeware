#ifndef __ALARM_ENV_H__
#define __ALARM_ENV_H__

#include "env.h"

class CAlarmEnv:public CEnv
{
	public:
		static CAlarmEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CAlarmEnv();
		virtual ~CAlarmEnv();
		static CAlarmEnv* m_cAlarmEnvIns;
	public:

		void startEnv();
		void stopEnv();
	
}


#endif // alarm_env.h
