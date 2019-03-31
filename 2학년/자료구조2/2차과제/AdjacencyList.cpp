#include "AdjacencyList.h"

AdjacencyList ::~AdjacencyList()
{
	Stack<Node*> s;
	for (int i = 0; i < size; i++)
	{
		Node *ptr = adjList[i];
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
	delete[] adjList;
}

void AdjacencyList:: roadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "파일이 존재하지 않습니다." << endl;
		return;
	}

	fin >> size;
	adjList = new Node*[size];
	for (int i = 0; i < size; i++)
	{
		adjList[i] = NULL;
	}

	int from;
	int to;
	while (!fin.eof())
	{
		fin >> from;
		if (from == -1) break;
		fin >> to;

		if (adjList[from] == NULL)
		{
			adjList[from] = new Node(to, NULL);
		}
		else
		{
			Node *ptr = adjList[from];
			adjList[from] = new Node(to, ptr);
		}

		if (adjList[to] == NULL)
		{
			adjList[to] = new Node(from, NULL);
		}
		else
		{
			Node *ptr = adjList[to];
			adjList[to] = new Node(from, ptr);
		}
	}
	fin.close();
}

void AdjacencyList::displayList()
{
	cout << "\n입력된 그래프의 인접리스트 표현" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << " -> ";
		Node *ptr = adjList[i];
		if (ptr == NULL)
		{
			cout << "null" << endl;
			continue;
		}

		while (ptr != NULL)
		{
			if (ptr->link == NULL)
			{
				cout << ptr->data ;
				break;
			}
			else
			{
				cout << ptr->data << " - ";
				ptr = ptr->link;
			}
		}
		cout << endl;
	}

	bool *visit = new bool[size];					// 방문한 곳 저장하는 배열 동적 할당
	fill(visit, visit + size, false);

	cout << "\n3.\t인접리스트 + DFS" << endl;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t연결요소 " << count << " - ";
		displayDFS(i,visit);
		count++; 
		cout << endl;
	}

	fill(visit, visit + size, false);
	cout << "\n4.\t인접리스트 + BFS" << endl;

	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t연결요소 " << count << " - ";
		displayBFS(i,visit);
		count++;
	}
	delete[] visit;									// 동적 할당 해제
}

void AdjacencyList:: displayDFS(int start, bool *visit)
{
	cout << start << " ";
	visit[start] = true;
	Node *ptr = adjList[start];

	if (ptr == NULL) return;
	while (ptr != NULL)
	{
		if(visit[ptr->data] == false) displayDFS(ptr->data, visit);
		
		ptr = ptr->link;
	}
}

void AdjacencyList::displayBFS(int start, bool *visit)
{
	Queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.isEmpty())
	{
		int temp = q.getFront();
		cout << temp << " ";
		q.pop();

		for (Node *ptr = adjList[temp]; ptr != NULL; ptr = ptr->link)
		{
			if (visit[ptr->data] == false)
			{
				q.push(ptr->data);
				visit[ptr->data] = true;
			}
		}
	}
	cout << endl;
}