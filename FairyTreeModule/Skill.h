#pragma once

#ifndef _SKILL_H
#define _SKILL_H

#include "define.h"
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
	int Get_Skill_Level();

	//���ü���ID
	void Set_Skill_ID(uint32 ssid);
	//��ȡ����ID
	int Get_Skill_ID();

	//���ü�������
	void Set_Skill_Describe(std::string skill);
	//��ȡ��������
	std::string Get_Skill_Describe();
	
	//�����Ӷ�Ч��
	void Set_uPillageEffect(uint32 uset);
	//��ȡ�Ӷ�Ч��
	int Get_uPillageEffect();

	//���ý�ˮЧ��
	void Set_uWateringEffect(uint32 uset);
	//��ȡ��ˮЧ��
	int Get_uWateringEffect();

	//���ô�����
	void Set_uReserveGold(uint32 uset);
	//��ȡ������
	int Get_uReserveGold();

	//��������Ч��
	void Set_uPlantEffect(uint32 uset);
	//��ȡ����Ч��
	int Get_uPlantEffect();

	//���ö������
	void Set_uDodgeAbility(uint32 uset);
	//��ȡ�������
	int Get_uDodgeAbility();

	//�������ټӳ�
	void Set_uRobAddition(uint32 uset);
	//��ȡ���ټӳ�
	int Get_uRobAddition();

	//����map
	std::map<uint32, CSkill*> map_skill;
private:
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

