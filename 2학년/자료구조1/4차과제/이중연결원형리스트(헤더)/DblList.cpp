#include "DblList.h"

DblList::DblList()
{
	Book b;
	head = new DblListNode(b,0, 0);
	head->left = head;
	head->right = head;					// 헤더 노드의 left와 right는 자기 자신을 가리키게 한다.
	first = head;
}

DblList::~DblList()
{
	if (first == head)					// first가 헤더 노드를 가리키고 있을 경우
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

	cout << "입력하신 정보가 존재하지 않습니다!" << endl;
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
	first = head->right;						// first가 항상 헤더노드의 다음 것을 가리키게 한다.
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
			first = head->right;				// first가 항상 헤더노드의 다음 것을 가리키게 한다.
			return;
		}
	}
	cout << "입력하신 정보가 존재하지 않습니다!" << endl;
}

void DblList:: showInOrder()
{
	if (first == head)
	{
		cout << "등록된 자료가 존재하지 않습니다!" << endl;
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
		cout << "등록된 자료가 존재하지 않습니다!" << endl;
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
		cout << "입력하신 파일이 존재하지 않습니다!" << endl;
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