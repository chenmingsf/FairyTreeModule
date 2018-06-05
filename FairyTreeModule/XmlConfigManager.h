#pragma once

#include "define.h"
#include <map>
#include "./TinyXML/tinyxml.h"
#include "./TinyXML/tinyxml.h"

//��Ʒ
struct ArticleInfo
{
	uint32 articleID; //��Ʒ
	std::string articlename; //��Ʒ��
	std::string articledescribe; //��Ʒ����
	uint32 goldprice; //��Ҽ۸�
	uint32 diamondprice; //��ʯ�۸�
	uint32 discountrate; //�ۿ���
	std::string type; //����
};

//С����
struct ElfinInfo
{
	uint32 grade; //�ȼ�
	uint32 physicalilmit; //��������
	uint32 cowaternumber; //����ˮ������
	uint32 cosunnum; //������������
	uint32 cogoldnum; //�����������
	uint32 codiamondnum; //��ʯ��������
};

//����
struct SkillInfo
{
	uint32 Level; //�ȼ�
	uint32 plunder; //�Ӷ�Ч��
	uint32 watering; //��ˮЧ��
	uint32 storage; //������
	uint32 cultivation; //����Ч��
	uint32 elude; //�������
	uint32 plunderAddition; //���ټӳ�
};

//����
struct SunshineInfo
{
	uint32 grade; //�ȼ�
	uint32 cowaternumber; //����ˮ������
	uint32 cosunnum; //������������
	uint32 cogoldnum; //�����������
	uint32 producompet; //��������
	uint32 produtime; //����ʱ��
};

//����
struct TaskInfo
{
	uint32 taskId; //���
	std::string headline; //����
	std::string content; //����
	uint32 totalcomptimes; //����ɴ���
	uint32 bonusitemnumOne; //������Ʒ���1
	uint32 numberOne; //����1
	uint32 bonusitemnumTwo; //������Ʒ���2
	uint32 numberTwo; //����2
	uint32 bonusitemnumThree; //������Ʒ���3
	uint32 numberThree; //����3
};

//������
struct TreeInfo
{
	uint32 gread; //�ȼ�
	uint32 cowaternum; //����ˮ������
	uint32 cosunnum; //������������
	uint32 cogoldnum; //�����������
	uint32 elfinprodco; //С������������
	uint32 productivity; //������
	uint32 treehigh; //���ĸ߶�
};

//�����
struct TreeEnchantmentInfo
{
	uint32 gread; //�ȼ�
	uint32 enchantdefense; //������
};

class XmlConfigManager
{
public:
	std::map<uint32, SkillInfo> SkillInfos;
	static XmlConfigManager* GetInstance()
	{
		if (Instance != nullptr)
			Instance = new XmlConfigManager();
		return Instance;
	}
	~XmlConfigManager();
private:
	XmlConfigManager();
	bool ParseXmlToArticle();//��Ʒ
	bool ParseXmlToElfin();//С����
	bool ParseXmlToSkill();//����
	bool ParseXmlToSunshine();//����
	bool ParseXmlToTask();//����
	bool ParseXmlToTree();//������
	bool ParseXmlToTreeEnchantment();//�����
	static XmlConfigManager* Instance;
};

