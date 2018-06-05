#pragma once

#ifndef _TASE_CLASS_H
#define _TASK_CLASS_H

#include "define.h"
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
	int Get_TSerialNumber();

	//�����������
	void Set_TTaskheadline(std::string ttn);
	//��ȡ�������
	string Get_TTaskheadline();

	//������������
	void Set_TTaskContent(std::string ttc);
	//��ȡ��������
	string Get_TTaskContent();

	//����������(��Ʒ��ı�,(���,����))1
	void Set_TTaskAwardOne(uint32 stta, uint32 unum);
	//��ȡ������(��Ʒ��ı�,(���,����))1
	std::map<uint32, uint32> Get_TTaskAwardOne();
	//����������(��Ʒ��ı�,(���,����))2
	void Set_TTaskAwardTwo(uint32 stta, uint32 unum);
	//��ȡ������(��Ʒ��ı�,(���,����))2
	std::map<uint32, uint32> Get_TTaskAwardTwo();
	//����������(��Ʒ��ı�,(���,����))3
	void Set_TTaskAwardThree(uint32 stta, uint32 unum);
	//��ȡ������(��Ʒ��ı�,(���,����))3
	std::map<uint32, uint32> Get_TTaskAwardThree();

	//����״̬(result���)
	TaskState TaskStateResult(uint32 utsr);

	//��������ǰ��ɶ�
	void Set_TaskCurComp(uint32 stcc);
	//��ȡ����ǰ��ɶ�
	int Get_TaskCurComp();

	//���������ܵ���ɶ�
	void Set_TaskSumUpComp(uint32 stsuc);
	//��ȡ�����ܵ���ɶ�
	int Get_TaskSumUpComp();

private:
	//������
	uint32 tserialnumber;

	//�������
	std::string staskheadline;

	//��������
	std::string staskcontent;

	//������(��Ʒ��ı�,(���,����))1
	std::map<uint32,uint32> vecwareone;
	//������(��Ʒ��ı�,(���,����))2
	std::map<uint32, uint32> vecwaretwo;
	//������(��Ʒ��ı�,(���,����))3
	std::map<uint32, uint32> vecwarethree;

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
	void Add_Task(TaskClass* addtask);
	//ɾ������
	void Erase_Task(TaskClass* addtask);
private:
	//�����б�
	std::vector<TaskClass*> vectc;
};



#endif
