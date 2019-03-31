#pragma once
#include "SalesList.h"

class TicketManager
{
private:
	PersonList pl;
	MenuList ml;
	SalesList sl;

	void manageMode();
	void salesMode();
	void managePerson();
	void manageMenu();
	void manageSales();
	void insertPerson();
	void deletePerson();
	void insertMenu();
	void deleteMenu();
public:
	void getMenu();

	void loadFile();
	void saveFile();
};

