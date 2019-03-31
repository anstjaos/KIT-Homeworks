/* ---  메뉴기반으로 사람을 관리하는 프로그램  --- */
/* ---     작성자: 김문서, 학번: 20130162      --- */
/* ---      254 lines, 작성일: 2017. 4. 14.    --- */

#include "PersonList.h"
enum Menu { inputPerson = 1, deletePerson ,findPerson, printAll, printMax, printMin, Exit};

void main()
{
	PersonList pl;
	int menu;
	while (1)
	{
		cout << "1. Input Person, 2. Delete Person, 3. Find Person, 4. Print All," << endl;
		cout << "5. Print Max, 6. Print Min, 7. Exit" << endl;
		cout << "> 메뉴를 입력하세요. ";
		cin >> menu;
		cin.ignore();					// 입력 버퍼 엔터 제거 getline인식 못함

		switch (menu)
		{
		case inputPerson:
			pl.inputPerson();
			break;
		case deletePerson:
			pl.deletePerson();
			break;
		case findPerson:
			pl.findPerson();
			break;
		case printAll:
			pl.printAll();
			break;
		case printMax:
			pl.printMax();
			break;
		case printMin:
			pl.printMin();
			break;
		case Exit:
			return ;
		default:
			cout << "> 잘못된 메뉴를 선택 하셨습니다!" << endl;
			break;
		}
	}
}