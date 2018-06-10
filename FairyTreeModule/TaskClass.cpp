#include "TaskClass.h"


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
TaskState TaskClass::TaskStateResult()
{
	//��������״̬
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
	taskc = new TaskClass;
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


//��������
TaskClass * CTaskListClass::ErgodicTask(uint32 index)
{
	return vectc[index];
}

