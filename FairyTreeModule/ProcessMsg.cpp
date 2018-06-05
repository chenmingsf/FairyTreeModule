#include "ProcessMsg.h"

//����
//��¼����1
void Process_LoginRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{	
	//���ȴӴ����ݿ���Ա�����
	LoginRequest logreq;

	//�ж��˺ź�����(����Ҫת����MD5���������ݿ����������жԱ�)�Ƿ���ȷ�����ؽ�����ͻ���
	logreq.account();

	char* pin = NULL;
	std::string pinput = logreq.passwd();
	uint32 ulen = pinput.length();
	memcpy_safe((char*)&pinput, (uint32)ulen, (char*)&pin, (uint32)ulen);
	char poutput[MAX_BUFF_50];
	CMD5 cmd5;
	cmd5.ENCODE_DATA(pin, ulen, poutput);
	

	//Ӧ����
	Process_LoginResponse(pMsg, pServerObj, pMessage);

}

//С��������2
void Process_ElfinRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	ElfinRequest pelfReq;
	//�յ����󷵻�����
	pelfReq.elfin();

	//Ӧ����
	Process_ElfinResponse(pMsg, pServerObj, pMessage);

}

//��ɫ��Ϣ����3
void Process_RollRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RollRequest rollreq;
	//�յ���ɫ��Ϣ����
	rollreq.roll();

	//Ӧ����
	Process_RollResponse(pMsg, pServerObj, pMessage);
}

//����������4
void Process_TreeRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	TreeRequest ptreReq;
	//�յ������������� ��������
	ptreReq.tree();

	//Ӧ����
	Process_TreeResponse(pMsg, pServerObj, pMessage);

}

//��Դ����5
void Process_ResourceRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	ResourceRequest rocrut;
	//�յ���Դ����
	rocrut.resource();

	//Ӧ����
	Process_ResourceResponse(pMsg, pServerObj, pMessage);
}

//��ȡ�����б�����6
void Process_TasksRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	TasksRequest ptasReq;
	//��ȡ�����б�����
	ptasReq.tasks();

	//Ӧ����
	Process_TasksResponse(pMsg, pServerObj, pMessage);
}

//�ʼ�����7
void Process_MailsRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	MailsRequest pmaiReq;
	//��ȡ�ʼ��б���Ϣ
	pmaiReq.mails();

	//Ӧ����
	Process_MailsResponse(pMsg, pServerObj, pMessage);

}

//̫������8
void Process_SunRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	SunRequest pwelReq;
	//�յ�̫�������� ��������
	pwelReq.sun();

	//Ӧ����
	Process_SunResponse(pMsg, pServerObj, pMessage);

}

//���������9
void Process_TreeEnchantmentRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	TreeEnchantmentRequest ptreEncReq;
	//�յ����� ��������
	ptreEncReq.well();

	//Ӧ����
	Process_TreeEnchantmentResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵�������Ʒ����10
void Process_StoreAllRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreAllRequest stoall;
	//�յ��̵�������Ʒ����
	stoall.storeall();

	//Ӧ����
	Process_StoreAllResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵�װ������Ʒ����11
void Process_StoreEquRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreEquRequest stoequ;
	//�յ��̵�װ������Ʒ����
	stoequ.storeequ();

	//Ӧ����
	Process_StoreEquResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵�ˮ��Դ����Ʒ����12
void Process_StoreWaterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreWaterRequest stowatreq;
	//�յ��̵�ˮ��Դ����Ʒ����
	stowatreq.storewater();

	//Ӧ����
	Process_StoreWaterResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�̵���������Ʒ����13
void Process_StoreSpePropsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	StoreSpePropsRequest stospeproreq;
	//�յ��̵���������Ʒ����
	stospeproreq.storespeprops();

	//Ӧ����
	Process_StoreSpePropsResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�ֿ�������Ʒ����14
void Process_WarehouseRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	WarehouseRequest warehreq;
	//�յ��ֿ�������Ʒ����
	warehreq.warehouse();

	//Ӧ����
	Process_WarehouseResponse(pMsg, pServerObj, pMessage);

}

//ɾ���ʼ�����15
void Process_DelMailRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	DelMailRequest delmail;
	//�յ�ɾ���ʼ�����
	delmail.id();

	//Ӧ����
	Process_DelMailResponse(pMsg, pServerObj, pMessage);

}

//������ȡ����16
void Process_ClaimedTaskRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	ClaimedTaskRequest clatask;
	//�յ���ȡ��������
	clatask.id();

	//Ӧ����
	Process_ClaimedTaskResponse(pMsg, pServerObj, pMessage);

}

//����������17
void Process_RecTaskAwardRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RecTaskAwardRequest rectaskaward;
	//�յ�����������
	rectaskaward.id();

	//Ӧ����
	Process_RecTaskAwardResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�����б�����18
void Process_FriendsRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	FriendsRequest friendsreq;
	//�յ������б�����
	friendsreq.friends();

	//Ӧ����
	Process_FriendsResponse(pMsg, pServerObj, pMessage);

}

//��ȡ�����б�����19
void Process_EnemiesRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	EnemiesRequest enemreq;
	//�յ������б�����
	enemreq.enemies();

	//Ӧ����
	Process_EnemiesResponse(pMsg, pServerObj, pMessage);

}

//����Ӷ�����20
void Process_PlunderRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	PlunderRequest ppluReq;
	//�Ӷ�����
	ppluReq.plunder();

	//Ӧ����
	Process_PlunderResponse(pMsg, pServerObj, pMessage);

}

//ʹ����Ʒ����21
void Process_UseItemRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	UseItemRequest useitereq;
	//�յ�ʹ����Ʒ����
	useitereq.id();

	//Ӧ����
	Process_UseItemResponse(pMsg, pServerObj, pMessage);

}

//��������22
void Process_SettleAccountRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	SettleAccountRequest psetAccReq;
	//�յ����� ��������
	psetAccReq.itemnum();
	psetAccReq.number();

	//Ӧ����
	Process_SettleAccountResponse(pMsg, pServerObj, pMessage);
	
}

//�����ȡ���а��б�23
void Process_RankingRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	RankingRequest pranReq;
	//��ȡ���а��б�
	pranReq.ranking();

	//Ӧ����
	Process_RankingResponse(pMsg, pServerObj, pMessage);

}

//������������24
void Process_ForgetSkillRequest(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	ForgetSkillRequest pforSkiReq;
	//�յ�����
	pforSkiReq.skillid();
	pforSkiReq.elfinid();

	//Ӧ����
	Process_ForgetSkillResponse(pMsg, pServerObj, pMessage);

}

//ע������25
void Process_RegisterRequest(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	RegisterRequest pregReq;
	//���յ�����ʱ,�Ա����ݿ����Ƿ�����ͬ���˺���.�����,�ͷ��ش���(�˺��Ѵ���).
	//���û�оͽ�����ת����MD5��,���ҽ��˺ź�����������ݿ�.�����سɹ�
	pregReq.account();

	char* pin = NULL;
	std::string pinput = pregReq.passwd();
	uint32 ulen = pinput.length();
	memcpy_safe((char*)&pinput, (uint32)ulen, (char*)&pin, (uint32)ulen);
	char poutput[MAX_BUFF_50];
	CMD5 cmd5;
	cmd5.ENCODE_DATA(pin,ulen,poutput);
	

	//Ӧ����
	Process_RegisterResponse(pMsg, pServerObj, pMessage);

}


//------------------------------------------------------------------------------------------------------------


//Ӧ��
//��¼Ӧ��1
void Process_LoginResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	LoginResponse* pLogin = pRes->release_login();
	pLogin = pRes->mutable_login();
	
	//���ؽ�� 0Ϊ�ɹ� 1Ϊ�˺Ż�������� 2Ϊδ֪����

	//�����ݿ���Ա�����
	std::string sname("admin");
	std::string spasswd("123456");

	if (sname == pMsg.req().login().account() && spasswd == pMsg.req().login().passwd())
	{
		//���÷���Ϊ �ɹ� 0
		pLogin->set_result(LoginResponse_ResultType_Success);
	}
	else
	{
		//���÷���Ϊ �˺Ż�������� 1
		pLogin->set_result(LoginResponse_ResultType_PsswadError);
	}

	//������ϢӦ��(ö�� 3001)
	gameMsg.set_msg(Login_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_50] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(msgLen), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//С����Ӧ��2
void Process_ElfinResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ElfinResponse* pelf = pRes->release_elfin();
	pelf = pRes->mutable_elfin();

	//���������û���Ϣ
	//FairyTreeUserClasses* user;
	//��֯Ӧ����Ϣ����(�ȼ�,����,�����,����,�������,����)
	pelf->set_id(123456);
	pelf->set_level(1);
	pelf->set_power(100);
	pelf->set_maxpower(100);
	pelf->set_etype(ElfinResponse_Elfintype_Jin);
	
	

	//������ϢӦ��(ö��  3011)
	gameMsg.set_msg(Elfin_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ɫ��ϢӦ��3
void Process_RollResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RollResponse* proll = pRes->release_roll();
	proll = pRes->mutable_roll();

	//��֯Ӧ����Ϣ����(ID,����)
	proll->set_id(12);                        
	std::string sname("JueSeXiaoXiYingDa");    
	proll->set_name(sname);                   



	//������ϢӦ��(ö�� 3021)
	gameMsg.set_msg(Roll_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//������Ӧ��4
void Process_TreeResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeResponse* ptree = pRes->release_tree();
	ptree = pRes->mutable_tree();

	//��֯Ӧ����Ϣ����(�ȼ�,����,�����,ÿ�������Ľ��)
	ptree->set_level(1);
	ptree->set_hight(1);
	ptree->set_prodgold(5);  

	//������ϢӦ��(ö�� 3031)
	gameMsg.set_msg(Tree_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ԴӦ��5
void Process_ResourceResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ResourceResponse* presres = pRes->release_resource();
	presres = pRes->mutable_resource();

	//��֯Ӧ����Ϣ����(���,��ͨˮ,����ˮ)
	presres->set_gold(10);
	presres->set_water(20);
	presres->set_sunshine(1);
	presres->set_diamond(1);

	//������ϢӦ��(ö�� 3041)
	gameMsg.set_msg(Resource_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�����б�Ӧ��6
void Process_TasksResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TasksResponse* ptasks = pRes->release_tasks();
	ptasks = pRes->mutable_tasks();

	//��֯Ӧ����Ϣ����(ID,����,����,����,��ʽ)
	ptasks->set_id(123456);
	std::string name("RenWuLieBiao");
	ptasks->set_title(name);
	std::string sn("HelloWorld");
	ptasks->set_details(sn);
	ptasks->set_type(TasksResponse_TaskType_Received);
	Prize* spr;
	ptasks->set_allocated_prize1(spr);
	ptasks->set_allocated_prize2(spr);
	ptasks->set_allocated_prize3(spr);

	//������ϢӦ��(ö�� 3051)
	gameMsg.set_msg(Tasks_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//�ʼ�Ӧ��7
void Process_MailsResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	MailsResponse* pmail = pRes->release_mails();
	pmail = pRes->mutable_mails();

	//��֯Ӧ����Ϣ����(ID,��ͷ,����ϸ��,���ͽ��,��Ʒ�ĸ�ʽ)
	pmail->set_id(10000001);
	std::string sname("YouJian");
	pmail->set_title(sname);
	std::string sn("HelloYouJian");
	pmail->set_details(sn);
	pmail->set_received(true);
	Prize* spr;
	pmail->set_allocated_prize1(spr);
	pmail->set_allocated_prize2(spr);
	pmail->set_allocated_prize3(spr);

	//������ϢӦ��(ö�� 3061)
	gameMsg.set_msg(Mails_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//̫��Ӧ��8
void Process_SunResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SunResponse* pwel = pRes->release_sun();
	pwel = pRes->mutable_sun();

	//��֯Ӧ����Ϣ����(�ȼ�,����)
	pwel->set_level(1);
	pwel->set_sunshine(1);

	//������ϢӦ��(ö�� 3071)
	//gameMsg.set_msg(Well_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//�����Ӧ��9
void Process_TreeEnchantmentResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	TreeEnchantmentResponse* ptreeench = pRes->release_treeenchantment();
	ptreeench = pRes->mutable_treeenchantment();

	//��֯Ӧ����Ϣ����(������״̬,����״̬)
	ptreeench->set_level(1);
	ptreeench->set_defenselevel(1); 

	//������ϢӦ��(ö�� 3081)
	gameMsg.set_msg(TreeEnchantment_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�̵�������ƷӦ��10
void Process_StoreAllResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreAllResponse* pstoall = pRes->release_storeall();
	pstoall = pRes->mutable_storeall();

	//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����,����,����)
	pstoall->set_id(1234);
	pstoall->set_goldprice(11);
	pstoall->set_diaprice(10);
	pstoall->set_discount(9);
	StdMode stdmode;
	pstoall->set_type(stdmode);
	std::string sds("�̵�������Ʒ:ˮ,װ��,�������");
	pstoall->set_describe(sds);
	std::string name("SuoYouWuPing");
	pstoall->set_name(name);

	//������ϢӦ��(ö�� 3091)
	gameMsg.set_msg(StoreAll_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�̵�װ������ƷӦ��11
void Process_StoreEquResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreEquResponse* pstoequ = pRes->release_storeequ();
	pstoequ = pRes->mutable_storeequ();

	//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����(װ����),����,����)
	pstoequ->set_id(101);
	pstoequ->set_goldprice(1000);
	pstoequ->set_diaprice(200);
	pstoequ->set_discount(95);
	pstoequ->set_type(Res_Equip);
	std::string sds("�̵���Ʒ:װ����");
	pstoequ->set_describe(sds);
	std::string name("ZhuangBei");
	pstoequ->set_name(name);

	//������ϢӦ��(ö�� 3101)
	gameMsg.set_msg(StoreEqu_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�̵�ˮ��Դ����ƷӦ��12
void Process_StoreWaterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreWaterResponse* pstowat = pRes->release_storewater();
	pstowat = pRes->mutable_storewater();

	//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����(ˮ��Դ��),����,����)
	pstowat->set_id(100);
	pstowat->set_goldprice(500);
	pstowat->set_diaprice(50);
	pstowat->set_discount(95);
	pstowat->set_type(Res_Water);
	std::string sds("�̵���Ʒ:ˮ��Դ��");
	pstowat->set_describe(sds);
	std::string name("ShuiZiYuan");
	pstowat->set_name(name);

	//������ϢӦ��(ö�� 3111)
	gameMsg.set_msg(StoreWater_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�̵���������ƷӦ��13
void Process_StoreSpePropsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	StoreSpePropsResponse* pstospe = pRes->release_storespeprops();
	pstospe = pRes->mutable_storespeprops();

	//��֯Ӧ����Ϣ����(ID,��Ҽ۸�,��ʯ�۸�,�ۿ�,����(������),����,����)
	pstospe->set_id(102);
	pstospe->set_goldprice(124);
	pstospe->set_diaprice(62);
	pstospe->set_discount(95);
	pstospe->set_type(Res_SpeProps);
	std::string sds("�̵���Ʒ:������");
	pstospe->set_describe(sds);
	std::string sname("TeShuDaoJu");
	pstospe->set_name(sname);

	//������ϢӦ��(ö�� 3121)
	gameMsg.set_msg(StoreSpeProps_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�ֿ�������ƷӦ��14
void Process_WarehouseResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	WarehouseResponse* pwareh = pRes->release_warehouse();
	pwareh = pRes->mutable_warehouse();

	//��֯Ӧ����Ϣ����(ID,����,����)
	pwareh->set_id(996);
	pwareh->set_number(1);
	
	//������ϢӦ��(ö�� 3131)
	gameMsg.set_msg(Warehouse_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//ɾ���ʼ�Ӧ��15
void Process_DelMailResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	DelMailResponse* pdelmail = pRes->release_delmail();
	pdelmail = pRes->mutable_delmail();

	//��֯Ӧ����Ϣ����(���,ID)
	pdelmail->set_success(true);
	pdelmail->set_id(135);

	//������ϢӦ��(ö�� 3141)
	gameMsg.set_msg(DelMail_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//Ӧ����ȡ����16
void Process_ClaimedTaskResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ClaimedTaskResponse* pclatask = pRes->release_claimedtask();
	pclatask = pRes->mutable_claimedtask();

	//��֯Ӧ����Ϣ����(���,ID)
	pclatask->set_success(true);
	pclatask->set_id(456);

	//������ϢӦ��(ö�� 3151)
	gameMsg.set_msg(ClaimedTask_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&msgLen, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//Ӧ��������17
void Process_RecTaskAwardResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RecTaskAwardResponse* prectask = pRes->release_rectaskaward();
	prectask = pRes->mutable_rectaskaward();

	//��֯Ӧ����Ϣ����(ID���,����,����,����)
	Prize* spr;
	prectask->set_allocated_prize1(spr);
	prectask->set_allocated_prize2(spr);
	prectask->set_allocated_prize3(spr);
	

	//������ϢӦ��(ö�� 3161)
	gameMsg.set_msg(RecTaskAward_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�����б�Ӧ��18
void Process_FriendsResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	FriendsResponse* pfeds = pRes->release_friends();
	pfeds = pRes->mutable_friends();

	//��֯Ӧ����Ϣ����(ID,����,���ĵȼ�)
	pfeds->set_id(333);
	std::string name("FriendsName");
	pfeds->set_name(name);
	pfeds->set_level(1);

	//������ϢӦ��(ö�� 3171)
	gameMsg.set_msg(Friends_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��ȡ�����б�Ӧ��19
void Process_EnemiesResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	EnemiesResponse* peneres = pRes->release_enemies();
	peneres = pRes->release_enemies();

	//��֯Ӧ����Ϣ����(ID,����,���ĵȼ�)
	peneres->set_id(444);
	std::string name("EnemiesName");
	peneres->set_name(name);
	peneres->set_level(1);

	//������ϢӦ��(ö�� 3181)
	gameMsg.set_msg(Enemies_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//����Ӧ��20
void Process_PlunderResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	PlunderResponse* pplures = pRes->release_plunder();
	pplures = pRes->mutable_plunder();

	//��֯Ӧ����Ϣ����(���,ID,�������)
	pplures->set_success(true);
	pplures->set_id(798);
	pplures->set_goldnum(22);

	//������ϢӦ��(ö�� 3191)
	gameMsg.set_msg(Plunder_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//ʹ����ƷӦ��21
void Process_UseItemResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	UseItemResponse* puseres = pRes->release_useitem();
	puseres = pRes->mutable_useitem();

	//��֯Ӧ����Ϣ����(���,ID)
	puseres->set_success(true);
	puseres->set_id(112233);

	//������ϢӦ��(ö�� 3201)
	gameMsg.set_msg(UseItem_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//����Ӧ��22
void Process_SettleAccountResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	SettleAccountResponse* psetres = pRes->release_settleaccount();
	psetres = pRes->mutable_settleaccount();

	//��֯Ӧ����Ϣ����(���,ID,����,�ܵļ۸�)
	psetres->set_success(true);
	psetres->set_id(755555);
	psetres->set_number(9);
	psetres->set_price(13579);

	//������ϢӦ��(ö�� 3211)
	gameMsg.set_msg(SettleAccount_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//Ӧ���ȡ���а��б�23
void Process_RankingResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	RankingResponse* pranres = pRes->release_ranking();
	pranres = pRes->mutable_ranking();

	//��֯Ӧ����Ϣ����(ID,����,���ĵȼ�,���û�������)
	pranres->set_id(987654321);
	std::string name("���а��б�");
	pranres->set_name(name);
	pranres->set_level(1);
	pranres->set_ranking(1);

	//������ϢӦ��(ö�� 3221)
	gameMsg.set_msg(Ranking_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//��������Ӧ��24
void Process_ForgetSkillResponse(const GameMessage& pMsg, CServerObject* pServerObj, IMessage* pMessage)
{
	GameMessage gameMsg;
	Response* pRes = gameMsg.release_res();
	pRes = gameMsg.mutable_res();
	ForgetSkillResponse* pforres = pRes->release_forgetskill();
	pforres = pRes->mutable_forgetskill();

	//��֯Ӧ����Ϣ����(���,ID)
	pforres->set_success(true);
	pforres->set_skillid(123);
	pforres->set_elfinid(345);

	//������ϢӦ��(ö�� 3231)
	gameMsg.set_msg(ForgetSkill_Response);

	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

//ע��Ӧ��25
void Process_RegisterResponse(const GameMessage & pMsg, CServerObject * pServerObj, IMessage * pMessage)
{
	GameMessage gameMsg;
	Response* presp = gameMsg.release_res();
	presp = gameMsg.mutable_res();
	RegisterResponse* pregister = presp->release_register_();
	pregister = presp->mutable_register_();

	//��֯Ӧ����Ϣ����(����ע����(0Ϊ�ɹ�,1Ϊʧ��))
	pregister->set_success(true);

	//������ϢӦ��(ö�� 3241)
	gameMsg.set_msg(Register_Response);


	//�õ�����
	uint32 msgLen = gameMsg.ByteSize();
	uint32 len = msgLen + sizeof(uint32);
	//���л�����
	char buff[MAX_BUFF_100] = { 0 };
	memcpy_safe((char*)&len, sizeof(uint32), (char*)buff, sizeof(uint32));
	gameMsg.SerializeToArray(buff + sizeof(uint32), msgLen);

	//�����ݷ���洢�������� ���̷���
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

