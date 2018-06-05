#include "Mail.h"



Mail::Mail()
{
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
int Mail::Get_MailSerialNumber()
{
	return umailSerialNumber;
}

//�����ʼ�����
void Mail::Set_MailHeadline(std::string smh)
{
	smailheadline = smh;
}

//��ȡ�ʼ�����
string Mail::Get_MailHeadline()
{
	return smailheadline;
}

//�����ʼ�����
void Mail::Set_MailContent(std::string smc)
{
	smailcontent = smc;
}

//��ȡ�ʼ�����
string Mail::Get_MailContent()
{
	return smailcontent;
}

//��ȡ(����ʼ���ȡ״̬)(falseΪδȡ��trueΪ��ȡ)
bool Mail::MailArticleGetState()
{
	bmailArtGetState = true;
	return bmailArtGetState;
}



//������
CMailbox::CMailbox()
{
}

CMailbox::~CMailbox()
{
}

//�����ʼ�
void CMailbox::AddMail(Mail* cmail)
{
	vecmail.push_back(cmail);
}

//ɾ���ʼ�
void CMailbox::CloseMail(uint32 closemail)
{
	
	//ͨ���ʼ���� ����Ҫɾ�����ʼ�
	for (std::vector<Mail*>::iterator itmail = vecmail.begin(); itmail != vecmail.end(); itmail++)
	{
		if (closemail == (*itmail)->Get_MailSerialNumber())
		{
			//�ҵ��� ɾ���ʼ�
			vecmail.erase(itmail);
		}
	}

}
