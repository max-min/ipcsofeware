
#include "live555_H264FrameSource.h"

CLive555FrameSource::CLive555FrameSource(UsageEnvironment & env,long sourceHandle,int sourceType):
	FramedSource(env), lSourceHandle(sourceHandle), uLastBufSize(0),iLeftDataSize(0),iSourceType(sourceType),iFirstFrame(1)
{
		//��ʼ׼��һЩ�������Ĺ���׼��
		fDataBuf = (char*)malloc(MAX_FRAME_LEN);
		memset(fDataBuf, 0, MAX_FRAME_LEN);
		if( fDataBuf == NULL)
		{
			LOG_NET_ERROR("create data source buf error" << stderr(errno));
		}
}

CLive555FrameSource::~CLive555FrameSource()
{
	if( fDataBuf != NULL)
	{
		free(fDataBuf);
		fDataBuf = NULL;
	}
}

CLive555FrameSource* CLive555FrameSource::createNew(UsageEnvironment & env,int streamtype,int channel,int sourceType)
{
	//���õײ�ӿڻ�ȡ��Ӧ�����������ʶ
	long sourceHandle = openStreamHandle(channel, streamtype);
	if(sourceHandle == 0 )
	{
		LOG_NET_ERROR("open the source failed, channel=%d, streamtype=%d", channel, streamtype);
		return NULL;
	}

	LOG_NET_INFO("open the source success, channel=%d, streamtype=%d", channel, streamtype);
}

long filesize( FILE* stream)
{
	long curpos, length;
	curpos = ftell(stream);
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek(stream, curpos, SEEK_SET);
	return length;
}

void CLive555FrameSource::getNextFrameData()
{
	int iRet = 0;
	//���õײ�ӿڻ�ȡһ֡����
	if( iLeftDataSize == 0)
	{
		iRet = getStreamData(lSourceHandle, fDataBuf, &iLastBufSize, &iLeftDataSize, iSourceType);
		if( iRet <= 0 )
		{
			LOG_NET_ERROR("RTSP,getStreamData Failed\n");
			return;
		}
	}

	int fNewFrameSize = iLeftDataSize;
	if( fNewFrameSize > fMaxSize )
	{
		fFrameSize = fMaxSize;
		fNumTruncateBytes = fNewFrameSize - fMaxSize;
		 fLeftDataSize = fNewFrameSize - fMaxSize;  
        // ע��memmove�������÷��������ڴ�ռ���ӵ�  
        memmove(fTo, fDataBuf, fFrameSize);   
        memmove(fDataBuf, fDataBuf+fMaxSize, fLeftDataSize);     
	}
	else   
    { //all the data   
        fFrameSize = fNewFrameSize;  
        fLeftDataSize = 0;           
        memmove(fTo, fDataBuf, fFrameSize);  
    }  
  
    gettimeofday(&fPresentationTime, NULL);  
  
    if (fFirstFrame)  
    {  
        fDurationInMicroseconds = 40000;  
        nextTask() = envir().taskScheduler().scheduleDelayedTask(100000,   
                (TaskFunc*)FramedSource::afterGetting, this);  
        fFirstFrame = 0;  
    }  
    else  
    {  
        FramedSource::afterGetting(this);  
    }  
}


void CLive555FrameSource::doStopGetFrame()  
{  
    closeStreamHandle(fSourceHandle);  
}  

