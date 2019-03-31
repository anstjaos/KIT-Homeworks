#include "ShapeList.h"
#include "ioHandler.h"
#include "TaskManager.h"

int main()
{
	ShapeList sList;
	ioHandler ioh;
	TaskManager tm;

	while (1)
	{
		int select = ioh.getMenu();
		if (select == EXIT) break;

		switch (select)
		{
		case INSERT:
			tm.insertShape(sList);
			break;
		case DELETE:
			tm.deleteShape(sList);
			break;
		case DISPLAY:
			tm.displayShapes(sList);
			break;
		}
	}
}