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
#include "XmlConfigManager.h"
#include "CharacterClass.h"




//�������û���
class FairyTreeUserClasses
{
public:
	FairyTreeUserClasses();
	~FairyTreeUserClasses();

	//���ü�¼�û��ĸ���
	void Set_RecordUserCount(uint32 ucon);
	//��ȡ��¼�û��ĸ���
	int Get_RecordUserCount();

	//�����û�ID
	void Set_UserId(uint32 suid);
	//����û�ID
	int Get_UserId();

	//��ȡС����
	Elfin Get_Elfin();

	//��ȡ������
	FairyTree Get_FairyTree();

	//��ȡ����
	CSunshine Get_SunShine();

	//��ȡ�̵�
	Shop Get_Shop();

	//��ȡ�����
	TreeEnchantment Get_TreeEnchantment();

	//��ȡ�ֿ�
	Warehouse Get_Warehouse();

	//��ȡ����
	CMailbox Get_CMailbox();

	//��ȡ������
	CTaskListClass Get_CTaskListClass();

	//��ȡ��ϵ
	Relation Get_Relation();

	//��ȡ���а�
	RankingList Get_RankingList();

	//��ɫ��
	CharacterClass Get_Characlass();

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
	//��ȡ��ʯ����
	int Get_UserDiamond();

	//̫����������
	void vUpgradeSolarFun(uint32 uid);
	//С������������
	void vUpgradeElfinFun(uint32 uelfid);
	//��������������
	void vUpgradeFairyTreeFun(uint32 uid);
	//������������
	void vUpgradeSkillFun(uint32 usklid);

	//����������ͨˮ���ĵ�����
	void vSetUpgradeWaterNum(uint32 num);
	//��ȡ������ͨˮ���ĵ�����
	int vGetUpgradeWaterNum();
	//������������ˮ���ĵ�����
	void vSetUpgradeFairyTreeNum(uint32 num);
	//��ȡ��������ˮ���ĵ�����
	int vGetUpgradeFairyTreeWaterNum();
	//��������������ĵ�����
	void vSetUpgradeGoldNum(uint32 num);
	//��ȡ����������ĵ�����
	int vGetUpgradeGoldNum();
	//���������������ĵ�����
	void vSetUpgradeSunNum(uint32 num);
	//��ȡ�����������ĵ�����
	int vGetUpgradeSunNum();
	//��������С�����������ĵ�����
	void vSetUpgradeElfinTiliNum(uint32 num);
	//��ȡ����С�����������ĵ�����
	int vGetUpgradeElfinTiliNum();
	//����������ʯ���ĵ�����
	void vSetUpgradeDiamoNum(uint32 num);
	//��ȡ������ʯ���ĵ�����
	int vGetUpgradeDiamoNum();
private:
	//��¼�û��ĸ���
	uint32 uRecordUserCount;

	//�û�ID
	uint32 userid;

	//С����(����)
	Elfin elf;

	//������
	FairyTree fairytree;

	//̫��
	CSunshine sunshine;
	
	//�̵�
	Shop cshop;

	//�����
	TreeEnchantment treeenchantment;

	//�ֿ�
	Warehouse warehouse;

	//����
	CMailbox mailbox;

	//������
	CTaskListClass tasklist;

	//��ϵ
	Relation relation;

	//���а�
	RankingList rankinglist;

	//��ɫ��
	CharacterClass characlass;

	//����
	CSkill skill;

	//��Դ(ˮ, ���)
	Water water;
	Gold gold;

	//��ʯ
	uint32 udiamond;

	//������Ҫ����ͨˮ������
	uint32 uUpwaterNum;
	//������Ҫ������ˮ������
	uint32 uUpfairywaterNum;
	//������Ҫ�Ľ�ҵ�����
	uint32 uUpgoldNum;
	//������Ҫ�����������
	uint32 uUpsunNum;
	//������Ҫ��С��������������
	uint32 uUpelfinTiliNUM;
	//������Ҫ����ʯ������
	uint32 uUpdiaNum;
};

class CAllUserInfoInstance 
{
	CAllUserInfoInstance() {};
	static CAllUserInfoInstance* _instance;
public:
	static CAllUserInfoInstance * GetInstance();
	std::map<uint32, FairyTreeUserClasses*> ConnetedUser;

};
#endif

