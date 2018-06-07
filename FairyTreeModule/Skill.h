#pragma once

#ifndef _SKILL_H
#define _SKILL_H

#include "define.h"

//��������
enum SkillType
{
	INITIATIVE, //����
	PASSIVITY   //����
};

class CSkill
{
public:
	CSkill();
	~CSkill();
	//���ü�������
	void Set_Skill_Type(uint32 sst);
	//��ȡ��������
	SkillType Get_Skill_Type();

	//���ü��ܵȼ�
	void Set_Skill_Level(bool ssl);
	//��ȡ���ܵȼ�
	int Get_Skill_Level();

	//���ü���ID
	void Set_Skill_ID(uint32 ssid);
	//��ȡ����ID
	int Get_Skill_ID();

	//���ü�������
	void Set_Skill_Describe(std::string skill);
	//��ȡ��������
	std::string Get_Skill_Describe();

private:
	//��������
	SkillType skilltype;

	//���ܵȼ�
	uint32 uskillLevel;

	//����ID
	uint32 uskillID;

	//��������
	std::string skilldescribe;

	//��Ч(����)

	//����(����)

	//����Ч��
};


//����Ч�� д�ɻ��� ������


#endif

