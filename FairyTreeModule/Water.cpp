#include "Water.h"



Water::Water()
{
	uordinarywater = 0; //��ͨˮ
	ufairywater = 0; //����ˮ
}


Water::~Water()
{
}

//����������ͨˮ������
void Water::Set_WAddOrdinaryWater(uint32 sow)
{
	uordinarywater += sow;
}

//���ü�����ͨˮ������
void Water::Set_ReduceOrdinaryWater(uint32 srow)
{
	uordinarywater -= srow;
}

//��ȡ��ͨˮ������
int Water::Get_WOrdinaryWater()
{
	return uordinarywater;
}

//������������ˮ������
void Water::Set_WAddFairyWater(uint32 sfw)
{
	ufairywater += sfw;
}

//���ü�������ˮ������
void Water::Set_WReduceFairyWater(uint32 sfw)
{
	ufairywater -= sfw;
}

//��ȡ����ˮ������
int Water::Get_WFairyWater()
{
	return ufairywater;
}
