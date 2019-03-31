#include "DblList.h"

DblList::DblList()
{
	Book b;
	head = new DblListNode(b,0, 0);
	head->left = head;
	head->right = head;					// ��� ����� left�� right�� �ڱ� �ڽ��� ����Ű�� �Ѵ�.
	first = head;
}

DblList::~DblList()
{
	if (first == head)					// first�� ��� ��带 ����Ű�� ���� ���
	{
		delete first;
		return;
	}
	for(DblListNode *temp = first->right; temp !=head; temp = temp->right)
	{
		delete first;
		first = temp;
	}
	delete first;
	delete head;
}

bool DblList :: checkNode(Book b)
{
	for (DblListNode *ptr = first; ptr != head; ptr = ptr->right)
	{
		if (ptr->data.getBookNumber() == b.getBookNumber()) return true;
	}
	return false;
}

DblListNode* DblList::findNode(string bookName)
{
	for (DblListNode *ptr = first; ptr != head; ptr = ptr->right)
	{
		if (ptr->data.getBookName() == bookName) return ptr;
	}

	cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�!" << endl;
	return NULL;
}

void DblList ::insertNode(Book b)
{
	DblListNode *ptr = first;
	for (ptr; ptr != head; ptr = ptr->right)
	{
		if (ptr->data.getBookName().compare(b.getBookName()) >= 0) break;
	}
	ptr->left->right = new DblListNode(b, ptr->left, ptr);
	ptr->left = ptr->left->right;
	first = head->right;						// first�� �׻� �������� ���� ���� ����Ű�� �Ѵ�.
}

void DblList::deleteNode(string bookNumber)
{
	DblListNode *ptr = first;
	for (ptr; ptr != head; ptr = ptr->right)
	{
		if (ptr->data.getBookNumber() == bookNumber)
		{
			ptr->left->right = ptr->right;
			ptr->right->left = ptr->left;
			delete ptr;
			first = head->right;				// first�� �׻� �������� ���� ���� ����Ű�� �Ѵ�.
			return;
		}
	}
	cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�!" << endl;
}

void DblList:: showInOrder()
{
	if (first == head)
	{
		cout << "��ϵ� �ڷᰡ �������� �ʽ��ϴ�!" << endl;
		return;
	}
	for (DblListNode *ptr = first; ptr != head; ptr = ptr->right)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
	}
}

void DblList::showReverse()
{
	if (first == head)
	{
		cout << "��ϵ� �ڷᰡ �������� �ʽ��ϴ�!" << endl;
		return;
	}
	for (DblListNode *ptr = head->left; ptr != head; ptr = ptr->left)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
	}
}

void DblList :: showSpecific(DblListNode *index)
{
	DblListNode *ptr;
	
	for (ptr = index; ptr != head; ptr = ptr->right)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
	}
	for (ptr = head->right; ptr != index; ptr = ptr->right)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
	}
}

void DblList:: showSpecificReverse(DblListNode *index)
{
	DblListNode *ptr;
	
	for (ptr = index; ptr != head; ptr = ptr->left)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
	}
}

bool DblList :: loadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�!" << endl;
		return false;
	}

	string bookNumber;
	string bookName;

	while (!fin.eof())
	{
		getline(fin, bookNumber, ' ');
		if (bookNumber == "") break;
		getline(fin, bookName, '\n');
		Book b(bookNumber, bookName);

		insertNode(b);
	}
	fin.close();
	return true;
}

void DblList :: saveFile(string fileName)
{
	ofstream fout;
	fout.open(fileName, ios_base::out);
	

	for (DblListNode *ptr = first; ptr != head; ptr = ptr->right)
	{
		if (ptr == head->left)
		{
			fout << ptr->data.getBookNumber() << " " << ptr->data.getBookName();
		}
		else
		{
			fout << ptr->data.getBookNumber() << " " << ptr->data.getBookName() << endl;
		}
	}
	fout.close();
}