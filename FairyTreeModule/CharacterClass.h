#pragma once

#ifndef _CHARACTER_CLASS_H
#define _CHARACTER_CLASS_H

#include "define.h"
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
	int Get_Role_ID();

	//���ý�ɫ����
	void Set_Role_Name(std::string srname);
	//��ȡ��ɫ����
	string Get_Role_Name();

	//���ý�ɫ�ɳ�ֵ
	void Set_RoleGrowthValue(uint32 srgv);
	//��ȡ��ɫ�ɳ�ֵ
	int Get_RoleGrowthValue();

	//��ɫ��map
	std::map<uint32, CharacterClass*> map_haracter;
private:
	//��ɫID
	uint32 uroleID;

	//��ɫ����
	std::string sroleName;

	//��ɫ�ɳ�ֵ
	uint32 urolegrowthvalue;

};


#endif

