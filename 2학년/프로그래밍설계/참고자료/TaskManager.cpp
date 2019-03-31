#include "TaskManager.h"
#include "ioHandler.h"
#include "ShapeList.h"

void TaskManager::insertShape(ShapeList& sList)
{
	ioHandler ioh;
	

	if (sList.getCount() >= MAX_SHAPES) {
		cout << endl << "�ִ� ���� ���� " << MAX_SHAPES << "�Դϴ�." << endl;
		cout << "���̻� �߰� �Ұ��մϴ�." << endl;
		return;
	}

	Shape s = ioh.getShape();

	int index = sList.findShape(s.getId());
	if (index != NOT_FOUND) {
		cout << "ID �ߺ��Դϴ�." << endl;
		return;
	}

	sList.insertShape(s);
}

void TaskManager::deleteShape(ShapeList& sList)
{
	ioHandler ioh;

	if (sList.getCount() <= 0) {
		cout << endl << "���� ���� ���� 0�Դϴ�." << endl;
		cout << "������ �Ұ��մϴ�." << endl;
		return;
	}

	int id = ioh.getInteger("������ ���� ID �Է�: ");

	int index = sList.findShape(id);
	if (index == NOT_FOUND) {
		cout << "������ ã�� �� �����ϴ�" << endl;
		return;
	}

	sList.deleteShape(index);
}

void TaskManager::displayShapes(ShapeList sList)
{
	ioHandler ioh;

	cout << "       ID              ��ǥ         ������          ����" << endl << endl;
	int sListCount = sList.getCount();
	for (int i = 0; i < sListCount; i++) {
		Shape s = sList.getShape(i);
		ioh.printShape(s);
	}

	cout << endl << endl;
}

