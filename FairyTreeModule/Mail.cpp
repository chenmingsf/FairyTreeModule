#include "Mail.h"



Mail::Mail()
{
	m_roleID = 0;//�û�ID

	umailSerialNumber = 0; //�ʼ����

	smailheadline = ""; //�ʼ�����

	smailcontent = ""; //�ʼ�����

	bmailArtGetState = false; //�ʼ���Ʒ����ȡ״̬(falseΪδȡ��trueΪ��ȡ)
}


Mail::~Mail()
{
}

//�����ʼ����
void Mail::Set_MailSerialNumber(uint32 smsn)
{
	umailSerialNumber = smsn;
}

//��ȡ�ʼ����
uint32 Mail::Get_MailSerialNumber()
{
	return umailSerialNumber;
}

//�����ʼ�����
void Mail::Set_MailHeadline(const std::string& smh)
{
	smailheadline = smh;
}

//��ȡ�ʼ�����
std::string Mail::Get_MailHeadline()
{
	return smailheadline;
}

//�����ʼ�����
void Mail::Set_MailContent(const std::string& smc)
{
	smailcontent = smc;
}

//��ȡ�ʼ�����
std::string Mail::Get_MailContent()
{
	return smailcontent;
}

//��ȡ(����ʼ���ȡ״̬)(falseΪδȡ��trueΪ��ȡ)
bool Mail::MailArticleGetState()
{
	bmailArtGetState = true;
	return bmailArtGetState;
}

//�����û�ID
void Mail::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//��ȡ�û�ID
uint32 Mail::Get_RoleID()
{
	return m_roleID;
}



//������
CMailbox::CMailbox()
{
	m_roleID = 0;//�û�ID
	pboxmail = new Mail;
}

CMailbox::~CMailbox()
{
	delete pboxmail;
}

//�����ʼ�
void CMailbox::AddMail(uint32 uid)
{
	map_mail[uid] = pboxmail;
}

//ɾ���ʼ�
void CMailbox::CloseMail(uint32 closemail)
{
	
	//ͨ���ʼ���� ����Ҫɾ�����ʼ�
	for (std::map<uint32, Mail*>::iterator itmail = map_mail.begin(); itmail != map_mail.end(); itmail++)
	{
		if (closemail == itmail->second->Get_MailSerialNumber())
		{
			//�ҵ��� ɾ���ʼ�
			map_mail.erase(itmail);
		}
	}

}

//�����ʼ�
Mail * CMailbox::ErgodicMail(uint32 uid)
{
	return map_mail[uid];
}

//�����û�ID
void CMailbox::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//��ȡ�û�ID
uint32 CMailbox::Get_RoleID()
{
	return m_roleID;
}
