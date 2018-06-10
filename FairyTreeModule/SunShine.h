#pragma once

#ifndef _FAIRY_WELL_H
#define _FAIRY_WELL_H

#include "define.h"
#include <map>

#define SOLARPROCAP 10 //̫������������


//̫���� ��ȡ����Xml�ļ�
class CSunshine
{
public:
	CSunshine();
	~CSunshine();
	//����������ͨˮ
	void Set_FAddWater(uint32 fwa);
	//���ü�����ͨˮ
	void Set_FMinusWater(uint32 ufmw);
	//��ȡ��ͨˮ
	int Get_FWater();

	//���õȼ�
	void Set_FGrade(bool setgrad);
	//��ȡ�ȼ�
	int Get_FGrade();

	//��������Ĳ�������
	void Set_FSunProCap(uint32 setpro);
	//��ȡ����Ĳ�������
	int Get_FSunProCap();

	//�������������ʱ��
	void Set_FSunProTime(uint32 setftime);
	//��ȡ���������ʱ��
	int Get_FSunProTime();

	//�����������������
	void Set_FAddSunNumber(uint32 unum);
	//���ü������������
	void Set_FSubSunNum(uint32 unum);
	//��ȡ���������
	int Get_FSunNumber();

	//��������ˮ������
	void Set_SunCoWaterNum(uint32 num);
	//��ȡ����ˮ������
	int Get_SunCoWaterNum();

	//����������������
	void Set_SunCoSunNum(uint32 num);
	//��ȡ������������
	int Get_SunCoSunNum();

	//���ý����������
	void Set_SunCoGoldNum(uint32 num);
	//��ȡ�����������
	int Get_SunCoGoldNum();

	//������ʯ��������
	void Set_SunCoJewelNum(uint32 num);
	//��ȡ��ʯ��������
	int Get_SunCoJewelNum();

	//̫����map
	std::map<uint32, CSunshine*> map_sunshine;
private:
	//��ͨˮ
	uint32 fwater;

	//�ȼ�
	uint32 ufgrade;

	//����Ĳ�������
	uint32 ufSunPCapa;

	//���������ʱ��
	uint32 ufSunPTime;

	//���������
	uint32 usunnum;

	//����ˮ������
	uint32 ucowaternum;
	//������������
	uint32 ucosunnum;
	//�����������
	uint32 ucogoldnum;
	//��ʯ��������
	uint32 ucojewel;
};


#endif
