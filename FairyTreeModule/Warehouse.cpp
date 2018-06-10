#include "Warehouse.h"


//��Ʒ��
CWarehouseArticle::CWarehouseArticle()
{
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
int CWarehouseArticle::Get_CArticleSerialNumber()
{
	return uarticleSerialNumber;
}

//������Ʒ��Ҽ۸�
void CWarehouseArticle::Set_CArticleGoldPrice(uint32 cgp)
{
	ugoldPrice = cgp;
}

//��ȡ��Ʒ��Ҽ۸�
int CWarehouseArticle::Get_CArticleGoldPrice()
{
	return ugoldPrice;
}

//������Ʒ��ʯ�۸�
void CWarehouseArticle::Set_CArticleJewelPrice(uint32 cajp)
{
	ujewelPrice = cajp;
}

//��ȡ��Ʒ��ʯ�۸�
int CWarehouseArticle::Get_CArticleJewelPrice()
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
void CWarehouseArticle::Set_CArticleDescribe(std::string & scad)
{
	eartDescribe = scad;
}

//��ȡ��Ʒ����(Describe)
string CWarehouseArticle::Get_CArticleDescribe()
{
	return eartDescribe;
}

//������Ʒ����
void CWarehouseArticle::Set_eArticleType(EArticleCategory ear)
{
	eartCat = ear;
}

//�����Ʒ����
EArticleCategory CWarehouseArticle::Get_eArticleType()
{
	return eartCat;
}

//������Ʒ����
void CWarehouseArticle::Set_WareName(std::string & swn)
{
	warename = swn;
}

//��ȡ��Ʒ����
string CWarehouseArticle::Get_WareName()
{
	return warename;
}





//�ֿ���
Warehouse::Warehouse()
{
}


Warehouse::~Warehouse()
{
}

//������Ʒ
void Warehouse::AddArticle(CWarehouseArticle* addart)
{
	vec.push_back(addart);
}

//ɾ����Ʒ ͨ����Ʒ���
void Warehouse::CloseArticle(uint32 cloart)
{
	
	//ͨ����Ʒ��� ���ұ�����Ķ�Ӧ����
	for (std::vector<CWarehouseArticle*>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (cloart == (*it)->Get_CArticleSerialNumber())
		{
			//�ҵ� ɾ��
			vec.erase(it);
		}
	}

}
