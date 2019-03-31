#include "topologicalOrder.h"

topologicalOrder :: ~topologicalOrder() 
{ 
	Stack<Node*> s;
	for (int i = 0; i < count; i++)
	{
		Node* ptr = edgeList[i].link;
		while (ptr != NULL)
		{
			s.push(ptr);
			ptr = ptr->link;
		}

		while (!s.isEmpty())
		{
			ptr = s.getTop();
			s.pop();
			delete ptr;
		}
	}
	delete[] edgeList;
}

void topologicalOrder:: roadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "파일이 존재하지 않습니다." << endl;
		return;
	}

	fin >> count;
	edgeList = new Node[count];
	for (int i = 0; i < count; i++)
	{
		edgeList[i].data = 0;
		edgeList[i].link = NULL;
	}

	int from;
	int to;
	while (!fin.eof())
	{
		fin >> from;
		if (from == -1) break;
		fin >> to;

		if (edgeList[from].link == NULL)
		{
			edgeList[from].link = new Node(to, NULL);
		}
		else
		{
			Node *ptr = edgeList[from].link;
			edgeList[from].link = new Node(to, ptr);
		}
		edgeList[to].data++;
	}
	fin.close();
}

void topologicalOrder:: displayTopologicalOrder()
{
	Stack<int> s;
	int *visit = new int[count];
	int visitCnt = 0;

	for (int i = 0; i < count; i++)
	{
		if (edgeList[i].data != 0) continue;
		else s.push(i);

		while (!s.isEmpty())
		{
			int index = s.getTop();
			s.pop();
			visit[visitCnt++] = index;
			edgeList[index].data = -1;			// 방문한 곳 data를 -1로 변경
			Node *ptr = edgeList[index].link;

			while (ptr != NULL)
			{
				edgeList[ptr->data].data--;
				if (edgeList[ptr->data].data == 0)
				{
					s.push(ptr->data);
				}
				edgeList[index].link = ptr->link;
				delete ptr;
				ptr = edgeList[index].link;
			}
		}
	}

	if (visitCnt != count)						// visit 배열에 모든 정점이 있지 않을 경우 위상 정렬을 만들 수 없다.
	{
		cout << "위상 정렬을 만들 수 없습니다." << endl;
		return;
	}
	else
	{
		cout << endl << "가능한 하나의 위상 정렬 : ";
		for (int i = 0; i < visitCnt; i++)
		{
			cout << visit[i] << " ";
		}
		cout << endl;
	}
	delete[] visit;
}