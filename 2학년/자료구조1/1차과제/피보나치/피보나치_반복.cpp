/* --- �Ǻ���ġ ���� �ݺ��� �̿��� �Լ� --- */
/* --- �ۼ���: �蹮��, �й�: 20130162   --- */
/* --- 35 lines,  �ۼ���: 2017. 3. 18.  --- */

#include <iostream>
using namespace std;

int getNthFiboNum(int n);

int main()
{
	int num;
	int result = 0;

	cout << "�� ��° �Ǻ���ġ ���� �˰� �ͽ��ϱ�? ";
	cin >> num;

	result = getNthFiboNum(num);
	cout << result;
}

int getNthFiboNum(int n)				// �Ǻ���ġ ������ ���� ��ȯ�ϴ� �Լ�
{
	int fnNum = 0;
	int fnNum1 = 0;
	int fnNum2 = 1;

	if (n <= 1) return n;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			fnNun = fnNum1 + fnNum2;
			fnNum1 = fnNum2;
			fnNum2 = fnNum;
		}
	}
	return fnNum;
}

// �ݺ����� �� ��� for������ Ȱ���ϱ� ������ ��͸� �̿��� �Լ��� �������� ��� �� ����� ������.
// �Է°����� 50�� �Է��Ͽ��� ��� �Ǻ���ġ ���� int�� ǥ���� �� �ִ� �ִ� ������ ������ ũ�Ƿ� �̻��� ���� ��µǰ� �ȴ�.