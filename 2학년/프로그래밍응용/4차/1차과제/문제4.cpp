#include <iostream>

using namespace std;
#define SIZE 10

void main()
{
	int setA[SIZE] = {};
	int setB[SIZE] = {};
	int result[SIZE * 2] = {};
	int countA = 0;
	int countB = 0;
	int count = 0;
	int check;
	int num = 0;

	cout << "집합 A 입력: ";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> num;
		if (num == -1) break;
		setA[i] = num;
		countA++;
	}

	cout << "집합 B 입력: ";
	for (int i = 0; i < SIZE; i++)
	{
		cin >> num;
		if (num == -1) break;
		setB[i] = num;
		countB++;
	}

	for (int i = 0; i < countA; i++)
	{
		result[count] = setA[i];
		count++;
	}

	for (int i = 0; i < countB; i++)
	{
		check = 0;
		for (int j = 0; j < countA; j++)
		{
			if (setB[i] == setA[j])
			{
				check++;
				break;
			}
		}
		if (check == 0)
		{
			result[count] = setB[i];
			count++;
		}
	}
	
	cout << "합집합: < ";
	for (int i = 0; i < count; i++)
	{
		if (i == count - 1)
		{
			cout << result[i] << " >" << endl;
		}
		else cout << result[i] << " ";
	}

	for (int i = 0; i < count; i++)
	{
		result[i] = {};
	}
	count = 0;

	for (int i = 0; i < countA; i++)
	{
		for (int j = 0; j < countB; j++)
		{
			if (setA[i] == setB[j])
			{
				result[count] = setA[i];
				count++;
			}
		}
	}

	cout << "교집합: < ";
	if (count == 0) cout << " >" << endl;
	else
	{
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				cout << result[i] << " >" << endl;
				break;
			}
			cout << result[i] << " ";
		}
	}

	for (int i = 0; i < count; i++)
	{
		result[i] = {};
	}
	count = 0;

	for (int i = 0; i < countA; i++)
	{
		check = 0;
		for (int j = 0; j < countB; j++)
		{
			if (setA[i] == setB[j])
			{
				check++;
				break;
			}
		}
		if (check == 0)
		{
			result[count] = setA[i];
			count++;
		}
	}

	cout << "차집합: < ";
	if (count == 0) cout << " >";
	else {
		for (int i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				cout << result[i] << " >" << endl;
				break;
			}
			cout << result[i] << " ";
		}
	}
}