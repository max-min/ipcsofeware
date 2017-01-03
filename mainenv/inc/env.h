#ifndef __ENV_H__
#define __ENV_H__



#define SIMULATOR_FLAG 1

class CEnv
{
	public:
		CEnv();
		virtual ~CEnv();

	public:
		virtual void startEnv() = 0;
		virtual void stopEnv()= 0;
}

#endif // env.h
