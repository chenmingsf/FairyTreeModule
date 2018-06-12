#include "XmlConfigManager.h"



XmlConfigManager::XmlConfigManager()
{
	ParseXmlToItem();//��Ʒ
	ParseXmlToElfin();//С����
	ParseXmlToSkill();//����
	ParseXmlToSunshine();//����
	ParseXmlToTask();//����
	ParseXmlToTree();//������
	ParseXmlToTreeEnchantment();//�����
}


bool XmlConfigManager::ParseXmlToItem()
{
	const char* pItemXmlFileName = "Item.xml"; //��Ʒxml�ļ���
	ItemInfo iteminfo; //��Ʒ�ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pItemXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		iteminfo.articleID = atoi(pchild->ToElement()->GetText());//������ƷID

		pchild = pnode->IterateChildren(pchild);
		iteminfo.articlename = pchild->ToElement()->GetText();//������Ʒ����

		pchild = pnode->IterateChildren(pchild);
		iteminfo.articledescribe = pchild->ToElement()->GetText(); //��Ʒ����

		pchild = pnode->IterateChildren(pchild);
		iteminfo.goldprice = atoi(pchild->ToElement()->GetText());//��Ʒ��Ҽ۸�

		pchild = pnode->IterateChildren(pchild);
		iteminfo.diamondprice = atoi(pchild->ToElement()->GetText());//��Ʒ��ʯ�۸�

		pchild = pnode->IterateChildren(pchild);
		iteminfo.discountrate = atof(pchild->ToElement()->GetText());//��Ʒ�ۿ���	

		pchild = pnode->IterateChildren(pchild);
		iteminfo.type = pchild->ToElement()->GetText(); //��Ʒ����		

		pchild = pnode->IterateChildren(pchild);
		iteminfo.photoname = atoi(pchild->ToElement()->GetText()); //��ƷͼƬ��

		ItemInfos[iteminfo.articleID] = &iteminfo;
		StoreItemsInStores(iteminfo.articleID);
	}
	return true;
}

bool XmlConfigManager::ParseXmlToElfin()
{
	const char* pElfinXmlFileName = "Elfin.xml"; //С����xml�ļ���
	ElfinInfo elifninfo; //С����ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pElfinXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		elifninfo.grade = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		elifninfo.physicalilmit = atoi(pchild->ToElement()->GetText());//��ȡ��������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cowaternumber = atoi(pchild->ToElement()->GetText());//��ȡ����ˮ������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cosunnum = atoi(pchild->ToElement()->GetText());//��ȡ������������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.cogoldnum = atoi(pchild->ToElement()->GetText());//��ȡ�����������

		pchild = pnode->IterateChildren(pchild);
		elifninfo.codiamondnum = atoi(pchild->ToElement()->GetText());//��ȡ��ʯ��������

		ElfinInfos[elifninfo.grade] = &elifninfo;
		InitElfinData(elifninfo.grade);
	}
	return true;
}

bool XmlConfigManager::ParseXmlToSkill()
{
	const char* pSkillXmlFileName = "Skill.xml"; //����xml�ļ���
	SkillInfo skillinfo; //���ܽṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pSkillXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		skillinfo.Level = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		skillinfo.plunder = atoi(pchild->ToElement()->GetText());//��ȡ�Ӷ�Ч��

		pchild = pnode->IterateChildren(pchild);
		skillinfo.watering = atoi(pchild->ToElement()->GetText());//��ȡ��ˮЧ��

		pchild = pnode->IterateChildren(pchild);
		skillinfo.storage = atoi(pchild->ToElement()->GetText());//��ȡ������

		pchild = pnode->IterateChildren(pchild);
		skillinfo.cultivation = atoi(pchild->ToElement()->GetText());//��ȡ����Ч��

		pchild = pnode->IterateChildren(pchild);
		skillinfo.elude = atoi(pchild->ToElement()->GetText());//��ȡ�������

		pchild = pnode->IterateChildren(pchild);
		skillinfo.plunderAddition = atoi(pchild->ToElement()->GetText());//��ȡ���ټӳ�

		SkillInfos[skillinfo.Level] = &skillinfo;
		InitSkillData(skillinfo.Level);
	}
	return true;
}

bool XmlConfigManager::ParseXmlToSunshine()
{
	const char* pSunXmlFileName = "Sun.xml"; //����xml�ļ���
	SunshineInfo sunshine; //�ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument();//�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pSunXmlFileName);//�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�

	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		sunshine.grade = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		sunshine.cowaternumber = atoi(pchild->ToElement()->GetText());//��ȡ����ˮ������

		pchild = pnode->IterateChildren(pchild);
		sunshine.cosunnum = atoi(pchild->ToElement()->GetText());//��ȡ������������

		pchild = pnode->IterateChildren(pchild);
		sunshine.cogoldnum = atoi(pchild->ToElement()->GetText());//��ȡ�����������

		pchild = pnode->IterateChildren(pchild);
		sunshine.codiamondnum = atoi(pchild->ToElement()->GetText());//��ȡ��ʯ��������

		pchild = pnode->IterateChildren(pchild);
		sunshine.producompet = atoi(pchild->ToElement()->GetText());//��ȡ��������

		pchild = pnode->IterateChildren(pchild);
		sunshine.produtime = atoi(pchild->ToElement()->GetText());//��ȡ����ʱ��

		SunInfos[sunshine.grade] = &sunshine;
		InitSunData(sunshine.grade);
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTask()
{
	const char* pTaskXmlFileName = "Task.xml"; //����xml�ļ���
	TaskInfo taskclass; //����ṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument(); //�����ĵ�����ָ��
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pTaskXmlFileName); //�����ļ�
	TiXmlElement* proot = ptixml->RootElement(); //ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		taskclass.taskId = atoi(pchild->ToElement()->GetText());//��ȡ������

		pchild = pnode->IterateChildren(pchild);
		taskclass.headline = pchild->ToElement()->GetText();//��ȡ�������

		pchild = pnode->IterateChildren(pchild);
		taskclass.content = pchild->ToElement()->GetText();//��ȡ��������

		pchild = pnode->IterateChildren(pchild);
		taskclass.totalcomptimes = atoi(pchild->ToElement()->GetText());//��ȡ���������ɶ�

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumOne = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ��� 1

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberOne = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ1������

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumTwo = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ��� 2

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberTwo = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ2������

		pchild = pnode->IterateChildren(pchild);
		taskclass.bonusitemnumThree = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ��� 3

		pchild = pnode->IterateChildren(pchild);
		taskclass.numberThree = atoi(pchild->ToElement()->GetText());//��ȡ������Ʒ3������

		TaskInfos[taskclass.taskId] = &taskclass;
		InitTaskData(taskclass.taskId);
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTree()
{
	const char* pTreeXmlFileName = "Tree.xml"; //������Xml�ļ���
	TreeInfo fairytree; //�������Ľṹ�����
	TiXmlDocument* ptixml = new TiXmlDocument(); //�����ĵ�����
	if (NULL == ptixml)
	{
		return false;
	}
	ptixml->LoadFile(pTreeXmlFileName);//����Xml�ļ�
	TiXmlElement* proot = ptixml->RootElement();//ָ����ڵ�
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		fairytree.gread = atoi(pchild->ToElement()->GetText());//��ȡ�ȼ�

		pchild = pnode->IterateChildren(pchild);
		fairytree.cowaternum = atoi(pchild->ToElement()->GetText());//��ȡ����ˮ������

		pchild = pnode->IterateChildren(pchild);
		fairytree.cosunnum = atoi(pchild->ToElement()->GetText());//��ȡ�������������

		pchild = pnode->IterateChildren(pchild);
		fairytree.cogoldnum = atoi(pchild->ToElement()->GetText());//��ȡ���Ľ�ҵ�����

		pchild = pnode->IterateChildren(pchild);
		fairytree.codiamondnum = atoi(pchild->ToElement()->GetText());//��ȡ��ʯ��������

		pchild = pnode->IterateChildren(pchild);
		fairytree.elfinprodco = atoi(pchild->ToElement()->GetText());//��ȡ����С��������������

		pchild = pnode->IterateChildren(pchild);
		fairytree.productivity = atoi(pchild->ToElement()->GetText());//��ȡ����������

		pchild = pnode->IterateChildren(pchild);
		fairytree.treehigh = atof(pchild->ToElement()->GetText());//��ȡ����

		pchild = pnode->IterateChildren(pchild);
		fairytree.breakthReq = atoi(pchild->ToElement()->GetText());//��ȡ����

		TreeInfos[fairytree.gread] = &fairytree;
		InitTreeData(fairytree.gread);
	}
	return true;
}

bool XmlConfigManager::ParseXmlToTreeEnchantment()
{
	const char* pTreeEnchantmentXmlFileName = "TreeEnchantment.xml"; //������xml�ļ�
	TreeEnchantmentInfo treeench; //�����ṹ�����
								  //�����ĵ�����ָ��
	TiXmlDocument* tixml = new TiXmlDocument();
	if (NULL == tixml)
	{
		return false;
	}
	tixml->LoadFile(pTreeEnchantmentXmlFileName);//�����ļ�
	TiXmlElement* proot = tixml->RootElement();//�����ĵ�����ָ���ҵ����ڵ�

											   //�ӵ�һ����Ϊ(Table)�Ľڵ� ѭ�� �����ݷ����������
	for (TiXmlNode* pnode = proot->FirstChild("Table"); pnode; pnode = pnode->NextSibling("Table"))
	{
		TiXmlNode* pchild = pnode->FirstChild();
		treeench.gread = atoi(pchild->ToElement()->GetText());//���������ĵȼ�		

		pchild = pnode->IterateChildren(pchild);
		treeench.enchantdefense = atoi(pchild->ToElement()->GetText());//������������

		TreeEnchantInfos[treeench.gread] = &treeench;
		InitTreeEnchantData(treeench.gread);
	}
	return true;
}


template<typename T>
void ReleaseMapFun(std::map<uint32, T*> it)
{
	for (std::map<uint32, T*>::iterator iter = it.begin(); iter != it.end(); iter++)
	{
		it.erase(iter);
	}
}

XmlConfigManager * XmlConfigManager::Instance = new XmlConfigManager();
XmlConfigManager * XmlConfigManager::GetInstance()
{
	return Instance;
}

XmlConfigManager::~XmlConfigManager()
{
	ReleaseMapFun(ItemInfos);
	ReleaseMapFun(ElfinInfos);
	ReleaseMapFun(SkillInfos);
	ReleaseMapFun(SunInfos);
	ReleaseMapFun(TaskInfos);
	ReleaseMapFun(TreeInfos);
	ReleaseMapFun(TreeEnchantInfos);
	delete xmlshop;
	xmlshop = nullptr;
	delete xmlelfin;
	xmlelfin = nullptr;
	delete xmlskill;
	xmlskill = nullptr;
	delete xmlsunshine;
	xmlsunshine = nullptr;
	delete xmlfairytree;
	xmlfairytree = nullptr;
	delete xmltreeenchantment;
	xmltreeenchantment = nullptr;

	delete Instance;
	Instance = nullptr;
}

//�洢��Ʒ���̵���
void XmlConfigManager::StoreItemsInStores(uint32 uid)
{
	xmlshop = new Shop;
	xmlshop->pwareArt->Set_CArticleSerialNumber(uid);
	xmlshop->pwareArt->Set_CArticleGoldPrice(ItemInfos[uid]->goldprice);
	xmlshop->pwareArt->Set_CArticleJewelPrice(ItemInfos[uid]->diamondprice);
	xmlshop->pwareArt->Set_CArticleDiscount(ItemInfos[uid]->discountrate);
	xmlshop->pwareArt->Set_WareName(ItemInfos[uid]->articlename);
	xmlshop->pwareArt->Set_CArticleDescribe(ItemInfos[uid]->articledescribe);
	xmlshop->storeItemInfo[uid] = xmlshop->pwareArt;

}

//��ʼ��С�������ݵ�С������
void XmlConfigManager::InitElfinData(uint32 uid)
{
	xmlelfin = new Elfin;
	xmlelfin->Set_EGrade(ElfinInfos[uid]->grade);
	xmlelfin->Set_EMaxPhysicalPower(ElfinInfos[uid]->physicalilmit);
	xmlelfin->Set_uCoWaterNum(ElfinInfos[uid]->cowaternumber);
	xmlelfin->Set_uCoSunNum(ElfinInfos[uid]->cosunnum);
	xmlelfin->Set_uCoGoldNum(ElfinInfos[uid]->cogoldnum);
	xmlelfin->Set_uCoJewelNum(ElfinInfos[uid]->codiamondnum);
	xmlelfin->map_elfin[uid] = xmlelfin;
}

//��ʼ���������ݵ�������
void XmlConfigManager::InitSkillData(uint32 id)
{
	xmlskill = new CSkill;
	xmlskill->Set_Skill_Level(SkillInfos[id]->Level);
	xmlskill->Set_uPillageEffect(SkillInfos[id]->plunder);
	xmlskill->Set_uWateringEffect(SkillInfos[id]->watering);
	xmlskill->Set_uReserveGold(SkillInfos[id]->storage);
	xmlskill->Set_uPlantEffect(SkillInfos[id]->cultivation);
	xmlskill->Set_uDodgeAbility(SkillInfos[id]->elude);
	xmlskill->Set_uRobAddition(SkillInfos[id]->plunderAddition);
	xmlskill->map_skill[id] = xmlskill;
}

//��ʼ��̫�����ݵ�̫����
void XmlConfigManager::InitSunData(uint32 id)
{
	xmlsunshine = new CSunshine;
	xmlsunshine->Set_FGrade(SunInfos[id]->grade);
	xmlsunshine->Set_SunCoWaterNum(SunInfos[id]->cowaternumber);
	xmlsunshine->Set_SunCoSunNum(SunInfos[id]->cosunnum);
	xmlsunshine->Set_SunCoGoldNum(SunInfos[id]->cogoldnum);
	xmlsunshine->Set_SunCoJewelNum(SunInfos[id]->codiamondnum);
	xmlsunshine->Set_FSunProCap(SunInfos[id]->producompet);
	xmlsunshine->Set_FSunProTime(SunInfos[id]->produtime);
	xmlsunshine->map_sunshine[id] = xmlsunshine;
}

//��ʼ���������ݵ�������
void XmlConfigManager::InitTaskData(uint32 id)
{
	xmltasklistclass.taskc->Set_TSerialNumber(TaskInfos[id]->taskId);
	xmltasklistclass.taskc->Set_TTaskheadline(TaskInfos[id]->headline);
	xmltasklistclass.taskc->Set_TTaskContent(TaskInfos[id]->content);
	xmltasklistclass.taskc->Set_TaskSumUpComp(TaskInfos[id]->totalcomptimes);
	xmltasklistclass.taskc->Set_TTaskAward(TaskInfos[id]->bonusitemnumOne, TaskInfos[id]->numberOne);
	xmltasklistclass.taskc->Set_TTaskAward(TaskInfos[id]->bonusitemnumTwo, TaskInfos[id]->numberTwo);
	xmltasklistclass.taskc->Set_TTaskAward(TaskInfos[id]->bonusitemnumThree, TaskInfos[id]->numberThree);
	xmltasklistclass.map_task[id] = xmltasklistclass.taskc;
}

//��ʼ�����������ݵ���������
void XmlConfigManager::InitTreeData(uint32 id)
{
	xmlfairytree = new FairyTree;
	xmlfairytree->Set_FGrade(TreeInfos[id]->gread);
	xmlfairytree->Set_FCoWaterNum(TreeInfos[id]->cowaternum);
	xmlfairytree->Set_FCoSunNum(TreeInfos[id]->cosunnum);
	xmlfairytree->Set_FCoGoldNum(TreeInfos[id]->cogoldnum);
	xmlfairytree->Set_FCoJewelNum(TreeInfos[id]->codiamondnum);
	xmlfairytree->Set_FCoeflinNum(TreeInfos[id]->elfinprodco);
	xmlfairytree->Set_FGold(TreeInfos[id]->productivity);
	xmlfairytree->Set_TreeHeight(TreeInfos[id]->treehigh);
	xmlfairytree->Set_FCoBreakthNum(TreeInfos[id]->breakthReq);
	xmlfairytree->map_fairytree[id] = xmlfairytree;
}

//��ʼ����������ݵ��������
void XmlConfigManager::InitTreeEnchantData(uint32 id)
{
	xmltreeenchantment = new TreeEnchantment;
	xmltreeenchantment->Set_TEGrade(TreeEnchantInfos[id]->gread);
	xmltreeenchantment->Set_TEDefense(TreeEnchantInfos[id]->enchantdefense);
	xmltreeenchantment->map_treeEn[id] = xmltreeenchantment;
}

