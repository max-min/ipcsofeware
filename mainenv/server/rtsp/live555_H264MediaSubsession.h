#ifndef __LIVE555_H264MEDIASUBSESSION_H__
#define __LIVE555_H264MEDIASUBSESSION_H__


#include "OnDemandServerMediaSubsession.hh"
class CLive555MediaSubsession:public OnDemandServerMediaSubsession
{
	public:
		static CLive555MediaSubsession* createNew(UsageEnvironment& env, int streamType, int videoType, int channel,
			bool reuseFirstSource, portNumBits initalNumPort = 6790);
	protected:
		CLive555MediaSubsession(UsageEnvironment& env, int streamType, int vidoeType, int channel, 
			bool reuseFirstSource, portNumBits initalNumPort);
		~CLive555MediaSubsession();

	public:
		FramedSource* createNewStreamSource(unsigned clientsessionId, unsigned& estBitrate);
		RTPSink* createNewRTPSink(Groupsock* rtpGroupsock, unsigned char rtpPayloadTypeIfDynamic, FramedSource* inputSource);
		

	public:
		int iStreamType;
		int iVideoType;
		int iChannel;


};



#endif // live555_H264MediaSubsession.h
