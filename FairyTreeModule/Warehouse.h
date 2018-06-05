#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "define.h"
#include <vector>


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

	//ʹ����Ʒ ͨ����Ʒ��� ��ȷ��ʹ�õ���Ʒ���
	virtual void ArticleSerialNumberCategory() = 0;

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
};


//�ֿ���(Ԥ��)
class Warehouse
{
public:
	Warehouse();
	~Warehouse();

	//������Ʒ
	void AddArticle(CWarehouseArticle* addart);
	//ɾ����Ʒ
	void CloseArticle(uint32 cloart);
private:
	//��Ʒ(Ԥ��)
	std::vector<CWarehouseArticle*> vec;
};

#endif
