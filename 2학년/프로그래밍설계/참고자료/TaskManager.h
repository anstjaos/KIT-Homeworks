#ifndef _TASK_MANAGER_H_
#define _TASK_MANAGER_H_

#include "ShapeList.h"

class TaskManager
{
public:
	void insertShape(ShapeList& sList);		// 도형 추가
	void deleteShape(ShapeList& sList);		// 도형 삭제
	void displayShapes(ShapeList sList);	// 도형 출력
};

#endif