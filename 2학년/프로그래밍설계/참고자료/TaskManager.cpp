#include "TaskManager.h"
#include "ioHandler.h"
#include "ShapeList.h"

void TaskManager::insertShape(ShapeList& sList)
{
	ioHandler ioh;
	

	if (sList.getCount() >= MAX_SHAPES) {
		cout << endl << "최대 도형 수는 " << MAX_SHAPES << "입니다." << endl;
		cout << "더이상 추가 불가합니다." << endl;
		return;
	}

	Shape s = ioh.getShape();

	int index = sList.findShape(s.getId());
	if (index != NOT_FOUND) {
		cout << "ID 중복입니다." << endl;
		return;
	}

	sList.insertShape(s);
}

void TaskManager::deleteShape(ShapeList& sList)
{
	ioHandler ioh;

	if (sList.getCount() <= 0) {
		cout << endl << "현재 도형 수는 0입니다." << endl;
		cout << "삭제가 불가합니다." << endl;
		return;
	}

	int id = ioh.getInteger("삭제할 도형 ID 입력: ");

	int index = sList.findShape(id);
	if (index == NOT_FOUND) {
		cout << "도형을 찾을 수 없습니다" << endl;
		return;
	}

	sList.deleteShape(index);
}

void TaskManager::displayShapes(ShapeList sList)
{
	ioHandler ioh;

	cout << "       ID              좌표         반지름          면적" << endl << endl;
	int sListCount = sList.getCount();
	for (int i = 0; i < sListCount; i++) {
		Shape s = sList.getShape(i);
		ioh.printShape(s);
	}

	cout << endl << endl;
}

