#ifndef __ZNV_SERV_H__
#define __ZNV_SERV_H__

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
};



#endif // znv_serv.h
