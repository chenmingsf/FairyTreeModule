#pragma once

#ifndef _RELATION_H
#define _RELATION_H

#include "define.h"
#include <list>
#include "CharacterClass.h"

//��ϵ��
class Relation
{
public:
	Relation();
	~Relation();
	//���Ӻ���
	void RAddFriend(CharacterClass* cr);
	// ɾ������ ͨ����ɫID
	void RDelFriend(uint32 udel);

	//���ӵ���
	void RAddEnemy(CharacterClass* cr);
	// ɾ������ ͨ����ɫID
	void RDelEnemy(uint32 udel);

private:
	//�������
	std::list<CharacterClass*> crfriendlist;

	//�ж����
	std::list<CharacterClass*> crenemylist;
};

#endif
