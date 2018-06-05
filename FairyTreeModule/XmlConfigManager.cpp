#include "XmlConfigManager.h"



XmlConfigManager::XmlConfigManager()
{
	ParseXmlToArticle();//��Ʒ
	ParseXmlToElfin();//С����
	ParseXmlToSkill();//����
	ParseXmlToSunshine();//����
	ParseXmlToTask();//����
	ParseXmlToTree();//������
	ParseXmlToTreeEnchantment();//�����
}

bool XmlConfigManager::ParseXmlToArticle()
{
	return false;
}

bool XmlConfigManager::ParseXmlToElfin()
{
	const char* pxmlFileName = "Elfin.xml"; //С����xml�ļ���
	ElfinInfo elifninfo; //
	return false;
}

bool XmlConfigManager::ParseXmlToSkill()
{
	const char* pxmlFileName = "Skill.xml"; //����xml�ļ���
	SkillInfo skillinfo; //�ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pxmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgread = pchild->ToElement()->GetText(); //��ȡ�ȼ�
		uint32 ugreadLen = strlen(pgread);
		if (NULL != pgread)
		{
			//���õȼ�
			uint32 setgread;
			memcpy_safe((char*)&pgread, ugreadLen, (char*)&setgread, ugreadLen);
			skillinfo.Level = setgread;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pplun = pchild->ToElement()->GetText(); //��ȡ�Ӷ�Ч��
		uint32 uplunLen = strlen(pplun);
		if (NULL != pplun)
		{
			//�����Ӷ�Ч��
			uint32 setplun;
			memcpy_safe((char*)&pplun, uplunLen, (char*)&setplun, uplunLen);
			skillinfo.plunder = setplun;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pwater = pchild->ToElement()->GetText(); //��ȡ��ˮЧ��
		uint32 uwaterLen = strlen(pwater);
		if (NULL != pwater)
		{
			//���ý�ˮЧ��
			uint32 setwater;
			memcpy_safe((char*)&pwater, uwaterLen, (char*)&setwater, uwaterLen);
			skillinfo.watering = setwater;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pstorage = pchild->ToElement()->GetText(); //��ȡ������
		uint32 ustorLen = strlen(pstorage);
		if (NULL != pstorage)
		{
			//���ô�����
			uint32 setstor;
			memcpy_safe((char*)&pstorage, ustorLen, (char*)&setstor, ustorLen);
			skillinfo.storage = setstor;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pculti = pchild->ToElement()->GetText(); //��ȡ����Ч��
		uint32 ucultiLen = strlen(pculti);
		if (NULL != pculti)
		{
			//��������Ч��
			uint32 setculti;
			memcpy_safe((char*)&pculti, ucultiLen, (char*)&setculti, ucultiLen);
			skillinfo.cultivation = setculti;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pelude = pchild->ToElement()->GetText(); //��ȡ�������
		uint32 ueludeiLen = strlen(pelude);
		if (NULL != pelude)
		{
			//���ö������
			uint32 setelude;
			memcpy_safe((char*)&pelude, ueludeiLen, (char*)&setelude, ueludeiLen);
			skillinfo.elude = setelude;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pplAdd = pchild->ToElement()->GetText(); //��ȡ���ټӳ�
		uint32 uplAddLen = strlen(pplAdd);
		if (NULL != pplAdd)
		{
			//�������ټӳ�
			uint32 setplAdd;
			memcpy_safe((char*)&pplAdd, uplAddLen, (char*)&setplAdd, uplAddLen);
			skillinfo.plunderAddition = setplAdd;
		}

	}
	return true;
}

bool XmlConfigManager::ParseXmlToSunshine()
{
	const char* pxmlFileName = "Sunshine.xml"; //����xml�ļ���
	SunshineInfo sunshine; //�ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pxmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�

	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgrad = pchild->ToElement()->GetText(); //��ȡ�ȼ�
		uint32 uglen = strlen(pgrad);
		if (NULL != pgrad)
		{
			//���õȼ�
			uint32 ugrad = 0;
			memcpy_safe((char*)&pgrad, uglen, (char*)&ugrad, uglen);
			sunshine.grade = ugrad;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pcowat = pchild->ToElement()->GetText(); //��ȡ����ˮ������
		uint32 ucolen = strlen(pcowat);
		if (NULL != pcowat)
		{
			//��������ˮ������
			uint32 unum = 0;
			memcpy_safe((char*)&pcowat, ucolen, (char*)&unum, ucolen);
			sunshine.cowaternumber = unum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pcosun = pchild->ToElement()->GetText(); //��ȡ������������
		uint32 uslen = strlen(pcosun);
		if (NULL != pcosun)
		{
			//����������������
			uint32 usunNum = 0;
			memcpy_safe((char*)&pcosun, uslen, (char*)&usunNum, uslen);
			sunshine.cosunnum = usunNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pgold = pchild->ToElement()->GetText(); //��ȡ�����������
		uint32 ugolen = strlen(pgold);
		if (NULL != pgold)
		{
			//���ý����������
			uint32 ugoldnum = 0;
			memcpy_safe((char*)&pgold, ugolen, (char*)&ugoldnum, ugolen);
			sunshine.cogoldnum = ugoldnum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pprocap = pchild->ToElement()->GetText(); //��ȡ��������
		uint32 uprolen = strlen(pprocap);
		if (NULL != pprocap)
		{
			//���ò�������
			uint32 uproCap = 0;
			memcpy_safe((char*)&pprocap, uprolen, (char*)&uproCap, uprolen);
			sunshine.producompet = uproCap;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pprotime = pchild->ToElement()->GetText(); //��ȡ����ʱ��
		uint32 uptlen = strlen(pprotime);
		if (NULL != pprotime)
		{
			//��������ʱ��
			uint32 uprot = 0;
			memcpy_safe((char*)&pprotime, uptlen, (char*)&uprot, uptlen);
			sunshine.produtime = uprot;
		}
	}

	return true;
}

bool XmlConfigManager::ParseXmlToTask()
{
	const char* ptaskXmlF = "Task.xml"; //����xml�ļ���
	TaskInfo taskclass; //����ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument(); //�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(ptaskXmlF); //�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�

	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pid = pchild->ToElement()->GetText(); //��ȡ������
		uint32 uidlen = strlen(pid);
		if (NULL != pid)
		{
			//����������
			uint32 uid = 0;
			memcpy_safe((char*)&pid, uidlen, (char*)&uid, uidlen);
			taskclass.taskId = uid;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pheadline = pchild->ToElement()->GetText(); //��ȡ�������
		uint32 uheadlen = strlen(pheadline);
		if (NULL != pheadline)
		{
			//�����������
			std::string shead = "";
			memcpy_safe((char*)&pheadline, uheadlen, (char*)&shead, uheadlen);
			taskclass.headline = shead;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pcontent = pchild->ToElement()->GetText(); //��ȡ��������
		uint32 ucontlen = strlen(pcontent);
		if (NULL != pcontent)
		{
			//������������
			std::string scont = "";
			memcpy_safe((char*)&pcontent, ucontlen, (char*)&scont, ucontlen);
			taskclass.content = scont;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pSunUC = pchild->ToElement()->GetText(); //��ȡ���������ɶ�
		uint32 usunuclen = strlen(pSunUC);
		if (NULL != pSunUC)
		{
			//�������������ɶ�
			uint32 uSunUC = 0;
			memcpy_safe((char*)&pSunUC, usunuclen, (char*)&uSunUC, usunuclen);
			taskclass.totalcomptimes = uSunUC;
		}

		//������Ʒ���1 �� ����1
		pchild = pnode->IterateChildren(pchild);
		const char* pbonIteNuOne = pchild->ToElement()->GetText(); //��ȡ������Ʒ��� 1
		uint32 ublen = strlen(pbonIteNuOne); //���1�ĳ���
		pchild = pnode->IterateChildren(pchild);
		const char* pnumb1 = pchild->ToElement()->GetText(); //��ȡ������Ʒ1������
		uint32 ublen1 = strlen(pnumb1);//����1�ĳ���
		if (NULL != pbonIteNuOne && NULL != pnumb1)
		{
			//���ý�����Ʒ���1 �� ����1
			uint32 ubINID = 0;
			uint32 ubiNNum = 0;
			memcpy_safe((char*)&pbonIteNuOne, ublen, (char*)&ubINID, ublen);
			memcpy_safe((char*)&pnumb1, ublen1, (char*)&ubiNNum, ublen1);
			taskclass.bonusitemnumOne = ubINID;
			taskclass.numberOne = ubiNNum;
		}

		//������Ʒ���2 �� ����2
		pchild = pnode->IterateChildren(pchild);
		const char* pbonIteNuTwo = pchild->ToElement()->GetText(); //��ȡ������Ʒ��� 2
		uint32 ublen2 = strlen(pbonIteNuTwo); //���2�ĳ���
		pchild = pnode->IterateChildren(pchild);
		const char* pnumbtwo = pchild->ToElement()->GetText(); //��ȡ������Ʒ2������
		uint32 ublentwo = strlen(pnumbtwo);//����2�ĳ���
		if (NULL != pbonIteNuTwo && NULL != pnumbtwo)
		{
			//���ý�����Ʒ���2 �� ����2
			uint32 ubINID2 = 0;
			uint32 ubiNNum2 = 0;
			memcpy_safe((char*)&pbonIteNuTwo, ublen2, (char*)&ubINID2, ublen2);
			memcpy_safe((char*)&pnumbtwo, ublentwo, (char*)&ubiNNum2, ublentwo);
			taskclass.bonusitemnumTwo = ubINID2;
			taskclass.numberTwo = ubiNNum2;
		}

		//������Ʒ���3 �� ����3
		pchild = pnode->IterateChildren(pchild);
		const char* pbonIteNuThree = pchild->ToElement()->GetText(); //��ȡ������Ʒ��� 3
		uint32 ublen3 = strlen(pbonIteNuThree); //���3�ĳ���
		pchild = pnode->IterateChildren(pchild);
		const char* pnumbthree = pchild->ToElement()->GetText(); //��ȡ������Ʒ3������
		uint32 ublenthree = strlen(pnumbthree);//����3�ĳ���
		if (NULL != pbonIteNuThree && NULL != pnumbthree)
		{
			//���ý�����Ʒ���2 �� ����2
			uint32 ubINID3 = 0;
			uint32 ubiNNum3 = 0;
			memcpy_safe((char*)&pbonIteNuThree, ublen3, (char*)&ubINID3, ublen3);
			memcpy_safe((char*)&pnumbthree, ublenthree, (char*)&ubiNNum3, ublenthree);
			taskclass.bonusitemnumThree = ubINID3;
			taskclass.numberThree = ubiNNum3;
		}
	}

	return true;
}

bool XmlConfigManager::ParseXmlToTree()
{
	const char* pftxf = "Tree.xml";
	TreeInfo fairytree; //�������Ľṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument(); //�����ĵ�����
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pftxf);//����Xml�ļ�
	TiXmlElement* proot = ptixml->RootElement();//ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgrad = pchild->ToElement()->GetText(); //��ȡ�ȼ�
		uint32 uglen = strlen(pgrad);
		if (NULL != pgrad)
		{
			//�����������ĵȼ�
			uint32 ugrad = 0;
			memcpy_safe((char*)&pgrad, uglen, (char*)&ugrad, uglen);
			fairytree.gread = ugrad;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pwater = pchild->ToElement()->GetText(); //��ȡ����ˮ������
		uint32 uwlen = strlen(pwater);
		if (NULL != pwater)
		{
			//��������������ˮ������
			uint32 uwNum = 0;
			memcpy_safe((char*)&pwater, uwlen, (char*)&uwNum, uwlen);
			fairytree.cowaternum = uwNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* psunshine = pchild->ToElement()->GetText(); //��ȡ�������������
		uint32 uslen = strlen(psunshine);
		if (NULL != psunshine)
		{
			//�����������������������
			uint32 uwNum = 0;
			memcpy_safe((char*)&psunshine, uslen, (char*)&uwNum, uslen);
			fairytree.cosunnum = uwNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pgold = pchild->ToElement()->GetText(); //��ȡ���Ľ�ҵ�����
		uint32 ugoldlen = strlen(pgold);
		if (NULL != pgold)
		{
			//���������������Ľ�ҵ�����
			uint32 ugoldNum = 0;
			memcpy_safe((char*)&pgold, ugoldlen, (char*)&ugoldNum, ugoldlen);
			fairytree.cogoldnum = ugoldNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pelfin = pchild->ToElement()->GetText(); //��ȡ����С��������������
		uint32 uelen = strlen(pelfin);
		if (NULL != pelfin)
		{
			//����������������С��������������
			uint32 ueNum = 0;
			memcpy_safe((char*)&pelfin, uelen, (char*)&ueNum, uelen);
			fairytree.elfinprodco = ueNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pprod = pchild->ToElement()->GetText(); //��ȡ����������
		uint32 uplen = strlen(pprod);
		if (NULL != pprod)
		{
			//����������������������
			uint32 upNum = 0;
			memcpy_safe((char*)&pprod, uplen, (char*)&upNum, uplen);
			fairytree.productivity = upNum;
		}

		pchild = pnode->IterateChildren(pchild);
		const char* pheitree = pchild->ToElement()->GetText(); //��ȡ����
		uint32 uheilen = strlen(pheitree);
		if (NULL != pheitree)
		{
			//����������������
			uint32 uheiNum = 0;
			memcpy_safe((char*)&pheitree, uheilen, (char*)&uheiNum, uheilen);
			fairytree.treehigh = uheiNum;
		}
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTreeEnchantment()
{
	const char* XmlName = "TreeEnchantment.xml"; //������xml�ļ�
	TreeEnchantmentInfo treeench; //�����ṹ�����
							  //�����ĵ�����ָ��
	TiXmlDocument* tixml = new TiXmlDocument();
	if (NULL == tixml)
	{
		return false;
	}
	//�����ļ�
	tixml->LoadFile(XmlName);

	//�����ĵ�����ָ���ҵ����ڵ�
	TiXmlElement* proot = tixml->RootElement();

	//�ӵ�һ����Ϊ(Table)�Ľڵ� ѭ�� �����ݷ����������
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		const char* pgrade = pchild->ToElement()->GetText();
		uint32 uglen = strlen(pgrade);
		if (NULL != pgrade)
		{
			//���������ĵȼ�
			uint32 ugrad = 0;
			memcpy_safe((char*)&pgrade, uglen, (char*)&ugrad, uglen);
			treeench.gread = ugrad;
		}
		pchild = pnode->IterateChildren(pchild);
		const char* pdef = pchild->ToElement()->GetText();
		uint32 udlen = strlen(pdef);
		if (NULL != pdef)
		{
			//������������
			uint32 udefe = 0;
			memcpy_safe((char*)&pdef, udlen, (char*)&udefe, udlen);
			treeench.enchantdefense = udefe;
		}
	}
}


XmlConfigManager::~XmlConfigManager()
{
}
