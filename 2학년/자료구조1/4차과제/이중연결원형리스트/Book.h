#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Book
{
private:
	string bookNumber;
	string bookName;
public:
	Book() {};
	Book(string i_bookNumber, string i_bookName);
	
	string getBookNumber() { return bookNumber; }
	string getBookName() { return bookName; }
};