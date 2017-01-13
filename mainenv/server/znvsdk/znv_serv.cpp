#include "znv_serv.h"
#include "net_api.h"
#include "tinyxml/tinyxml.h"

CZNVServ* CZNVServ::m_znvSerInst = NULL;

CZNVServ::CZNVServ()
{
	m_seqIndex = 0;
}
CZNVServ::~CZNVServ()
{
}

CZNVServ* CZNVServ::GetInstance()
{
	if( m_znvSerInst == NULL)
	{
		m_znvSerInst = new CZNVServ;
		
	}

	return m_znvSerInst;
}
void CZNVServ::ReleaseInstance()
{
	if( m_znvSerInst != NULL)
	{
		delete m_znvSerInst;
	}
}

void CZNVServ::startZNVPlatform()
{

	//初始化平台参数

	int sockFd = CNet::GetInstance()->connectTcpServer(m_pServerIP, m_iPort);
	if( sockFd < 0 )
	{
		LOG_SERV_ERROR("connect ZNVPlatform Failed\n");
		return;
	}

	CNet::GetInstance()->setNetHandle(sockFd, this);
	
}
void CZNVServ::stopZNVPlatform()
{
}


void CZNVServ::getRegisterXml(void* xml)
{

/*
	 <?xml version=”1.0” encoding=”UTF-8”?>
	 <Message version=”1.0”>
		<Header Message_Type=”PU_Register” Session_ID=”” Sequence_Number=”1” />
	 	<parameters>
	 		<puId>030001111000001</puId>
	 		<puIp>192.168.1.10<puIp>
	 		<puPort>8888<puPort>
	 		<puName>test_pu</puName>
	 		<puPassword>21218cca77804d2ba1922c33e0151105<puPassword>
	 		<PPPoeName>testuser</PPPoeName>
	 		<puType>2<puType>
	 	</parameters>
	 */
	 TiXmlDocument *doc = new TiXmlDocument();  
	 TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "UTF-8", "" );
     doc->LinkEndChild(decl);
 
     TiXmlElement* message = new TiXmlElement("Message");
	 message->SetAttribute("version", "1.0");
     doc->LinkEndChild(message);

 	 TiXmlElement* header = new TiXmlElement("Header");
	 header->SetAttribute("Message_type", "PU_Register");
	 header->SetAttribute("Session_ID", "");
	 header->SetAttribute("Sequence_Number", m_seqIndex++);
	 doc->LinkEndChild(header);

	 TiXmlElement* param = new TiXmlElement("parameters");
	 doc->LinkEndChild(param);

	 TiXmlElement* id = new TiXmlElement("puId");
	 TiXmlText* idtext = new TiXmlText(m_puID);
	 id->LinkEndChild(idtext);
	 param->LinkEndChild(id);

	 TiXmlElement* ip = new TiXmlElement("puIp");
	 TiXmlText* iptext = new TiXmlText(m_puIP);
	 ip->LinkEndChild(iptext);
	 param->LinkEndChild(ip);

	 TiXmlElement* port = new TiXmlElement("puPort");
	 TiXmlText* porttext = new TiXmlText(m_puPort);
	 port->LinkEndChild(porttext);
	 param->LinkEndChild(port);
	 
 	 TiXmlElement* name= new TiXmlElement("puName");
	 TiXmlText* nametext = new TiXmlText(m_puName);
	 name->LinkEndChild(nametext);
	 param->LinkEndChild(name);

	 TiXmlElement* passwd = new TiXmlElement("puPassword");
	 TiXmlText* pswdtext = new TiXmlText(m_puPasswd);
	 passwd->LinkEndChild(pswdtext);
	 param->LinkEndChild(passwd);

	 TiXmlElement* type = new TiXmlElement("puType");
	 TiXmlText* typetext = new TiXmlText(2);
	 type->LinkEndChild(typetext);
	 param->LinkEndChild(type);

	TiXmlPrinter printer;
	doc->Accept(&printer);
	
 	sprintf(xml, HTTP_HEAD, printer.Size());
	memcpy(xml + sizeof(HTTP_HEAD), printer.CStr(), printer.Size());

	delete doc;
	doc = NULL;
	
}

