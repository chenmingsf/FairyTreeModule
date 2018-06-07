#include "FairyTree.h"



FairyTree::FairyTree()
{
	fgrade = 0;//�ȼ�

	uheightTree = 0;//���� = �ȼ�

	fgold = FGOLDNUMBER;//�����Ľ��

	fgoldtime = FMAXGOLDTIME; //������ҵ�ʱ��

	cfaiTreStoGol = 0;//�������洢���

}


FairyTree::~FairyTree()
{
}

//���õȼ� 
void FairyTree::Set_FGrade(bool fgr)
{
	
	if (fgr)
	{
		//�ȼ�����һ��
		fgrade += 1;

		//������ҵ�����������
		Set_FGold(FGOLDNUMBER);
		//��������
		Set_TreeHeight(fgrade);
	}
	
}

//��ȡ�ȼ�
int FairyTree::Get_FGrade()
{
	return fgrade;
}

//��������
void FairyTree::Set_TreeHeight(uint32 sth)
{
	uheightTree = sth;
}

//��ȡ����
int FairyTree::Get_TreeHeight()
{
	return uheightTree;
}

//���������Ľ�� 
void FairyTree::Set_FGold(uint32 fgo)
{
	//���ĵȼ�ÿ����һ�� ������ҵ����������� �̶�ֵ
	fgold = fgo;
}

//��ȡ�����Ľ��
int FairyTree::Get_FGold()
{
	//ÿ���һ�ν�� �ͽ���Ҵ�Ž� ����
	Set_FAddFaiTreStoGol(fgold);

	return fgold;
}

//����������ҵ�ʱ��
void FairyTree::Set_FGoldTime(uint32 ufgt)
{
	//���ĵȼ�ÿ����һ�� ������ҵ�ʱ�� �Ƿ���Ҫ���� �̶�ʱ��
	fgoldtime += ufgt;
}

//��ȡ������ҵ�ʱ��
int FairyTree::Get_FGoldTime()
{
	return fgoldtime;
}

//�������洢���
void FairyTree::Set_FAddFaiTreStoGol(uint32 ufftsg)
{
	//���Ĵ洢����Ƿ���Ҫ����
	//���ĵȼ�ÿ����һ�� �Ƿ���Ҫ�� ���Ĵ洢������� �̶�ֵ
	cfaiTreStoGol += ufftsg;
}

//���ü������洢���
void FairyTree::Set_FMinusFaiTreStoGol(uint32 ufmftsg)
{
	//�����ý�ҹ�����Ʒ��ʱ�� �洢�Ľ�Ҿ� ����(����Ʒ�ļ۸�,������)
	cfaiTreStoGol -= ufmftsg;
}

//��ȡ���洢���
int FairyTree::Get_FFaiTreStoGol()
{
	//�õ��ܴ洢�Ľ������
	return cfaiTreStoGol;
}


