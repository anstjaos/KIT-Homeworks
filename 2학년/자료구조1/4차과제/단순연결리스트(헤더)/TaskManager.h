#pragma once
#include "Chain.h"

class TaskManager
{
public:
	void taskMenu(Chain &c);			// �޴� ��°� �۾� ����
	void insertNode(Chain &c);			// ���� ��ȣ�� �������� �Է¹޾� ��ü ���� �� ��� ����
	void deleteNode(Chain &c);			// ���� ��ȣ�� �Է¹޾� ��� ����
};