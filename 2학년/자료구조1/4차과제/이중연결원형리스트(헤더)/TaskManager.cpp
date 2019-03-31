#include "TaskManager.h"

void TaskManager::taskMenu(DblList &dl)
{
	int menu;

	cout << "==========================================" << endl;
	cout << "(1)   새 도서 입력" << endl;
	cout << "(2)   도서 삭제" << endl;
	cout << "(3)   도서명 순으로 전체 출력" << endl;
	cout << "(4)   도서명 역순으로 전체 출력" << endl;
	cout << "(5)   특정 도서명부터 전체 출력" << endl;
	cout << "(6)   특정 도서명부터 첫 도서명까지 역순 출력" << endl;
	cout << "(7)   파일에 저장하고 종료" << endl;
	cout << "==========================================" << endl;

	while (1)
	{
		cout << "원하는 기능을 선택하세요 : ";
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
			cout << "종료합니다." << endl;
			return;
			break;
		default:
			cout << "잘못된 메뉴를 입력하셨습니다!" << endl;
			break;
		}
	}
}

void TaskManager::insertNode(DblList &dl)
{
	string bookNumber;
	string bookName;

	cout << "도서 번호와 도서명을 입력하세요. ";
	getline(cin, bookNumber, ' ');
	getline(cin, bookName, '\n');
	Book b(bookNumber, bookName);
	if (dl.checkNode(b))
	{
		cout << "입력하신 도서번호가 이미 존재합니다!" << endl;
		return;
	}
	dl.insertNode(b);
}

void TaskManager::deleteNode(DblList &dl)
{
	string bookNumber;

	cout << "도서 번호를 입력하세요. ";
	cin >> bookNumber;
	dl.deleteNode(bookNumber);
}

void TaskManager::showSpecific(DblList &dl)
{
	string bookName;
	DblListNode *ptr;

	cout << "도서명을 입력하세요. ";
	getline(cin, bookName, '\n');
	ptr = dl.findNode(bookName);
	if (ptr == NULL) return;
	dl.showSpecific(ptr);
}

void TaskManager::showSpecificReverse(DblList &dl)
{
	string bookName;
	DblListNode *ptr;

	cout << "도서명을 입력하세요. ";
	getline(cin, bookName, '\n');
	ptr = dl.findNode(bookName);
	if (ptr == NULL) return;
	dl.showSpecificReverse(ptr);
}