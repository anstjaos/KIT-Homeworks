#include "WeightedEdgeList.h"

WeightedEdgeList:: WeightedEdgeList()
{
	count = 0;
	capacity = 4;
	weList = new WeightedEdge[capacity];
}

WeightedEdgeList:: ~WeightedEdgeList()
{
	delete[] weList;
	delete[] parents;
}

void WeightedEdgeList:: changeSize()
{
	WeightedEdge *temp = new WeightedEdge[capacity * 2];
	copy(weList, weList + capacity, temp);
	capacity = capacity * 2;
	delete[] weList;
	weList = temp;
}

void WeightedEdgeList::insertEdge(WeightedEdge e)
{
	if (count == capacity) changeSize();

	weList[count++] = e;
}

void WeightedEdgeList::sortList(int left, int right)
{
	int leftIndex = left;
	int rightIndex = right;
	int pivot = weList[(left + right) / 2].getWeight();

	while (leftIndex <= rightIndex)
	{
		while (weList[leftIndex].getWeight() < pivot) leftIndex++;
		while (weList[rightIndex].getWeight() > pivot) rightIndex--;

		if (leftIndex <= rightIndex)
		{
			swap(weList[leftIndex], weList[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}

	if (left < rightIndex) sortList(left, rightIndex);
	if (right > leftIndex) sortList(leftIndex, right);
}

void WeightedEdgeList::weightedUnion(int vertex1, int vertex2)
{
	int temp = parents[vertex1] + parents[vertex2];
	if (parents[vertex1] > parents[vertex2])
	{
		parents[vertex1] = vertex2;
		parents[vertex2] = temp;
	}
	else
	{
		parents[vertex2] = vertex1;
		parents[vertex1] = temp;
	}
}

int WeightedEdgeList::collapsingFind(int vertex)
{
	int root;
	for (root = vertex; parents[root] >= 0; root = parents[root]);

	while (vertex != root)
	{
		int temp = parents[vertex];
		parents[vertex] = root;
		vertex = temp;
	}
	return root;
}

void WeightedEdgeList::roadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "파일이 존재하지 않습니다." << endl;
		return;
	}

	fin >> vertexCount;
	parents = new int[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		parents[i] = -1;			// -1로 초기화
	}

	int vertex1;
	int vertex2;
	int weight;
	while (!fin.eof())
	{
		fin >> vertex1;
		if (vertex1 == -1) break;
		fin >> vertex2 >> weight;
		WeightedEdge e(vertex1, vertex2, weight);
		insertEdge(e);
	}
	fin.close();
}

void WeightedEdgeList:: minCostSpanningTree()
{
	sortList(0, count - 1);
	for (int i = 0; i < count; i++)
	{
		WeightedEdge we = weList[i];
		int vertex1 = we.getVertex1();
		int vertex2 = we.getVertex2();
		
		if (parents[vertex1] == -1 && parents[vertex2] == -1)
		{
			weightedUnion(vertex1, vertex2);
			weList[i].setSelected();
		}
		else if (parents[vertex1] == parents[vertex2] && parents[vertex1] > 0 && parents[vertex2] > 0) continue;	// 두 개의 정점의 부모가 같을 경우 continue;
		else
		{
			int root1 = collapsingFind(vertex1);
			int root2 = collapsingFind(vertex2);

			if (root1 == root2) continue;				// 두 정점의 root가 같을 경우 continue;
			else										// 두 정점의 root가 다를 경우 트리를 합친다.
			{
				weightedUnion(root1, root2);
				for (int i = 0; i < count; i++)
				{
					if(parents[i] == vertex1) collapsingFind(i);		// 자기 자신을 부모로 가지는 정점을 붕괴시킨다.
					if(parents[i] == vertex2) collapsingFind(i);
				}
				weList[i].setSelected();
			}
		}
	}
}

void WeightedEdgeList::displayTree()
{
	int check = 0;
	for (int i = 0; i < count; i++)
	{
		if (weList[i].getSelected() == true) check++;
	}

	if (check != vertexCount - 1)				// 최소비용 신장트리는 항상 (정점 개수 -1)의 간선을 가진다.
	{
		cout << endl << "최소비용 신장트리를 구할 수 없음" << endl;
		return;
	}

	cout << endl << "선택된 간선 ";
	for (int i = 0; i < count; i++)
	{
		if (weList[i].getSelected() == true)
		{
			cout << "(" << weList[i].getVertex1() << " " << weList[i].getVertex2() << " " << weList[i].getWeight() << ") ";
		}
	}
	cout << "\n최소비용 신장트리를 구할 수 있음" << endl;
	cout << "최소 비용은 ";

	check = 0;
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		if (weList[i].getSelected() == true)
		{
			check++;
			sum = sum + weList[i].getWeight();
			if (check == vertexCount - 1)
			{
				cout << weList[i].getWeight() << " = " << sum << endl;
				break;
			}
			else cout << weList[i].getWeight() << "+";
		}
	}
}