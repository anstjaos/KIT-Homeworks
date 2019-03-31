#include "Chain.h"
Chain :: ~Chain()						// new로 동적 할당해준 메모리를 동적 해제.
{
	ChainNode* temp = first;

	while(temp != 0)
	{
		first = temp;
		temp = temp->link;
		delete first;
	}
}
bool Chain :: checkNode(Book b)			// 매개변수로 받은 객체와 노드의 값들을 비교하여 중복을 검사한다.
{
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.getBookNumber() == b.getBookNumber()) return true;
	}
	return false;
}

void Chain ::insertNode(Book b)			// 매개변수로 받은 객체와 노드의 값들을 비교하여 삽입과 동시에 정렬한다.
{
	ChainNode *prePtr = first;
	
 	if (first)
	{
		for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
		{
			if (ptr->data.getBookName().compare(b.getBookName()) >= 0) break;	// 파라미터로 받은 책의 책이름이 사전순으로 더 빠를 경우
			prePtr = ptr;
		}
		// 입력받은 객체가 first 바로 다음에 와야할 경우
		if (prePtr == first && prePtr->data.getBookName().compare(b.getBookName()) >= 0) first = new ChainNode(b, first);
		else prePtr->link = new ChainNode(b, prePtr->link);

	}
	else first = new ChainNode(b, 0);
}

void Chain :: deleteNode(string bookNumber)
{
	ChainNode *prePtr = first;
	
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.getBookNumber() == bookNumber)
		{
			if (ptr == first)			// first가 가리키는 노드를 삭제시 first를 그다음 노드로 연결시켜준다.
			{
				first = ptr->link;
				delete ptr;
				return;
			}
			else
			{
				prePtr->link = ptr->link;
				delete ptr;
				return;
			}
		}
		prePtr = ptr;
	}

	cout << "입력하신 도서번호는 존재하지 않습니다!" << endl;
}

void Chain::printAll()
{
	if (first == NULL)
	{
		cout << "등록된 자료가 존재하지 않습니다!" << endl;
		return;
	}

	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		cout << ptr->data.getBookName() << " [" << ptr->data.getBookNumber() << "]" << endl;
	}
}

bool Chain::loadFile(string fileName)
{
	ifstream in;
	in.open(fileName, ios_base::in);
	if (in.fail())
	{
		cout << "입력하신 파일명이 존재하지 않습니다!" << endl;
		return false;
	}

	string bookNumber;
	string bookName;

	while (!in.eof())
	{
		getline(in, bookNumber, ' ');
		if (bookNumber == "") break;
		getline(in, bookName, '\n');

		Book b(bookNumber, bookName);
		insertNode(b);
	}
	in.close();
	return true;
}

void Chain::saveFile(string fileName)
{
	ofstream out;
	out.open(fileName, ios_base::out);

	string bookNumber;
	string bookName;

	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->link == 0)
		{
			out << ptr->data.getBookNumber() << " ";
			out << ptr->data.getBookName();
		}
		else
		{
			out << ptr->data.getBookNumber() << " ";
			out << ptr->data.getBookName() << endl;
		}
	}
	out.close();
}