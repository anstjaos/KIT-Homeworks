#pragma once
#include "Dictionary.h"

class WordMatching
{
private:
	Dictionary *wordList;
	int count;
	int capacity;

	Dictionary randomWord();
	string eraseWhitespace(string str);
	void insertWord(Dictionary d);
public:
	WordMatching();
	~WordMatching() { delete[] wordList; }

	void showQuiz();
	int selectMenu();
	void loadFile();
};