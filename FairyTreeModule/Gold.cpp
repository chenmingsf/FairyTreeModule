#include "Gold.h"



Gold::Gold()
{
	m_roleID = 0;//�û�ID

	ugoldnumber = 0; //��ҵ�����
}


Gold::~Gold()
{
}

//�������ӽ�ҵ�����
void Gold::Set_GAddGoldNumber(uint32 ggn)
{
	ugoldnumber += ggn;
}

//���ü��ٽ�ҵ�����
void Gold::Set_GReduceGoldNumber(uint32 grgn)
{
	ugoldnumber -= grgn;
}

//��ȡ��ҵ�����
uint32 Gold::Get_GGoldNumber()
{
	return ugoldnumber;
}

//�����û�ID
void Gold::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//��ȡ�û�ID
int Gold::Get_RoleID()
{
	return m_roleID;
}
