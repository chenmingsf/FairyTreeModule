#include "Relation.h"



Relation::Relation()
{
}


Relation::~Relation()
{
}

//���Ӻ���
void Relation::RAddFriend(CharacterClass* cr)
{
	crfriendlist.push_back(cr);
}

// ɾ������
void Relation::RDelFriend(uint32 udel)
{

	//ͨ����ɫID���� Ҫɾ���Ľ�ɫ
	for (std::list<CharacterClass*>::iterator it = crfriendlist.begin(); it != crfriendlist.end(); it++)
	{
		if (udel == (*it)->Get_Role_ID())
		{
			crfriendlist.erase(it);
		}
	}
	
}

//���ӵ���
void Relation::RAddEnemy(CharacterClass* cr)
{
	crenemylist.push_back(cr);
}

// ɾ������
void Relation::RDelEnemy(uint32 udel)
{

	//ͨ����ɫID���� Ҫɾ���Ľ�ɫ
	for (std::list<CharacterClass*>::iterator it = crenemylist.begin(); it != crenemylist.end(); it++)
	{
		if (udel == (*it)->Get_Role_ID())
		{
			crenemylist.erase(it);
		}
	}

}