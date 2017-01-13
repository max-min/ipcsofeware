#ifndef __ZNV_SERV_H__
#define __ZNV_SERV_H__

#define HTTP_HEAD "POST HTTP/1.1\r\n"\
				  "Content-Type: text/xml\r\n"\
				  "Content-Length:%d\r\n\r\n"
class CZNVServ
{
	public:
		static CZNVServ* GetInstance();
		static void ReleaseInstance();

	private:
		CZNVServ();
		virtual ~CZNVServ();
		static CZNVServ* m_znvSerInst;

	public:
		void startZNVPlatform();
		void stopZNVPlatform();
	private:
		void getRegisterXml(void* buf);
	private:
		int  m_seqIndex;
		char *m_pServerID;
		char *m_pServerIP;
		int m_iPort;

		// pu 
		char *m_puID;
		char *m_puIP;
		int   m_puPort;

		char m_puName[30];
		char m_puPasswd[30];
};



#endif // znv_serv.h
