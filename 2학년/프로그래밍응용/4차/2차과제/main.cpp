/* ---  �޴�������� ����� �����ϴ� ���α׷�  --- */
/* ---     �ۼ���: �蹮��, �й�: 20130162      --- */
/* ---      254 lines, �ۼ���: 2017. 4. 14.    --- */

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
		cout << "> �޴��� �Է��ϼ���. ";
		cin >> menu;
		cin.ignore();					// �Է� ���� ���� ���� getline�ν� ����

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
			cout << "> �߸��� �޴��� ���� �ϼ̽��ϴ�!" << endl;
			break;
		}
	}
}