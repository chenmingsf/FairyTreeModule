#include "FairyTreeUserClasses.h"



FairyTreeUserClasses::FairyTreeUserClasses()
{
	udiamond = 0; //��ʯ
}


FairyTreeUserClasses::~FairyTreeUserClasses()
{
}

//��ȡС����
Elfin* FairyTreeUserClasses::Get_Elfin(uint32 id)
{ 
	for (std::list<Elfin*>::iterator it = slistElfin.begin(); it != slistElfin.end(); it++)
	{
		if (id == (*it)->Get_ID())
		{
			return *it;
		}
	}
	return nullptr;
}

//��ȡ������
FairyTree FairyTreeUserClasses::Get_FairyTree()
{
	return fairytree;
}

//��ȡ̫��
CSunshine FairyTreeUserClasses::Get_SunShine()
{
	return sunshine;
}

//��ȡ�����
TreeEnchantment FairyTreeUserClasses::Get_TreeEnchantment()
{
	return treeenchantment;
}

//��ȡ�ֿ�
Warehouse FairyTreeUserClasses::Get_Warehouse()
{
	return warehouse;
}

//��ȡ�̵�
Shop FairyTreeUserClasses::Get_Shop()
{
	return shop;
}

//��ȡ����
CMailbox FairyTreeUserClasses::Get_CMailbox()
{
	return mailbox;
}

//��ȡ�����б�
CTaskListClass FairyTreeUserClasses::Get_CTaskListClass()
{
	return tasklist;
}

//��ȡ��ϵ
Relation FairyTreeUserClasses::Get_Relation()
{
	return relation;
}

//��ȡ���а�
RankingList FairyTreeUserClasses::Get_RankingList()
{
	return rankinglist;
}

//��ȡ����
CSkill FairyTreeUserClasses::Get_CSkill()
{
	return skill;
}

//��ȡ��Դˮ
Water FairyTreeUserClasses::Get_Water()
{
	return water;
}

//��ȡ��Դ���
Gold FairyTreeUserClasses::Get_Gold()
{
	return gold;
}

//����������ʯ
void FairyTreeUserClasses::Set_UserAddDiamond(uint32 sd)
{
	udiamond += sd;
}

//���ü�����ʯ
void FairyTreeUserClasses::Set_UserRedDiamond(uint32 surd)
{
	udiamond -= surd;
}

//��ȡ��ʯ
int FairyTreeUserClasses::Get_UserDiamond()
{
	return udiamond;
}





//����Xml�ļ�
//bool bPaintXml(const char* pfilepath)
//{
//	//const char* filepath = ".Test.Xml";
//	//����һ���ļ��ڵ�TiXmlDocumentָ��, ���صĽ�������XML�ĵ�,�����ĵ�����
//	TiXmlDocument* tixml = new TiXmlDocument(pfilepath);
//	if (NULL == tixml)
//	{
//		return false;
//	}
//	// �����ļ� �ļ���,���ǽ��ļ���Ϣ���뵽�ĵ�������
//	tixml->LoadFile();
//
//	//ElementԪ����һ��������
//	//�����ĵ������ҵ���Ԫ�ػ���ڵ�,����ָ��ڵ��ָ��
//	TiXmlElement* proot = tixml->RootElement();
//
//	////�ӵ�һ������Ϊ("Table")�Ľڵ�ѭ�� ��������һ���ڵ� 
//	////NextSibling("Table")��һ����Ϊ"Table"���ӽڵ�
//	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
//	{
//		TiXmlNode* pchild = pnode->FirstChild();
//		const char* pgrade = pchild->ToElement()->GetText(); //�������ڵ��ֵ(�ȼ�)
//
//		if (pgrade)
//		{
//			OUR_DEBUG((LM_INFO, "pgrade = %s\n", pgrade));
//		}
//		else
//		{
//			OUR_DEBUG((LM_INFO, "error pgrade = %s\n"));
//		}
//
//		pchild = pnode->IterateChildren(pchild);//IterateChildren()������һ���ӽڵ�
//		const char* ptiLi = pchild->ToElement()->GetText(); //�������ڵ��ֵ(��ǰ�ȼ��µ��������)
//
//		if (ptiLi)
//		{
//			OUR_DEBUG((LM_INFO, "ptiLi = %s\n", ptiLi));
//		}
//		else
//		{
//			OUR_DEBUG((LM_INFO, "error ptiLi = %s\n"));
//		}
//	}
//	return true;
//}
