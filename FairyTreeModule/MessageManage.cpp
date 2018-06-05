#include "MessageManage.h"
#include "ProcessMsg.h"

std::map<GameMsgCode, void(*)(const GameMessage& , CServerObject*, IMessage*)> CMessageManage::MsgMap;

CMessageManage::CMessageManage()
{
	Init();
}

void CMessageManage::Init()
{
	//����
	MsgMap[Login_Request] = Process_LoginRequest;                          //��¼����1
	MsgMap[Elfin_Request] = Process_ElfinRequest;						   //С��������2
	MsgMap[Roll_Request] = Process_RollRequest;							   //��ɫ��Ϣ����3
	MsgMap[Tree_Request] = Process_TreeRequest;							   //����������4
	MsgMap[Resource_Request] = Process_ResourceRequest;					   //��Դ����5
	MsgMap[Tasks_Request] = Process_TasksRequest;						   //�����ȡ�����б�6
	MsgMap[Mails_Request] = Process_MailsRequest;						   //�ʼ�����7
	MsgMap[Sun_Request] = Process_SunRequest;							   //��ȡ̫��������8
	MsgMap[TreeEnchantment_Request] = Process_TreeEnchantmentRequest;	   //���������9
	MsgMap[StoreAll_Request] = Process_StoreAllRequest;					   //��ȡ�̵�������Ʒ����10
	MsgMap[StoreEqu_Request] = Process_StoreEquRequest;					   //��ȡ�̵�װ������Ʒ����11
	MsgMap[StoreWater_Request] = Process_StoreWaterRequest;				   //��ȡ�̵�ˮ��Դ����Ʒ����12
	MsgMap[StoreSpeProps_Request] = Process_StoreSpePropsRequest;		   //��ȡ�̵���������Ʒ����13
	MsgMap[Warehouse_Request] = Process_WarehouseRequest;				   //��ȡ�ֿ�������Ʒ����14
	MsgMap[DelMail_Request] = Process_DelMailRequest;					   //ɾ���ʼ�����15
	MsgMap[ClaimedTask_Request] = Process_ClaimedTaskRequest;			   //������ȡ����16
	MsgMap[RecTaskAward_Request] = Process_RecTaskAwardRequest;			   //����������17
	MsgMap[Friends_Request] = Process_FriendsRequest;					   //��ȡ�����б�����18
	MsgMap[Enemies_Request] = Process_EnemiesRequest;					   //��ȡ�����б�����19
	MsgMap[Plunder_Request] = Process_PlunderRequest;					   //����Ӷ�����20
	MsgMap[UseItem_Request] = Process_UseItemRequest;					   //ʹ����Ʒ����21
	MsgMap[SettleAccount_Request] = Process_SettleAccountRequest;		   //��������22
	MsgMap[Ranking_Request] = Process_RankingRequest;					   //�����ȡ���а��б�23
	MsgMap[ForgetSkill_Request] = Process_ForgetSkillRequest;			   //������������24
	MsgMap[Register_Request] = Process_RegisterRequest;                    //ע������25

	//Ӧ��
	MsgMap[Login_Response] = Process_LoginResponse;                        //��¼Ӧ��1
	MsgMap[Elfin_Response] = Process_ElfinResponse;						   //С����Ӧ��2
	MsgMap[Roll_Response] = Process_RollResponse;						   //��ɫ��ϢӦ��3
	MsgMap[Tree_Response] = Process_TreeResponse;						   //������Ӧ��4
	MsgMap[Resource_Response] = Process_ResourceResponse;				   //��ԴӦ��5
	MsgMap[Tasks_Response] = Process_TasksResponse;						   //��ȡ�����б�Ӧ��6
	MsgMap[Mails_Response] = Process_MailsResponse;						   //�ʼ�Ӧ��7
	MsgMap[Sun_Response] = Process_SunResponse;						       //��ȡ̫����Ӧ��8
	MsgMap[TreeEnchantment_Response] = Process_TreeEnchantmentResponse;	   //�����Ӧ��9
	MsgMap[StoreAll_Response] = Process_StoreAllResponse;				   //��ȡ�̵�������ƷӦ��10
	MsgMap[StoreEqu_Response] = Process_StoreEquResponse;				   //��ȡ�̵�װ������ƷӦ��11
	MsgMap[StoreWater_Response] = Process_StoreWaterResponse;			   //��ȡ�̵�ˮ��Դ����ƷӦ��12
	MsgMap[StoreSpeProps_Response] = Process_StoreSpePropsResponse;		   //��ȡ�̵���������ƷӦ��13
	MsgMap[Warehouse_Response] = Process_WarehouseResponse;				   //��ȡ�ֿ�������ƷӦ��14
	MsgMap[DelMail_Response] = Process_DelMailResponse;					   //ɾ���ʼ�Ӧ��15
	MsgMap[ClaimedTask_Response] = Process_ClaimedTaskResponse;			   //Ӧ����ȡ����16
	MsgMap[RecTaskAward_Response] = Process_RecTaskAwardResponse;		   //Ӧ��������17
	MsgMap[Friends_Response] = Process_FriendsResponse;					   //��ȡ�����б�Ӧ��18
	MsgMap[Enemies_Response] = Process_EnemiesResponse;					   //��ȡ�����б�Ӧ��19
	MsgMap[Plunder_Response] = Process_PlunderResponse;					   //����Ӷ�Ӧ��20
	MsgMap[UseItem_Response] = Process_UseItemResponse;					   //ʹ����ƷӦ��21
	MsgMap[SettleAccount_Response] = Process_SettleAccountResponse;		   //����Ӧ��22
	MsgMap[Ranking_Response] = Process_RankingResponse;					   //Ӧ���ȡ���а��б�23
	MsgMap[ForgetSkill_Response] = Process_ForgetSkillResponse;			   //��������Ӧ��24
	MsgMap[Register_Response] = Process_RegisterResponse;                  //ע��Ӧ��25
	
}

bool CMessageManage::Dispose(const GameMessage& msg, CServerObject* pServerObj, IMessage* pMessage)
{
	bool bKet = false;
	auto iter = MsgMap.find(msg.msg());
	if (iter != MsgMap.end())
	{
		iter->second(msg, pServerObj, pMessage);
		bKet = true;
	}
	return bKet;
}

