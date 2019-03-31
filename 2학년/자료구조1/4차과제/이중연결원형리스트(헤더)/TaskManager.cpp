#include "TaskManager.h"

void TaskManager::taskMenu(DblList &dl)
{
	int menu;

	cout << "==========================================" << endl;
	cout << "(1)   �� ���� �Է�" << endl;
	cout << "(2)   ���� ����" << endl;
	cout << "(3)   ������ ������ ��ü ���" << endl;
	cout << "(4)   ������ �������� ��ü ���" << endl;
	cout << "(5)   Ư�� ��������� ��ü ���" << endl;
	cout << "(6)   Ư�� ��������� ù ��������� ���� ���" << endl;
	cout << "(7)   ���Ͽ� �����ϰ� ����" << endl;
	cout << "==========================================" << endl;

	while (1)
	{
		cout << "���ϴ� ����� �����ϼ��� : ";
		cin >> menu;

		cin.ignore();
		switch (menu)
		{
		case 1:
			insertNode(dl);
			break;
		case 2:
			deleteNode(dl);
			break;
		case 3:
			dl.showInOrder();
			break;
		case 4:
			dl.showReverse();
			break;
		case 5:
			showSpecific(dl);
			break;
		case 6:
			showSpecificReverse(dl);
			break;
		case 7:
			cout << "�����մϴ�." << endl;
			return;
			break;
		default:
			cout << "�߸��� �޴��� �Է��ϼ̽��ϴ�!" << endl;
			break;
		}
	}
}

void TaskManager::insertNode(DblList &dl)
{
	string bookNumber;
	string bookName;

	cout << "���� ��ȣ�� �������� �Է��ϼ���. ";
	getline(cin, bookNumber, ' ');
	getline(cin, bookName, '\n');
	Book b(bookNumber, bookName);
	if (dl.checkNode(b))
	{
		cout << "�Է��Ͻ� ������ȣ�� �̹� �����մϴ�!" << endl;
		return;
	}
	dl.insertNode(b);
}

void TaskManager::deleteNode(DblList &dl)
{
	string bookNumber;

	cout << "���� ��ȣ�� �Է��ϼ���. ";
	cin >> bookNumber;
	dl.deleteNode(bookNumber);
}

void TaskManager::showSpecific(DblList &dl)
{
	string bookName;
	DblListNode *ptr;

	cout << "�������� �Է��ϼ���. ";
	getline(cin, bookName, '\n');
	ptr = dl.findNode(bookName);
	if (ptr == NULL) return;
	dl.showSpecific(ptr);
}

void TaskManager::showSpecificReverse(DblList &dl)
{
	string bookName;
	DblListNode *ptr;

	cout << "�������� �Է��ϼ���. ";
	getline(cin, bookName, '\n');
	ptr = dl.findNode(bookName);
	if (ptr == NULL) return;
	dl.showSpecificReverse(ptr);
}