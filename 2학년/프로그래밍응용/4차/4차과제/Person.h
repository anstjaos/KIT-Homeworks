#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <iomanip>
using namespace std;
#define NOT_FOUND -1

class Person
{
private:
	string name;
	string department;
	string phoneNumber;
public:
	Person() {};
	Person(string p_name, string p_department, string p_phoneNumber);
	
	string getName() { return name; }
	string getDepartment() { return department; }
	string getPhoneNum() { return phoneNumber; }
};

