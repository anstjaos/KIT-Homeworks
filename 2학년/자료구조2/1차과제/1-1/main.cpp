/* ---				�迭 ���� ���			--- */
/* ---    �ۼ���: �蹮��, �й�: 20130162    --- */
/* ---    210 lines, �ۼ���: 2017. 8. 27.   --- */

#include "Tree.h"

void main()
{
	int capacity;
	cout << "��� ������ �Է��ϼ��� : ";
	cin >> capacity;

	Tree<int> t(capacity);
	t.printAll();
}