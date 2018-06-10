#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "define.h"
#include <vector>
#include <map>


//��Ʒ���
enum EArticleCategory
{
	WATERRESOURCECLASS, //ˮ��Դ��
	EQUIPPEDWITHCLASS, //װ����
	SPECIALPROPS //���������
};

//��Ʒ��
class CWarehouseArticle
{
public:
	CWarehouseArticle();
	~CWarehouseArticle();

	//������Ʒ���
	void Set_CArticleSerialNumber(uint32 casn);
	//��ȡ��Ʒ���
	int Get_CArticleSerialNumber();

	//������Ʒ��Ҽ۸�
	void Set_CArticleGoldPrice(uint32 cgp);
	//��ȡ��Ʒ��Ҽ۸�
	int Get_CArticleGoldPrice();

	//������Ʒ��ʯ�۸�
	void Set_CArticleJewelPrice(uint32 cajp);
	//��ȡ��Ʒ��ʯ�۸�
	int Get_CArticleJewelPrice();

	//������Ʒ�ۿ�
	void Set_CArticleDiscount(float cad);
	//��ȡ��Ʒ�ۿ�
	float Get_CArticleDiscount();

	//������Ʒ����(Describe)
	void Set_CArticleDescribe(std::string& scad);
	//��ȡ��Ʒ����(Describe)
	string Get_CArticleDescribe();

	//������Ʒ����
	void Set_eArticleType(EArticleCategory ear);
	//�����Ʒ����
	EArticleCategory Get_eArticleType();

	//ʹ����Ʒ ͨ����Ʒ��� ��ȷ��ʹ�õ���Ʒ���
	//virtual void ArticleSerialNumberCategory() = 0;

	//������Ʒ����
	void Set_WareName(std::string& swn);
	//��ȡ��Ʒ����
	string Get_WareName();


private:
	//��Ʒ���
	uint32 uarticleSerialNumber;

	//��Ʒ��Ҽ۸�
	uint32 ugoldPrice;

	//��Ʒ��ʯ�۸�
	uint32 ujewelPrice;

	//��Ʒ�ۿ�
	float uarticleDiscount;

	//��Ʒ���(ˮ��Դ��,װ����,���������)
	EArticleCategory eartCat;

	//��Ʒ����(Describe)
	std::string eartDescribe;

	//��Ʒ��
	std::string warename;
};


//�ֿ���
class Warehouse
{
public:
	Warehouse();
	~Warehouse();

	//������Ʒ
	void AddArticle(CWarehouseArticle* addart);
	//ɾ����Ʒ
	void CloseArticle(uint32 cloart);

	//��Ʒ���map
	std::map<uint32, CWarehouseArticle*> map_warehouse;
private:
	//��Ʒ(Ԥ��)
	std::vector<CWarehouseArticle*> vec;
};

#endif
