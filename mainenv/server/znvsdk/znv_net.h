#ifndef __ZNV_NET_H__
#define __ZNV_NET_H__

#include "net_base.h"

class CZNVNet:public CNetBase
{
	public:
		CZNVNet();
		virtual ~CZNVNet();
	public: 
		int OnReceive(char *buf , int len);
		int OnSendData(char*buf ,int len);
		int OnAccept(int sockFd);
};




#endif // znv_net.h
