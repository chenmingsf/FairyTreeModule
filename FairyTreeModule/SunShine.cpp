#include "SunShine.h"



CSunshine::CSunshine()
{
	fwater = 0; //��ͨˮ

	ufgrade = 0; //�ȼ�

	ufCoSun = 0; //������������

	ufCoGold = 0; //���Ľ������

	ufSunPCapa = 0; //����Ĳ�������

	ufSunPTime = 0; //���������ʱ��

	usunnum = 0; //���������
}


CSunshine::~CSunshine()
{
}

//����������ͨˮ
void CSunshine::Set_FAddWater(uint32 fwa)
{
	//����й�����ͨˮ ���� ���ɾ���������ͨˮ ��ͨˮ������������
	fwater += fwa;
}

//���ü�����ͨˮ
void CSunshine::Set_FMinusWater(uint32 ufmw)
{
	//�����ʹ����ͨˮ ��ͨˮ�������ͼ���
	fwater -= ufmw;
}

//��ȡ��ͨˮ
int CSunshine::Get_FWater()
{
	//������ͨˮ������
	return fwater;
}


//���õȼ�
void CSunshine::Set_FGrade(uint32 setgrad)
{
	ufgrade = setgrad;
}

//��ȡ�ȼ�
int CSunshine::Get_FGrade()
{
	return ufgrade;
}

//��������Ĳ�������
void CSunshine::Set_FSunProCap(uint32 setpro)
{
	ufSunPCapa += setpro;
}

//��ȡ����Ĳ�������
int CSunshine::Get_FSunProCap()
{
	return ufSunPCapa;
}

//�������������ʱ��
void CSunshine::Set_FSunProTime(uint32 setftime)
{
	ufSunPTime = setftime;
}

//��ȡ���������ʱ��
int CSunshine::Get_FSunProTime()
{
	return ufSunPTime;
}

//�����������������
void CSunshine::Set_FAddSunNumber(uint32 unum)
{
	usunnum += unum;
}

//���ü������������
void CSunshine::Set_FSubSunNum(uint32 unum)
{
	usunnum -= unum;
}

//��ȡ���������
int CSunshine::Get_FSunNumber()
{
	return usunnum;
}


