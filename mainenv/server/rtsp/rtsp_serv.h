#ifndef __RTSP_SERV_H__
#define __RTSP_SERV_H__

class CRtspServ
{
	public:
		static CRtspServ* GetInstance();
		static void ReleaseInstance();
		

		void startRtspServ();
		void stopRtspServ();
	private:
		CRtspServ();
		virtual ~CRtspServ();
		static CRtspServ* m_cRtspIns;
	public:
		// port 
		// sdp
		// option,description, setup, play, teardown,
};

#endif // rtsp_serv.h
