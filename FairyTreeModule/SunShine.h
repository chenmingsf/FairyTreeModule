#pragma once

#ifndef _FAIRY_WELL_H
#define _FAIRY_WELL_H

#include "Gamedefine.h"
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
	uint32 Get_FWater();

	//���õȼ�
	void Set_FGrade(bool setgrad);
	//��ȡ�ȼ�
	uint32 Get_FGrade();

	//��������Ĳ�������
	void Set_FSunProCap(uint32 setpro);
	//��ȡ����Ĳ�������
	uint32 Get_FSunProCap();

	//�������������ʱ��
	void Set_FSunProTime(uint32 setftime);
	//��ȡ���������ʱ��
	uint32 Get_FSunProTime();

	//�����������������
	void Set_FAddSunNumber(uint32 unum);
	//���ü������������
	void Set_FSubSunNum(uint32 unum);
	//��ȡ���������
	uint32 Get_FSunNumber();

	//��������ˮ������
	void Set_SunCoWaterNum(uint32 num);
	//��ȡ����ˮ������
	uint32 Get_SunCoWaterNum();

	//����������������
	void Set_SunCoSunNum(uint32 num);
	//��ȡ������������
	uint32 Get_SunCoSunNum();

	//���ý����������
	void Set_SunCoGoldNum(uint32 num);
	//��ȡ�����������
	uint32 Get_SunCoGoldNum();

	//������ʯ��������
	void Set_SunCoJewelNum(uint32 num);
	//��ȡ��ʯ��������
	uint32 Get_SunCoJewelNum();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//̫����map
	std::map<uint32, CSunshine*> map_sunshine;
private:

	//�û�ID
	uint32 m_roleID;

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
