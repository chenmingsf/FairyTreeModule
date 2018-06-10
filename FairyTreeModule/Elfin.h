#pragma once

#ifndef _ELFIN_H
#define _ELFIN_H

#include "Skill.h"
#include "define.h"
#include <vector>
#include <windows.h>
#include <time.h>
#include <map>

#define SEGMAXPHYSICALPOWER 10 //�������������ֵ

enum ElfinType//��������
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
	ElfinType Get_ESkillStyle();

	//���õȼ�
	void Set_EGrade(uint32 beg);
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

	//��������ˮ������
	void Set_uCoWaterNum(uint32 num);
	//��ȡ����ˮ������
	int Get_uCoWaterNum();

	//����������������
	void Set_uCoSunNum(uint32 num);
	//��ȡ������������
	int Get_uCoSunNum();

	//���ý����������
	void Set_uCoGoldNum(uint32 num);
	//��ȡ�����������
	int Get_uCoGoldNum();

	//������ʯ��������
	void Set_uCoJewelNum(uint32 num);
	//��ȡ��ʯ��������
	int Get_uCoJewelNum();

	//С�����map
	std::map<uint32, Elfin*> map_elfin;
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
	ElfinType estype;

	//����ˮ������
	uint32 ucowaternum;
	//������������
	uint32 ucosunnum;
	//�����������
	uint32 ucogoldnum;
	//��ʯ��������
	uint32 ujewelnum;

	//����(�������¼���)
	//1:��(��һ���� ������) 2:ľ(��һ���� ������Ч�ʸ���) 3:ˮ(��һ���� ��ˮ)
	//4:��(��һ���� �ó��Ӷ�������ҽ�ң�����Ϊ����5��) 5:��(��һ���� �ܿ�����) 6:��(����)
};


#endif

