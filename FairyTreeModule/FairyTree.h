#pragma once
#ifndef _FAIRY_TREE_H
#define _FAIRY_TREE_H

#include "define.h"

//������(FairyTree)�ܹ�����(store)���(gold)�����(max)��(number)
//#define FAIRYTREESTOREMAXNUMBER  1000

#define FMAXEXPERIENCE 100 //������(FairyTree)�������ֵ

#define FMAXGOLDTIME 50 //������ҵ����ʱ��

#define FGOLDNUMBER 10 //������ҵ�����

//��������
class FairyTree
{
public:
	FairyTree();
	~FairyTree();
	//���õȼ� ��ȡ�ȼ�
	void Set_FGrade(uint32 fgr);
	int Get_FGrade();

	//��������
	void Set_TreeHeight(uint32 sth);
	//��ȡ����
	int Get_TreeHeight();

	//���������Ľ�� 
	void Set_FGold(uint32 fgo);
	//��ȡ���
	int Get_FGold();

	//����������ҵ�ʱ��
	void Set_FGoldTime(uint32 ufgt);
	//��ȡʱ��
	int Get_FGoldTime();

	//�����������洢���
	void Set_FAddFaiTreStoGol(uint32 ufftsg);
	//���ü������洢���
	void Set_FMinusFaiTreStoGol(uint32 ufmftsg);
	//��ȡ���洢���
	int Get_FFaiTreStoGol();

	//��������ˮ������
	void Set_ConsumptionWater(uint32 scw);
	//��ȡ����ˮ������
	int Get_ConsumptionWater();

	//�����������������
	void Set_ConsumptionSunshine(uint32 scs);
	//��ȡ�������������
	int Get_ConsumptionSunshine();

	//�������Ľ�ҵ�����
	void Set_ConsumptionGold(uint32 scg);
	//��ȡ���Ľ�ҵ�����
	int Get_ConsumptionGold();

	//��������С��������������
	void Set_ConsumptionElfinPP(uint32 scepp);
	//��ȡ����С��������������
	int Get_ConsumptionElfinPP();
private:
	//�ȼ�
	uint32 fgrade;
	//���� = �ȼ�
	uint32 uheightTree;

	//�����Ľ��
	uint32 fgold;

	//������ҵ�ʱ��
	uint32 fgoldtime;

	//�������洢���
	uint32 cfaiTreStoGol;

	//����ˮ������
	uint32 uCoWaterNum;

	//�������������
	uint32 uCoSunNum;

	//���Ľ�ҵ�����
	uint32 uCoGoldNum;

	//����С��������������
	uint32 uCoElfinPP;


};


#endif
