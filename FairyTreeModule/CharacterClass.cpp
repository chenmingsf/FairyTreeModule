#include "CharacterClass.h"



CharacterClass::CharacterClass()
{
	uroleID = 0; //��ɫID

	sroleName = ""; //��ɫ����

	urolegrowthvalue = 0; //��ɫ�ɳ�ֵ
}


CharacterClass::~CharacterClass()
{
}

//���ý�ɫID
void CharacterClass::Set_Role_ID(uint32 srid)
{
	uroleID = srid;
}

//��ȡ��ɫID
int CharacterClass::Get_Role_ID()
{
	return uroleID;
}

//���ý�ɫ����
void CharacterClass::Set_Role_Name(std::string srname)
{
	sroleName = srname;
}

//��ȡ��ɫ����
string CharacterClass::Get_Role_Name()
{
	return sroleName;
}

//���ý�ɫ�ɳ�ֵ
void CharacterClass::Set_RoleGrowthValue(uint32 srgv)
{
	urolegrowthvalue += srgv;
}

//��ȡ��ɫ�ɳ�ֵ
int CharacterClass::Get_RoleGrowthValue()
{
	return urolegrowthvalue;
}
