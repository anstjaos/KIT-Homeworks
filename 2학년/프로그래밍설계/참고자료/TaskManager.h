#ifndef _TASK_MANAGER_H_
#define _TASK_MANAGER_H_

#include "ShapeList.h"

class TaskManager
{
public:
	void insertShape(ShapeList& sList);		// ���� �߰�
	void deleteShape(ShapeList& sList);		// ���� ����
	void displayShapes(ShapeList sList);	// ���� ���
};

#endif