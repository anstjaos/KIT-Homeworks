#include <iostream>
using namespace std;

void main()
{
	int num;
	int arr[31];
	int index = 0;
	cout << "10진수 정수 입력(20억 이하) : ";
	cin >> num;
	while (num > 0)
	{
		if (num % 2 == 0)
		{
			arr[index] = 0;
		}
		else arr[index] = 1;

		index++;
		num = num / 2;
	}
	cout << "2진수 변환 결과 : ";
	for (int i = index-1; i >= 0; i--)
	{
		cout << arr[i];
	}
	cout << endl;
}