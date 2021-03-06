#ifndef __ENV_H__
#define __ENV_H__


#include <stdio.h>


/***********************
 *  every env base class 
 ***********************/
#define X86_COMM 1
class CEnv
{
	public:
		CEnv(){}
		virtual ~CEnv(){}

	public:
		virtual void startEnv() = 0;
		virtual void stopEnv()= 0;
};

#endif // env.h
