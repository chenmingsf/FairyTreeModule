#pragma once

#ifndef _CHARACTER_CLASS_H
#define _CHARACTER_CLASS_H

#include "Gamedefine.h"
#include <map>

//��ɫ��
class CharacterClass
{
public:
	CharacterClass();
	~CharacterClass();

	//���ý�ɫID
	void Set_Role_ID(uint32 srid);
	//��ȡ��ɫID
	uint32 Get_Role_ID();

	//���ý�ɫ����
	void Set_Role_Name(const std::string& srname);
	//��ȡ��ɫ����
	std::string Get_Role_Name();

	//���ý�ɫ�ɳ�ֵ
	void Set_RoleGrowthValue(uint32 srgv);
	//��ȡ��ɫ�ɳ�ֵ
	uint32 Get_RoleGrowthValue();

	//���ý�ɫ��ͷ���ַ
	void Set_HaracterHeadPortraitSite(const std::string& shps);
	//��ȡ��ɫ��ͷ���ַ
	std::string Get_HaracterHeadPortraitSite();

	//�������ĵȼ�
	void Set_TreeToGread(uint32 sttg);
	//��ȡ���ĵȼ�
	uint32 Get_TreeToGread();

	//��ɫ��map
	std::map<uint32, CharacterClass*> map_haracter;
private:
	//��ɫID
	uint32 m_roleID;

	//��ɫ����
	std::string sroleName;

	//��ɫ�ɳ�ֵ
	uint32 urolegrowthvalue;

	//��ɫ(haracter)��ͷ��(HeadPortrait)��ַ(Site)
	std::string uharaHPSite;

	//���ĵȼ�
	uint32 utreeToGread;

};


#endif

