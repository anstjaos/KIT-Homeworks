/* ---	 ���ڿ��� ���� binary search tree	--- */
/* ---    �ۼ���: �蹮��, �й�: 20130162    --- */
/* ---    333 lines, �ۼ���: 2017. 9. 9.    --- */

#include "Tree.h"

void main()
{
	Tree<string> t;
	string input;

	cout << "���ڿ����� �Է��ϼ��� (�������� 0) : ";
	while (1)
	{
		cin >> input;
		if (input == "0") break;
		t.createNode(input);
	}
	
	t.showAll();
}