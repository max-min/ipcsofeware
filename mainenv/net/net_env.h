#ifndef __NET_ENV_H__
#define __NET_ENV_H__

#include "env.h"

class CNetEnv:public CEnv
{
	public:
		static CNetEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CNetEnv();
		virtual ~CNetEnv();
		static CNetEnv* m_cNetEnvIns;
	public:
		void startEnv();
		void stopEnv();
	

	
};


#endif // net_env.h
