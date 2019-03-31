#pragma once
#include "Person.h"
#define NOT_FOUND -1

class PersonList {
private:
	Person personList[10];
	int count;

	int findIndex(string menu);
public:
	PersonList() { count = 0; }

	void inputPerson();
	void deletePerson();
	void findPerson();
	void printAll();
	void printMax();
	void printMin();
};