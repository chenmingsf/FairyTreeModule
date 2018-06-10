#pragma once

#ifndef _SHOP_H
#define _SHOP_H

#include "Warehouse.h"
#include "map"
#include "define.h"

#define WATERCOMMODITYID 10001 //ˮ��Դ����ƷID ������
#define EQUIPPEDWITHID   20001 //װ������ƷID ������
#define SPECIALPROPSID   30001 //�����������ƷID ������

//�̵���
class Shop
{
public:
	Shop();
	~Shop();
	//���� ��Ʒ��� ��Ʒ����
	bool ShopCloseAnAccountFun(uint32 ugoodsID, uint32 ugoodsNum);

	//����
	void ShopDiscountFun(float sdf);

	//����ˮ��Դ����Ʒ
	void ShopAddWaterCommodityFun(CWarehouseArticle* cwha);

	//����װ������Ʒ
	void ShopAddEquipFun(CWarehouseArticle* cwha);

	//���������������Ʒ
	void ShopAddSpecialFun(CWarehouseArticle* cwha);

	//���ù�����Ʒ����ܼ۸�
	void Set_ShopBuyGoodsTotalPrice(float sbgtp);
	//��ȡ������Ʒ����ܼ۸�
	float Get_ShopBuyGoodsTotalPrice();

	//��ȡ��Ʒ�� ������Ʒ
	CWarehouseArticle* Get_ArticleClass(uint32 uid);

	//map�����洢��Ʒ����Ϣ<��Ʒ��ID,��Ʒ��>
	std::map<uint32, CWarehouseArticle*> storeItemInfo;
	//�̵�����Ʒ������
	inline int WarehouSize() { return (int)storeItemInfo.size(); }

	//��Ʒ�� ������Ʒ
	CWarehouseArticle * pwareArt;
private:

	//(WATERRESOURCECLASS)ˮ��Դ����Ʒ vector��
	std::vector<CWarehouseArticle*> vecwater;

	//(EQUIPPEDWITHCLASS)װ������Ʒ vector��
	std::vector<CWarehouseArticle*> vecequ;

	//(SPECIALPROPS)�����������Ʒ vector��
	std::vector<CWarehouseArticle*> vecspe;

	//������Ʒ����ܼ۸�
	float ubuyGoodsTotalPrice;

};


#endif
