#pragma once

#ifndef _FAIRY_WELL_H
#define _FAIRY_WELL_H

#include "define.h"


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
	void Set_FGrade(uint32 setgrad);
	//��ȡ�ȼ�
	int Get_FGrade();

	//����������������
	void Set_FSunCoNum(uint32 setfsun);
	//��ȡ������������
	int Get_FSunCoNum();

	//�������Ľ������
	void Set_FCoGoldNum(uint32 setfco);
	//��ȡ���Ľ������
	int Get_FCoGoldNum();

	//��������Ĳ�������
	void Set_FSunProCap(uint32 setpro);
	//��ȡ����Ĳ�������
	int Get_FSunProCap();

	//�������������ʱ��
	void Set_FSunProTime(uint32 setftime);
	//��ȡ���������ʱ��
	int Get_FSunProTime();
private:
	//��ͨˮ
	uint32 fwater;

	//�ȼ�
	uint32 ufgrade;

	//������������
	uint32 ufCoSun;

	//���Ľ������
	uint32 ufCoGold;

	//����Ĳ�������
	uint32 ufSunPCapa;

	//���������ʱ��
	uint32 ufSunPTime;
};


#endif
