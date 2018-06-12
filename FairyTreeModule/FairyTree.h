#pragma once
#ifndef _FAIRY_TREE_H
#define _FAIRY_TREE_H

#include "Gamedefine.h"
#include "CharacterClass.h"
#include <map>

//������(FairyTree)�ܹ�����(store)���(gold)�����(max)��(number)
//#define FAIRYTREESTOREMAXNUMBER  1000


#define FMAXGOLDTIME 50 //������ҵ����ʱ��

#define FGOLDNUMBER 10 //������ҵ�����

//��������
class FairyTree
{
public:
	FairyTree();
	~FairyTree();
	//���õȼ�
	void Set_FGrade(bool fgr);
	// ��ȡ�ȼ�
	uint32 Get_FGrade();

	//��������
	void Set_TreeHeight(uint32 sth);
	//��ȡ����
	uint32 Get_TreeHeight();

	//���������Ľ�� 
	void Set_FGold(uint32 fgo);
	//��ȡ���
	uint32 Get_FGold();

	//����������ҵ�ʱ��
	void Set_FGoldTime(uint32 ufgt);
	//��ȡʱ��
	uint32 Get_FGoldTime();

	//�����������洢���
	void Set_FAddFaiTreStoGol(uint32 ufftsg);
	//���ü������洢���
	void Set_FMinusFaiTreStoGol(uint32 ufmftsg);
	//��ȡ���洢���
	uint32 Get_FFaiTreStoGol();

	//��������ˮ������
	void Set_FCoWaterNum(uint32 num);
	//��ȡ����ˮ������
	uint32 Get_FCoWaterNum();

	//����������������
	void Set_FCoSunNum(uint32 num);
	//��ȡ������������
	uint32 Get_FCoSunNum();

	//���ý����������
	void Set_FCoGoldNum(uint32 num);
	//��ȡ�����������
	uint32 Get_FCoGoldNum();

	//������ʯ��������
	void Set_FCoJewelNum(uint32 num);
	//��ȡ��ʯ��������
	uint32 Get_FCoJewelNum();

	//����С������������
	void Set_FCoeflinNum(uint32 num);
	//��ȡС������������
	uint32 Get_FCoeflinNum();

	//����ͻ������
	void Set_FCoBreakthNum(uint32 num);
	//��ȡͻ������
	uint32 Get_FCoBreakthNum();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//��������map
	std::map<uint32, FairyTree*> map_fairytree;
private:

	//�û�ID
	uint32 m_roleID;

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
	uint32 ucowaternum;
	//������������
	uint32 ucosunnum;
	//�����������
	uint32 ucogoldnum;
	//��ʯ��������
	uint32 ucojewelnum;
	//С������������
	uint32 ucoeflinnum;
	//ͻ������
	uint32 ucobreakthnum;


};


#endif
