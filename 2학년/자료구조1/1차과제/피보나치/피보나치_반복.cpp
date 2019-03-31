/* --- 피보나치 수열 반복을 이용한 함수 --- */
/* --- 작성자: 김문서, 학번: 20130162   --- */
/* --- 35 lines,  작성일: 2017. 3. 18.  --- */

#include <iostream>
using namespace std;

int getNthFiboNum(int n);

int main()
{
	int num;
	int result = 0;

	cout << "몇 번째 피보나치 수를 알고 싶습니까? ";
	cin >> num;

	result = getNthFiboNum(num);
	cout << result;
}

int getNthFiboNum(int n)				// 피보나치 수열의 값을 반환하는 함수
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

// 반복문을 쓸 경우 for문만을 활용하기 때문에 재귀를 이용한 함수를 쓸때보다 결과 값 계산이 빠르다.
// 입력값으로 50을 입력하였을 경우 피보나치 값이 int가 표현할 수 있는 최대 정수의 값보다 크므로 이상한 값이 출력되게 된다.