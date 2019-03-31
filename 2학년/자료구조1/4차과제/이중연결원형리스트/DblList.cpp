#include "DblList.h"

DblList::~DblList()
{
	DblListNode *ptr = first;
	bool flag = false;

	while (ptr)
	{
		if (flag == false)
		{
			first->left->right = 0;
			flag = true;
		}
		ptr = first->right;
		delete first;
		first = ptr;
	}
}

bool DblList::checkNode(Book b)
{
	DblListNode *ptr = first;

	while(first)
	{
		if (ptr->data.getBookNumber() == b.getBookNumber()) return true;

		if (ptr->right == first) break;
		ptr = ptr->right;
	}
	return false;
}

DblListNode* DblList :: findNode(string bookName)
{
	DblListNode *ptr = first;
	
	while(first)
	{
		if (ptr->data.getBookName() == bookName) return ptr;		// Ư�� ������ �ּҰ��� return

		if (ptr->right == first) break;
		ptr = ptr->right;
		
	}
	cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�!" << endl;
	return NULL;
}

void DblList :: insertNode(Book b) 
{
	DblListNode *ptr = first;
	if (first)
	{
		while(1)
		{
			if (ptr->data.getBookName().compare(b.getBookName()) >= 0) break;
			if (ptr->right == first) break;
			ptr = ptr->right;
			
		}
		if (ptr == first && ptr->data.getBookName().compare(b.getBookName()) >= 0)		// ó���� ���� �� ���
		{
			first = new DblListNode(b, first->left, first);
			ptr->left = first;
			first->left->right = first;
		}
		else if (ptr == first->left)		// �������� ���� �� ���
		{
			ptr->right = new DblListNode(b, ptr, first);
			first->left = ptr->right;
		}
		else								// ���̿� ���� �� ���
		{
			ptr->left->right = new DblListNode(b, ptr->left, ptr);
			ptr->left = ptr->left->right;
		}
	}
	else
	{
		first = new DblListNode(b, 0,0);
		first->left = first;
		first->right = first;
	}
}

void DblList :: deleteNode(string bookNumber)
{
	DblListNode *ptr = first;
	
	while(first)
	{
		if (ptr->data.getBookNumber() == bookNumber)
		{
			if (ptr == first)			// first�� ����Ű�� ��� ������ first �翬��
			{ 
				if (ptr->right == first) 
				{
					first = 0;
					delete ptr;
					return;
				}
				else first = ptr->right;
			}	
			
			ptr->left->right = ptr->right;
			ptr->right->left = ptr->left;
			delete ptr;
			return;
		}
		if (ptr->right == first) break;
		ptr = ptr->right;
	}

	cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�!" << endl;
}

void DblList ::showInOrder()
{
	DblListNode *ptr = first;

	while(first)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
		if (ptr->right == first) return;
		ptr = ptr->right;
	}
	cout << "�ڷᰡ �������� �ʽ��ϴ�!" << endl;
}

void DblList :: showReverse()
{
	DblListNode *ptr = first;
	bool flag = false;

	while(first)
	{
		if (flag == false)				// ó�� ������ ���� ������ �ϱ�����
		{
			ptr = ptr->left;
			flag = true;
		}
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
		if (ptr->left == first->left) return;
		ptr = ptr->left;
	}
	cout << "�ڷᰡ �������� �ʽ��ϴ�!" << endl;
}

void DblList:: showSpecific(DblListNode *index)
{
	DblListNode *ptr = index;

	while(first)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
		if (ptr->right == index) return;
		ptr = ptr->right;
	}
}

void DblList :: showSpecificReverse(DblListNode *index)
{
	DblListNode *ptr = index;
	
	while(first)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;

		if (ptr->left == first->left) return;
		ptr = ptr->left;
	}
}

bool DblList::loadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	
	if (fin.fail())
	{
		cout << "�Է��Ͻ� ���ϸ��� �������� �ʽ��ϴ�." << endl;
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

	string bookNumber;
	string bookName;
	DblListNode *ptr = first;

	while(first)
	{
		if (ptr == first->left)
		{
			fout << ptr->data.getBookNumber() << " " << ptr->data.getBookName();
			break;
		}
		else
		{
			fout << ptr->data.getBookNumber() << " " << ptr->data.getBookName() << endl;
			ptr = ptr->right;
		}
	}
	fout.close();
}