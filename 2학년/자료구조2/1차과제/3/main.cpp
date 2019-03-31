/* ---	 문자열에 대한 binary search tree	--- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    333 lines, 작성일: 2017. 9. 9.    --- */

#include "Tree.h"

void main()
{
	Tree<string> t;
	string input;

	cout << "문자열들을 입력하세요 (마지막은 0) : ";
	while (1)
	{
		cin >> input;
		if (input == "0") break;
		t.createNode(input);
	}
	
	t.showAll();
}