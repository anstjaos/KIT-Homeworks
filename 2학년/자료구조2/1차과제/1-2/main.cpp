/* ---		pointer를 이용한 구현 방식		--- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    363 lines, 작성일: 2017. 9. 2.    --- */

#include "Tree.h"

void main()
{
	cout << "노드 개수를 입력하세요 : ";
	int nodeCount;
	cin >> nodeCount;

	Tree<int> t(nodeCount);
	t.printAll();
}