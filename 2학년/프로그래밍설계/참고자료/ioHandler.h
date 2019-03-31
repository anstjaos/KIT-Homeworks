#ifndef _IO_HANDLER_H_
#define _IO_HANDLER_H_

#include "ShapeList.h"
#include <iomanip>

enum Menus {INSERT = 1, DELETE, DISPLAY, EXIT};

class ioHandler
{
public:
	int getMenu();
	Shape getShape();
	void printShape(Shape);
	
	int getInteger(string msg);
};

#endif