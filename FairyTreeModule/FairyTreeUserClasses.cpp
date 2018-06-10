#include "FairyTreeUserClasses.h"



FairyTreeUserClasses::FairyTreeUserClasses()
{
	uRecordUserCount = 0;//��¼�û��ĸ���

	userid = 10000; //�û�ID

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
int FairyTreeUserClasses::Get_RecordUserCount()
{
	return uRecordUserCount;
}

//�����û�ID
void FairyTreeUserClasses::Set_UserId(uint32 suid)
{
	//�û�ID��
	userid += suid;
	//��ɫID��
	characlass.Set_Role_ID(userid);

}

//����û�ID
int FairyTreeUserClasses::Get_UserId()
{
	return userid;
}

//��ȡС����
Elfin FairyTreeUserClasses::Get_Elfin()
{ 
	return elf;
}

//��ȡ������
FairyTree FairyTreeUserClasses::Get_FairyTree()
{
	return fairytree;
}

//��ȡ̫��
CSunshine FairyTreeUserClasses::Get_SunShine()
{
	return sunshine;
}

//��ȡ�̵�
Shop FairyTreeUserClasses::Get_Shop()
{
	return cshop;
}

//��ȡ�����
TreeEnchantment FairyTreeUserClasses::Get_TreeEnchantment()
{
	return treeenchantment;
}

//��ȡ�ֿ�
Warehouse FairyTreeUserClasses::Get_Warehouse()
{
	return warehouse;
}

//��ȡ����
CMailbox FairyTreeUserClasses::Get_CMailbox()
{
	return mailbox;
}

//��ȡ������
CTaskListClass FairyTreeUserClasses::Get_CTaskListClass()
{
	return tasklist;
}

//��ȡ��ϵ
Relation FairyTreeUserClasses::Get_Relation()
{
	return relation;
}

//��ȡ���а�
RankingList FairyTreeUserClasses::Get_RankingList()
{
	return rankinglist;
}

//��ɫ��
CharacterClass FairyTreeUserClasses::Get_Characlass()
{
	return characlass;
}

//��ȡ����
CSkill FairyTreeUserClasses::Get_CSkill()
{
	return skill;
}

//��ȡ��Դˮ
Water FairyTreeUserClasses::Get_Water()
{
	return water;
}

//��ȡ��Դ���
Gold FairyTreeUserClasses::Get_Gold()
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
int FairyTreeUserClasses::Get_UserDiamond()
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
int FairyTreeUserClasses::vGetUpgradeWaterNum()
{
	return uUpwaterNum;
}
//������������ˮ���ĵ�����
void FairyTreeUserClasses::vSetUpgradeFairyTreeNum(uint32 num)
{
	uUpfairywaterNum += num;
}
//��ȡ��������ˮ���ĵ�����
int FairyTreeUserClasses::vGetUpgradeFairyTreeWaterNum()
{
	return uUpfairywaterNum;
}
//��������������ĵ�����
void FairyTreeUserClasses::vSetUpgradeGoldNum(uint32 num)
{
	uUpgoldNum += num;
}
//��ȡ����������ĵ�����
int FairyTreeUserClasses::vGetUpgradeGoldNum()
{
	return uUpgoldNum;
}
//���������������ĵ�����
void FairyTreeUserClasses::vSetUpgradeSunNum(uint32 num)
{
	uUpsunNum += num;
}
//��ȡ�����������ĵ�����
int FairyTreeUserClasses::vGetUpgradeSunNum()
{
	return uUpsunNum;
}
//��������С�����������ĵ�����
void FairyTreeUserClasses::vSetUpgradeElfinTiliNum(uint32 num)
{
	uUpelfinTiliNUM += num;
}
//��ȡ����С�����������ĵ�����
int FairyTreeUserClasses::vGetUpgradeElfinTiliNum()
{
	return uUpelfinTiliNUM;
}
//����������ʯ���ĵ�����
void FairyTreeUserClasses::vSetUpgradeDiamoNum(uint32 num)
{
	uUpdiaNum += num;
}
//��ȡ������ʯ���ĵ�����
int FairyTreeUserClasses::vGetUpgradeDiamoNum()
{
	return uUpdiaNum;
}

CAllUserInfoInstance* CAllUserInfoInstance::_instance = new CAllUserInfoInstance();
CAllUserInfoInstance * CAllUserInfoInstance::GetInstance()
{
	return _instance;
}
