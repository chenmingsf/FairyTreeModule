#include "TreeEnchantment.h"



TreeEnchantment::TreeEnchantment()
{
	ugrade = 0;//�ȼ�

	udefense = 0; //������

	bopenguard = false; //�򿪱�����

	bcloseguard = false; //�رձ�����

	bopenpitfall = false; //������(Ԥ��)

	bclosepitfall = false;//�ر�����(Ԥ��) 

}


TreeEnchantment::~TreeEnchantment()
{
}

//���õȼ�
void TreeEnchantment::Set_TEGrade(uint32 sg)
{
	ugrade = sg;
}

//��ȡ�ȼ�
int TreeEnchantment::Get_TEGrade()
{
	return ugrade;
}

//���ý�����
void TreeEnchantment::Set_TEDefense(uint32 sted)
{
	udefense = sted;
}

//��ȡ������
int TreeEnchantment::Get_TEDefense()
{
	return udefense;
}

//�򿪱����� Ҫ�򿪱����ֵ����� ��true
bool TreeEnchantment::OpenGuard(bool bog)
{
	//����򿪱�����Ϊ�� ��ô�رձ����־�Ϊ��
	bopenguard = bog;
	if (bopenguard)
		CloseGuard(false);
	
	return bopenguard;
}

//�رձ����� Ҫ�رձ����ֵ����� ��true
bool TreeEnchantment::CloseGuard(bool bcg)
{
	//����رձ�����Ϊ�� ��ô�򿪱����־�Ϊ��
	bcloseguard = bcg;
	if (bcloseguard)
		OpenGuard(false);
	return bcloseguard;
}

//������ Ҫ����������� ��true
bool TreeEnchantment::OpenPitfall(bool bop)
{
	//���������Ϊ�� ��ô�ر������Ϊ��
	bopenpitfall = bop;
	if (bopenpitfall)
		ClosePitfall(false);
	return bopenpitfall;
}

//�ر����� Ҫ�ر���������� ��true
bool TreeEnchantment::ClosePitfall(bool bcp)
{
	//����ر�����Ϊ�� ��ô�������Ϊ��
	bclosepitfall = bcp;
	if (bclosepitfall)
		OpenPitfall(false);
	return bclosepitfall;
}


