#include "SunShine.h"



CSunshine::CSunshine()
{
	fwater = 0; //��ͨˮ

	ufgrade = 0; //�ȼ�

	ufSunPCapa = 0; //����Ĳ�������

	ufSunPTime = 0; //���������ʱ��

	usunnum = 0; //���������
	 
	ucowaternum = 0;//����ˮ������
	
	ucosunnum = 0;//������������
	
	ucogoldnum = 0;//�����������
	
	ucojewel = 0;//��ʯ��������
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
void CSunshine::Set_FGrade(bool setgrad)
{
	if (setgrad)
	{
		ufgrade += 1;

		//̫��ÿ����һ�� ��������Ҳ������
		Set_FSunProCap(SOLARPROCAP);

		//��ô��������Ҫ����Ʒ����Ҳ������
	}

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

//��������ˮ������
void CSunshine::Set_SunCoWaterNum(uint32 num)
{
	ucowaternum = num;
}

//��ȡ����ˮ������
int CSunshine::Get_SunCoWaterNum()
{
	return ucowaternum;
}

//����������������
void CSunshine::Set_SunCoSunNum(uint32 num)
{
	ucosunnum = num;
}

//��ȡ������������
int CSunshine::Get_SunCoSunNum()
{
	return ucosunnum;
}

//���ý����������
void CSunshine::Set_SunCoGoldNum(uint32 num)
{
	ucogoldnum = num;
}

//��ȡ�����������
int CSunshine::Get_SunCoGoldNum()
{
	return ucogoldnum;
}

//������ʯ��������
void CSunshine::Set_SunCoJewelNum(uint32 num)
{
	ucojewel = num;
}

//��ȡ��ʯ��������
int CSunshine::Get_SunCoJewelNum()
{
	return ucojewel;
}


