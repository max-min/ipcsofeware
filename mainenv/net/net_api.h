#ifndef __NET_API_H__
#define __NET_API_H__
#include <map>
#include <pthread.h>
#include "event2/event.h"
#include "event2/event_compat.h"
#include "net_base.h"

class CNet
{
	public:
		static CNet* GetInstance();
		static void ReleaseInstance();

	private:
		static CNet* m_cNetIns;
		CNet();
		virtual ~CNet();
	public:
		struct event_base* getEventBase();
	public:
		
		int startNetServer();
		void stopNetServer();
		
		int listenTcpServer(char *ip, int port, void* handle);
		int connectTcpServer(char* ip, int port);



		int sendTcpData(int socketFd, char* buf, int len);
		int readTcpData(int socketFd, char* buf, int len);

		void closeServer(int socketFd);
		
		char* getRecvBuffer();

		CNetBase* getNetHandle(int Fd);
		int setNetHandle(int Fd,CNetBase* handle);
		int getSocketFd(CNetBase* handle);
		
	private:
		void InitEventLoop();
		pthread_t m_eventloopID;
		struct event_base* m_eventBase;

		std::map<int, CNetBase*> m_cNetBaseMap;
		pthread_mutex_t m_mutexLock;
		char *m_recvBuffer;
		

};

#define CNET CNet::GetInstance()







#endif // net_api.h
