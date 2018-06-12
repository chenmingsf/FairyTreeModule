#include "FairyTreeUserClasses.h"



FairyTreeUserClasses::FairyTreeUserClasses()
{
	uRecordUserCount = 0;//��¼�û��ĸ���

	m_roleID = 10000; //�û�ID

	udiamond = 0; //��ʯ

	uUpwaterNum = 0;//������Ҫ����ͨˮ������
	
	uUpfairywaterNum = 0;//������Ҫ������ˮ������
	
	uUpgoldNum = 0;//������Ҫ�Ľ�ҵ�����
	
	uUpsunNum = 0;//������Ҫ�����������
	
	uUpelfinTiliNUM = 0;//������Ҫ��С��������������
	
	uUpdiaNum = 0;//������Ҫ����ʯ������
}


FairyTreeUserClasses::~FairyTreeUserClasses()
{
}

//���ü�¼�û��ĸ���
void FairyTreeUserClasses::Set_RecordUserCount(uint32 ucon)
{
	//�û��ĸ����� 1 
	uRecordUserCount += ucon;
	//�û���ID�ü� 1;
	Set_UserId(ucon);
}

//��ȡ��¼�û��ĸ���
uint32 FairyTreeUserClasses::Get_RecordUserCount()
{
	return uRecordUserCount;
}

//�����û�ID
void FairyTreeUserClasses::Set_UserId(uint32 suid)
{
	//�û�ID��
	m_roleID += suid;
	//��ɫID��
	characlass.Set_Role_ID(m_roleID);
	elf.Set_RoleID(m_roleID);
	fairytree.Set_RoleID(m_roleID);
	sunshine.Set_RoleID(m_roleID);
	cshop.Set_RoleID(m_roleID);
	treeenchantment.Set_RoleID(m_roleID);
	warehouse.Set_RoleID(m_roleID);
	mailbox.Set_RoleID(m_roleID);
	tasklist.Set_RoleID(m_roleID);
	relation.Set_RoleID(m_roleID);
	rankinglist.Set_RoleID(m_roleID);
	skill.Set_RoleID(m_roleID);
	water.Set_RoleID(m_roleID);
	gold.Set_RoleID(m_roleID);

}

//����û�ID
uint32 FairyTreeUserClasses::Get_UserId()
{
	return m_roleID;
}

//��ȡС����
Elfin& FairyTreeUserClasses::Get_Elfin()
{ 
	return elf;
}

//��ȡ������
FairyTree& FairyTreeUserClasses::Get_FairyTree()
{
	return fairytree;
}

//��ȡ̫��
CSunshine& FairyTreeUserClasses::Get_SunShine()
{
	return sunshine;
}

//��ȡ�̵�
Shop& FairyTreeUserClasses::Get_Shop()
{
	return cshop;
}

//��ȡ�����
TreeEnchantment& FairyTreeUserClasses::Get_TreeEnchantment()
{
	return treeenchantment;
}

//��ȡ�ֿ�
Warehouse& FairyTreeUserClasses::Get_Warehouse()
{
	return warehouse;
}

//��ȡ����
CMailbox& FairyTreeUserClasses::Get_CMailbox()
{
	return mailbox;
}

//��ȡ������
CTaskListClass& FairyTreeUserClasses::Get_CTaskListClass()
{
	return tasklist;
}

//��ȡ��ϵ
Relation& FairyTreeUserClasses::Get_Relation()
{
	return relation;
}

//��ȡ���а�
RankingList& FairyTreeUserClasses::Get_RankingList()
{
	return rankinglist;
}

//��ɫ��
CharacterClass& FairyTreeUserClasses::Get_Characlass()
{
	return characlass;
}

//��ȡ����
CSkill& FairyTreeUserClasses::Get_CSkill()
{
	return skill;
}

//��ȡ��Դˮ
Water& FairyTreeUserClasses::Get_Water()
{
	return water;
}

//��ȡ��Դ���
Gold& FairyTreeUserClasses::Get_Gold()
{
	return gold;
}

//����������ʯ
void FairyTreeUserClasses::Set_UserAddDiamond(uint32 sd)
{
	udiamond += sd;
}

//���ü�����ʯ
void FairyTreeUserClasses::Set_UserRedDiamond(uint32 surd)
{
	udiamond -= surd;
}

//��ȡ��ʯ
uint32 FairyTreeUserClasses::Get_UserDiamond()
{
	return udiamond;
}

//̫����������
void FairyTreeUserClasses::vUpgradeSolarFun(uint32 uid)
{
	if (characlass.Get_Role_ID() == uid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum()
		&& elf.Get_EPhysicalPower() >= vGetUpgradeElfinTiliNum())
	{
		sunshine.Set_FGrade(true);
	}
}

//С������������
void FairyTreeUserClasses::vUpgradeElfinFun(uint32 uelfid)
{
	if (elf.Get_ID() == uelfid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum())
	{
		elf.Set_EGrade(true);
	}

}

//��������������
void FairyTreeUserClasses::vUpgradeFairyTreeFun(uint32 uid)
{
	if (characlass.Get_Role_ID() == uid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum()
		&& elf.Get_EPhysicalPower() >= vGetUpgradeElfinTiliNum())
	{
		fairytree.Set_FGrade(true);
	}
}

//������������
void FairyTreeUserClasses::vUpgradeSkillFun(uint32 usklid)
{
	if (skill.Get_Skill_ID() == usklid
		&& water.Get_WOrdinaryWater() >= vGetUpgradeWaterNum()
		&& gold.Get_GGoldNumber() >= vGetUpgradeGoldNum()
		&& sunshine.Get_FSunNumber() >= vGetUpgradeSunNum()
		&& Get_UserDiamond() >= vGetUpgradeDiamoNum())
	{
		skill.Set_Skill_Level(true);
	}

}


//����������ͨˮ���ĵ�����
void FairyTreeUserClasses::vSetUpgradeWaterNum(uint32 num)
{
	uUpwaterNum += num;
}
//��ȡ������ͨˮ���ĵ�����
uint32 FairyTreeUserClasses::vGetUpgradeWaterNum()
{
	return uUpwaterNum;
}
//������������ˮ���ĵ�����
void FairyTreeUserClasses::vSetUpgradeFairyTreeNum(uint32 num)
{
	uUpfairywaterNum += num;
}
//��ȡ��������ˮ���ĵ�����
uint32 FairyTreeUserClasses::vGetUpgradeFairyTreeWaterNum()
{
	return uUpfairywaterNum;
}
//��������������ĵ�����
void FairyTreeUserClasses::vSetUpgradeGoldNum(uint32 num)
{
	uUpgoldNum += num;
}
//��ȡ����������ĵ�����
uint32 FairyTreeUserClasses::vGetUpgradeGoldNum()
{
	return uUpgoldNum;
}
//���������������ĵ�����
void FairyTreeUserClasses::vSetUpgradeSunNum(uint32 num)
{
	uUpsunNum += num;
}
//��ȡ�����������ĵ�����
uint32 FairyTreeUserClasses::vGetUpgradeSunNum()
{
	return uUpsunNum;
}
//��������С�����������ĵ�����
void FairyTreeUserClasses::vSetUpgradeElfinTiliNum(uint32 num)
{
	uUpelfinTiliNUM += num;
}
//��ȡ����С�����������ĵ�����
uint32 FairyTreeUserClasses::vGetUpgradeElfinTiliNum()
{
	return uUpelfinTiliNUM;
}
//����������ʯ���ĵ�����
void FairyTreeUserClasses::vSetUpgradeDiamoNum(uint32 num)
{
	uUpdiaNum += num;
}
//��ȡ������ʯ���ĵ�����
uint32 FairyTreeUserClasses::vGetUpgradeDiamoNum()
{
	return uUpdiaNum;
}

CAllUserInfoInstance* CAllUserInfoInstance::_instance = new CAllUserInfoInstance();
CAllUserInfoInstance * CAllUserInfoInstance::GetInstance()
{
	return _instance;
}

std::map<uint32, FairyTreeUserClasses*> CAllUserInfoInstance::fun(uint32 uid)
{
	ConnetedUser[uid]->Get_Elfin().map_elfin = fairy.Get_Elfin().map_elfin;
	ConnetedUser[uid]->Get_CMailbox().map_mail = fairy.Get_CMailbox().map_mail;
	ConnetedUser[uid]->Get_CSkill().map_skill = fairy.Get_CSkill().map_skill;
	ConnetedUser[uid]->Get_CTaskListClass().map_task = fairy.Get_CTaskListClass().map_task;
	ConnetedUser[uid]->Get_Characlass().map_haracter = fairy.Get_Characlass().map_haracter;
	ConnetedUser[uid]->Get_FairyTree().map_fairytree = fairy.Get_FairyTree().map_fairytree;
	ConnetedUser[uid]->Get_Gold().map_gold = fairy.Get_Gold().map_gold;
	ConnetedUser[uid]->Get_Shop().storeItemInfo = fairy.Get_Shop().storeItemInfo;
	ConnetedUser[uid]->Get_SunShine().map_sunshine = fairy.Get_SunShine().map_sunshine;
	ConnetedUser[uid]->Get_TreeEnchantment().map_treeEn = fairy.Get_TreeEnchantment().map_treeEn;
	ConnetedUser[uid]->Get_Warehouse().map_warehouse = fairy.Get_Warehouse().map_warehouse;
	ConnetedUser[uid]->Get_Water().map_water = fairy.Get_Water().map_water;
	return ConnetedUser;
}
