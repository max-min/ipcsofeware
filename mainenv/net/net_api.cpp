#include "net_api.h"



CNet* CNet::m_cNetIns = NULL;
CNet::CNet()
{
	m_eventBase = NULL;
}

CNet::~CNet()
{
}

CNet* CNet::GetInstance()
{
	if( m_cNetIns == NULL )
	{
		m_cNetIns = new CNet;
	}

	return m_cNetIns;
}

void CNet::ReleaseInstance()
{
	if( m_cNetIns != NULL )
	{
		delete m_cNetIns;
		m_cNetIns = NULL;
	}
}

int CNet::startNetServer()
{

  	m_eventBase = event_base_new();

	if( m_eventBase )
	{
		LOG_NET_INFO(" Net Event start\n");
		event_base_dispatch(m_eventBase);
		return 0;
	}

	LOG_NET_ERROR("Net Event start error \n");
	return 0;
}

void CNet::stopNetServer()
{
}



int CNet::listenTcpServer(char *ip, int port)
{
	
}
int CNet::connectTcpServer(char* ip, int port)
{
}

int CNet::sendTcpData(int socketFd, char* buf, int len)
{
}
int CNet::readTcpData(int socketFd, char* buf, int len)
{
}

