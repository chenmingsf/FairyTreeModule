#include "RankingList.h"



RankingList::RankingList()
{
	m_roleID = 0;//�û�ID
	pcharass = new CharacterClass;
}


RankingList::~RankingList()
{
	delete pcharass;
}


//���ӽ�ɫ
void RankingList::RankingList_AddCharacter(CharacterClass* uid)
{
	list_ranking.push_back(uid);
}

//ɾ����ɫ
void RankingList::RankingList_DelCharacter(uint32 delc)
{

	//ͨ����ɫID���� Ҫɾ���Ľ�ɫ
	for (std::list<CharacterClass*>::iterator itlist = list_ranking.begin(); itlist != list_ranking.end(); itlist++)
	{
		if (delc == (*itlist)->Get_Role_ID())
		{
			list_ranking.erase(itlist);
			return;
		}
	}

}

//��ȡ���а�
std::list<CharacterClass*> RankingList::Get_Rankinglist()
{
	list_ranking.sort(JudgeCharaLevel);
	return list_ranking;
}

//�����û�ID
void RankingList::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//��ȡ�û�ID
uint32 RankingList::Get_RoleID()
{
	return m_roleID;
}


