#ifndef __SERVER_ENV_H__
#define __SERVER_ENV_H__

#include "env.h"
#include "net_base.h"


class CServEnv:public CEnv, public CNetBase
{
	public:
		static CServEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CServEnv();
		virtual ~CServEnv();
		static CServEnv* m_cServEnvIns;
	public:
		// CEnv
		void startEnv();
		void stopEnv();

		// CNet
		int OnReceive(char *buf , int len);
		int OnSendData(char*buf ,int len);
		int OnAccept(int sockFd);
	

	
};



#endif //serv_env.h
