#ifndef __SERVER_ENV_H__
#define __SERVER_ENV_H__

#include "env.h"


class CServEnv:public CEnv
{
	public:
		static CServEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CServEnv();
		virtual ~CServEnv();
		static CServEnv* m_cServEnvIns;
	public:
		void startEnv();
		void stopEnv();
	

	
}



#endif //serv_env.h
