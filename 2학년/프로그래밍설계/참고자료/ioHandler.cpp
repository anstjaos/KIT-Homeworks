#include "ioHandler.h"


int ioHandler::getMenu()
{
	while (1)
	{
		cout << "1) 도형 추가" << endl;
		cout << "2) 도형 삭제" << endl;
		cout << "3) 도형 출력" << endl;
		cout << "4) 종료" << endl << endl;

		int select = getInteger("선택: ");
		if (select >= INSERT && select <= EXIT)
			return select;

		cout << "잘못된 입력입니다" << endl;
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

	id = getInteger("ID 입력: ");
	x = getInteger("좌표 X 입력: ");
	y = getInteger("좌표 Y 입력: ");
	r = getInteger("반지름 입력: ");

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