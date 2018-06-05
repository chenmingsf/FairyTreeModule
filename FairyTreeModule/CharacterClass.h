#pragma once

#ifndef _CHARACTER_CLASS_H
#define _CHARACTER_CLASS_H

#include "define.h"

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

	//���ý�ɫ�ȼ�
	void Set_RoleLevel(uint32 srl);
	//��ȡ��ɫ�ȼ�
	int Get_RoleLevel();

	//���ý�ɫ�ɳ�ֵ
	void Set_RoleGrowthValue(uint32 srgv);
	//��ȡ��ɫ�ɳ�ֵ
	int Get_RoleGrowthValue();

private:
	//��ɫID
	uint32 uroleID;

	//��ɫ����
	std::string sroleName;

	//��ɫ�ȼ�
	uint32 urolelevel;

	//��ɫ�ɳ�ֵ
	uint32 urolegrowthvalue;

};


#endif

