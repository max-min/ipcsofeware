#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "net_api.h"
#include "log_env.h"

#define MAX_RECV_LEN 1024*10

CNet* CNet::m_cNetIns = NULL;
CNet::CNet()
{
	m_eventBase = NULL;
	pthread_mutex_init(&m_mutexLock, NULL);
	m_recvBuffer = NULL;

	m_recvBuffer = new char[MAX_RECV_LEN];
	if( m_recvBuffer == NULL )
	{
		LOG_NET_ERROR(" m_recvBuffer new space failed\n");
		exit(-1);
	}

	memset(m_recvBuffer, '\0', MAX_RECV_LEN);
}

CNet::~CNet()
{
	pthread_mutex_destroy(&m_mutexLock);
	if( m_recvBuffer != NULL )
	{
		delete []m_recvBuffer;
	}
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

void thread_func(void *args)
{
	CNet* pNet = (CNet*)args;
	if( pNet != NULL )
	{
		pNet->InitEventLoop();
	}
}
int CNet::startNetServer()
{

	if( pthread_create(&m_eventloopID, NULL, thread_func, this) != 0 )
	{
		LOG_NET_ERROR(" create libevent loop thread error:%s\n", stderror(errno));
		return -1;
	}

}

void CNet::InitEventLoop()
{

  	m_eventBase = event_base_new();
	if( m_eventBase == NULL )
	{
		
		LOG_NET_ERROR("Net Event start error base == NULL\n");
		return;
	}
	
	LOG_NET_INFO(" Net Event Loop start\n");
	event_base_dispatch(m_eventBase);
}

void CNet::stopNetServer()
{
}

struct event_base* CNet::getEventBase()
{
	return m_eventBase;
}

// 读事件  
void onReadEvent(int clifd,short ievent,void *arg)  
{  

    int ilen;  
    char *pBuf = CNet::GetInstance()->getRecvBuffer();  
  
    ilen = recv(clifd, pBuf, MAX_RECV_LEN, 0);  
    if(ilen <= 0)  
    {     
        struct event *pread = (struct event*)arg;  
        event_del(pread);  
        delete pread;  
        close(clifd);  
        return;  
    }       
	CNetBase* pNetBase = CNet::GetInstance()->getHandle(clifd);
	if( pNetBase == NULL )
	{
		LOG_NET_INFO("not found the socketFd NetBaseHanlde sockFd=%d\n", clifd);
		return;
	}

	pNetBase->OnReceive(pBuf, ilen);
}  

// 连接事件  
void onAcceptEvent(int svrfd,short ievent,void *arg)  
{  
    int clifd;  
    struct sockaddr_in cliaddr;  
  
    socklen_t sinsize = sizeof(cliaddr);  
    clifd = accept(svrfd,(struct sockaddr*)&cliaddr,&sinsize);  
	
	if(clifd < 0 )
	{
		LOG_NET_ERROR("accept error : %s", stderror(errno));
		return ;
	}
	
	//CNet::GetInstance()->setNetHandle(clifd,(CNetBase* )arg);
	//保持代码回调的统一性，在上层设置句柄
	CNetBase *pBase = (CNetBase*)arg;
	pBase->onAccept(int clifd);

	struct event_base *base = CNet::GetInstance()->getEventBase();
    struct event *eventAccept = event_new(base, clifd,EV_READ|EV_PERSIST,onReadEvent,eventAccept);  // 注册读(写)事件  

    event_add(eventAccept,NULL);  
}



int CNet::listenTcpServer(char *ip, int port, void* handle)
{
	 int svrfd;  
    struct sockaddr_in svraddr;  
  
    memset(&svrfd,0,sizeof(svraddr));  
    svraddr.sin_family = AF_INET;  
    svraddr.sin_port = htons(port);  
    svraddr.sin_addr.s_addr = inet_addr(ip);  
  
    svrfd = socket(AF_INET,SOCK_STREAM,0);  
	if( svrfd <= 0 )
	{
		LOG_NET_ERROR("create listen socket error:%s\n", stderror(errno));
		return -1;
	}
	evutil_make_listen_socket_reuseable(svrfd);
    if(bind(svrfd,(struct sockaddr*)&svraddr,sizeof(svraddr)) < 0 )
	{
		LOG_NET_ERROR("bind socket error:%s\n", stderror(errno));
		return -1;
	}
	
    if( listen(svrfd,10) < 0 )
	{
		LOG_NET_ERROR(" listen socket error:%s\n", stderror(errno));
		return -1;
	}
  
	evutil_make_socket_nonblocking(svrfd);
    struct event *evlisten = event_new(m_eventBase , svrfd,EV_READ|EV_PERSIST,onAcceptEvent, handle);  
  
    event_add(evlisten,NULL);  
	return svrfd;
	
}
int CNet::connectTcpServer(char* ip, int port)
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if( sockfd <= 0 )
	{
		LOG_NET_ERROR(" create a socket err:%s\n", stderror(errno));
		return -1;
	}
	struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    servaddr.sin_port = htons(port);
    
    if( (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0 )
    {
    	LOG_NET_ERROR("connenct server(%s:%d) error:%s\n", ip, port, stderror(errno));
		return -1;
    }

	struct event_base *base = CNet::GetInstance()->getEventBase();
	struct event *eventConnect = event_new(base , sockfd, EV_READ|EV_PERSIST,onReadEvent,eventConnect);  // 注册读(写)事件  

    event_add(eventConnect,NULL); 

	return sockfd;
}

int CNet::sendTcpData(int socketFd, char* buf, int len)
{
	int iLeftSize = len;
	int iSendSize = 0;
	int iRet      = 0;

	while( iLeftSize > 0)
	{
		iRet = send( socketFd, buf +iSendSize, iLeftSize, 0);
		if ( s32Ret < 0)
		{
			LOG_NET_ERROR("send error:%s\n", strerror(errno));
			break;
		}

		iLeftSize-= iRet;
		iSendSize+= iRet;
	}

	if ( iSendSize != len )
	{
		LOG_NET_ERROR("Send Len erro:len=%d, iSendSize=%d\n", len, iSendSize);
		return -1;
	}
	return 0;
}

int CNet::readTcpData(int socketFd, char* buf, int len)
{
	return 0;
}

void closeServer(int socketFd)
{
	LOG_NET_INFO("close the socket :%d\n", socketFd);
	close(socketFd);
}


char * CNet::getRecvBuffer()
{
	return m_recvBuffer;
}

CNetBase* CNet::getNetHandle(int Fd)
{
	CNetBase* handle = NULL;
	pthread_mutex_lock(&m_mutexLock);
	std::map<int, CNetBase*>::iterator pos;
	for(pos = m_cNetBaseMap.begin(); pos != m_cNetBaseMap.end(); pos++)
	{
		if( pos->first == Fd )
		{
			handle = pos->second;
			break;
		}
	}

	pthread_mutex_unlock(&m_mutexLock);
	return handle;
}


int CNet::setNetHandle(int Fd,CNetBase* handle)
{
	pthread_mutex_lock(&m_mutexLock);
	std::map<int, CNetBase*>::iterator pos;
	for(pos = m_cNetBaseMap.begin(); pos != m_cNetBaseMap.end(); pos++)
	{
		if( pos->first == Fd )
		{
			LOG_NET_INFO("the socket is already exit socketFd=%d\n", Fd);
			pthread_mutex_unlock(&m_mutexLock);
			return 0;
		}
	}

	m_cNetBaseMap[Fd] = handle;
	pthread_mutex_unlock(&m_mutexLock);
	return 0;
}


int CNet::getSocketFd(CNetBase* handle)
{
	int sockFd = 0;
	pthread_mutex_lock(&m_mutexLock);
	std::map<int, CNetBase*>::iterator pos;
	for(pos = m_cNetBaseMap.begin(); pos != m_cNetBaseMap.end(); pos++)
	{
		if( pos->second == handle )
		{
			sockFd = pos->first;
			break;
		}
	}

	pthread_mutex_unlock(&m_mutexLock);
	return sockFd;
}





