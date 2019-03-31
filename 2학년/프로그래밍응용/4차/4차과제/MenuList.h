#pragma once
#include "Menu.h"

class MenuList
{
private :
	Menu *menuList;
	int count;
	int capacity;
public:
	MenuList();
	~MenuList() { delete[] menuList;  }

	int getCount() { return count; }
	Menu getMenu(int index) { return menuList[index]; }
	int findMenu(string menuName);

	void insertMenu(Menu m);
	void deleteMenu(int index);
	void plusTicket();
	void minusTicket(int index, int orderQuantity);

	void loadFile(string fileName);
	void saveFile(string fileName);
};