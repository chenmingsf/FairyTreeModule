#include "Gold.h"



Gold::Gold()
{
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
int Gold::Get_GGoldNumber()
{
	return ugoldnumber;
}
