#ifndef __LIVE555_H264RTSPSERVER_H__
#define __LIVE555_H264RTSPSERVER_H__


class CLive555RtspServer:public RTSPServer
{
	public:
		CLive555RtspServer* createNew(UsageEnvironment& env, Port rtspport =554,
			UserAuthenticationDatabase* authDatabase = NULL, unsigned reclamationTestSeconds = 65);
	protected:
		CLive555RtspServer(UsageEnvironment& env, int ourSock, Port rtspport, 
			UserAuthenticationDatabase* authDatabase, unsigned reclamationTestSeconds);
		virtual ~CLive555RtspServer();
		
		class CLive555RtspClientSession:public RTSPServer::RTSPClientSession
		{
			public:
				CLive555RtspClientSession(CLive555RtspServer& rtspserver, unsigned clientSessionID, int clientSocket,
					struct sockaddr_in clientAddr);
				virtual ~CLive555RtspClientSession();
		};
	public:
		
		//redefine 
		virtual ServerMediaSession* lookupServerMediaSession(const char* streamName);
		virtual CLive555RtspServer::CLive555RtspClientSession* createNewClientSession(unsigned clientSessionID, int clientSocket, struct sockaddr_in clientAddr);

		int stopCLive555RtspServer();

	public:
		std::list<CLive555RtspServer::CLive555RtspClientSession*> fClientSessionList;
		bool bRtspServerState; // 
		
};







#endif // live555_H264RTSPServer.h
