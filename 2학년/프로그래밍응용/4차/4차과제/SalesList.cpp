#include "SalesList.h"

SalesList::SalesList()
{
	capacity = 4;
	count = 0;
	salesList = new Sales[capacity];
}

void SalesList::insertSales(Sales s)
{
	if (count == capacity)
	{
		capacity *= 2;
		Sales *temp = new Sales[capacity];
		memcpy(temp, salesList, sizeof(Sales) * count);
		delete[] salesList;
		salesList = temp;
	}

	salesList[count++] = s;
}

void SalesList :: statisticsMenu(MenuList &ml)
{
	string menuName;
	int sumofFee;
	int orderQuantity;
	int remnant;
	if (count == 0)
	{
		cout << "판매 기록이 존재하지 않습니다!" << endl;
		return;
	}
	Sales *list = new Sales[count];
	int listCount = 0;
	bool flag;

	for (int i = 0; i < count; i++)
	{
		flag = true;
		menuName = salesList[i].getMenuName();
		orderQuantity = salesList[i].getOrderQuantity();
		sumofFee = salesList[i].getSumOfFee();
		
		for (int j = 0; j < listCount; j++)
		{
			if (list[j].getMenuName() == menuName)
			{
				orderQuantity += list[j].getOrderQuantity();
				sumofFee += list[j].getSumOfFee();
				Sales s("", menuName, orderQuantity, "", sumofFee);
				list[j] = s;
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			Sales s("", menuName, orderQuantity, "", sumofFee);
			list[listCount++] = s;
		}
	}

	for (int i = 0; i < listCount; i++)
	{
		int j = i;
		for (int k = i + 1; k < listCount; k++)
		{
			if (list[j].getSumOfFee() < list[k].getSumOfFee()) j = k;
		}
		swap(list[i], list[j]);
	}

	cout << "=========================================================================" << endl;
	cout.setf(ios_base::left);
	cout << setw(16) << "메뉴 이름" << setw(15) << "총 판매 금액" << setw(15) << "판매 수량" << setw(15) << "잔여 수량" << endl;
	cout << "=========================================================================" << endl;
	for (int i = 0; i < listCount; i++)
	{
		remnant = 0;
		for (int j = 0; j < ml.getCount(); j++)
		{
			if (list[i].getMenuName() == ml.getMenu(j).getMenuName())
			{
				remnant = ml.getMenu(j).getRemnant();
				break;
			}
		}
		cout << setw(20) << list[i].getMenuName() << setw(20) << list[i].getSumOfFee();
		cout << setw(20) << list[i].getOrderQuantity() << setw(20) << remnant << endl;
	}
	delete[] list;
}

void SalesList :: statisticsPerson()
{
	string personName;
	int sumofFee;

	if (count == 0)
	{
		cout << "판매 기록이 존재하지 않습니다!" << endl;
		return;
	}
	Sales *list = new Sales[count];
	int listCount = 0;
	bool flag;

	for (int i = 0; i < count; i++)
	{
		flag = true;
		personName = salesList[i].getPersonName();
		sumofFee = salesList[i].getSumOfFee();

		for (int j = 0; j < listCount; j++)
		{
			if (list[j].getPersonName() == personName)
			{
				sumofFee += list[j].getSumOfFee();
				Sales s(personName, "", 0, "", sumofFee);
				list[j] = s;
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			Sales s(personName, "", 0, "", sumofFee);
			list[listCount++] = s;
		}
	}

	for (int i = 0; i < listCount; i++)
	{
		int j = i;
		for (int k = i + 1; k < listCount; k++)
		{
			if (list[j].getSumOfFee() < list[k].getSumOfFee()) j = k;
		}
		swap(list[i], list[j]);
	}

	cout << "==============================================" << endl;
	cout.setf(ios_base::left);
	cout << setw(16) << "사람 이름" << setw(15) << "구입 금액" << endl;
	cout << "==============================================" << endl;
	for (int i = 0; i < listCount; i++)
	{
		cout << setw(20) << list[i].getPersonName() << setw(20) << list[i].getSumOfFee() << endl;
	}
	delete[] list;
}

void SalesList :: statisticsPersonBuy()
{
	string personName;
	string menuName;
	int orderQuantity;
	int sumofFee;

	if (count == 0)
	{
		cout << "판매 기록이 존재하지 않습니다!" << endl;
		return;
	}
	string *person = new string[count];
	int p_count = 0;
	Sales *list = new Sales[count];
	int s_count = 0;
	bool flag;

	for (int i = 0; i < count; i++)
	{
		flag = true;
		personName = salesList[i].getPersonName();
		for (int j = 0; j < p_count; j++)
		{
			if (person[j] == personName)
			{
				flag = false;
				break;
			}
		}
		if (flag == true) person[p_count++] = personName;
	}

	for (int i = 0; i < count; i++)
	{
		flag = true;
		personName = salesList[i].getPersonName();
		menuName = salesList[i].getMenuName();
		orderQuantity = salesList[i].getOrderQuantity();
		sumofFee = salesList[i].getSumOfFee();

		for (int j = 0; j < s_count; j++)
		{
			if (list[j].getPersonName() == personName && list[j].getMenuName() == menuName)
			{
				orderQuantity += list[j].getOrderQuantity();
				sumofFee += list[j].getSumOfFee();
				Sales s(personName, menuName, orderQuantity, "", sumofFee);
				list[j] = s;
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			Sales s(personName, menuName, orderQuantity, "", sumofFee);
			list[s_count++] = s;
		}
	}

	cout << "=========================================================================" << endl;
	cout.setf(ios_base::left);
	cout << setw(16) << "사람 이름" << setw(15) << "메뉴 이름" << setw(15) << "판매 수량" << setw(15) << "총 구입 금액" << endl;
	cout << "=========================================================================" << endl;
	for (int i = 0; i < p_count; i++)
	{
		flag = true;
		for (int j = 0; j < s_count; j++)
		{
			if (person[i] == list[j].getPersonName() && flag == true)
			{
				cout << setw(20) << list[j].getPersonName() << setw(19) << list[j].getMenuName();
				cout << setw(19) << list[j].getOrderQuantity() << setw(20) << list[j].getSumOfFee() << endl;
				flag = false;
			}
			else if (person[i] == list[j].getPersonName())
			{
				cout << setw(20) << " " << setw(19) << list[j].getMenuName();
				cout << setw(19) << list[j].getOrderQuantity() << setw(20) << list[j].getSumOfFee() << endl;
			}
		}
	}
	delete[] person;
	delete[] list;
}

void SalesList :: statisticsDate()
{
	string date;
	if (count == 0)
	{
		cout << "판매 기록이 존재하지 않습니다!" << endl;
		return;
	}
	string *list = new string[count];
	int listCount = 0;
	bool flag;

	for (int i = 0; i < count; i++)
	{
		flag = true;
		date = salesList[i].getDate();
		for (int j = 0; j < listCount; j++)
		{
			if (list[j] == date)
			{
				flag = false;
				break;
			}
		}
		if (flag == true) list[listCount++] = date;
	}
	cout << "=======================================================================================" << endl;
	cout.setf(ios_base::left);
	cout << setw(10) << "날짜" << setw(15) << "사람 이름"  << setw(15) << "메뉴 이름" << setw(15) << "판매 수량" << setw(15) << "구입 금액" << endl;
	cout << "=======================================================================================" << endl;
	for (int i = 0 ;i < listCount; i++)
	{
		flag = true;
		for (int j = 0; j < count; j++)
		{
			if (list[i] == salesList[j].getDate() && flag == true)
			{
				cout << setw(12) << salesList[j].getDate() << setw(19) << salesList[j].getPersonName() << setw(19) << salesList[j].getMenuName();
				cout << setw(19) << salesList[j].getOrderQuantity() << setw(20) << salesList[j].getSumOfFee() << endl;
				flag = false;
			}
			else if (list[i] == salesList[j].getDate())
			{
				cout << setw(12) << " " << setw(19) << salesList[j].getPersonName() << setw(19) << salesList[j].getMenuName();
				cout << setw(19) << salesList[j].getOrderQuantity() << setw(20) << salesList[j].getSumOfFee() << endl;
			}
		}
	}
	delete[] list;
}

void SalesList::loadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "파일이 존재하지 않습니다 !" << endl;
		return;
	}

	string personName;
	string menuName;
	int orderQuantity;
	string date;
	int sumOfFee;
	string temp;

	while (!fin.eof())
	{
		getline(fin, personName, ',');
		if (personName == "") break;
		getline(fin, menuName, ',');
		getline(fin, temp,',');
		orderQuantity = stoi(temp);
		getline(fin, date, ',');
		getline(fin, temp);
		sumOfFee = stoi(temp);

		Sales s(personName, menuName, orderQuantity, date, sumOfFee);
		insertSales(s);
	}
	fin.close();
}

void SalesList::saveFile(string fileName)
{
	ofstream fout;
	fout.open(fileName, ios_base::out);

	for (int i = 0; i < count; i++)
	{
		if (i == count - 1)
		{
			fout << salesList[i].getPersonName() << "," << salesList[i].getMenuName() << "," << salesList[i].getOrderQuantity() << ",";
			fout << salesList[i].getDate() << "," << salesList[i].getSumOfFee();
		}
		else
		{
			fout << salesList[i].getPersonName() << "," << salesList[i].getMenuName() << "," << salesList[i].getOrderQuantity() << ",";
			fout << salesList[i].getDate() << "," << salesList[i].getSumOfFee() << endl;
		}
	}
	fout.close();
}