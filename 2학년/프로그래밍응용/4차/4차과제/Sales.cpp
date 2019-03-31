#include "Sales.h"

Sales :: Sales (string s_pname, string s_mname, int s_quantity, string s_date, int s_sum)
{
	personName = s_pname;
	menuName = s_mname;
	orderQuantity = s_quantity;
	date = s_date;
	sumOfFee = s_sum;
}