#pragma once
#include "List.h"

class ListGraph {
public:
	int numV;
	int numE;
	List* adjlist;
	int* VisitInfo;

	ListGraph(int vertexnum);
	void AddEdge(int fromV, int toV);
};