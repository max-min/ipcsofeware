#include "rtsp_serv.h"


CRtspServ* CRtspServ::m_cRtspIns = NULL;

CRtspServ::CRtspServ()
{
}

CRtspServ::~CRtspServ()
{
}

CRtspServ* CRtspServ::GetInstance()
{
	if( m_cRtspIns == NULL)
	{
		m_cRtspIns = new CRtspServ();
	}

	return m_cRtspIns;
}

void CRtspServ::ReleaseInstance()
{
	if( m_cRtspIns != NULL)
	{
		delete m_cRtspIns;
		m_cRtspIns = NULL;
	}
}

void CRtspServ::startRtspServ()
{
}

void CRtspServ::stopRtspServ()
{
}












