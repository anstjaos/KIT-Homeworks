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
		if (ptr->data.getBookName() == bookName) return ptr;		// 특정 도서의 주소값을 return

		if (ptr->right == first) break;
		ptr = ptr->right;
		
	}
	cout << "입력하신 정보가 존재하지 않습니다!" << endl;
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
		if (ptr == first && ptr->data.getBookName().compare(b.getBookName()) >= 0)		// 처음에 삽입 될 경우
		{
			first = new DblListNode(b, first->left, first);
			ptr->left = first;
			first->left->right = first;
		}
		else if (ptr == first->left)		// 마지막에 삽입 될 경우
		{
			ptr->right = new DblListNode(b, ptr, first);
			first->left = ptr->right;
		}
		else								// 사이에 삽입 될 경우
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
			if (ptr == first)			// first가 가리키는 노드 삭제시 first 재연결
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

	cout << "입력하신 정보가 존재하지 않습니다!" << endl;
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
	cout << "자료가 존재하지 않습니다!" << endl;
}

void DblList :: showReverse()
{
	DblListNode *ptr = first;
	bool flag = false;

	while(first)
	{
		if (flag == false)				// 처음 시작을 제일 끝에서 하기위해
		{
			ptr = ptr->left;
			flag = true;
		}
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
		if (ptr->left == first->left) return;
		ptr = ptr->left;
	}
	cout << "자료가 존재하지 않습니다!" << endl;
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
		cout << "입력하신 파일명이 존재하지 않습니다." << endl;
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