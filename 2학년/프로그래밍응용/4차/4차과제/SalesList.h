#pragma once
#include "Sales.h"

class SalesList
{
private:
	Sales *salesList;
	int count;
	int capacity;
public:
	SalesList();
	~SalesList() { delete[] salesList; }

	void insertSales(Sales s);
	void statisticsMenu(MenuList &ml);
	void statisticsPerson();
	void statisticsPersonBuy();
	void statisticsDate();

	void loadFile(string fileName);
	void saveFile(string fileName);
};

