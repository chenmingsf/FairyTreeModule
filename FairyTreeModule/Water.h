#pragma once

#ifndef _WATER_H
#define _WATER_H

#include "define.h"


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
	int Get_WOrdinaryWater();

	//������������ˮ������
	void Set_WAddFairyWater(uint32 sfw);
	//���ü�������ˮ������
	void Set_WReduceFairyWater(uint32 sfw);
	//��ȡ����ˮ������
	int Get_WFairyWater();
private:
	//��ͨˮ
	uint32 uordinarywater;

	//����ˮ
	uint32 ufairywater;

};

#endif
