

#ifndef __MAIN_ENV_H__
#define __MAIN_ENV_H__

#include <list>
#include "env.h"

class CMainEnv
{
	public:
		static CMainEnv* GetInstance();
		static void  ReleaseInstance();
	private:
		CMainEnv();
		virtual ~CMainEnv();
		static CMainEnv* m_cMainEnvIns;


	public:
		void InitEnvPoint();
		void startMainEnv();
		void stopMainEnv();

	private:
		std::list<CEnv*> m_envList;		
};




#endif // mainenv.h
