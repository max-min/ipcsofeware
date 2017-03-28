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
void CRtspServ::initRtspParam()
{
  // Begin by setting up the live555 usage environment   
    m_scheduler = BasicTaskScheduler::createNew();  
    m_env = BasicUsageEnvironment::createNew(*m_scheduler);  
          
#if ACCESS_CONTROL   // ��֤  
    m_authDB = new UserAuthenticationDatabase;  
    m_authDB->addUserRecord("username", "password");  
#endif   
  
    m_rtspServer = NULL;  
    m_rtspServerPortNum = 554; // �����޸�  
    m_liveServerFlag = true;  

}
void CRtspServ::startRtspServ()
{
	if( !m_liveServerFlag)
	{

		LOG_NET_ERROR("Not Init the live server !\n");
		return -1; 
	}
	
	LOG_NET_INFO(" ~~~~Start live555 stream\n");

	// ����RTSP����
	m_rtspServer = CLive555RtspServer::createNew(*m_env, m_rtspServerPortNum, m_authDB);
	
	if( m_rtspServer == NULL)
	{
		// *m_env << " create RTSPServer Failed:" << m_env->getResultMsg() << "\n";
		LOG_NET_ERROR("create RTSPServer Failed:%s\n", m_env->getResultMsg());
		return -1;
	}


	// loop and not come back~
	m_env->taskScheduler().doEventLoop();
	
	return 0;
}

void CRtspServ::stopRtspServ()
{
	LOG_NET_INFO(" ~~~~stop live555 stream\n");
	if(m_liveServerFlag)
	{
		if(m_rtspServer)
			m_rtspServer->stopCLive555RtspServer();
		m_liveServerFlag = false;	
	}
}


/*��ʵʱ�������*/  
long openStreamHandle(int channelNO, int streamType)  
{  
    //��ʼʵʱ����һЩ׼������:��ȡ������ʵʱ�����ľ�����������ֱ��get����  
  
    // ��������ԣ����Ի������Լ�������ļ���������������ÿ�ζ��Ƕ�һ֡����  
    // �ļ�����ʽΪ FrameHeader_S + H264 + FrameHeader_S + H264 ...  
    FILE* fp = fopen("stream264file.h264", "rb+");  
    if (NULL == fp )  
    {  
        LOG_NET_ERROR("open streamhandle failed!\n");  
        return -1;  
    }  
  
    return (long)fp;  
          
}  
/*ʵʱ��ȡһ֡����*/  
int getStreamData(long lHandle, char* buf, unsigned* bufsize, unsigned* leftbufsize, int sourcetype)  
{  
    if(lHandle <= 0)  
    {  
        LOG_NET_ERROR(" lHandle error !\n");  
        return -1;  
    }  
    FrameHead_S stFrameHead;  
    memset(&stFrameHead, 0, sizeof(FrameHead_S));  
    FILE* fp = (FILE*)lHandle;  
    int readlen = 0;  
    // 1���ȶ�ȡһ֡���ݵ�ͷ��Ϣ  
    readlen = fread(&stFrameHead, 1, sizeof(FrameHead_S), fp);  
    if( readlen != sizeof(FrameHead_S))  
    {  
        LOG_NET_ERROR(" read Frame Header Failed !\n");  
        return -1;  
    }  
  
    //2����ȡһ֡H264ʵʱ����  
    if(stFrameHead.FrameLen > 2*1024*1024) // ��source��databufָ������2M  
    {  
        LOG_NET_ERROR("data is too long:framlen=%d\n", stFrameHead.FrameLen);  
        //���·����ڴ洦��  
        return 0;  
    }  
    readlen = fread(buf, 1, stFrameHead.FrameLen, fp);  
    if(readlen != stFrameHead.FrameLen)  
    {  
        LOG_NET_ERROR("read Frame rawdata Failed!\n");  
        return -1;  
    }  
  
    return stFrameHead.FrameLen;  
}  
/*�ر��������*/  
void closeStreamHandle(long lHandle)  
{  
    //һЩ�ر�������������  
    fclose((FILE*)lHandle);  
}  










