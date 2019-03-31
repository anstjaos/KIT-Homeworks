#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Dictionary
{
private:
	int number;
	string word;
	string definition;
public:
	Dictionary() {}
	Dictionary(int i_number, string i_word, string i_definition);

	string getWord() { return word; }
	string getDef() { return definition; }
};