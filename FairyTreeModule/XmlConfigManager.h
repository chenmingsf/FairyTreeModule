#pragma once

#include "define.h"
#include <map>
#include "./TinyXML/tinyxml.h"
#include "./TinyXML/tinyxml.h"

//物品
struct ArticleInfo
{
	uint32 articleID; //物品
	std::string articlename; //物品名
	std::string articledescribe; //物品描述
	uint32 goldprice; //金币价格
	uint32 diamondprice; //钻石价格
	uint32 discountrate; //折扣率
	std::string type; //类型
};

//小精灵
struct ElfinInfo
{
	uint32 grade; //等级
	uint32 physicalilmit; //体力上限
	uint32 cowaternumber; //消耗水的数量
	uint32 cosunnum; //阳光数量消耗
	uint32 cogoldnum; //金币数量消耗
	uint32 codiamondnum; //钻石消耗数量
};

//技能
struct SkillInfo
{
	uint32 Level; //等级
	uint32 plunder; //掠夺效果
	uint32 watering; //浇水效果
	uint32 storage; //储存金币
	uint32 cultivation; //栽培效果
	uint32 elude; //躲避能力
	uint32 plunderAddition; //抢劫加成
};

//阳光
struct SunshineInfo
{
	uint32 grade; //等级
	uint32 cowaternumber; //消耗水的数量
	uint32 cosunnum; //阳光数量消耗
	uint32 cogoldnum; //金币数量消耗
	uint32 producompet; //产出能力
	uint32 produtime; //生产时间
};

//任务
struct TaskInfo
{
	uint32 taskId; //编号
	std::string headline; //标题
	std::string content; //内容
	uint32 totalcomptimes; //总完成次数
	uint32 bonusitemnumOne; //奖励物品编号1
	uint32 numberOne; //数量1
	uint32 bonusitemnumTwo; //奖励物品编号2
	uint32 numberTwo; //数量2
	uint32 bonusitemnumThree; //奖励物品编号3
	uint32 numberThree; //数量3
};

//神仙树
struct TreeInfo
{
	uint32 gread; //等级
	uint32 cowaternum; //消耗水的数量
	uint32 cosunnum; //阳光数量消耗
	uint32 cogoldnum; //金币数量消耗
	uint32 elfinprodco; //小精灵体力消耗
	uint32 productivity; //生产力
	uint32 treehigh; //树的高度
};

//树结界
struct TreeEnchantmentInfo
{
	uint32 gread; //等级
	uint32 enchantdefense; //结界防御
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
	bool ParseXmlToArticle();//物品
	bool ParseXmlToElfin();//小精灵
	bool ParseXmlToSkill();//技能
	bool ParseXmlToSunshine();//阳光
	bool ParseXmlToTask();//任务
	bool ParseXmlToTree();//神仙树
	bool ParseXmlToTreeEnchantment();//树结界
	static XmlConfigManager* Instance;
};

