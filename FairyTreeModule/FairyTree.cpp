#include "FairyTree.h"



FairyTree::FairyTree()
{
	fgrade = 0;//�ȼ�

	uheightTree = 0;//���� = �ȼ�

	fgold = FGOLDNUMBER;//�����Ľ��

	fgoldtime = FMAXGOLDTIME; //������ҵ�ʱ��

	cfaiTreStoGol = 0;//�������洢���

	uCoWaterNum = 0; //����ˮ������

	uCoSunNum = 0; //�������������

	uCoGoldNum = 0; //���Ľ�ҵ�����

	uCoElfinPP = 0; //����С��������������

}


FairyTree::~FairyTree()
{
}

//���õȼ� 
void FairyTree::Set_FGrade(uint32 fgr)
{
	
	
		//�ȼ�����һ��
		fgrade += fgr;

		//������ҵ�ʱ������
		//Set_FGoldTime(FMAXGOLDTIME);

		//������ҵ�����������
		Set_FGold(FGOLDNUMBER);
	
}

//��ȡ�ȼ�
int FairyTree::Get_FGrade()
{
	return fgrade;
}

//��������
void FairyTree::Set_TreeHeight(uint32 sth)
{
	uheightTree += sth;
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
void FairyTree::Set_ConsumptionWater(uint32 scw)
{
	uCoWaterNum = scw;
}

//��ȡ����ˮ������
int FairyTree::Get_ConsumptionWater()
{
	return uCoWaterNum;
}

//�����������������
void FairyTree::Set_ConsumptionSunshine(uint32 scs)
{
	uCoSunNum = scs;
}

//��ȡ�������������
int FairyTree::Get_ConsumptionSunshine()
{
	return uCoSunNum;
}

//�������Ľ�ҵ�����
void FairyTree::Set_ConsumptionGold(uint32 scg)
{
	uCoGoldNum = scg;
}

//��ȡ���Ľ�ҵ�����
int FairyTree::Get_ConsumptionGold()
{
	return uCoGoldNum;
}

//��������С��������������
void FairyTree::Set_ConsumptionElfinPP(uint32 scepp)
{
	uCoElfinPP = scepp;
}

//��ȡ����С��������������
int FairyTree::Get_ConsumptionElfinPP()
{
	return uCoElfinPP;
}






