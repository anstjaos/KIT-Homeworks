#pragma once
#include "CommonHeader.h"

class WeightedEdge					// ����ġ�� �ִ� ������ ������ ��� Ŭ����
{
private:
	int vertex1;
	int vertex2;
	int weight;
	bool selected;					// ���É���� ���θ� �Ǵ��ϴ� ����
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