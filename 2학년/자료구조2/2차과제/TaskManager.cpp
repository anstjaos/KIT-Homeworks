#include "TaskManager.h"

void TaskManager::search()
{
	string fileName;
	cout << endl << "파일명을 입력하세요(종료는 quit): ";
	cin >> fileName;

	if (fileName == "quit")
	{
		cout << "종료합니다." << endl;
		return;
	}

	AdjancencyArray adjArr;
	adjArr.roadFile(fileName);
	adjArr.displayArray();

	AdjacencyList adjList;
	adjList.roadFile(fileName);
	adjList.displayList();

	cout << endl;
}

void TaskManager::minimumCostSpanningTree()
{
	string fileName;
	cout << endl << "무방향 가중치 그래프가 저장된 파일명을 입력하시오(종료는 quit): ";
	cin >> fileName;

	if (fileName == "quit")
	{
		cout << "종료합니다." << endl;
		return;
	}
	WeightedEdgeList we;
	we.roadFile(fileName);
	we.minCostSpanningTree();
	we.displayTree();

	cout << endl;
}

void TaskManager:: topologicalSort()
{
	string fileName;
	cout << endl << "방향 그래프가 저장된 파일명을 입력하시오(종료는 quit): ";
	cin >> fileName;

	if (fileName == "quit")
	{
		cout << "종료합니다." << endl;
		return;
	}
	topologicalOrder to;
	to.roadFile(fileName);
	to.displayTopologicalOrder();

	cout << endl;
}