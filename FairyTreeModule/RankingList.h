#pragma once

#ifndef _RANKING_LIST_H
#define _RANKING_LIST_H

#include "Gamedefine.h"
#include <list>
#include "CharacterClass.h"

//���а���
class RankingList
{
public:
	RankingList();
	~RankingList();
	//���ӽ�ɫ
	void RankingList_AddCharacter(CharacterClass* uid);
	//ɾ����ɫ
	void RankingList_DelCharacter(uint32 delc);

	//��ȡ���а�
	std::list<CharacterClass*> Get_Rankinglist();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

private:

	//�û�ID
	uint32 m_roleID;

	CharacterClass * pcharass;
	
	std::list<CharacterClass*> list_ranking;

};

//���а��ɫ�ɳ�ֵ����
inline bool JudgeCharaLevel(CharacterClass* charaleve, CharacterClass* charalevel)
{
	return (charaleve->Get_RoleGrowthValue()) > (charalevel->Get_RoleGrowthValue());
}

#endif
