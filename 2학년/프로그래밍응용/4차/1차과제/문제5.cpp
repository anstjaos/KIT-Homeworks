#include <iostream>
#include <string>
using namespace std;

void main()
{
	string word;
	string result[10];
	int count = 0;
	cout << "영어 단어 10개 입력" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " 번째 단어? ";
		cin >> word;
		int size = word.length();
		for (int j = 0; j < size; j++)
		{
			if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
			{
				if (j == size - 1) break;
				else if (word[j + 1] == 'a' || word[j + 1] == 'e' || word[j + 1] == 'i' || word[j + 1] == 'o' || word[j + 1] == 'u')
				{
					result[count] = word;
					count++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << result[i] << endl;
	}
}