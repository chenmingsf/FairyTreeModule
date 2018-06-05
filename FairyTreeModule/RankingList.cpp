#include "RankingList.h"



RankingList::RankingList()
{
}


RankingList::~RankingList()
{
}


//���ӽ�ɫ
void RankingList::RankingList_AddCharacter(CharacterClass* addch)
{
	rlist.push_back(addch);
}

//ɾ����ɫ
void RankingList::RankingList_DelCharacter(uint32 delc)
{

	//ͨ����ɫID���� Ҫɾ���Ľ�ɫ
	for (std::list<CharacterClass*>::iterator itlist = rlist.begin(); itlist != rlist.end(); itlist++)
	{
		if (delc == (*itlist)->Get_Role_ID())
		{
			rlist.erase(itlist);
		}
	}

}

//��ȡ�ý�ɫ��Ϣ
CharacterClass RankingList::Get_CharaMessage(CharacterClass * addch)
{
	//���ݵȼ���������
	rlist.sort(JudgeCharaLevel);

	return *addch;
}

