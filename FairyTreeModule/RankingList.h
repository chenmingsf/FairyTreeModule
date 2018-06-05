#pragma once

#ifndef _RANKING_LIST_H
#define _RANKING_LIST_H

#include "define.h"
#include <list>
#include "CharacterClass.h"

//���а���
class RankingList
{
public:
	RankingList();
	~RankingList();
	//���ӽ�ɫ
	void RankingList_AddCharacter(CharacterClass* addch);
	//ɾ����ɫ
	void RankingList_DelCharacter(uint32 delc);

	//��ȡ�ý�ɫ��Ϣ
	CharacterClass Get_CharaMessage(CharacterClass* addch);
	
private:
	//���а�����
	std::list<CharacterClass*> rlist;
	
};

//�жϽ�ɫ�ȼ�
inline bool JudgeCharaLevel(CharacterClass* charaleve, CharacterClass* charalevel)
{
	return (charaleve->Get_RoleLevel()) > (charalevel->Get_RoleLevel());
}

#endif
