#include "TaskClass.h"


TaskClass::TaskClass()
{
	m_roleID = 0;//�û�ID

	tserialnumber = 0; //������

	staskheadline = ""; //�������

	staskcontent = ""; //��������

	taskstate = NotYet; //����״̬

	taskCurComp = 0; //����ǰ��ɶ�

	taskSumUpComp = 0; //��������ɶ�
}


TaskClass::~TaskClass()
{
}

//����������
void TaskClass::Set_TSerialNumber(uint32 tsn)
{
	tserialnumber = tsn;
}

// ��ȡ������
uint32 TaskClass::Get_TSerialNumber()
{
	return tserialnumber;
}

//�����������
void TaskClass::Set_TTaskheadline(const std::string& ttn)
{
	staskheadline = ttn;
}

//��ȡ�������
std::string TaskClass::Get_TTaskheadline()
{
	return staskheadline;
}

//������������
void TaskClass::Set_TTaskContent(const std::string& ttc)
{
	staskcontent = ttc;
}

//��ȡ��������
std::string TaskClass::Get_TTaskContent()
{
	return staskcontent;
}

//����������(��Ʒ��ı�,(���,����))
void TaskClass::Set_TTaskAward(uint32 stta, uint32 unum)
{
	mapware[stta] = unum;
}

//��ȡ������(��Ʒ��ı�,(���,����))
std::map<uint32, uint32> TaskClass::Get_TTaskAward()
{
	return mapware;
}

//����״̬(result���)
void TaskClass::Set_TaskStateResult(uint32 num)
{
	//��������״̬
	switch (num)
	{
	case 0: { taskstate = NotYet; break; }
	case 1: { taskstate = Already; break; }
	case 2: { taskstate = Done; break; }
	case 3: { taskstate = Received; break; }
	}
}

//��ȡ����״̬(result���)
TaskState TaskClass::Get_TaskStateResult()
{
	return taskstate;
}

//��������ǰ��ɶ�
void TaskClass::Set_TaskCurComp(uint32 stcc)
{
	taskCurComp += stcc;
}

//��ȡ����ǰ��ɶ�
uint32 TaskClass::Get_TaskCurComp()
{
	return taskCurComp;
}

//���������ܵ���ɶ�
void TaskClass::Set_TaskSumUpComp(uint32 stsuc)
{
	taskSumUpComp = stsuc;
}

//��ȡ�����ܵ���ɶ�
uint32 TaskClass::Get_TaskSumUpComp()
{
	return taskSumUpComp;
}

//�����û�ID
void TaskClass::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//��ȡ�û�ID
uint32 TaskClass::Get_RoleID()
{
	return m_roleID;
}



//�����б���
CTaskListClass::CTaskListClass()
{
	m_roleID = 0;//�û�ID
	taskc = new TaskClass;
}

CTaskListClass::~CTaskListClass()
{
	delete taskc;
}

//��������
void CTaskListClass::Add_Task(uint32 uid)
{
	map_task[uid] = taskc;

}

//ɾ������
void CTaskListClass::Erase_Task(uint32 uid)
{
	for (std::map<uint32, TaskClass*>::iterator ittask = map_task.begin(); ittask != map_task.end(); ittask++)
	{
		if (uid == ittask->second->Get_TSerialNumber())
		{
			map_task.erase(ittask);
		}
	}

}


//��������
TaskClass * CTaskListClass::ErgodicTask(uint32 index)
{
	return map_task[index];
}

//�����û�ID
void CTaskListClass::Set_RoleID(uint32 uid)
{
	m_roleID = uid;
}

//��ȡ�û�ID
uint32 CTaskListClass::Get_RoleID()
{
	return m_roleID;
}

