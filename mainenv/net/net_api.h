#ifndef __NET_API_H__
#define __NET_API_H__
class CNet
{
	public:
		static CNet* GetInstance();
		static void ReleaseInstance();

	private:
		static CNet* m_cNetIns;
		CNet();
		~CNet();

	public:
		int startNetServer();
		void stopNetServer();
		int listenTcpServer(char *ip, int port);
		int connectTcpServer(char* ip, int port);

		int sendTcpData(int socketFd, char* buf, int len);
		int readTcpData(int socketFd, char* buf, int len);

	private:
		struct event_base* m_eventBase;
		

};

#define CNET CNet::GetInstance()







#endif // net_api.h
