#pragma once

#ifndef _WATER_H
#define _WATER_H

#include "Gamedefine.h"
#include <map>


//ˮ��Դ��
class Water
{
public:
	Water();
	~Water();
	//����������ͨˮ������
	void Set_WAddOrdinaryWater(uint32 sow);
	//���ü�����ͨˮ������
	void Set_ReduceOrdinaryWater(uint32 srow);
	//��ȡ��ͨˮ������
	uint32 Get_WOrdinaryWater();

	//������������ˮ������
	void Set_WAddFairyWater(uint32 sfw);
	//���ü�������ˮ������
	void Set_WReduceFairyWater(uint32 sfw);
	//��ȡ����ˮ������
	uint32 Get_WFairyWater();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//ˮ��Դ��map
	std::map<uint32, Water*> map_water;
private:

	//�û�ID
	uint32 m_roleID;

	//��ͨˮ
	uint32 uordinarywater;

	//����ˮ
	uint32 ufairywater;

};

#endif
