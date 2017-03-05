#include "gb_serv.h"


CGB28181Serv* CGB28181Serv::m_cGBServIns = NULL;
CGB28181Serv::CGB28181Serv()
{
}

CGB28181Serv::~CGB28181Serv()
{
}

CGB28181Serv* CGB28181Serv::GetInstance()
{
	if(m_cGBServIns == NULL)
	{
		m_cGBServIns = new CGB28181Serv();
	}

	return m_cGBServIns;
}

void CGB28181Serv::ReleasesInstance()
{
	if( m_cGBServIns != NULL )
	{
		delete m_cGBServIns;
		m_cGBServIns = NULL;
	}
}


void  CGB28181Serv::startGB28181Server()
{
}

void CGB28181Serv::stopGB28181Server()
{
}










