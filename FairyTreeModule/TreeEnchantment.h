#pragma once

#ifndef _TREE_ENCHANTMENT_H
#define _TREE_ENCHANTMENT_H

#include "define.h"

//�������
class TreeEnchantment
{
public:
	TreeEnchantment();
	~TreeEnchantment();
	//���õȼ�
	void Set_TEGrade(uint32 sg);
	//��ȡ�ȼ�
	int Get_TEGrade();

	//���ý�����
	void Set_TEDefense(uint32 sted);
	//��ȡ������
	int Get_TEDefense();

	//�򿪱�����
	bool OpenGuard(bool bog);
	//�رձ�����
	bool CloseGuard(bool bcg);

	//������
	bool OpenPitfall(bool bop);
	//�ر�����
	bool ClosePitfall(bool bcp);
private:
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
