#ifndef __CODEC_ENV_H__
#define __CODEC_ENV_H__
#include "env.h"

class CCodecEnv:public CEnv
{
	public:
		static CCodecEnv* GetInstance();
		static void   ReleaseInstance();
	private:
		CCodecEnv();
		virtual ~CCodecEnv();
		static CCodecEnv* m_cCodecEnvIns;
	public:

		void startEnv();
		void stopEnv();
	
};





#endif // codec_env.h
