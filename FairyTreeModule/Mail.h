#pragma once

#ifndef _MAIL_H
#define _MAIL_H

#include "Gamedefine.h"
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
	uint32 Get_MailSerialNumber();

	//�����ʼ�����
	void Set_MailHeadline(const std::string& smh);
	//��ȡ�ʼ�����
	std::string Get_MailHeadline();

	//�����ʼ�����
	void Set_MailContent(const std::string& smc);
	//��ȡ�ʼ�����
	std::string Get_MailContent();

	//��ȡ(����ʼ���ȡ״̬)(falseΪδȡ��trueΪ��ȡ)
	bool MailArticleGetState();

	//
	std::map<uint32, uint32> GetPrizes() {
		return vecmailArt;
	}

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

private:

	//�û�ID
	uint32 m_roleID;

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
	void AddMail(uint32 uid);
	//ɾ���ʼ�
	void CloseMail(uint32 closemail);
	//�����ʼ�
	Mail* ErgodicMail(uint32 uid);
	//�ʼ�������
	uint32 MailNumber() { return (uint32)map_mail.size(); }

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//�ʼ���map
	std::map<uint32, Mail*> map_mail;
private:

	//�û�ID
	uint32 m_roleID;

	Mail * pboxmail;

};


#endif
