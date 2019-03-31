#include "PersonList.h"

PersonList::PersonList()
{
	capacity = 4;
	count = 0;
	personList = new Person[capacity];
}

int PersonList:: findPerson(string personName)
{
	for (int i = 0; i < count; i++)
	{
		if (personList[i].getName() == personName) return i;
	}
	return NOT_FOUND;
}

void PersonList :: insertPerson(Person p)
{
	if (count == capacity)
	{
		capacity *= 2;
		Person *temp = new Person[capacity];
		memcpy(temp, personList, sizeof(Person) * count);
		delete[] personList;
		personList = temp;
	}

	personList[count++] = p;
}

void PersonList::deletePerson(int index)
{
	for (int i = index; i < count-1; i++)
	{
		personList[i] = personList[i + 1];
	}
	count--;
}

void PersonList :: showPerson(string personName)
{
	int index = NOT_FOUND;
	for (int i = 0; i < count; i++)
	{
		if (personList[i].getName().find(personName) != -1)
		{
			index = i;
			break;
		}
	}
	if (index == NOT_FOUND)
	{
		cout << "입력하신 이름이 존재하지 않습니다!" << endl;
		return;
	}
	cout << personList[index].getName() << "\t" << personList[index].getDepartment() << "\t" << personList[index].getPhoneNum() << endl;
}

void PersonList:: loadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "파일이 존재하지 않습니다 !" << endl;
		return;
	}

	string personName;
	string department;
	string phoneNum;

	while (!fin.eof())
	{
		getline(fin, personName, ',');
		if (personName == "") break;
		getline(fin, department, ',');
		getline(fin, phoneNum);

		Person p(personName, department, phoneNum);
		insertPerson(p);
	}
	fin.close();
}

void PersonList ::saveFile(string fileName)
{
	ofstream fout;
	fout.open(fileName, ios_base::out);
	
	for (int i = 0; i < count; i++)
	{
		if (i == count - 1)
			fout << personList[i].getName() << "," << personList[i].getDepartment() << "," << personList[i].getPhoneNum();
		else 
			fout << personList[i].getName() << "," << personList[i].getDepartment() << "," << personList[i].getPhoneNum() << endl;
	}
	fout.close();
}

