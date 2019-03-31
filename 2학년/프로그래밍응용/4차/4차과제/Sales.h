#pragma once
#include "MenuList.h"

class Sales
{
private:
	string personName;
	string menuName;
	int orderQuantity;
	string date;
	int sumOfFee;
public:
	Sales() {}
	Sales(string s_pname, string s_mname, int s_quantity, string s_date, int s_sum);

	string getPersonName() { return personName; }
	string getMenuName() { return menuName; }
	int getOrderQuantity() { return orderQuantity; }
	string getDate() { return date; }
	int getSumOfFee() { return sumOfFee; }
};

