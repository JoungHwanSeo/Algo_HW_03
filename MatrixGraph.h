#pragma once
#include <iostream>
#include <vector>

#define TRUE 1
#define FASLE 0

using namespace std;

///���� ������ �͵� �����ؾ���...

class MatrixGraph {
public:
	int* visitinfo;
	int* finishdrder;
	int** matrix;
	int numV;
	int numE;

	int order;  //DFS�� ���

	MatrixGraph(int numv);

	void AddEdge(int fromV, int toV);

	void DFS(int fromV);
};