#pragma once
#include "Chain.h"

class TaskManager
{
public:
	void getMenu(Chain &c);				// �޴� ��°� �۾� ����
	void insertNode(Chain &c);			// ������ȣ�� �������� �Է¹޾� Book ��ü ���� �� ��� ����
	void deleteNode(Chain &c);			// ������ȣ�� �Է¹޾� ��� ����
};