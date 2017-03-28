#ifndef __LIVE555_H264FRAMESOURCE_H__
#define __LIVE555_H264FRAMESOURCE_H__


#define MAX_FRAME_LEN  2*1024*1024

#include "FramedSource.h"
class CLive555FrameSource:public FramedSource
{
	public:
		static CLive555FrameSource* createNew(UsageEnvironment& env, int streamtype, int channel, int sourceType);
	protected:
		CLive555FrameSource(UsageEnvironment& env, long sourceHandle, int sourceType);
		~CLive555FrameSource();
	private:
		virtual void getNextFrameData();
	public:
		void stopGetFrameData();

	public:
		char *fDataBuf;
		long lSourceHandle;
		unsigned uLastBufSize;
		int iLeftDataSize;
		int iSourceType;
		int iFirstFrame;
			
};


#endif // live555_H264FrameSource.h
