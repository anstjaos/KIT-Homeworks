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

		cout << endl << "�ܾ� : ";
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

		cout << endl << "��Ʈ : " << d.getDef() << endl;

		cout << "��� ������ ���� : ";
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

		cout << endl << "���ĺ� <A - z> �� �Է��ϼ��� : ";
		cin >> input;

		if (input.length() > 1 && input == word) break;
		else if ((input[0] - 'A' >= 0 && input[0] - 'Z' <= 0) || (input[0] - 'a' >= 0 && input[0] - 'z' <= 0))
		{
			input = tolower(input[0]);			// ���ĺ��� �ҹ��ڷ� ��ȯ
			
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
		else cout << "���ĺ��� �Է����ּ���!" << endl;

		if(checkCorrect == false) falseCount++;
		cout << endl;
	}

	end = clock();
	cout << endl << "�ܾ� ã�⿡ �����ϼ̽��ϴ�!!" << endl;
	cout << "������ " << word << " : " << d.getDef() << endl;
	cout << "Ʋ�� Ƚ�� : " << falseCount << "��" << endl;
	cout << "�ɸ� �ð� : " << ((double)(end - begin) / CLOCKS_PER_SEC) << "��" << endl;

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
		else cout << "�߸��� ���ڸ� �Է��ϼ̽��ϴ�!" << endl;
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
			cout << fileName << "�� �������� �ʽ��ϴ�!" << endl << endl;
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
