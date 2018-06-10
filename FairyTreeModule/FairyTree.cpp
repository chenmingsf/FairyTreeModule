#include "FairyTree.h"



FairyTree::FairyTree()
{
	fgrade = 0;//�ȼ�

	uheightTree = 0;//���� = �ȼ�

	fgold = FGOLDNUMBER;//�����Ľ��

	fgoldtime = FMAXGOLDTIME; //������ҵ�ʱ��

	cfaiTreStoGol = 0;//�������洢���
		  
	ucowaternum = 0;//����ˮ������
	
	ucosunnum = 0;//������������
	
	ucogoldnum = 0;//�����������
	
	ucojewelnum = 0;//��ʯ��������
	
	ucoeflinnum = 0;//С������������
	
	ucobreakthnum = 0;//ͻ������

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

//��������ˮ������
void FairyTree::Set_FCoWaterNum(uint32 num)
{
	ucowaternum = num;
}

//��ȡ����ˮ������
int FairyTree::Get_FCoWaterNum()
{
	return ucowaternum;
}

//����������������
void FairyTree::Set_FCoSunNum(uint32 num)
{
	ucosunnum = num;
}

//��ȡ������������
int FairyTree::Get_FCoSunNum()
{
	return ucosunnum;
}

//���ý����������
void FairyTree::Set_FCoGoldNum(uint32 num)
{
	ucogoldnum = num;
}

//��ȡ�����������
int FairyTree::Get_FCoGoldNum()
{
	return ucogoldnum;
}

//������ʯ��������
void FairyTree::Set_FCoJewelNum(uint32 num)
{
	ucojewelnum = num;
}

//��ȡ��ʯ��������
int FairyTree::Get_FCoJewelNum()
{
	return ucojewelnum;
}

//����С������������
void FairyTree::Set_FCoeflinNum(uint32 num)
{
	ucoeflinnum = num;
}

//��ȡС������������
int FairyTree::Get_FCoeflinNum()
{
	return ucoeflinnum;
}

//����ͻ������
void FairyTree::Set_FCoBreakthNum(uint32 num)
{
	ucobreakthnum = num;
}

//��ȡͻ������
int FairyTree::Get_FCoBreakthNum()
{
	return ucobreakthnum;
}


