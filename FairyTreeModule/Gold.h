#pragma once

#ifndef _GOLD_H
#define _GOLD_H

#include "define.h"
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
	int Get_GGoldNumber();

	//�����map
	std::map<uint32, Gold*> map_gold;
private:
	//��ҵ�����
	uint32 ugoldnumber;
};

#endif
