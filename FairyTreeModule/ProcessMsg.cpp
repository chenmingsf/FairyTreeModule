#include "ProcessMsg.h"

//请求
//登录请求1
void Process_LoginRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{	
	//首先从数据库里对比id
	LoginRequest logreq;

	//登录时间放入数据库
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));

	//调用数据库查找登录账号ID
	//FairyTreeUserClasses* faitreUser = SelectUserById(logreq.account());
	//if (faitreUser == null)
	//{
	//	//创建一个新用户
	//	 faitreUser = new FairyTreeUserClasses();
	 //  用户的个数加 1 = faitreUser->Set_RecordUserCount(1);
	//}
	//通过连接ID,将用户存入map中
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId] = faitreUser;

	//神仙树用户类
	//应答函数
	Process_LoginResponse(pMsg, pServerObj, pMessage);

}

//小精灵请求2
void Process_ElfinRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//收到请求返回数据

	//应答函数
	Process_ElfinResponse(pMsg, pServerObj, pMessage);

}

//角色信息请求3
void Process_RollRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//RollRequest rollreq;

	//收到角色信息请求
	//rollreq.roll();

	//应答函数
	Process_RollResponse(pMsg, pServerObj, pMessage);
}

//神仙树请求4
void Process_TreeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//TreeRequest ptreReq;

	//收到神仙树的请求 返回数据
	//ptreReq.tree();

	//应答函数
	Process_TreeResponse(pMsg, pServerObj, pMessage);

}

//资源请求5
void Process_ResourceRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//ResourceRequest rocrut;

	//收到资源请求
	//rocrut.resource();

	//应答函数
	Process_ResourceResponse(pMsg, pServerObj, pMessage);
}

//获取任务列表请求6
void Process_TasksRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//TasksRequest ptasReq;

	//获取人物列表请求
	//ptasReq.tasks();

	//应答函数
	Process_TasksResponse(pMsg, pServerObj, pMessage);
}

//邮件请求7
void Process_MailsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//MailsRequest pmaiReq;

	//获取邮件列表信息
	//pmaiReq.mails();

	//应答函数
	Process_MailsResponse(pMsg, pServerObj, pMessage);

}

//太阳请求8
void Process_SunRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//SunRequest pwelReq;

	//收到太阳的请求 返回数据
	//pwelReq.sun();

	//应答函数
	Process_SunResponse(pMsg, pServerObj, pMessage);

}

//树结界请求9
void Process_TreeEnchantmentRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//TreeEnchantmentRequest ptreEncReq;

	//收到请求 返回数据
	//ptreEncReq.treeench();

	//应答函数
	Process_TreeEnchantmentResponse(pMsg, pServerObj, pMessage);

}

//获取商店所有物品请求10
void Process_StoreAllRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreAllRequest stoall;

	//收到商店所有物品请求
	//stoall.storeall();

	//应答函数
	Process_StoreAllResponse(pMsg, pServerObj, pMessage);

}

//获取商店装备类物品请求11
void Process_StoreEquRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreEquRequest stoequ;

	//收到商店装备类物品请求
	//stoequ.storeequ();

	//应答函数
	Process_StoreEquResponse(pMsg, pServerObj, pMessage);

}

//获取商店水资源类物品请求12
void Process_StoreWaterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreWaterRequest stowatreq;

	//收到商店水资源类物品请求
	//stowatreq.storewater();

	//应答函数
	Process_StoreWaterResponse(pMsg, pServerObj, pMessage);

}

//获取商店特殊类物品请求13
void Process_StoreSpePropsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//StoreSpePropsRequest stospeproreq;

	//收到商店特殊类物品请求
	//stospeproreq.storespeprops();

	//应答函数
	Process_StoreSpePropsResponse(pMsg, pServerObj, pMessage);

}

//获取仓库所有物品请求14
void Process_WarehouseRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//WarehouseRequest warehreq;

	//收到仓库所有物品请求
	//warehreq.warehouse();

	//应答函数
	Process_WarehouseResponse(pMsg, pServerObj, pMessage);

}

//删除邮件请求15
void Process_DelMailRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	DelMailRequest delmail;

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//收到删除邮件请求
	if (delmail.id() == faitreUser->Get_CMailbox().map_mail[delmail.id()]->Get_MailSerialNumber())
	{
		faitreUser->Get_CMailbox().CloseMail(delmail.id());
	}

	//应答函数
	Process_DelMailResponse(pMsg, pServerObj, pMessage);

}

//请求领取任务16
void Process_ClaimedTaskRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	ClaimedTaskRequest clatask;

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//收到领取任务请求 并设置为当前任务状态
	if (clatask.id() == faitreUser->Get_CTaskListClass().map_task[clatask.id()]->Get_TSerialNumber())
	{
		faitreUser->Get_CTaskListClass().map_task[clatask.id()]->Set_TaskStateResult(1);
	}

	//应答函数
	Process_ClaimedTaskResponse(pMsg, pServerObj, pMessage);

}

//请求任务奖励17
void Process_RecTaskAwardRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RecTaskAwardRequest rectaskaward;

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//收到任务奖励请求 并将奖励的物品存入该用户的仓库里面(?物品的类型是什么,物品的数量是多少)
	rectaskaward.id();

	//应答函数
	Process_RecTaskAwardResponse(pMsg, pServerObj, pMessage);

}

//获取好友列表请求18
void Process_FriendsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//收到好友列表请求
	//FriendsRequest friendsreq;

	//friendsreq.friends();

	//应答函数
	Process_FriendsResponse(pMsg, pServerObj, pMessage);

}

//获取敌人列表请求19
void Process_EnemiesRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//EnemiesRequest enemreq;

	//收到敌人列表请求
	//enemreq.enemies();

	//应答函数
	Process_EnemiesResponse(pMsg, pServerObj, pMessage);

}

//随机掠夺请求20
void Process_PlunderRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//PlunderRequest ppluReq;

	// 得到消息连接ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//掠夺请求 小精灵的ID
	//ppluReq.elfinid();

	//收到掠夺请求 随机返回一个用户ID给客户端

	//应答函数
	Process_PlunderResponse(pMsg, pServerObj, pMessage);

}

//使用物品请求21
void Process_UseItemRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	UseItemRequest useitereq;

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];
	
	//收到使用物品请求 小精灵对神仙树使用物品,设置神仙树的数据,过后小精灵的当前体力值减少,
	// if(useitereq.itemid() == faitreUser->Get_Warehouse().map_warehouse[useitereq.itemid()]->Get_CArticleSerialNumber())
	//{
	//		faitreUser->Get_Warehouse().CloseArticle(useitereq.itemid());
	//		设置增加小精灵的各个属性
	useitereq.itemid();
	useitereq.elfinid();

	//应答函数
	Process_UseItemResponse(pMsg, pServerObj, pMessage);

}

//结账请求22
void Process_SettleAccountRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	SettleAccountRequest psetAccReq;

	//收到请求 返回数据
	psetAccReq.itemnum();
	psetAccReq.number();

	//应答函数
	Process_SettleAccountResponse(pMsg, pServerObj, pMessage);
	
}

//请求获取排行榜列表23
void Process_RankingRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	RankingRequest pranReq;

	//获取排行榜列表
	pranReq.ranking();

	//应答函数
	Process_RankingResponse(pMsg, pServerObj, pMessage);

}

//遗忘技能请求24
void Process_ForgetSkillRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	//收到请求
	ForgetSkillRequest pforSkiReq;

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//设置遗忘小精灵的技能
	faitreUser->Get_Elfin().map_elfin[pforSkiReq.elfinid()]->Set_EReduceSkillStyle(pforSkiReq.skillid());
	
	//应答函数
	Process_ForgetSkillResponse(pMsg, pServerObj, pMessage);

}

//注册请求25
void Process_RegisterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RegisterRequest pregReq;
	//bool isHaveAccount=false;
	//当收到请求时,对比数据库里是否有相同的账号名.如果有,就返回错误(账号已存在).
	//如果没有就将密码转换成MD5码,并且将(账号,密码,名字)存入数据库.并返回成功
	//if (isHaveAccount == FALSE)
	//{
		//TODO服务器分配id,并初始化所有数据,默认初始id,当前玩家数量+1,并保存在数据库,100000
	//}
	//else
	//{//TODO
		//定义一个用户类的对象,用来接收数据库中对应id的数据
		//关联连接id和用户类的对象指针,存入map里面
	//}
	//返回成功
	//uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类
	//FairyTreeUserClasses* faitreUser = new FairyTreeUserClasses();
	//CAllUserInfoInstance::GetInstance()->ConnetedUser[faitreUser->Get_RecordUserCount()] = faitreUser;
	//faitreUser->Set_UserId(1);
	//应答函数
	Process_RegisterResponse(pMsg, pServerObj, pMessage);

}

//太阳升级请求26
void Process_SolarUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//收到升级太阳的请求
	SolarUpgradeRequest solReq;
	
	//逻辑处理太阳升级
	solReq.solar();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];
	

	Process_SolarUpgradeResponse(pMsg, pServerObj, pMessage);
}

//技能升级请求27
void Process_SkillUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//收到技能升级请求
	SkillUpgradeRequest skiReq;

	//逻辑处理技能升级
	skiReq.elfinid();
	skiReq.skillid();
	
	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	Process_SkillUpgradeResponse(pMsg, pServerObj, pMessage);
}

//神仙树升级请求28
void Process_TreeUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//收到升级神仙树的请求
	TreeUpgradeRequest trReq;
	
	//逻辑处理神仙树的升级
	trReq.tree();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	Process_TreeUpgradeResponse(pMsg, pServerObj, pMessage);
}

//小精灵升级请求29
void Process_ElfinUpgradeRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//收到小精灵的升级请求
	ElfinUpgradeRequest elReq;

	//逻辑处理小精灵的升级
	elReq.elfinid();
	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	Process_ElfinUpgradeResponse(pMsg, pServerObj, pMessage);
}

//心跳包请求30
void Process_HeartBeatRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//不做任何处理
}


//------------------------------------------------------------------------------------------------------------


//应答
//登录应答1
void Process_LoginResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	LoginResponse* pLogin = pRes->release_login();
	pLogin = pRes->mutable_login();

	//设置返回为 成功 0
	pLogin->set_result(LoginResponse_ResultType_Success);	

	//设置消息应答(枚举 3001)
	gameMsg.set_msg(Login_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_50] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(msgLen), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//小精灵应答2
void Process_ElfinResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ElfinResponse* pelf = pRes->release_elfin();
	pelf = pRes->mutable_elfin();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(ID,等级,体力,最大体力,类型)
	pelf->set_id(faitreUser->Get_Elfin().Get_ID());
	pelf->set_level(faitreUser->Get_Elfin().Get_EGrade());
	pelf->set_power(faitreUser->Get_Elfin().Get_EPhysicalPower());
	pelf->set_maxpower(faitreUser->Get_Elfin().Get_EMaxPhysicalPower());
	switch (faitreUser->Get_Elfin().Get_ESkillStyle())
	{
	case ElfinType::EGOLD:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Jin);
		break;
	}
	case ElfinType::EWOOD:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Mu);
		break;
	}
	case ElfinType::EWATER:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Shui);
		break;
	}
	case ElfinType::EFIRE:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Huo);
		break;
	}
	case ElfinType::ESOIL:
	{
		pelf->set_etype(ElfinResponse_Elfintype_Tu);
		break;
	}
	}

	//设置消息应答(枚举  3011)
	gameMsg.set_msg(Elfin_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//角色信息应答3
void Process_RollResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RollResponse* proll = pRes->release_roll();
	proll = pRes->mutable_roll();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(ID,名字,成长值,图片的地址)
	proll->set_id(faitreUser->Get_Characlass().Get_Role_ID()); 
	proll->set_name(faitreUser->Get_Characlass().Get_Role_Name());
	proll->set_growrate(faitreUser->Get_Characlass().Get_RoleGrowthValue());
	//proll->set_headurl();


	//设置消息应答(枚举 3021)
	gameMsg.set_msg(Roll_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//神仙树应答4
void Process_TreeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeResponse* ptree = pRes->release_tree();
	ptree = pRes->mutable_tree();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(等级,经验,最大经验,每次生产的金币)
	ptree->set_level(faitreUser->Get_FairyTree().Get_FGrade());
	ptree->set_hight(faitreUser->Get_FairyTree().Get_TreeHeight());
	ptree->set_prodgold(faitreUser->Get_FairyTree().Get_FFaiTreStoGol());

	//设置消息应答(枚举 3031)
	gameMsg.set_msg(Tree_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//资源应答5
void Process_ResourceResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ResourceResponse* presres = pRes->release_resource();
	presres = pRes->mutable_resource();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(金币,普通水,阳光,钻石)
	presres->set_gold(faitreUser->Get_Gold().Get_GGoldNumber());
	presres->set_water(faitreUser->Get_Water().Get_WOrdinaryWater());
	presres->set_sunshine(faitreUser->Get_SunShine().Get_FSunNumber());
	presres->set_diamond(faitreUser->Get_UserDiamond());

	//设置消息应答(枚举 3041)
	gameMsg.set_msg(Resource_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);


}

//获取任务列表应答6
void Process_TasksResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TasksResponse* ptasks = pRes->release_tasks();
	ptasks = pRes->mutable_tasks();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];


	for (uint32 i = 0; i < faitreUser->Get_CTaskListClass().GetTaskCount(); ++i)
	{
		TaskClass* taskclass = faitreUser->Get_CTaskListClass().ErgodicTask(i);

		//组织应答消息内容(ID,标题,内容,类型,格式)
		ptasks->set_id(taskclass->Get_TSerialNumber());
		ptasks->set_title(taskclass->Get_TTaskheadline());
		ptasks->set_details(taskclass->Get_TTaskContent());
		switch (taskclass->Get_TaskStateResult())
		{
		case NotYet:
		{
			ptasks->set_type(TasksResponse_TaskType_NotYet);
			break;
		}
		case Already:
		{
			ptasks->set_type(TasksResponse_TaskType_Already);
			break;
		}
		case Done:
		{
			ptasks->set_type(TasksResponse_TaskType_Done);
			break;
		}
		case Received:
		{
			ptasks->set_type(TasksResponse_TaskType_Received);
			break;
		}
		}
		
		Prize* spr1 = new Prize();
		Prize* spr2 = new Prize();
		Prize* spr3 = new Prize();
		TaskInfo* pTaskInfo = XmlConfigManager::GetInstance()->TaskInfos[taskclass->Get_TSerialNumber()];

		if (NULL != pTaskInfo->bonusitemnumOne)
		{
			spr1->set_id(pTaskInfo->bonusitemnumOne);
			spr1->set_number(pTaskInfo->numberOne);
			ptasks->set_allocated_prize1(spr1);
		}

		if (NULL != pTaskInfo->bonusitemnumTwo)
		{
			spr2->set_id(pTaskInfo->bonusitemnumTwo);
			spr2->set_number(pTaskInfo->numberTwo);
			ptasks->set_allocated_prize2(spr2);
		}

		if (NULL != pTaskInfo->bonusitemnumThree)
		{
			spr3->set_id(pTaskInfo->bonusitemnumThree);
			spr3->set_number(pTaskInfo->numberThree);
			ptasks->set_allocated_prize3(spr3);
		}

		//设置消息应答(枚举 3051)
		gameMsg.set_msg(Tasks_Response);

		//得到长度
		uint32 msgLen = gameMsg.ByteSize();
		//序列化数据
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//将数据放入存储数据里面 立刻发送
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);

		delete[] spr1;
		delete[] spr2;
		delete[] spr3;
	}
}

//邮件应答7
void Process_MailsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	MailsResponse* pmail = pRes->release_mails();
	pmail = pRes->mutable_mails();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];
	
	for (uint32 i = 0; i < faitreUser->Get_CMailbox().MailNumber(); i++)
	{
		Mail* mail = faitreUser->Get_CMailbox().ErgodicMail(i);

		//组织应答消息内容(ID,标头,内容细节,发送结果,奖品的格式)
		pmail->set_id(mail->Get_MailSerialNumber());
		
		pmail->set_title(mail->Get_MailHeadline());
		
		pmail->set_details(mail->Get_MailContent());
		pmail->set_received(mail->MailArticleGetState());

		Prize* spr1 = new Prize();
		Prize* spr2 = new Prize();
		Prize* spr3 = new Prize();
		if (0 < mail->GetPrizes().size())
		{
			std::map<uint32, uint32>::iterator it = mail->GetPrizes().begin();
			spr1->set_id(it->first);
			spr1->set_number(it->second);
			pmail->set_allocated_prize1(spr1);
			it++;
			if (it!=mail->GetPrizes().end())
			{
				spr2->set_id(it->first);
				spr2->set_number(it->second);
				pmail->set_allocated_prize2(spr2);
				
			}
			it++;
			if (it != mail->GetPrizes().end())
			{
				spr3->set_id(it->first);
				spr3->set_number(it->second);
				pmail->set_allocated_prize3(spr3);
			}
		}
		//设置消息应答(枚举 3061)
		gameMsg.set_msg(Mails_Response);

		//得到长度
		uint32 msgLen = gameMsg.ByteSize();
		//序列化数据
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//将数据放入存储数据里面 立刻发送
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
		delete[] spr1;
		delete[] spr2;
		delete[] spr3;
	}

}

//太阳应答8
void Process_SunResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SunResponse* pwel = pRes->release_sun();
	pwel = pRes->mutable_sun();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(等级,阳光)
	pwel->set_level(faitreUser->Get_SunShine().Get_FGrade());
	pwel->set_sunshine(faitreUser->Get_SunShine().Get_FSunNumber());

	//设置消息应答(枚举 3071)
	gameMsg.set_msg(Sun_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);


}

//树结界应答9
void Process_TreeEnchantmentResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeEnchantmentResponse* ptreeench = pRes->release_treeenchantment();
	ptreeench = pRes->mutable_treeenchantment();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(树结界等级,防御)
	ptreeench->set_level(faitreUser->Get_TreeEnchantment().Get_TEGrade());
	ptreeench->set_defenselevel(faitreUser->Get_TreeEnchantment().Get_TEDefense());

	//设置消息应答(枚举 3081)
	gameMsg.set_msg(TreeEnchantment_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);


}

//获取商店所有物品应答10
void Process_StoreAllResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreAllResponse* pstoall = pRes->release_storeall();
	pstoall = pRes->mutable_storeall();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//for循环物品的数量 数量有多少就循环发送几次
	for (uint32 i = 0; i < faitreUser->Get_Shop().WarehouSize(); ++i)
	{
		CWarehouseArticle* cware = faitreUser->Get_Shop().Get_ArticleClass(i);
		//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型,描述,名字)
		pstoall->set_id(cware->Get_CArticleSerialNumber());
		pstoall->set_goldprice(cware->Get_CArticleGoldPrice());
		pstoall->set_diaprice(cware->Get_CArticleJewelPrice());
		pstoall->set_discount(cware->Get_CArticleDiscount());

		//设置消息应答(枚举 3091)
		gameMsg.set_msg(StoreAll_Response);

		//得到长度
		uint32 msgLen = gameMsg.ByteSize();
		//序列化数据
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//将数据放入存储数据里面 立刻发送
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
	}


}

//获取商店装备类物品应答11
void Process_StoreEquResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreEquResponse* pstoequ = pRes->release_storeequ();
	pstoequ = pRes->mutable_storeequ();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	uint32 utemp = 10002;//装备类ID
	for (int i = 0; i < faitreUser->Get_Shop().storeItemInfo.size(); ++i)
	{
		if (utemp == faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleSerialNumber())
		{
			//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型(装备类),描述,名字)
			pstoequ->set_id(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleSerialNumber());
			pstoequ->set_goldprice(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleGoldPrice());
			pstoequ->set_diaprice(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleJewelPrice());
			pstoequ->set_discount(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleDiscount());
			pstoequ->set_type(Res_Equip);
			break;
		}
	}

	//设置消息应答(枚举 3101)
	gameMsg.set_msg(StoreEqu_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//获取商店水资源类物品应答12
void Process_StoreWaterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreWaterResponse* pstowat = pRes->release_storewater();
	pstowat = pRes->mutable_storewater();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	uint32 utemp = 10001; //水资源类ID
	for (int i = 0; i < faitreUser->Get_Shop().storeItemInfo.size(); ++i)
	{
		if (utemp == faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleSerialNumber())
		{
			//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型(水资源类),描述,名字)
			pstowat->set_id(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleSerialNumber());
			pstowat->set_goldprice(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleGoldPrice());
			pstowat->set_diaprice(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleJewelPrice());
			pstowat->set_discount(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleDiscount());
			pstowat->set_type(Res_Water);
			break;
		}
	}
	
	//设置消息应答(枚举 3111)
	gameMsg.set_msg(StoreWater_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//获取商店特殊类物品应答13
void Process_StoreSpePropsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreSpePropsResponse* pstospe = pRes->release_storespeprops();
	pstospe = pRes->mutable_storespeprops();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	uint32 utemp = 10003; //特殊类ID
	for (int i = 0; i < faitreUser->Get_Shop().storeItemInfo.size(); ++i)
	{
		if (utemp == faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleSerialNumber())
		{
			//组织应答消息内容(ID,金币价格,钻石价格,折扣,类型(特殊类),描述,名字)
			pstospe->set_id(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleSerialNumber());
			pstospe->set_goldprice(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleGoldPrice());
			pstospe->set_diaprice(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleJewelPrice());
			pstospe->set_discount(faitreUser->Get_Shop().storeItemInfo[i]->Get_CArticleDiscount());
			pstospe->set_type(Res_SpeProps);
			break;
		}
	}

	//设置消息应答(枚举 3121)
	gameMsg.set_msg(StoreSpeProps_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//获取仓库所有物品应答14
void Process_WarehouseResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	WarehouseResponse* pwareh = pRes->release_warehouse();
	pwareh = pRes->mutable_warehouse();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];


	//水资源的id
	uint32 uwid = 10001;
	//装备的id
	uint32 ueid = 10002;
	//特殊道具的id
	uint32 usid = 10003;
	for (int i = 0; i < faitreUser->Get_Warehouse().map_warehouse.size(); ++i)
	{
		//组织应答消息内容(ID,数量)
		if (uwid == faitreUser->Get_Warehouse().map_warehouse[i]->Get_CArticleSerialNumber())
		{
			pwareh->set_id(faitreUser->Get_Warehouse().map_warehouse[i]->Get_CArticleSerialNumber());
			pwareh->set_number(faitreUser->Get_Warehouse().Get_ArticleToWaterCount());
		}
		if (ueid == faitreUser->Get_Warehouse().map_warehouse[i]->Get_CArticleSerialNumber())
		{
			pwareh->set_id(faitreUser->Get_Warehouse().map_warehouse[i]->Get_CArticleSerialNumber());
			pwareh->set_number(faitreUser->Get_Warehouse().Get_ArticleToEquipCount());
		}
		if (usid == faitreUser->Get_Warehouse().map_warehouse[i]->Get_CArticleSerialNumber())
		{
			pwareh->set_id(faitreUser->Get_Warehouse().map_warehouse[i]->Get_CArticleSerialNumber());
			pwareh->set_number(faitreUser->Get_Warehouse().Get_ArticleToSepProCount());
		}
		
		//设置消息应答(枚举 3131)
		gameMsg.set_msg(Warehouse_Response);

		//得到长度
		uint32 msgLen = gameMsg.ByteSize();
		//序列化数据
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//将数据放入存储数据里面 立刻发送
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
	}
	
}

//删除邮件应答15
void Process_DelMailResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	DelMailResponse* pdelmail = pRes->release_delmail();
	pdelmail = pRes->mutable_delmail();

	DelMailRequest delmail;

	//得到消息连接ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(结果bool,ID)
	pdelmail->set_success(true);
	pdelmail->set_id(delmail.id());

	//设置消息应答(枚举 3141)
	gameMsg.set_msg(DelMail_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//应答领取任务16
void Process_ClaimedTaskResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ClaimedTaskResponse* pclatask = pRes->release_claimedtask();
	pclatask = pRes->mutable_claimedtask();

	ClaimedTaskRequest clatask;

	//得到消息连接ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(结果bool,ID)
	pclatask->set_success(true);
	pclatask->set_id(clatask.id());

	//设置消息应答(枚举 3151)
	gameMsg.set_msg(ClaimedTask_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//应答任务奖励17
void Process_RecTaskAwardResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RecTaskAwardResponse* prectask = pRes->release_rectaskaward();
	prectask = pRes->mutable_rectaskaward();

	RecTaskAwardRequest rectaskaward;

	//得到消息连接ID
	//uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	//FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(ID编号,名字,描述,数量)
	prectask->set_success(true);
	prectask->set_id(rectaskaward.id());
	
	//设置消息应答(枚举 3161)
	gameMsg.set_msg(RecTaskAward_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//获取好友列表应答18
void Process_FriendsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	FriendsResponse* pfeds = pRes->release_friends();
	pfeds = pRes->mutable_friends();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	for (std::list<CharacterClass*>::iterator i = faitreUser->Get_Relation().Get_RelationRfriendRanking().begin();
		i != faitreUser->Get_Relation().Get_RelationRfriendRanking().end(); i++)
	{
		//组织应答消息内容(ID,名字,树的等级)
		pfeds->set_id((*i)->Get_Role_ID());
		pfeds->set_name((*i)->Get_Role_Name());
		pfeds->set_level((*i)->Get_TreeToGread());
		pfeds->set_headurl((*i)->Get_HaracterHeadPortraitSite());
		pfeds->set_growrate((*i)->Get_RoleGrowthValue());

		//设置消息应答(枚举 3171)
		gameMsg.set_msg(Friends_Response);

		//得到长度
		uint32 msgLen = gameMsg.ByteSize();
		uint32 len = msgLen + sizeof(uint32);
		//序列化数据
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//将数据放入存储数据里面 立刻发送
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
	}

}

//获取敌人列表应答19
void Process_EnemiesResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	EnemiesResponse* peneres = pRes->release_enemies();
	peneres = pRes->release_enemies();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	for (std::list<CharacterClass*>::iterator i = faitreUser->Get_Relation().Get_RelationRenemyRanking().begin();
		i != faitreUser->Get_Relation().Get_RelationRenemyRanking().end(); i++)
	{
		//组织应答消息内容(ID,名字,树的等级)
		peneres->set_id((*i)->Get_Role_ID());
		peneres->set_name((*i)->Get_Role_Name());
		peneres->set_level((*i)->Get_TreeToGread());
		peneres->set_headurl((*i)->Get_HaracterHeadPortraitSite());
		peneres->set_growrate((*i)->Get_RoleGrowthValue());

		//设置消息应答(枚举 3181)
		gameMsg.set_msg(Enemies_Response);

		//得到长度
		uint32 msgLen = gameMsg.ByteSize();
		uint32 len = msgLen + sizeof(uint32);
		//序列化数据
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//将数据放入存储数据里面 立刻发送
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);
	}

}

//抢夺应答20
void Process_PlunderResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	PlunderResponse* pplures = pRes->release_plunder();
	pplures = pRes->mutable_plunder();


	PlunderRequest ppluReq;
	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];
	
	//组织应答消息内容(抢夺结果,被掠夺者的ID,小精灵的ID,金币数量)
	pplures->set_success(true);
	srand((uint32)time(0));
	rand();//空随机一次
	//用户的初始ID好
	uint32 roleInitID = 10001;
	uint32 uid = 0;
	//如果当前的用户ID 等于 随机生成的用户ID
	uid = rand() % CAllUserInfoInstance::GetInstance()->ConnetedUser.size() + roleInitID;
	if (faitreUser->Get_Characlass().Get_Role_ID() == uid)
	{
		rand();
		uid = rand() % CAllUserInfoInstance::GetInstance()->ConnetedUser.size() + roleInitID;
	}
	pplures->set_id(uid);
	pplures->set_elfinid(ppluReq.elfinid());

	//设置消息应答(枚举 3191)
	gameMsg.set_msg(Plunder_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//使用物品应答21
void Process_UseItemResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	UseItemResponse* puseres = pRes->release_useitem();
	puseres = pRes->mutable_useitem();

	UseItemRequest useitereq;

	//组织应答消息内容(结果,请求里的物品ID,小精灵ID)
	puseres->set_success(true);
	puseres->set_id(useitereq.itemid());
	puseres->set_elfinid(useitereq.elfinid());

	//设置消息应答(枚举 3201)
	gameMsg.set_msg(UseItem_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//结账应答22
void Process_SettleAccountResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SettleAccountResponse* psetres = pRes->release_settleaccount();
	psetres = pRes->mutable_settleaccount();

	SettleAccountRequest psetAccReq;

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	//组织应答消息内容(结果,ID,数量,总的价格)
	psetres->set_success(true);
	psetres->set_id(psetAccReq.itemnum());
	psetres->set_number(psetAccReq.number());
	//返回总的金币的价格
	faitreUser->Get_Shop().ShopCloseAnGoldFun(psetAccReq.itemnum(),psetAccReq.number());
	uint32 uZGold = faitreUser->Get_Shop().Get_ShopBuyGoodsTotalPrice();
	psetres->set_goldprice(uZGold);
	//返回总的钻石的价格
	faitreUser->Get_Shop().ShopCloseAnJewelFun(psetAccReq.itemnum(), psetAccReq.number());
	uint32 uZJewel = faitreUser->Get_Shop().Get_ShopBuyGoodsTotalPrice();
	psetres->set_diaprice(uZJewel);

	//设置消息应答(枚举 3211)
	gameMsg.set_msg(SettleAccount_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//应答获取排行榜列表23
void Process_RankingResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RankingResponse* pranres = pRes->release_ranking();
	pranres = pRes->mutable_ranking();

	//得到消息连接ID
	uint32 uConId = pMessage->GetMessageBase()->m_u4ConnectID;
	//神仙树用户类指针 
	FairyTreeUserClasses* faitreUser = CAllUserInfoInstance::GetInstance()->ConnetedUser[uConId];

	uint32 urank = 1;//角色排名
	for (std::list<CharacterClass*>::iterator it = faitreUser->Get_RankingList().Get_Rankinglist().begin();
		it != faitreUser->Get_RankingList().Get_Rankinglist().end(); it++)
	{
		//组织应答消息内容(ID,名字,树的等级,该用户的排名)
		pranres->set_id((*it)->Get_Role_ID());
		pranres->set_name((*it)->Get_Role_Name());
		pranres->set_level((*it)->Get_TreeToGread());
		pranres->set_growrate((*it)->Get_RoleGrowthValue());
		pranres->set_ranking(urank);
		pranres->set_headurl((*it)->Get_HaracterHeadPortraitSite());

		//设置消息应答(枚举 3221)
		gameMsg.set_msg(Ranking_Response);

		//得到长度
		uint32 msgLen = gameMsg.ByteSize();
		uint32 len = msgLen + sizeof(uint32);
		//序列化数据
		char buff[MAX_BUFF_100] = { 0 };
		memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
		gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

		//将数据放入存储数据里面 立刻发送
		uint16 u2PostCommandID = COMMAND_BASE_ID;
		int nMessageID = 1;
		IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
		pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
		pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
			pbuffPacket,
			SENDMESSAGE_NOMAL,
			u2PostCommandID,
			PACKET_SEND_IMMEDIATLY,
			PACKET_IS_FRAMEWORK_RECYC,
			nMessageID);

		urank += 1; //角色排名
	}
	
}

//遗忘技能应答24
void Process_ForgetSkillResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ForgetSkillResponse* pforres = pRes->release_forgetskill();
	pforres = pRes->mutable_forgetskill();

	ForgetSkillRequest pforSkiReq;

	//组织应答消息内容(结果,ID)
	pforres->set_success(true);
	pforres->set_skillid(pforSkiReq.skillid());
	pforres->set_elfinid(pforSkiReq.elfinid());

	//设置消息应答(枚举 3231)
	gameMsg.set_msg(ForgetSkill_Response);

	//得到长度
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//注册应答25
void Process_RegisterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	/*GameMessage gameMsg;
	Response* presp = gameMsg.release_res();
	presp = gameMsg.mutable_res();
	RegisterResponse* pregister = presp->release_register_();
	pregister = presp->mutable_register_();*/

	//神仙树用户类
	//FairyTreeUserClasses* faitreUser;

	//组织应答消息内容(返回注册结果(0为成功,1为失败))
	//pregister->set_success(true);

	//设置消息应答(枚举 3241)
	//gameMsg.set_msg(Register_Response);


	//得到长度
	//uint32 msgLen = gameMsg.ByteSize();
	//uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	//char buff[MAX_BUFF_100] = { 0 };
	//memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	//gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	/*uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);*/
}

//太阳升级应答26
void Process_SolarUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	SolarUpgradeResponse* psol = pres->release_solarupgrade();
	psol = pres->mutable_solarupgrade();

	//组织应答消息内容(返回 0为失败 1 成功)
	psol->set_solar(true);

	//设置消息应答(枚举 3251)
	gamemsg.set_msg(SolarUpgrade_Response);

	//得到长度
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//技能升级应答27
void Process_SkillUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	SkillUpgradeResponse* skRes = pres->release_skillupgrade();
	skRes = pres->mutable_skillupgrade();

	SkillUpgradeRequest skiReq;
	//组织应答消息内容(返回 0为失败 1为成功, 小精灵的Id, 技能的ID)
	skRes->set_success(true);
	skRes->set_elfinid(skiReq.elfinid());
	skRes->set_skillid(skiReq.skillid());

	//设置消息应答(枚举 3261)
	gamemsg.set_msg(SkillUpgrade_Response);

	//得到长度
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//神仙树升级应答28
void Process_TreeUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	TreeUpgradeResponse* trRes = pres->release_treeupgrade();
	trRes = pres->mutable_treeupgrade();

	//组织应答消息内容(返回 0为失败 1为成功)
	trRes->set_success(true);

	//设置消息应答(枚举 3271)
	gamemsg.set_msg(TreeUpgrade_Response);

	//得到长度
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//小精灵升级应答29
void Process_ElfinUpgradeResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gamemsg;
	Response* pres = gamemsg.release_res();
	pres = gamemsg.mutable_res();
	ElfinUpgradeResponse* elRes = pres->release_elfinupgrade();
	elRes = pres->mutable_elfinupgrade();

	ElfinUpgradeRequest elReq;
	//组织应答消息内容(返回 0为失败 1为成功, 小精灵的ID)
	elRes->set_success(true);
	elRes->set_elfinid(elReq.elfinid());

	//设置消息应答(枚举 3281)
	gamemsg.set_msg(ElfinUpgrade_Response);

	//得到长度
	uint32 msgLen = gamemsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//序列化数据
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gamemsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//将数据放入存储数据里面 立刻发送
	uint16 u2PostCommandID = COMMAND_BASE_ID;
	int nMessageID = 1;
	IBuffPacket* pbuffPacket = pServerObj->GetPacketManager()->Create();
	pbuffPacket->WriteStream(buff, msgLen + sizeof(uint32));
	pServerObj->GetConnectManager()->PostMessage(pMessage->GetMessageBase()->m_u4ConnectID,
		pbuffPacket,
		SENDMESSAGE_NOMAL,
		u2PostCommandID,
		PACKET_SEND_IMMEDIATLY,
		PACKET_IS_FRAMEWORK_RECYC,
		nMessageID);

}

//心跳包应答30
void Process_HeartBeatResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	//不做任何处理
}

