#include <iostream>

using namespace std;

int main()
{
	int num;
	while (1)
	{
		cout << "정수 입력 : ";
		cin >> num;

		if (0 < num && num % 2 != 0) break;
	}
	int count = num / 2;
	for (int i = 0; i < num / 2; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < (num - (2 * count)); k++)
		{
			cout << "*";
		}
		count--;
		cout << endl;
	}
	for (int i = 0; i <= num / 2; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cout << " ";
		}
		for (int k = 0; k < (num - (2 * count)); k++)
		{
			cout << "*";
		}
		count++;
		cout << endl;
	}
}