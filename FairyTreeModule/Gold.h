#pragma once

#ifndef _GOLD_H
#define _GOLD_H

#include "define.h"

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
	int Get_GGoldNumber();
private:
	//��ҵ�����
	uint32 ugoldnumber;
};

#endif
