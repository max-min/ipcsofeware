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
          
#if ACCESS_CONTROL   // 认证  
    m_authDB = new UserAuthenticationDatabase;  
    m_authDB->addUserRecord("username", "password");  
#endif   
  
    m_rtspServer = NULL;  
    m_rtspServerPortNum = 554; // 可以修改  
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

	// 建立RTSP服务
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


/*打开实时码流句柄*/  
long openStreamHandle(int channelNO, int streamType)  
{  
    //开始实时流的一些准备工作:获取此类型实时码流的句柄，方便后面直接get码流  
  
    // 我这里测试，所以还是用自己定义的文件码流来读，不过每次都是读一帧数据  
    // 文件流格式为 FrameHeader_S + H264 + FrameHeader_S + H264 ...  
    FILE* fp = fopen("stream264file.h264", "rb+");  
    if (NULL == fp )  
    {  
        LOG_NET_ERROR("open streamhandle failed!\n");  
        return -1;  
    }  
  
    return (long)fp;  
          
}  
/*实时获取一帧数据*/  
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
    // 1、先读取一帧数据的头信息  
    readlen = fread(&stFrameHead, 1, sizeof(FrameHead_S), fp);  
    if( readlen != sizeof(FrameHead_S))  
    {  
        LOG_NET_ERROR(" read Frame Header Failed !\n");  
        return -1;  
    }  
  
    //2、获取一帧H264实时数据  
    if(stFrameHead.FrameLen > 2*1024*1024) // 在source中databuf指分配了2M  
    {  
        LOG_NET_ERROR("data is too long:framlen=%d\n", stFrameHead.FrameLen);  
        //重新分配内存处理  
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
/*关闭码流句柄*/  
void closeStreamHandle(long lHandle)  
{  
    //一些关闭码流的清理工作  
    fclose((FILE*)lHandle);  
}  










