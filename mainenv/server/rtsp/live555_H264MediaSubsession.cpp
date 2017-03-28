#include "live555_H264MediaSubsession.h"



CLive555MediaSubsession::CLive555MediaSubsession(UsageEnvironment & env,int streamType,int videoType,int channel,bool reuseFirstSource,portNumBits initalNumPort)
	:OnDemandServerMediaSubsession(env, reuseFirstSource), iStreamType(streamType), iVideoType(videoType),iChannel(channel)
{
	
}

CLive555MediaSubsession::~CLive555MediaSubsession()
{
}

CLive555MediaSubsession* CLive555MediaSubsession::createNew(UsageEnvironment &env, int streamType, int videoType, int channel,
	bool reuseFirstSource, portNumBits initalNumPort)
{
	CLive555MediaSubsession* csubs = new CLive555MediaSubsession(env, streamType, videoType, channel, reuseFirstSource,initalNumPort);

	return csubs;	
}


FramedSource* CLive555MediaSubsession::createNewStreamSource(unsigned clientsessionId,unsigned & estBitrate)
{

	switch(iVideoType)
	{
		case TYPE_H264:
			{
				estBitrate = 2000;
				CLive555FrameSource* source = CLive555FrameSource::createNew(envir(),	iStreamType, iChannel, TYPE_H264);
				if( source == NULL)
				{
					LOG_NET_ERROR("create FrameSource error:streamType=%d, channel=%d", iStreamType, iChannel);
					return 	NULL;
				}

				return H264VideoStreamFramer::createNew(envir(), source);
			}
			//break;
		case TYPE_MEPG4:
			{
				//TODO
			}
			break;
		case TYPE_G711:
			{
				//TODO
			}
			break;
		default:
			{
				LOG_NET_ERROR("Unknow the videoType:%d", iVideoType);
			}
			break;
	}
	return NULL;	
}

RTPSink* CLive555MediaSubsession::createNewRTPSink(Groupsock * rtpGroupsock,unsigned char rtpPayloadTypeIfDynamic,FramedSource * inputSource)
{
	if( iVideoType == TYPE_H264)
	{
		return H264VideoRTPSink::createNew(envir(), rtpGroupsock, rtpPayloadTypeIfDynamic);
	}
	else if( iVideoType == TYPE_MEPG4)
	{ // Mpeg-4

	}
	else if( iVideoType == TYPE_G711)
	{ // G711 audio

	}
	else 
	{
		LOG_NET_ERROR("Unknow iVideoType:%d", iVideoType);
	}

	return NULL;
}














