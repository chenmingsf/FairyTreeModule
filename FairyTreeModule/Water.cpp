#include "Water.h"



Water::Water()
{
	m_roleID = 0;//�û�ID
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
uint32 Water::Get_WOrdinaryWater()
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
uint32 Water::Get_WFairyWater()
{
	return ufairywater;
}

//�����û�ID
void Water::Set_RoleID(uint32 uid)
{
	m_roleID = uid;//�û�ID
}

//��ȡ�û�ID
uint32 Water::Get_RoleID()
{
	return m_roleID;
}
