#include "Warehouse.h"


//��Ʒ��
CWarehouseArticle::CWarehouseArticle()
{
	m_roleID = 0;//�û�ID

	uarticleSerialNumber = 0; //��Ʒ���

	ugoldPrice = 0; //��Ʒ��Ҽ۸�

	ujewelPrice = 0; //��Ʒ��ʯ�۸�

	uarticleDiscount = 1.0f; //��Ʒ�ۿ�

	eartCat = WATERRESOURCECLASS; //ˮ��Դ��

	eartDescribe = ""; //��Ʒ����(Describe)

	warename = "";//��Ʒ��
}

CWarehouseArticle::~CWarehouseArticle()
{
}

//������Ʒ���
void CWarehouseArticle::Set_CArticleSerialNumber(uint32 casn)
{
	uarticleSerialNumber = casn;
}

//��ȡ��Ʒ���
uint32 CWarehouseArticle::Get_CArticleSerialNumber()
{
	return uarticleSerialNumber;
}

//������Ʒ��Ҽ۸�
void CWarehouseArticle::Set_CArticleGoldPrice(uint32 cgp)
{
	ugoldPrice = cgp;
}

//��ȡ��Ʒ��Ҽ۸�
uint32 CWarehouseArticle::Get_CArticleGoldPrice()
{
	return ugoldPrice;
}

//������Ʒ��ʯ�۸�
void CWarehouseArticle::Set_CArticleJewelPrice(uint32 cajp)
{
	ujewelPrice = cajp;
}

//��ȡ��Ʒ��ʯ�۸�
uint32 CWarehouseArticle::Get_CArticleJewelPrice()
{
	return ujewelPrice;
}

//������Ʒ�ۿ�
void CWarehouseArticle::Set_CArticleDiscount(float cad)
{
	uarticleDiscount = cad;
}

//��ȡ��Ʒ�ۿ�
float CWarehouseArticle::Get_CArticleDiscount()
{
	return uarticleDiscount;
}

//������Ʒ����(Describe)
void CWarehouseArticle::Set_CArticleDescribe(const std::string& scad)
{
	eartDescribe = scad;
}

//��ȡ��Ʒ����(Describe)
std::string CWarehouseArticle::Get_CArticleDescribe()
{
	return eartDescribe;
}

//������Ʒ����
void CWarehouseArticle::Set_eArticleType(const EArticleCategory& ear)
{
	eartCat = ear;
}

//�����Ʒ����
EArticleCategory CWarehouseArticle::Get_eArticleType()
{
	return eartCat;
}

//������Ʒ����
void CWarehouseArticle::Set_WareName(const std::string& swn)
{
	warename = swn;
}

//��ȡ��Ʒ����
std::string CWarehouseArticle::Get_WareName()
{
	return warename;
}

//�����û�ID
void CWarehouseArticle::Set_RoleID(uint32 uid)
{
	m_roleID = uid;//�û�ID
}

//��ȡ�û�ID
uint32 CWarehouseArticle::Get_RoleID()
{
	return m_roleID;
}





//�ֿ���
Warehouse::Warehouse()
{
	m_roleID = 0;//�û�ID

	uWatercount = 0; //��¼��Ʒˮ��Դ������

	uEquipcount = 0; //��¼��Ʒװ��������

	uSepProcount = 0; //��¼��Ʒ������ߵ�����

	wareArt = new CWarehouseArticle;
}


Warehouse::~Warehouse()
{
	delete wareArt;
}

//������Ʒ
void Warehouse::AddArticle(uint32 uid)
{
	//ˮ��Դ��id
	uint32 uwater = 10001;
	//װ����id
	uint32 uequip = 10002;
	//������ߵ�id
	uint32 useppro = 10003;
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == uwater)
	{
		map_warehouse[uid] = wareArt;
		uWatercount += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == uequip)
	{
		map_warehouse[uid] = wareArt;
		uEquipcount += 1;
	}
	if (map_warehouse[uid]->Get_CArticleSerialNumber() == useppro)
	{
		map_warehouse[uid] = wareArt;
		uSepProcount += 1;
	}
	
	
}

//ɾ����Ʒ ͨ����Ʒ���
void Warehouse::CloseArticle(uint32 cloart)
{
	//ͨ����Ʒ��� ���ұ�����Ķ�Ӧ����
	for (std::map<uint32, CWarehouseArticle*>::iterator it = map_warehouse.begin(); it != map_warehouse.end(); it++)
	{
		if (cloart == it->second->Get_CArticleSerialNumber())
		{
			map_warehouse.erase(it);
		}
	}

}

//��ȡ��Ʒˮ��Դ������
uint32 Warehouse::Get_ArticleToWaterCount()
{
	return uWatercount;
}

//��ȡ��Ʒװ��������
uint32 Warehouse::Get_ArticleToEquipCount()
{
	return uEquipcount;
}

//��ȡ��Ʒ������ߵ�����
uint32 Warehouse::Get_ArticleToSepProCount()
{
	return uSepProcount;
}

//�����û�ID
void Warehouse::Set_RoleID(uint32 uid)
{
}

//��ȡ�û�ID
uint32 Warehouse::Get_RoleID()
{
	return m_roleID;
}


