#include "AdjacencyArray.h"

AdjancencyArray ::~AdjancencyArray()
{
	for (int i = 0; i < size; i++)
	{
		delete[] adjArray[i];
	}
	delete[] adjArray;
}

void AdjancencyArray:: roadFile(string fileName)
{
	ifstream fin;
	fin.open(fileName, ios_base::in);
	if (fin.fail())
	{
		cout << "������ �������� �ʽ��ϴ�." << endl;
		return;
	}

	fin >> size;
	adjArray = new int*[size];
	for (int i = 0; i < size; i++)						// ������ ���� �迭 ����
	{
		adjArray[i] = new int[size];
		memset(adjArray[i], 0, sizeof(int) * size);
	}

	int from;
	int to;
	while (!fin.eof())
	{
		fin >> from;
		if (from == -1) break;
		fin >> to;

		adjArray[from][to] = 1;
		adjArray[to][from] = 1;
	}
	fin.close();
}

void AdjancencyArray:: displayArray()
{
	cout << endl << "�Էµ� �׷����� ���� ��� ǥ��" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << adjArray[i][j] << " ";
		}
		cout << endl;
	}

	bool *visit = new bool[size];				// �湮�� ���� �����ϴ� �迭�� ���� �Ҵ�
	fill(visit, visit + size, false);			// �迭 �ʱ�ȭ

	cout << "\n1.\t������� + DFS" << endl;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t������ " << count << " - ";
		displayDFS(i,visit);
		count++;
		cout << endl;
	}

	count = 1;
	fill(visit, visit + size, false);			// �迭 �ʱ�ȭ
	cout << "\n2.\t������� + BFS" << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t������ " << count << " - ";
		displayBFS(i,visit);
		count++;
	}
	delete[] visit;
}

void AdjancencyArray::displayDFS(int start, bool *visit)		// ��ͷ� ����
{
	cout << start << " ";
	visit[start] = true;
	for (int i = 0; i < size; i++)
	{
		if (adjArray[start][i] == 1 && visit[i] == false)
		{
			displayDFS(i,visit);
		}
	}
}

void AdjancencyArray:: displayBFS(int start, bool *visit)
{
	Queue<int> q;
	q.push(start);
	visit[start] = true;
	
	while(!q.isEmpty())
	{
		int temp = q.getFront();
		cout << temp << " ";
		q.pop();

		for (int i = 0; i < size; i++)
		{
			if (adjArray[temp][i] == 1 && visit[i] == false)
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}
	cout << endl;
}