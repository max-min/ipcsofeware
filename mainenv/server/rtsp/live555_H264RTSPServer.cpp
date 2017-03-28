#include "live555_H264RTSPServer.h"

CLive555RtspServer::CLive555RtspServer::createNew(UsageEnvironment & env,Port rtspport,
	UserAuthenticationDatabase * authDatabase,unsigned reclamationTestSeconds)
{
	int rtspsock = -1;
	rtspsock = setUpOurSocket(env, rtspPort);
	if( rtspsock == -1)
	{
		LOG_NET_ERROR("setUpOurSocket Failed\n");
		return NULL;
	}

	return new CLive555RtspServer(env, rtspsock, rtspport, authDatabase, reclamationTestSeconds);
}

CLive555RtspServer::CLive555RtspServer(UsageEnvironment & env,int ourSock,Port rtspport,
	UserAuthenticationDatabase * authDatabase,unsigned reclamationTestSeconds)
	:RTSPServer(env, ourSock, rtspport, authDatabase, reclamationTestSeconds), bRtspServerState(false)
{
	bRtspServerState =true;
	LOG_NET_INFO(" create CLive555RtspServer \n");
}


CLive555RtspServer::~CLive555RtspServer()
{
}


ServerMediaSession* CLive555RtspServer::lookupServerMediaSession(const char* streamName)
{
	// streamName, 为URL地址后面的字符串 如 	
	// rtsp://10.0.2.15/streamNameCH00StreamType00, 则streamName = "streamNameCH00StreamType00";	
	// 当客户端发来url请求时，可以解析streamName来判断请求那个通道的哪种码流	
	// 1 解析url 我这里不处理，可以自己回调接口进来处理	int channelNO   = 0;  
	// 通道号	int streamType  = 0;  
	// 码流类型	int videoType   = 1;  
	// 视频 or 音频	int requestType = 0;  
	// 请求类型 实时预览 or 回放	

	ServerMediaSession* sms = NULL;	
	switch(requestType)	
	{		
		case 0:  // realtime
			sms = RTSPServer::lookupServerMediaSession(streamName);
			if ( NULL == sms )
			{
				sms = ServerMediaSession::createNew(envir(), streamName, NULL, NULL);
				CLive555MediaSubsession*session = CLive555MediaSubsession::createNew(envir(), streamType, videoType, channelNO, false);
				sms->addSubsession(session);
			}			
			break;
		case 1:			// play back			
			LOG_NET_INFO("play back request !\n");			
			break;
		default:
			LOG_NET_ERROR("unknown  request type!\n");			
			break;	
	}

	this->addServerMediaSession(sms);	

	return sms;
}

CLive555RtspServer::CLive555RtspClientSession* CLive555RtspServer::createNewClientSession(unsigned clientSessionID, int clientSocket, struct sockaddr_in clientAddr)
{
	CLive555RtspServer::CLive555RtspClientSession* client = new CLive555RtspClientSession(*this, clientSessionID, clientSocket, clientAddr);
	fClientSessionList.push_back(client);	
	LOG_NET_INFO("add client session success!\n");	
	return client;
}

int CLive555RtspServer::stopCLive555RtspServer()
{	
	// 删除所有的客户端的session	
	std::list<CLive555RtspServer::CLive555RtspClientSession*> ::iterator pos =
		this->fClientSessionList.begin();	
	for(pos; pos != this->fClientSessionList.end(); pos ++ )
	{
		CLive555RtspServer::DemoH264RTSPClientSession* tmp = *pos;		
		delete tmp;	
	}	
	delete this; //	
	return 0;	
}

CLive555RtspServer::CLive555RtspClientSession::CLive555RtspClientSession(CLive555RtspServer& rtspServer,unsigned clietnSessionID, int clientSocket, struct sockaddr_in clientAddr)
	:RTSPServer::RTSPClientSession(rtspServer, clietnSessionID, clientSocket, clientAddr)
{

}

CLive555RtspServer::CLive555RtspClientSession::CLive555RtspClientSession()
{	
	/*	
	std::list<CLive555RtspServer::CLive555RtspClientSession*> ::iterator pos =
	((CLive555RtspServer&)fOurServer).fClientSessionList.begin();
	for(pos; pos != ((CLive555RtspServer&)fOurServer).fClientSessionList.end(); 
		pos ++ )
	{
		if ((*pos)->fOurSessionId == this->fOurSessionId)
		{
			((CLive555RtspServer&)fOurServer).fClientSessionList.erase(pos);
			LOG_NET_INFO("client session has been delete !\n");
			break ;
		}
	}
	*/
}













