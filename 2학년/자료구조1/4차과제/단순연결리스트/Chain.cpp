#include "Chain.h"
Chain :: ~Chain()						// new�� ���� �Ҵ����� �޸𸮸� ���� ����.
{
	ChainNode* temp = first;

	while(temp != 0)
	{
		first = temp;
		temp = temp->link;
		delete first;
	}
}
bool Chain :: checkNode(Book b)			// �Ű������� ���� ��ü�� ����� ������ ���Ͽ� �ߺ��� �˻��Ѵ�.
{
	for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
	{
		if (ptr->data.getBookNumber() == b.getBookNumber()) return true;
	}
	return false;
}

void Chain ::insertNode(Book b)			// �Ű������� ���� ��ü�� ����� ������ ���Ͽ� ���԰� ���ÿ� �����Ѵ�.
{
	ChainNode *prePtr = first;
	
 	if (first)
	{
		for (ChainNode *ptr = first; ptr != 0; ptr = ptr->link)
		{
			if (ptr->data.getBookName().compare(b.getBookName()) >= 0) break;	// �Ķ���ͷ� ���� å�� å�̸��� ���������� �� ���� ���
			prePtr = ptr;
		}
		// �Է¹��� ��ü�� first �ٷ� ������ �;��� ���
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
			if (ptr == first)			// first�� ����Ű�� ��带 ������ first�� �״��� ���� ��������ش�.
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

	cout << "�Է��Ͻ� ������ȣ�� �������� �ʽ��ϴ�!" << endl;
}

void Chain::printAll()
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