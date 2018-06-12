#pragma once

#ifndef _GOLD_H
#define _GOLD_H

#include "Gamedefine.h"
#include <map>

//�����
class Gold
{
public:
	Gold();
	~Gold();
	//�������ӽ�ҵ�����
	void Set_GAddGoldNumber(uint32 ggn);
	//���ü��ٽ�ҵ�����
	void Set_GReduceGoldNumber(uint32 grgn);
	//��ȡ��ҵ�����
	uint32 Get_GGoldNumber();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	int Get_RoleID();

	//�����map
	std::map<uint32, Gold*> map_gold;
private:

	//�û�ID
	uint32 m_roleID;

	//��ҵ�����
	uint32 ugoldnumber;
};

#endif
