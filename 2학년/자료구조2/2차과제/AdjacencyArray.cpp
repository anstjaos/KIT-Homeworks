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
		cout << "파일이 존재하지 않습니다." << endl;
		return;
	}

	fin >> size;
	adjArray = new int*[size];
	for (int i = 0; i < size; i++)						// 이차원 동적 배열 선언
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
	cout << endl << "입력된 그래프의 인접 행렬 표현" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << adjArray[i][j] << " ";
		}
		cout << endl;
	}

	bool *visit = new bool[size];				// 방문한 곳을 저장하는 배열을 동적 할당
	fill(visit, visit + size, false);			// 배열 초기화

	cout << "\n1.\t인접행렬 + DFS" << endl;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t연결요소 " << count << " - ";
		displayDFS(i,visit);
		count++;
		cout << endl;
	}

	count = 1;
	fill(visit, visit + size, false);			// 배열 초기화
	cout << "\n2.\t인접행렬 + BFS" << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (visit[i] == true) continue;

		cout << "\t연결요소 " << count << " - ";
		displayBFS(i,visit);
		count++;
	}
	delete[] visit;
}

void AdjancencyArray::displayDFS(int start, bool *visit)		// 재귀로 구현
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