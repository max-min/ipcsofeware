#include "onvif_serv.h"


COnvifServ* COnvifServ::m_cOnvifInc = NULL;

COnvifServ::COnvifServ()
{
}

COnvifServ::~COnvifServ()
{
}

COnvifServ* COnvifServ::GetInstance()
{
	if( m_cOnvifInc == NULL )
	{
		m_cOnvifInc = new COnvifServ();
	}

	return m_cOnvifInc;
}

void COnvifServ::ReleaseInstance()
{
	if( m_cOnvifInc != NULL )
	{
		delete m_cOnvifInc;
		m_cOnvifInc = NULL;
	}
}

void COnvifServ::startOnvifServer()
{
}

void COnvifServ::stopOnvifServer()
{
}






