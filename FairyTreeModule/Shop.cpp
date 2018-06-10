#include "Shop.h"



Shop::Shop()
{
	pwareArt = new CWarehouseArticle;
	ubuyGoodsTotalPrice = 0;//������Ʒ����ܼ۸�
}


Shop::~Shop()
{
}

//���� ��Ʒ��� ��Ʒ����
bool Shop::ShopCloseAnAccountFun(uint32 ugoodsID, uint32 ugoodsNum)
{
	//10001 < ˮ��Դ����Ʒ��ID��Χ < 20001
	if (WATERCOMMODITYID < ugoodsID && ugoodsID < EQUIPPEDWITHID)
	{
		//ͨ����Ʒ��Ų����Ƿ���ˮ��Դ���
		for (std::vector<CWarehouseArticle*>::iterator itwater = vecwater.begin(); itwater != vecwater.end(); itwater++)
		{
			if (ugoodsID == (*itwater)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										//������Ʒ������ * ���(ע:������ʯ) * �ۿ� = �������ܼ۸�
				utotalprice = ugoodsNum * (*itwater)->Get_CArticleGoldPrice() * (*itwater)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//20001 < װ������Ʒ��ID��Χ < 30001
	if (EQUIPPEDWITHID < ugoodsID && ugoodsID < SPECIALPROPSID)
	{
		//ͨ����Ʒ��Ų����Ƿ���װ�����
		for (std::vector<CWarehouseArticle*>::iterator itequ = vecequ.begin(); itequ != vecequ.end(); itequ++)
		{
			if (ugoodsID == (*itequ)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										//������Ʒ������ * ���(ע:������ʯ) * �ۿ� = �������ܼ۸�
				utotalprice = ugoodsNum * (*itequ)->Get_CArticleGoldPrice() * (*itequ)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	//30001 < �����������Ʒ��ID��Χ
	if (ugoodsID > SPECIALPROPSID)
	{
		//ͨ����Ʒ��Ų����Ƿ�������������
		for (std::vector<CWarehouseArticle*>::iterator itspe = vecspe.begin(); itspe != vecspe.end(); itspe++)
		{
			if (ugoodsID == (*itspe)->Get_CArticleSerialNumber())
			{
				//�ҵ�
				float utotalprice = 0.0f; //��ʱ���ܼ۸�
										//������Ʒ������ * ���(ע:������ʯ) * �ۿ� = �������ܼ۸�
				utotalprice = ugoodsNum * (*itspe)->Get_CArticleGoldPrice() * (*itspe)->Get_CArticleDiscount();
				Set_ShopBuyGoodsTotalPrice(utotalprice);
				return true;
			}
		}
	}

	return false;
}

//���� 
void Shop::ShopDiscountFun(float sdf)
{
	//�̵������Ʒ��(pwareArt)�����ۿ�
	pwareArt->Set_CArticleDiscount(sdf);
}


//����ˮ��Դ����Ʒ
void Shop::ShopAddWaterCommodityFun(CWarehouseArticle * cwha)
{
	vecwater.push_back(cwha);
}

//����װ������Ʒ
void Shop::ShopAddEquipFun(CWarehouseArticle * cwha)
{
	vecequ.push_back(cwha);
}

//���������������Ʒ
void Shop::ShopAddSpecialFun(CWarehouseArticle * cwha)
{
	vecspe.push_back(cwha);
}

//���ù�����Ʒ����ܼ۸�
void Shop::Set_ShopBuyGoodsTotalPrice(float sbgtp)
{
	ubuyGoodsTotalPrice = sbgtp;
}

//��ȡ������Ʒ����ܼ۸�
float Shop::Get_ShopBuyGoodsTotalPrice()
{
	return ubuyGoodsTotalPrice;
}

//��ȡ��Ʒ��  ������Ʒ
CWarehouseArticle * Shop::Get_ArticleClass(uint32 uid)
{
	return storeItemInfo[uid];
}


