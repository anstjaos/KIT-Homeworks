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
		cout << "������ �������� �ʽ��ϴ�." << endl;
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
	cout << "\n�Էµ� �׷����� ��������Ʈ ǥ��" << endl;
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

	bool *visit = new bool[size];					// �湮�� �� �����ϴ� �迭 ���� �Ҵ�
	fill(visit, visit + size, false);

	cout << "\n3.\t��������Ʈ + DFS" << endl;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t������ " << count << " - ";
		displayDFS(i,visit);
		count++; 
		cout << endl;
	}

	fill(visit, visit + size, false);
	cout << "\n4.\t��������Ʈ + BFS" << endl;

	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t������ " << count << " - ";
		displayBFS(i,visit);
		count++;
	}
	delete[] visit;									// ���� �Ҵ� ����
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