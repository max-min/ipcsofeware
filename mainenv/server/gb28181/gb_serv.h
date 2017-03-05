#ifndef __GB28181_SERV_H__
#define __GB28181_SERV_H__

class CGB28181Serv
{
	public:
		static CGB28181Serv* GetInstance();
		static void ReleasesInstance();

		void startGB28181Server();
		void stopGB28181Server();
		
	private:
		CGB28181Serv();
		virtual ~CGB28181Serv();
		static CGB28181Serv* m_cGBServIns;
		
		

};


#endif // gb_serv.h
