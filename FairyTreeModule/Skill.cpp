#pragma once

#include "Skill.h"

CSkill::CSkill()
{
	skilltype = INITIATIVE; //��������

	uskillLevel = 0; //���ܵȼ�

	uskillID = 0; //����ID

	skilldescribe = "";//��������

	upillageEffect = 0; //�Ӷ�Ч��
	
	uwateringEffect = 0;//��ˮЧ��
	
	ureserveGold = 0;//������
	
	uplantEffect = 0;//����Ч��
	
	udodgeAbility = 0;//�������
	
	urobAddition = 0;//���ټӳ�
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
void CSkill::Set_Skill_Level(bool ssl)
{
	if (ssl)
	{
		uskillLevel += 1;
	}
	
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

//�����Ӷ�Ч��
void CSkill::Set_uPillageEffect(uint32 uset)
{
	upillageEffect = uset;
}

//��ȡ�Ӷ�Ч��
int CSkill::Get_uPillageEffect()
{
	return upillageEffect;
}

//���ý�ˮЧ��
void CSkill::Set_uWateringEffect(uint32 uset)
{
	uwateringEffect = uset;
}

//��ȡ��ˮЧ��
int CSkill::Get_uWateringEffect()
{
	return uwateringEffect;
}

//���ô�����
void CSkill::Set_uReserveGold(uint32 uset)
{
	ureserveGold = uset;
}

//��ȡ������
int CSkill::Get_uReserveGold()
{
	return ureserveGold;
}

//��������Ч��
void CSkill::Set_uPlantEffect(uint32 uset)
{
	uplantEffect = uset;
}

//��ȡ����Ч��
int CSkill::Get_uPlantEffect()
{
	return uplantEffect;
}

//���ö������
void CSkill::Set_uDodgeAbility(uint32 uset)
{
	udodgeAbility = uset;
}

//��ȡ�������
int CSkill::Get_uDodgeAbility()
{
	return udodgeAbility;
}

//�������ټӳ�
void CSkill::Set_uRobAddition(uint32 uset)
{
	urobAddition = uset;
}

//��ȡ���ټӳ�
int CSkill::Get_uRobAddition()
{
	return urobAddition;
}
