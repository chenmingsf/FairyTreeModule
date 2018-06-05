#pragma once

#ifndef _FAIRY_TREE_USER_CLASSES_H
#define _FAIRY_TREE_USER_CLASSES_H

#include "define.h"
#include "Elfin.h"
#include "FairyTree.h"
#include "SunShine.h"
#include "Gold.h"
#include "Mail.h"
#include "RankingList.h"
#include "Relation.h"
#include "Shop.h"
#include "Skill.h"
#include "TaskClass.h"
#include "TreeEnchantment.h"
#include "Warehouse.h"
#include "Water.h"
#include "./TinyXML/tinyxml.h"
#include "./TinyXML/tinyxml.h"



//�������û���
class FairyTreeUserClasses
{
public:
	FairyTreeUserClasses();
	~FairyTreeUserClasses();

	//��ȡС����
	Elfin* Get_Elfin(uint32 id);

	//��ȡ������
	FairyTree Get_FairyTree();

	//��ȡ���ɾ�
	CSunshine Get_SunShine();

	//��ȡ�����
	TreeEnchantment Get_TreeEnchantment();

	//��ȡ�ֿ�
	Warehouse Get_Warehouse();

	//��ȡ�̵�
	Shop Get_Shop();

	//��ȡ����
	CMailbox Get_CMailbox();

	//��ȡ�����б�
	CTaskListClass Get_CTaskListClass();

	//��ȡ��ϵ
	Relation Get_Relation();

	//��ȡ���а�
	RankingList Get_RankingList();

	//��ȡ����
	CSkill Get_CSkill();

	//��ȡ��Դˮ
	Water Get_Water();

	//��ȡ��Դ���
	Gold Get_Gold();

	//����������ʯ
	void Set_UserAddDiamond(uint32 sd);
	//���ü�����ʯ
	void Set_UserRedDiamond(uint32 surd);
	//��ȡ��ʯ
	int Get_UserDiamond();

private:
	//С����(����)
	std::list<Elfin*> slistElfin;

	//������
	FairyTree fairytree;

	//̫��
	CSunshine sunshine;

	//�����
	TreeEnchantment treeenchantment;

	//�ֿ�
	Warehouse warehouse;

	//�̵�
	Shop shop;

	//����
	CMailbox mailbox;

	//�����б�
	CTaskListClass tasklist;

	//��ϵ
	Relation relation;

	//���а�
	RankingList rankinglist;

	//����
	CSkill skill;

	//��Դ(ˮ, ���)
	Water water;
	Gold gold;

	//��ʯ
	uint32 udiamond;

};

//��Xml�ļ�
//bool bPaintXml(const char* pfilepath);


#endif

