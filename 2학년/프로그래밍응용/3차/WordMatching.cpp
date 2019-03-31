#include "WordMatching.h"

WordMatching::WordMatching()
{
	capacity = 4;
	count = 0;
	wordList = new Dictionary[capacity];
}

Dictionary WordMatching::randomWord()
{
	int index = 1;
	srand((unsigned int)time(NULL));
	index = rand() % count;
	Dictionary d = wordList[index];

	return d;
}

string WordMatching::eraseWhitespace(string str)
{
	string temp = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			temp += str[i];
		}
	}
	return temp;
}

void WordMatching :: insertWord(Dictionary d)
{
	if (count == capacity)
	{
		capacity *= 2;
		Dictionary *temp = new Dictionary[capacity];
		copy(wordList, wordList + count, temp);
		delete[] wordList;
		wordList = temp;
	}

	wordList[count++] = d;
}


void WordMatching::showQuiz()
{
	bool checkCorrect;
	bool complete = false;
	int checkAlphabet[26] = { 0 };
	int falseCount = 0;
	string input;
	clock_t begin, end;

	Dictionary d = randomWord();
	string word = d.getWord();
	int length = word.length();

	int *checkWord = new int[length];
	for (int i = 0; i < length; i++)
	{
		checkWord[i] = { 0 };
	}

	begin = clock();

	while (1)
	{
		checkCorrect = false;

		cout << endl << "단어 : ";
		for (int i =0; i < length; i++)
		{
			if (checkWord[i] == 0)
			{
				cout << "_ ";
			}
			else
			{
				cout << word[i] << " ";
		
			}
		}

		cout << endl << "힌트 : " << d.getDef() << endl;

		cout << "사용 가능한 문자 : ";
		for (int i = 0; i < 26; i++)
		{
			if (checkAlphabet[i] == 0) cout << (char)('A' + i) << " ";
			else cout << "_ ";

		}

		for (int i = 0; i < length; i++)
		{
			if (checkWord[i] == 0)
			{
				complete = false;
				break;
			}
			else complete = true;
		}
		if (complete == true) break;

		cout << endl << "알파벳 <A - z> 을 입력하세요 : ";
		cin >> input;

		if (input.length() > 1 && input == word) break;
		else if ((input[0] - 'A' >= 0 && input[0] - 'Z' <= 0) || (input[0] - 'a' >= 0 && input[0] - 'z' <= 0))
		{
			input = tolower(input[0]);			// 알파벳을 소문자로 변환
			
			for (int j = 0; j < length; j++)
			{
				if (input[0] == word[j])
				{
					checkWord[j] = 1;
					checkCorrect = true;
				}
			}

			for (int i = 0; i < 26; i++)
			{
				if (input[0] - 'a' == i)
				{
					checkAlphabet[i] = 1;
					break;
				}
			}
			
		}
		else cout << "알파벳을 입력해주세요!" << endl;

		if(checkCorrect == false) falseCount++;
		cout << endl;
	}

	end = clock();
	cout << endl << "단어 찾기에 성공하셨습니다!!" << endl;
	cout << "정답은 " << word << " : " << d.getDef() << endl;
	cout << "틀린 횟수 : " << falseCount << "번" << endl;
	cout << "걸린 시간 : " << ((double)(end - begin) / CLOCKS_PER_SEC) << "초" << endl;

	delete[] checkWord;
}

int WordMatching :: selectMenu()
{
	int menu;
	while (1)
	{
		cout << endl << "Continue[0] ? Exit[9]  ";
		cin >> menu;

		if (menu == 0 || menu == 9) return menu;
		else cout << "잘못된 숫자를 입력하셨습니다!" << endl;
	}
}

void WordMatching::loadFile()
{
	string fileName;
	ifstream fin;

	while (1)
	{
		cout << "File Name ? ";
		cin >> fileName;
		fin.open(fileName, ios_base::in);
		if (fin.fail())
		{
			cout << fileName << "이 존재하지 않습니다!" << endl << endl;
			continue;
		}
		else break;
	}

	int number;
	string word;
	string definition;
	string temp;

	while (!fin.eof())
	{
		getline(fin, temp, ',');
		if (temp == "") break;
		number = stoi(temp);
		getline(fin, temp, ',');
		word = eraseWhitespace(temp);
		getline(fin, definition, '\n');

		Dictionary d(number, word, definition);
		insertWord(d);
	}
	fin.close();
}
