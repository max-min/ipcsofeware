#include "serv_env.h"
#include "log_env.h"


#define LISTEN_PORT  10089
CServEnv* CServEnv::m_cServEnvIns = NULL;

CServEnv::CServEnv()
{
}

CServEnv::~CServEnv()
{
}

CServEnv* CServEnv::GetInstance()
{
	if( m_cServEnvIns == NULL)
	{
		m_cServEnvIns = new CServEnv;
	}

	return m_cServEnvIns;
}


void CServEnv::ReleaseInstance()
{
	if( m_cServEnvIns != NULL )
	{
		delete m_cServEnvIns;
		m_cServEnvIns = NULL;
	}
}

void CServEnv::startEnv()
{

	LOG_SERV_FATAL(" ************************************* \n");
	LOG_SERV_FATAL(" ******** SERV Env is start ********** \n");
	LOG_SERV_FATAL(" ************************************* \n");

	//监听本地服务，传入this指针，当回调accept的时候，设置accept的客户端sockfd的指针句柄。
	// 有数据产生时，则回调 OnReceiv()
 	CNet::listenTcpServer("127.0.0.1", LISTEN_PORT, this);
	
}


void CServEnv::stopEnv()
{

}



int CServEnv::OnReceive(char *buf , int len)
{
	
}

int CServEnv::OnSendData(char*buf ,int len)
{

}

int CServEnv::OnAccept(int sockFd);
{
	if( sockFd > 0 )
	{
		CNet::GetInstance()->setNetHandle(sockFd, this);
	}

	return 0;
}


