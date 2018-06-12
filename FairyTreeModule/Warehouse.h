#pragma once

#ifndef _WAREHOUSE_H
#define _WAREHOUSE_H

#include "Gamedefine.h"
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
	uint32 Get_CArticleSerialNumber();

	//������Ʒ��Ҽ۸�
	void Set_CArticleGoldPrice(uint32 cgp);
	//��ȡ��Ʒ��Ҽ۸�
	uint32 Get_CArticleGoldPrice();

	//������Ʒ��ʯ�۸�
	void Set_CArticleJewelPrice(uint32 cajp);
	//��ȡ��Ʒ��ʯ�۸�
	uint32 Get_CArticleJewelPrice();

	//������Ʒ�ۿ�
	void Set_CArticleDiscount(float cad);
	//��ȡ��Ʒ�ۿ�
	float Get_CArticleDiscount();

	//������Ʒ����(Describe)
	void Set_CArticleDescribe(const std::string& scad);
	//��ȡ��Ʒ����(Describe)
	std::string Get_CArticleDescribe();

	//������Ʒ����
	void Set_eArticleType(const EArticleCategory& ear);
	//�����Ʒ����
	EArticleCategory Get_eArticleType();

	//ʹ����Ʒ ͨ����Ʒ��� ��ȷ��ʹ�õ���Ʒ���
	//void ArticleSerialNumberCategory();

	//������Ʒ����
	void Set_WareName(const std::string& swn);
	//��ȡ��Ʒ����
	std::string Get_WareName();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();


private:

	//�û�ID
	uint32 m_roleID;

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
	void AddArticle(uint32 uid);
	//ɾ����Ʒ
	void CloseArticle(uint32 uid);

	
	//��ȡ��Ʒˮ��Դ������
	uint32 Get_ArticleToWaterCount();
	//��ȡ��Ʒװ��������
	uint32 Get_ArticleToEquipCount();
	//��ȡ��Ʒ������ߵ�����
	uint32 Get_ArticleToSepProCount();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//��Ʒ���map
	std::map<uint32, CWarehouseArticle*> map_warehouse;
private:

	//�û�ID
	uint32 m_roleID;

	CWarehouseArticle * wareArt;

	//��¼��Ʒˮ��Դ������
	uint32 uWatercount;
	//��¼��Ʒװ��������
	uint32 uEquipcount;
	//��¼��Ʒ������ߵ�����
	uint32 uSepProcount;
};

#endif
