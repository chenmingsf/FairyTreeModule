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

private:
	//�ʼ����
	uint32 umailSerialNumber;

	//�ʼ�����
	std::string smailheadline;

	//�ʼ�����
	std::string smailcontent;

	//�ʼ���Ʒ ��Ʒ������Key ����Ϊֵ
	std::map<CWarehouseArticle*,int> vecmailArt;

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

private:
	//��Ʒ�� map
	std::vector<Mail*> vecmail;
};


#endif
