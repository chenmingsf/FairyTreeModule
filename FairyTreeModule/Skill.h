#pragma once

#ifndef _SKILL_H
#define _SKILL_H

#include "Gamedefine.h"
#include <map>

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
	uint32 Get_Skill_Level();

	//���ü���ID
	void Set_Skill_ID(uint32 ssid);
	//��ȡ����ID
	uint32 Get_Skill_ID();

	//���ü�������
	void Set_Skill_Describe(const std::string& skill);
	//��ȡ��������
	std::string Get_Skill_Describe();
	
	//�����Ӷ�Ч��
	void Set_uPillageEffect(uint32 uset);
	//��ȡ�Ӷ�Ч��
	uint32 Get_uPillageEffect();

	//���ý�ˮЧ��
	void Set_uWateringEffect(uint32 uset);
	//��ȡ��ˮЧ��
	uint32 Get_uWateringEffect();

	//���ô�����
	void Set_uReserveGold(uint32 uset);
	//��ȡ������
	uint32 Get_uReserveGold();

	//��������Ч��
	void Set_uPlantEffect(uint32 uset);
	//��ȡ����Ч��
	uint32 Get_uPlantEffect();

	//���ö������
	void Set_uDodgeAbility(uint32 uset);
	//��ȡ�������
	uint32 Get_uDodgeAbility();

	//�������ټӳ�
	void Set_uRobAddition(uint32 uset);
	//��ȡ���ټӳ�
	uint32 Get_uRobAddition();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//����map
	std::map<uint32, CSkill*> map_skill;
private:

	//�û�ID
	uint32 m_roleID;

	//��������
	SkillType skilltype;

	//���ܵȼ�
	uint32 uskillLevel;

	//����ID
	uint32 uskillID;

	//��������
	std::string skilldescribe;

	//�Ӷ�Ч��
	uint32 upillageEffect;
	//��ˮЧ��
	uint32 uwateringEffect;
	//������
	uint32 ureserveGold;
	//����Ч��
	uint32 uplantEffect;
	//�������
	uint32 udodgeAbility;
	//���ټӳ�
	uint32 urobAddition;

	//��Ч(����)

	//����(����)

	//����Ч��
};


//����Ч�� д�ɻ��� ������


#endif

