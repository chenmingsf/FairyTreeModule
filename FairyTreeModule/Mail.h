#pragma once

#ifndef _MAIL_H
#define _MAIL_H

#include "define.h"
#include <map>
#include "Warehouse.h"


//�ʼ���
class Mail
{
public:
	Mail();
	~Mail();

	//�����ʼ����
	void Set_MailSerialNumber(uint32 smsn);
	//��ȡ�ʼ����
	int Get_MailSerialNumber();

	//�����ʼ�����
	void Set_MailHeadline(std::string smh);
	//��ȡ�ʼ�����
	string Get_MailHeadline();

	//�����ʼ�����
	void Set_MailContent(std::string smc);
	//��ȡ�ʼ�����
	string Get_MailContent();

	//��ȡ(����ʼ���ȡ״̬)(falseΪδȡ��trueΪ��ȡ)
	bool MailArticleGetState();

	//
	std::map<uint32, uint32> GetPrizes() {
		return vecmailArt;
	}

private:
	//�ʼ����
	uint32 umailSerialNumber;

	//�ʼ�����
	std::string smailheadline;

	//�ʼ�����
	std::string smailcontent;

	//�ʼ���Ʒ ��Ʒid��Key ����Ϊֵ
	std::map<uint32,uint32> vecmailArt;

	//�ʼ���Ʒ����ȡ״̬(falseΪδȡ��trueΪ��ȡ)
	bool bmailArtGetState;
};


//������
class CMailbox
{
public:
	CMailbox();
	~CMailbox();
	//�����ʼ�
	void AddMail(Mail* cmail);
	//ɾ���ʼ�
	void CloseMail(uint32 closemail);
	//�����ʼ�
	Mail* ErgodicMail(uint32 uid);
	//�ʼ�������
	inline int MailNumber() { return (int)vecmail.size(); }

	//�ʼ���map
	std::map<uint32, Mail*> map_mail;
private:
	//�ʼ��� map
	std::vector<Mail*> vecmail;
};


#endif
