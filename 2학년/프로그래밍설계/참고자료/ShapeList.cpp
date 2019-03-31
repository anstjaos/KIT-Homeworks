#include "ShapeList.h"

void ShapeList::insertShape(Shape s)
{
	shapeList[count] = s;
	count++;
}

void ShapeList::deleteShape(int index)
{
	shapeList[index] = shapeList[count - 1];
	count--;
}


int ShapeList::findShape(int id)
{
	Shape s;
	for (int i = 0; i<count; i++) {
		s = shapeList[i];
		if (s.getId() == id) {
			return i;
		}
	}
	return NOT_FOUND;
}