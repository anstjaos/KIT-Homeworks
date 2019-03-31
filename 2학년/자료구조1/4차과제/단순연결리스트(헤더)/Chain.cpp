#include "Chain.h"

Chain::Chain()
{
	Book b; 
	first = NULL;
	head = new ChainNode(b, first);			// ��� ��� ����
}

Chain :: ~Chain()
{
	ChainNode *temp = head->link;
	delete head;

	while (temp)
	{
		first = temp;
		temp = temp->link;
		delete first;
	}
}

bool Chain :: checkNode(Book b)
{
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.getBookNumber() == b.getBookNumber()) return true;
	}
	return false;
}

void Chain ::insertNode(Book b)
{
	ChainNode *prePtr = head;
	
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.getBookName().compare(b.getBookName()) >= 0) break;
		prePtr = ptr;
	}
	prePtr->link = new ChainNode(b, prePtr->link);
	first = head->link;			// first�� �׻� ù ��带 ����Ų��.
}

void Chain::deleteNode(string bookNumber)
{
	ChainNode *prePtr = head;
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.getBookNumber() == bookNumber)
		{
			prePtr->link = ptr->link;
			delete ptr;
			first = head->link;
			return;
		}
		prePtr = ptr;
	}

	cout << "�Է��Ͻ� ������ �������� �ʽ��ϴ�! " << endl;
}

void Chain:: printAll()
{
	if (first == NULL)
	{
		cout << "��ϵ� �ڷᰡ �������� �ʽ��ϴ�!" << endl;
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
		cout << "�Է��Ͻ� ���ϸ��� �������� �ʽ��ϴ�!" << endl;
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