#include "znv_serv.h"

CZNVServ* CZNVServ::m_znvSerInst = NULL;

CZNVServ::CZNVServ()
{
}
CZNVServ::~CZNVServ()
{
}

CZNVServ* CZNVServ::GetInstance()
{
	if( m_znvSerInst == NULL)
	{
		m_znvSerInst = new CZNVServ;
		
	}

	return m_znvSerInst;
}
void CZNVServ::ReleaseInstance()
{
	if( m_znvSerInst != NULL)
	{
		delete m_znvSerInst;
	}
}

void CZNVServ::startZNVPlatform()
{
	
}
void CZNVServ::stopZNVPlatform()
{
}
