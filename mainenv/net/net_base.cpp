#include "net_base.h"


CNetBase::CNetBase(){}
CNetBase::~CNetBase(){}

int CNetBase::OnReceive(char *buf , int len)
{
	return 0;
}
int CNetBase::OnSendData(char*buf ,int len)
{
	return 0;
}
int CNetBase::OnAccept()
{
	return 0;
}