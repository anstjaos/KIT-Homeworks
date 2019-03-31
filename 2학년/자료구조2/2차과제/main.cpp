/* ---		   6장 과제 프로그래밍 	     	--- */
/* ---    작성자: 김문서, 학번: 20130162    --- */
/* ---    1023 lines, 작성일: 2017. 10. 5.  --- */

// 연결리스트나 행렬을 이용하지 않음. 왜냐하면 최소 비용 신장트리 프로그램에서는 
// Kruskal 알고리즘을 이용하여 구현했기 때문에 edge들을 객체 배열에 담아
// 비용이 작은 순부터 정렬을 해서 edge를 선택하고 사이클이 발생하지 않게
// 책의 Weighted Union과 CollapsingFind 함수를 사용하여 사이클이 발생하는지 확인하고
// 발생하지 않을 경우 edge를 선택하는 식으로 구현하였습니다.

#include "TaskManager.h"

void main()
{
	TaskManager tm;			// 메뉴를 관리하는 클래스 선언
	char menu;
	while (1)
	{
		cout << "프로그램을 선택하세요 ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit) : ";
		cin >> menu;
		switch (menu)
		{
		case 'S':				// DFS와 BFS
			tm.search();
			break;
		case 'M':				// 최소비용 신장트리
			tm.minimumCostSpanningTree();
			break;
		case 'T':				// 위상 정렬
			tm.topologicalSort();
			break;
		case 'Q':
			return;
		default:
			cout << "잘못된 프로그램을 선택하셨습니다." << endl;
			break;
		}
	}
}