#ifndef __RTSP_SERV_H__
#define __RTSP_SERV_H__

enum enVideoType{
	TYPE_H264  = 0x01,
	TYPE_MEPG4 = 0x02,
	TYPE_G711  = 0x04,
};


class CRtspServ
{
	public:
		static CRtspServ* GetInstance();
		static void ReleaseInstance();
		
		void initRtspParam();
		void startRtspServ();
		void stopRtspServ();
	private:
		CRtspServ();
		virtual ~CRtspServ();
		static CRtspServ* m_cRtspIns;
	public:
		//live555
		bool m_liveServerFlag;		
		TaskScheduler* m_scheduler;		
		UsageEnvironment* m_env;		
		UserAuthenticationDatabase* m_authDB;		
		CLive555RtspServer* m_rtspServer;		
		int m_rtspServerPortNum; // rtsp port 
};

#endif // rtsp_serv.h
