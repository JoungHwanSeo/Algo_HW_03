#pragma once
#include <iostream>
#include <vector>

#define TRUE 1
#define FASLE 0

using namespace std;

///간선 뒤집는 것도 구현해야함...

class MatrixGraph {
public:
	int* visitinfo;
	int* finishdrder;
	int** matrix;
	int numV;
	int numE;

	int order;  //DFS시 사용

	MatrixGraph(int numv);

	void AddEdge(int fromV, int toV);

	void DFS(int fromV);
};