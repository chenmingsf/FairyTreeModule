#pragma once

#ifndef _TASE_CLASS_H
#define _TASK_CLASS_H

#include "Gamedefine.h"
#include "Warehouse.h"
#include <map>

enum TaskState
{
	//δ��ȡ
	NotYet,
	//�Ѿ���ȡ
	Already,
	//�����
	Done,
	//�Ѿ���ȡ��Ʒ
	Received
};


//������
class TaskClass
{
public:
	TaskClass();
	~TaskClass();
	//����������
	void Set_TSerialNumber(uint32 tsn);
	// ��ȡ������
	uint32 Get_TSerialNumber();

	//�����������
	void Set_TTaskheadline(const std::string& ttn);
	//��ȡ�������
	std::string Get_TTaskheadline();

	//������������
	void Set_TTaskContent(const std::string& ttc);
	//��ȡ��������
	std::string Get_TTaskContent();

	//����������(��Ʒ��ı�,(���,����))
	void Set_TTaskAward(uint32 stta, uint32 unum);
	//��ȡ������(��Ʒ��ı�,(���,����))
	std::map<uint32, uint32> Get_TTaskAward();

	//��������״̬(result���)
	void Set_TaskStateResult(uint32 num);
	//��ȡ����״̬(result���)
	TaskState Get_TaskStateResult();

	//��������ǰ��ɶ�
	void Set_TaskCurComp(uint32 stcc);
	//��ȡ����ǰ��ɶ�
	uint32 Get_TaskCurComp();

	//���������ܵ���ɶ�
	void Set_TaskSumUpComp(uint32 stsuc);
	//��ȡ�����ܵ���ɶ�
	uint32 Get_TaskSumUpComp();

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

private:

	//�û�ID
	uint32 m_roleID;

	//������
	uint32 tserialnumber;

	//�������
	std::string staskheadline;

	//��������
	std::string staskcontent;

	//������(��Ʒ��ı�,(���,����))
	std::map<uint32,uint32> mapware;
	

	//����״̬
	TaskState taskstate;

	//����ǰ��ɶ�
	uint32 taskCurComp;

	//��������ɶ�
	uint32 taskSumUpComp;

};


//�����б���
class CTaskListClass
{
public:
	CTaskListClass();
	~CTaskListClass();
	//��������
	void Add_Task(uint32 uid);
	//ɾ������
	void Erase_Task(uint32 uid);
	//��������
	TaskClass* ErgodicTask(uint32 uid);
	//�������
	uint32 GetTaskCount() { return (uint32)map_task.size(); }

	//�����û�ID
	void Set_RoleID(uint32 uid);
	//��ȡ�û�ID
	uint32 Get_RoleID();

	//������map
	std::map<uint32, TaskClass*> map_task;

	TaskClass * taskc;
private:

	//�û�ID
	uint32 m_roleID;
	
	
};



#endif
