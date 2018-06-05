#include "TaskClass.h"


//std::map<uint32, uint32> vecwareone;
TaskClass::TaskClass()
{
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
int TaskClass::Get_TSerialNumber()
{
	return tserialnumber;
}

//�����������
void TaskClass::Set_TTaskheadline(std::string ttn)
{
	staskheadline = ttn;
}

//��ȡ�������
string TaskClass::Get_TTaskheadline()
{
	return staskheadline;
}

//������������
void TaskClass::Set_TTaskContent(std::string ttc)
{
	staskcontent = ttc;
}

//��ȡ��������
string TaskClass::Get_TTaskContent()
{
	return staskcontent;
}

//����������(��Ʒ��ı�,(���,����))1
void TaskClass::Set_TTaskAwardOne(uint32 stta, uint32 unum)
{
	vecwareone.insert(pair<uint32, uint32>(stta,unum));
}

//��ȡ������(��Ʒ��ı�,(���,����))1
std::map<uint32, uint32> TaskClass::Get_TTaskAwardOne()
{
	return vecwareone;
}

//����������(��Ʒ��ı�,(���,����))2
void TaskClass::Set_TTaskAwardTwo(uint32 stta, uint32 unum)
{
	vecwaretwo.insert(pair<uint32, uint32>(stta, unum));
}

//��ȡ������(��Ʒ��ı�,(���,����))2
std::map<uint32, uint32> TaskClass::Get_TTaskAwardTwo()
{
	return vecwaretwo;
}

//����������(��Ʒ��ı�,(���,����))3
void TaskClass::Set_TTaskAwardThree(uint32 stta, uint32 unum)
{
	vecwarethree.insert(pair<uint32, uint32>(stta, unum));
}

//��ȡ������(��Ʒ��ı�,(���,����))3
std::map<uint32, uint32> TaskClass::Get_TTaskAwardThree()
{
	return vecwarethree;
}

//����״̬(result���)
TaskState TaskClass::TaskStateResult(uint32 utsr)
{
	//��������״̬
	switch (utsr)
	{
	case 0: {taskstate = NotYet; break; }
	case 1: {taskstate = Already; break; }
	case 2: {taskstate = Done; break; }
	case 3: {taskstate = Received; break; }
	}
	return taskstate;
}

//��������ǰ��ɶ�
void TaskClass::Set_TaskCurComp(uint32 stcc)
{
	taskCurComp += stcc;
}

//��ȡ����ǰ��ɶ�
int TaskClass::Get_TaskCurComp()
{
	return taskCurComp;
}

//���������ܵ���ɶ�
void TaskClass::Set_TaskSumUpComp(uint32 stsuc)
{
	taskSumUpComp = stsuc;
}

//��ȡ�����ܵ���ɶ�
int TaskClass::Get_TaskSumUpComp()
{
	return taskSumUpComp;
}



//�����б���
CTaskListClass::CTaskListClass()
{
}

CTaskListClass::~CTaskListClass()
{
}

//��������
void CTaskListClass::Add_Task(TaskClass * addtask)
{
	vectc.push_back(addtask);

}

//ɾ������
void CTaskListClass::Erase_Task(TaskClass * addtask)
{
	std::vector<TaskClass*>::iterator ittask = std::find(vectc.begin(), vectc.end(), addtask);
	if (ittask == vectc.end())
	{
		return;
	}
	else
	{
		vectc.erase(ittask);
	}

}

