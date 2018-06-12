#include "Elfin.h"
#include <stdlib.h>
#include <time.h>

std::map<uint32, Elfin*> Elfin::map_elfin;

Elfin::Elfin()
{
	m_roleID = 0;//�û�ID

	uEid = 0;//С�����ID

	_egrade = 0;//�ȼ�

	_ephysicalpower = SEGMAXPHYSICALPOWER;//���� ��ʼ������Ϊ���

	_emaxphysicalpower = SEGMAXPHYSICALPOWER;//�������

	estype = ElfinType::EGOLD;//ö�����͵ļ�������

	ucowaternum = 0;//����ˮ������
	
	ucosunnum = 0;//������������
	
	ucogoldnum = 0;//�����������
	
	ujewelnum = 0;//��ʯ��������

	cskill = new CSkill;
}


Elfin::~Elfin()
{
	delete cskill;
}

//������Ӽ��ܸ�
void Elfin::Set_ESkillStyle(CSkill* ecsk)
{
	vec.push_back(ecsk);
}

//����ɾ������ (Ҳ������������)
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
ElfinType Elfin::Get_ESkillStyle()
{
	//�������һ������
	srand(time(NULL));
	ElfinType etype = (ElfinType)(rand() % 5);

	//���ؼ���
	return etype;
}

//���õȼ�
void Elfin::Set_EGrade(uint32 beg)
{
	
	_egrade += beg;

	//ÿ����һ�� �������ֵ������ָ��ֵ
	Set_EMaxPhysicalPower(SEGMAXPHYSICALPOWER);

	
}

//��ȡ�ȼ�
uint32 Elfin::Get_EGrade()
{
	return _egrade;
}

//������������
void Elfin::Set_EAddPhysicalPower(uint32 ueap)
{
	//�����ǰ����ֵС���������ֵ
	if (_ephysicalpower < _emaxphysicalpower)
	{
		_ephysicalpower += ueap;
		//�����ǰ����ֵ�����������ֵ ��ô��ǰ����ֵ�͵����������ֵ
		if (_ephysicalpower > _emaxphysicalpower)
		{
			_ephysicalpower = _emaxphysicalpower;
		}
	}
		
}

//���ü�������
void Elfin::Set_EReducePhysicalPower(uint32 uerp)
{
	_ephysicalpower -= uerp;
	//�����ǰ���� С�� 0 ��ô��ǰ����ֵ�͵���0
	if (_ephysicalpower < 0)
	{
		_ephysicalpower = 0;
	}
}

//��ȡ��ǰ����
uint32 Elfin::Get_EPhysicalPower()
{
	return _ephysicalpower;
}

//�����������
void Elfin::Set_EMaxPhysicalPower(uint32 uempp)
{
	//С����ÿ��һ��,��������ͻ���Ӧ����
	_emaxphysicalpower += uempp;
}

//��ȡ�������
uint32 Elfin::Get_EMaxPhysicalPower()
{
	return _emaxphysicalpower;
}

//����С�����ID
void Elfin::Set_EToID(uint32 etoid)
{
	uEid = etoid;
}

//��ȡС�����ID
uint32 Elfin::Get_ID()
{
	return uEid;
}

//��������ˮ������
void Elfin::Set_uCoWaterNum(uint32 num)
{
	ucowaternum = num;
}

//��ȡ����ˮ������
uint32 Elfin::Get_uCoWaterNum()
{
	return ucowaternum;
}

//����������������
void Elfin::Set_uCoSunNum(uint32 num)
{
	ucosunnum = num;
}

//��ȡ������������
uint32 Elfin::Get_uCoSunNum()
{
	return ucosunnum;
}

//���ý����������
void Elfin::Set_uCoGoldNum(uint32 num)
{
	ucogoldnum = num;
}

//��ȡ�����������
uint32 Elfin::Get_uCoGoldNum()
{
	return ucogoldnum;
}

//������ʯ��������
void Elfin::Set_uCoJewelNum(uint32 num)
{
	ujewelnum = num;
}

//��ȡ��ʯ��������
uint32 Elfin::Get_uCoJewelNum()
{
	return ujewelnum;
}

//�����û�ID
void Elfin::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//��ȡ�û�ID
uint32 Elfin::Get_RoleID()
{
	return 0;
}

