#pragma once
#include "CommonHeader.h"

class WeightedEdge					// 가중치가 있는 간선의 정보를 담는 클래스
{
private:
	int vertex1;
	int vertex2;
	int weight;
	bool selected;					// 선택됬는지 여부를 판단하는 변수
public:
	WeightedEdge() {}
	WeightedEdge(int i_vertex1, int i_vertex2, int i_weight);
	~WeightedEdge() {}

	int getVertex1() { return vertex1; }
	int getVertex2() { return vertex2; }
	int getWeight() { return weight; }
	bool getSelected() { return selected; }
	
	void setSelected() { selected = true; }
};