#include "WeightedEdge.h"

WeightedEdge::WeightedEdge(int i_vertex1, int i_vertex2, int i_weight)
{
	vertex1 = i_vertex1;
	vertex2 = i_vertex2;
	weight = i_weight;
	selected = false;
}