#ifndef __NET_BASE_H__
#define __NET_BASE_H__

class CNetBase
{
	public:
		CNetBase();
		virtual ~CNetBase();

	public: 
		int OnReceive(char *buf , int len);
		int OnSendData(char*buf ,int len);
		int OnAccept(int sockFd);

	private:
		
};



#endif // net_base.h
