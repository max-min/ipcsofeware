#ifndef __TIMER_ENV_H__
#define __TIMER_ENV_H__

#include <pthread.h>
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

		long createTimer(int timesec);
		void cancelTimer(long timeid);
	private:
		void timerLoop();		
	private:
		//pthread_t m_pthreadId;
		//pthread_mutex_t timer_lock;
		//pthread_cond_t timer_cond;
		//std::map<long, int> m_timerMap;
	
}



#endif // timer_env.h
