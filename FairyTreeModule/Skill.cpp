#pragma once

#include "Skill.h"

CSkill::CSkill()
{
	skilltype = INITIATIVE; //��������

	uskillLevel = 0; //���ܵȼ�

	uskillID = 0; //����ID

	skilldescribe = "";//��������
}

CSkill::~CSkill()
{
}

//���ü�������
void CSkill::Set_Skill_Type(uint32 sst)
{
	switch (sst)
	{
	case 0: {skilltype = INITIATIVE; break; }
	case 1: {skilltype = PASSIVITY; break; }
	}
}

//��ȡ��������
SkillType CSkill::Get_Skill_Type()
{
	return skilltype;
}

//���ü��ܵȼ�
void CSkill::Set_Skill_Level(uint32 ssl)
{
	uskillLevel += ssl;
}

//��ȡ���ܵȼ�
int CSkill::Get_Skill_Level()
{
	return uskillLevel;
}

//���ü���ID
void CSkill::Set_Skill_ID(uint32 ssid)
{
	uskillID = ssid;
}

//��ȡ����ID
int CSkill::Get_Skill_ID()
{
	return uskillID;
}

//���ü�������
void CSkill::Set_Skill_Describe(std::string skill)
{
	skilldescribe = skill;
}

//��ȡ��������
std::string CSkill::Get_Skill_Describe()
{
	return skilldescribe;
}
