#pragma once
#include "Queue.h"
#include "CommonHeader.h"

class AdjancencyArray {			// 무방향 그래프를 인접 행렬로 표현
private:
	int **adjArray;				// 2차원 동적 배열
	int size;					// 동적 배열 사이즈

	void displayDFS(int start, bool *visit);	// DFS 출력
	void displayBFS(int start, bool *visit);	// BFS 출력
public:
	AdjancencyArray() {}
	~AdjancencyArray();

	void roadFile(string fileName);				// 파일로 부터 정보를 읽어와 변수 초기화한다.
	void displayArray();
};