#include "PersonList.h"

int PersonList::findIndex(string menu)
{
	string name;

	cout << "> Input Person (Name)? ";
	cin.sync();
	getline(cin,name, '\n');

	if (menu == "delete")
	{
		for (int i = 0; i < count; i++)
		{
			if (personList[i].getName() == name) return i;
		}
		return NOT_FOUND;
	}
	else if (menu == "find")
	{
		for (int i = 0; i < count; i++)
		{
			if (personList[i].getName().find(name) != NOT_FOUND) return i;
		}
		return NOT_FOUND;
	}
	return 0;
}

void PersonList::inputPerson()
{
	if (count == 10)
	{
		cout << "> ��� ������ �л� ���� �ʰ��Ͽ����ϴ�!" << endl;
		return;
	}

	string name;
	int korScore;
	int engScore;
	int mathScore;
	string temp;

	cout << "> Input Person (Name, Korean, English, Math)? ";
	getline(cin, name, ',');
	getline(cin, temp, ',');
	korScore = stoi(temp);
	getline(cin, temp, ',');
	engScore = stoi(temp);
	getline(cin, temp, '\n');
	mathScore = stoi(temp);

	Person p(name, korScore, engScore, mathScore);
	personList[count] = p;
	count++;
	cout << "> ����� �Ϸ� �Ǿ����ϴ�!" << endl;
}

void PersonList::deletePerson()
{
	int index = findIndex("delete");
	if (index == NOT_FOUND)
	{
		cout << "> �Է��Ͻ� �л��� ������ �������� �ʽ��ϴ�." << endl;
		return;
	}

	for (int i = index; i < count; i++)
	{
		personList[i] = personList[i + 1];
	}
	count--;
	cout << "> ������ �Ϸ� �Ǿ����ϴ�!" << endl;
}

void PersonList :: findPerson()
{
	int index = findIndex("find");
	if (index == NOT_FOUND)
	{
		cout << "> �Է��Ͻ� �л��� ������ �������� �ʽ��ϴ�." << endl;
		return;
	}

	cout << "> " << personList[index].getName() << " is " << personList[index].getGrade();
	cout.precision(4);
	cout << " (Average: " << personList[index].getAverage() << ")" << endl;
}

void PersonList::printAll()
{
	if (count == 0)
	{
		cout << "> ��ϵ� �л��� �����ϴ�." << endl;
		return;
	}

	for (int i = 0; i < count; i++)
	{
		cout << "> " << personList[i].getName() << " is " << personList[i].getGrade();
		cout.precision(4);
		cout << " (Average: " << personList[i].getAverage() << ")" << endl;
	}
}

void PersonList::printMax()
{
	float maxAverage = (float)INT_MIN;
	int index = 0;

	for (int i = 0; i < count; i++)
	{
		if (personList[i].getAverage() > maxAverage)
		{
			maxAverage = personList[i].getAverage();
			index = i;
		}
	}

	cout << "> " << personList[index].getName() << " is " << personList[index].getGrade();
	cout.precision(4);
	cout << " (Average: " << personList[index].getAverage() << ")" << endl;
}

void PersonList::printMin()
{
	float minAverage = (float)INT_MAX;
	int index = 0;

	for (int i = 0; i < count; i++)
	{
		if (personList[i].getAverage() < minAverage)
		{
			minAverage = personList[i].getAverage();
			index = i;
		}
	}

	cout << "> " << personList[index].getName() << " is " << personList[index].getGrade();
	cout.precision(4);
	cout << " (Average: " << personList[index].getAverage() << ")" << endl;
}