#pragma once

#ifndef _TREE_ENCHANTMENT_H
#define _TREE_ENCHANTMENT_H

#include "Gamedefine.h"
#include <map>

//�������
class TreeEnchantment
{
public:
	TreeEnchantment();
	~TreeEnchantment();
	//���õȼ�
	void Set_TEGrade(uint32 sg);
	//��ȡ�ȼ�
	uint32 Get_TEGrade();

	//���ý�����
	void Set_TEDefense(uint32 sted);
	//��ȡ������
	uint32 Get_TEDefense();

	//�򿪱�����
	bool OpenGuard(bool bog);
	//�رձ�����
	bool CloseGuard(bool bcg);

	//������
	bool OpenPitfall(bool bop);
	//�ر�����
	bool ClosePitfall(bool bcp);

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//������map
	std::map<uint32, TreeEnchantment*> map_treeEn;
private:

	//�û�ID
	uint32 m_roleID;

	//�ȼ�
	uint32 ugrade;
	//������
	uint32 udefense;

	//������
	bool bopenguard;//��
	bool bcloseguard;//�ر�

	//����(Ԥ��)
	bool bopenpitfall;//��
	bool bclosepitfall;//�ر�
};



#endif
