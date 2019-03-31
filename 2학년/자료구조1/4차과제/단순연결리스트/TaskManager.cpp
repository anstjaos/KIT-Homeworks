#include "TaskManager.h"

void TaskManager::getMenu(Chain &c)
{
	int menu;
	
	cout << "==========================================" << endl;
	cout << "(1)   �� ���� �Է�" << endl;
	cout << "(2)   ���� ����" << endl;
	cout << "(3)   ������ ������ ��ü ���" << endl;
	cout << "(4)   ���Ͽ� �����ϰ� ����" << endl;
	cout << "==========================================" << endl;
	
	while (1)
	{
		cout << "���ϴ� ����� �����ϼ��� : ";
		cin >> menu;
		
		cin.ignore();
		switch (menu)
		{
		case 1:
			insertNode(c);
			break;
		case 2:
			deleteNode(c);
			break;
		case 3:
			c.printAll();
			break;
		case 4:
			cout << "�����մϴ�." << endl;
			return;
			break;
		default:
			cout << "�߸��� �޴��� �Է��ϼ̽��ϴ�!" << endl;
			break;
		}
	}
}

void TaskManager::insertNode(Chain &c)
{
	string bookNumber;
	string bookName;

	cout << "������ȣ�� �������� �Է��ϼ��� : ";
	getline(cin, bookNumber, ' ');
	getline(cin, bookName, '\n');
	
	Book b(bookNumber, bookName);
	if (c.checkNode(b))
	{
		cout << "�Է��� ������ȣ�� �̹� �����մϴ�!" << endl;
		return;
	}
	c.insertNode(b);
}

void TaskManager::deleteNode(Chain &c)
{
	string bookNumber;

	cout << "������ȣ�� �Է��ϼ��� : ";
	cin >> bookNumber;

	c.deleteNode(bookNumber);
}