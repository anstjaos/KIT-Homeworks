#include <iostream>

using namespace std;

void main()
{
	int num=0;
	int squared =1;
	int result = 0;
	cout << "2���� �Է� ?";
	cin >> num;

	while (num > 0)
	{
		result = result + (num%10)*2;
		num = num / 10;
		squared = squared * 2;
	}

	cout << "10���� = " << result << endl;
}