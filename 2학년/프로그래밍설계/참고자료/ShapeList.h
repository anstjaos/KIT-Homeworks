#ifndef _SHAPE_LIST_H_
#define _SHAPE_LIST_H_

#include "Shape.h"

const int MAX_SHAPES = 10;
const int NOT_FOUND = -1;

class ShapeList
{
private:
	Shape shapeList[MAX_SHAPES];		// 도형 목록
	int count;							// 현재 도형 수

public:
	ShapeList() { count = 0;}
	~ShapeList() {}


	Shape getShape(int index) { return shapeList[index]; }
	int getCount() { return count; }

	void insertShape(Shape s);
	void deleteShape(int index);
	int findShape(int id);				//NOT_FOUND == -1
};


#endif