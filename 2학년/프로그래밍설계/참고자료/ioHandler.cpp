#include "ioHandler.h"


int ioHandler::getMenu()
{
	while (1)
	{
		cout << "1) ���� �߰�" << endl;
		cout << "2) ���� ����" << endl;
		cout << "3) ���� ���" << endl;
		cout << "4) ����" << endl << endl;

		int select = getInteger("����: ");
		if (select >= INSERT && select <= EXIT)
			return select;

		cout << "�߸��� �Է��Դϴ�" << endl;
	}
}

int ioHandler::getInteger(string msg)
{
	int value;
	cout << msg;
	cin >> value;

	return value;
}

Shape ioHandler::getShape()
{
	int id, x, y, r;

	id = getInteger("ID �Է�: ");
	x = getInteger("��ǥ X �Է�: ");
	y = getInteger("��ǥ Y �Է�: ");
	r = getInteger("������ �Է�: ");

	Shape s(id, x, y, r);
	return s;
}

void ioHandler::printShape(Shape s)
{
	cout << setw(8) << s.getId() << "\t";
	cout << setw(8) << "(" << s.getX() << ", " << s.getY() << ")" << "\t";
	cout << setw(8) << s.getRadius() << "\t";
	cout << setw(8) << s.getArea() << endl;
}