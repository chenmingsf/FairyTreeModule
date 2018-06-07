#pragma once

#ifndef _ELFIN_H
#define _ELFIN_H

#include "Skill.h"
#include "define.h"
#include <vector>
#include <windows.h>
#include <time.h>

#define SEGMAXPHYSICALPOWER 10 //�������������ֵ

enum ElfinSkillType//��������
{
	EGOLD,   //��
	EWOOD,   //ľ
	EWATER,  //ˮ
	EFIRE,   //��
	ESOIL   //��
	//EDARK    //��
};

//С������
class Elfin
{
public:
	Elfin();
	~Elfin();
	//������Ӽ��ܸ�
	void Set_ESkillStyle(CSkill* ecsk);
	//����ɾ������
	void Set_EReduceSkillStyle(uint32 iderss);
	//��ȡ���ܸ�
	int Get_ESkillStyle();

	//���õȼ�
	void Set_EGrade(bool beg);
	//��ȡ�ȼ�
	int Get_EGrade();

	//������������
	void Set_EAddPhysicalPower(uint32 ueap);
	//���ü�������
	void Set_EReducePhysicalPower(uint32 uerp);
	//��ȡ��ǰ����
	int Get_EPhysicalPower();

	//�����������
	void Set_EMaxPhysicalPower(uint32 uempp);
	//��ȡ�������
	int Get_EMaxPhysicalPower();

	//����С�����ID
	void Set_EToID(uint32 etoid);
	//��ȡС�����ID
	int Get_ID();
private:

	//���ܸ�(���)
	std::vector<CSkill*> vec;
	
	//С�����ID
	uint32 uEid;

	//��Ʒ(Ԥ��)
	//----------

	//�ȼ�
	uint32 _egrade;

	//����
	uint32 _ephysicalpower;
	//�������
	uint32 _emaxphysicalpower;

	//ö�����͵ļ�������
	ElfinSkillType estype;

	//����(�������¼���)
	//1:��(��һ���� ������) 2:ľ(��һ���� ������Ч�ʸ���) 3:ˮ(��һ���� ��ˮ)
	//4:��(��һ���� �ó��Ӷ�������ҽ�ң�����Ϊ����5��) 5:��(��һ���� �ܿ�����) 6:��(����)
};


#endif

