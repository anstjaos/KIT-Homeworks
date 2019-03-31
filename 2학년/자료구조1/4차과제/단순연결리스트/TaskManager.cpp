#include "TaskManager.h"

void TaskManager::getMenu(Chain &c)
{
	int menu;
	
	cout << "==========================================" << endl;
	cout << "(1)   새 도서 입력" << endl;
	cout << "(2)   도서 삭제" << endl;
	cout << "(3)   도서명 순으로 전체 출력" << endl;
	cout << "(4)   파일에 저장하고 종료" << endl;
	cout << "==========================================" << endl;
	
	while (1)
	{
		cout << "원하는 기능을 선택하세요 : ";
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
			cout << "종료합니다." << endl;
			return;
			break;
		default:
			cout << "잘못된 메뉴를 입력하셨습니다!" << endl;
			break;
		}
	}
}

void TaskManager::insertNode(Chain &c)
{
	string bookNumber;
	string bookName;

	cout << "도서번호와 도서명을 입력하세요 : ";
	getline(cin, bookNumber, ' ');
	getline(cin, bookName, '\n');
	
	Book b(bookNumber, bookName);
	if (c.checkNode(b))
	{
		cout << "입력한 도서번호가 이미 존재합니다!" << endl;
		return;
	}
	c.insertNode(b);
}

void TaskManager::deleteNode(Chain &c)
{
	string bookNumber;

	cout << "도서번호를 입력하세요 : ";
	cin >> bookNumber;

	c.deleteNode(bookNumber);
}