#include "MenuList.h"

MenuList::MenuList()
{
	capacity = 4;
	count = 0;
	menuList = new Menu[capacity];
}

int MenuList::findMenu(string menuName)
{
	for (int i = 0; i < count; i++)
	{
		if (menuList[i].getMenuName() == menuName) return i;
	}
	return NOT_FOUND;
}

void MenuList :: insertMenu(Menu m)
{
	if (count == capacity)
	{
		capacity *= 2;
		Menu *temp = new Menu[capacity];
		memcpy(temp, menuList, sizeof(Menu) * count);
		delete[] menuList;
		menuList = temp;
	}
	menuList[count++] = m;
}

void MenuList::deleteMenu(int index)
{
	if (menuList[index].getRemnant() != 0)
	{
		cout << "현재 메뉴 식권 잔고는 " << menuList[index].getRemnant() << "입니다." << endl;
		cout << "잔고가 0일 때만 삭제가 가능합니다." << endl;
		return;
	}

	for (int i = index; i < count-1; i++)
	{
		menuList[i] = menuList[i + 1];
	}
	count--;
}

void MenuList :: plusTicket()
{
	string menuName;
	int quantity;

	cout << "추가하고자 하는 메뉴의 이름을 입력하세요-> ";
	cin >> menuName;

	int index = findMenu(menuName);
	if (index == NOT_FOUND)
	{
		cout << "존재하지 않는 메뉴입니다!" << endl;
		return;
	}

	cout << "추가하고자 하는 수량을 입력하세요-> ";
	cin >> quantity;
	menuList[index].plusRemnant(quantity);
}

void MenuList :: minusTicket(int index, int orderQuantity)
{
	menuList[index].minusRemnant(orderQuantity);
}

void MenuList::loadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "파일이 존재하지 않습니다 !" << endl;
		return;
	}

	string menuName;
	string temp;
	int fee;
	int remnant;

	while (!fin.eof())
	{
		getline(fin, menuName, ',');
		if (menuName == "") break;
		getline(fin, temp, ',');
		fee = stoi(temp);
		getline(fin, temp);
		remnant = stoi(temp);

		Menu m(menuName, fee, remnant);
		insertMenu(m);
	}
	fin.close();
}

void MenuList::saveFile(string fileName)
{
	ofstream fout;
	fout.open(fileName, ios_base::out);

	for (int i = 0; i < count; i++)
	{
		if (i == count - 1)
			fout << menuList[i].getMenuName() << "," << menuList[i].getFee() << "," << menuList[i].getRemnant();
		else
			fout << menuList[i].getMenuName() << "," << menuList[i].getFee() << "," << menuList[i].getRemnant() << endl;
	}
	fout.close();
}