#ifndef __ONVIF_SERV_H__
#define __ONVIF_SERV_H__

class COnvifServ
{
	public:
		static COnvifServ* GetInstance();
		static void ReleaseInstance();

		void startOnvifServer();
		void stopOnvifServer();
	private:
		COnvifServ();
		virtual ~COnvifServ();
		static COnvifServ* m_cOnvifInc;

	

};


#endif // onvif_serv.h
