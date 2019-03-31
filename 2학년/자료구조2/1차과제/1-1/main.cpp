/* ---				배열 구현 방식			--- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    210 lines, 작성일: 2017. 8. 27.   --- */

#include "Tree.h"

void main()
{
	int capacity;
	cout << "노드 개수를 입력하세요 : ";
	cin >> capacity;

	Tree<int> t(capacity);
	t.printAll();
}