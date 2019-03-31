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
		cout << "���� �޴� �ı� �ܰ�� " << menuList[index].getRemnant() << "�Դϴ�." << endl;
		cout << "�ܰ� 0�� ���� ������ �����մϴ�." << endl;
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

	cout << "�߰��ϰ��� �ϴ� �޴��� �̸��� �Է��ϼ���-> ";
	cin >> menuName;

	int index = findMenu(menuName);
	if (index == NOT_FOUND)
	{
		cout << "�������� �ʴ� �޴��Դϴ�!" << endl;
		return;
	}

	cout << "�߰��ϰ��� �ϴ� ������ �Է��ϼ���-> ";
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
		cout << "������ �������� �ʽ��ϴ� !" << endl;
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