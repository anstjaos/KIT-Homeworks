/* --- �Ǻ���ġ ���� ��͸� �̿��� �Լ� --- */
/* --- �ۼ���: �蹮��, �й�: 20130162   --- */
/* --- 28 lines,  �ۼ���: 2017. 3. 18.  --- */

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

int getNthFiboNum(int n)			// �Ǻ���ġ ������ ���� ��ȯ�ϴ� �Լ�
{
	int fnNum;

	if (n <= 1) return n;
	else
	{
		fnNum = getNthFiboNum(n - 1) + getNthFiboNum(n - 2);
	}
	return fnNum;
}

// ��͸� �̿��� �Լ��� �� ��� �Ķ���ͷ� �Ѱ��ִ� ���� 1���ϰ� �� ������ ��� ��͸� �ؾ��ϹǷ� �ݺ��� �̿��� �Լ����� ����� ������.
// �Է°����� 50�� �Է��Ͽ��� ��� �Ǻ���ġ ���� int�� ǥ���� �� �ִ� �ִ� ������ ������ ũ�Ƿ� �̻��� ���� ��µǰ� �ȴ�.