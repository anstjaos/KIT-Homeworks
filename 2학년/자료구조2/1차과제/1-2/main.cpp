/* ---		pointer�� �̿��� ���� ���		--- */
/* ---    �ۼ���: �蹮��, �й�: 20130162    --- */
/* ---    363 lines, �ۼ���: 2017. 9. 2.    --- */

#include "Tree.h"

void main()
{
	cout << "��� ������ �Է��ϼ��� : ";
	int nodeCount;
	cin >> nodeCount;

	Tree<int> t(nodeCount);
	t.printAll();
}