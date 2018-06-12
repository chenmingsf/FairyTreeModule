#pragma once

#ifndef _SHOP_H
#define _SHOP_H

#include "Warehouse.h"
#include "map"
#include "Gamedefine.h"

#define WATERCOMMODITYID 1001 //ˮ��Դ����ƷID ������
#define EQUIPPEDWITHID   2001 //װ������ƷID ������
#define SPECIALPROPSID   3001 //�����������ƷID ������

//�̵���
class Shop
{
public:
	Shop();
	~Shop();
	//����(�����) ��Ʒ��� ��Ʒ����
	bool ShopCloseAnGoldFun(uint32 ugoodsID, uint32 ugoodsNum);

	//����(����ʯ) ��Ʒ��� ��Ʒ����
	bool ShopCloseAnJewelFun(uint32 ugoodsID, uint32 ugoodsNum);

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
	uint32 WarehouSize() { return (uint32)storeItemInfo.size(); }

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//��Ʒ�� ������Ʒ
	CWarehouseArticle * pwareArt;
private:

	//�û�ID
	uint32 m_roleID;

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
