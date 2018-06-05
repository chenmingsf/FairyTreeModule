#include "Elfin.h"



Elfin::Elfin()
{

	_egrade = 0;//�ȼ�

	_ephysicalpower = SEGMAXPHYSICALPOWER;//���� ��ʼ������Ϊ���

	_emaxphysicalpower = SEGMAXPHYSICALPOWER;//�������

	estype = EGOLD;//ö�����͵ļ�������
}


Elfin::~Elfin()
{
}

//������Ӽ��ܸ�
void Elfin::Set_ESkillStyle(CSkill* ecsk)
{
	vec.push_back(ecsk);
}

//����ɾ������
void Elfin::Set_EReduceSkillStyle(uint32 iderss)
{

	//ͨ���±� ���Ҷ�Ӧ������
	for (std::vector<CSkill*>::iterator itskill = vec.begin(); itskill != vec.end(); itskill++)
	{
		if (iderss == (*itskill)->Get_Skill_ID())
		{
			//�ҵ� ɾ��
			vec.erase(itskill);
		}
	}

}

//��ȡ���ܸ�
int Elfin::Get_ESkillStyle()
{
	//�������һ������
	srand((uint32)time(0));
	rand();
	uint32 ucount = rand() % 5 + 0;
	switch (ucount)
	{
	case 0: {estype = EGOLD; break; }
	case 1: {estype = EWOOD; break;}
	case 2: {estype = EWATER; break; }
	case 3: {estype = EFIRE; break; }
	case 4: {estype = ESOIL; break; }
	}

	//���ؼ���
	return estype;
}

//���õȼ�
void Elfin::Set_EGrade(bool beg)
{
	//���С����ľ���ֵ�ﵽ��� 
	//�ȼ��� 1
	if (beg)
	{
		_egrade += 1;

		//ÿ����һ��������� ����ָ��ֵ
		Set_EMaxPhysicalPower(SEGMAXPHYSICALPOWER);

		beg = false;
	}
}

//��ȡ�ȼ�
int Elfin::Get_EGrade()
{
	return _egrade;
}

//������������
void Elfin::Set_EAddPhysicalPower(uint32 ueap)
{
	_ephysicalpower += ueap;
}

//���ü�������
void Elfin::Set_EReducePhysicalPower(uint32 uerp)
{
	_ephysicalpower -= uerp;
}

//��ȡ����
int Elfin::Get_EPhysicalPower()
{
	return _ephysicalpower;
}

//�����������
void Elfin::Set_EMaxPhysicalPower(uint32 uempp)
{
	_emaxphysicalpower += uempp;
}

//��ȡ�������
int Elfin::Get_EMaxPhysicalPower()
{
	return _emaxphysicalpower;
}
