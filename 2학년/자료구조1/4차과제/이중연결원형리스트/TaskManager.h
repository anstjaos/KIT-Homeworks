#pragma once
#include "DblList.h"

class TaskManager
{
public:
	void taskMenu(DblList &dl);
	void insertNode(DblList &dl);
	void deleteNode(DblList &dl);
	void showSpecific(DblList &dl);
	void showSpecificReverse(DblList &dl);
};