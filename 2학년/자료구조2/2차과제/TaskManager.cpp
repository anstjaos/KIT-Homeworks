#include "TaskManager.h"

void TaskManager::search()
{
	string fileName;
	cout << endl << "���ϸ��� �Է��ϼ���(����� quit): ";
	cin >> fileName;

	if (fileName == "quit")
	{
		cout << "�����մϴ�." << endl;
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
	cout << endl << "������ ����ġ �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit): ";
	cin >> fileName;

	if (fileName == "quit")
	{
		cout << "�����մϴ�." << endl;
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
	cout << endl << "���� �׷����� ����� ���ϸ��� �Է��Ͻÿ�(����� quit): ";
	cin >> fileName;

	if (fileName == "quit")
	{
		cout << "�����մϴ�." << endl;
		return;
	}
	topologicalOrder to;
	to.roadFile(fileName);
	to.displayTopologicalOrder();

	cout << endl;
}