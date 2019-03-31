#pragma once
#include "Person.h"

class PersonList
{
private:
	Person *personList;
	int count;
	int capacity;
public:
	PersonList();
	~PersonList() { delete[] personList; }
	
	int getCount() { return count; }
	int findPerson(string personName);

	void insertPerson(Person p);
	void deletePerson(int index);
	void showPerson(string personName);

	void loadFile(string fileName);
	void saveFile(string fileName);
};