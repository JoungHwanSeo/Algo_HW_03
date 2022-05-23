#pragma once
#include "List.h"
#include <fstream>
#include <string>
#include <random>

#define TRUE 1
#define FALSE 0

class ListGraph {
public:
	int numV;
	int numE;
	List* adjlist;
	int* VisitInfo;
	int* Vertexorder; //�� idx�� order�̰� �� order�� vertex�� ����
	int order;

	List* reverselist;

	ofstream ofs;

	ListGraph(int vertexnum, string filename);

	~ListGraph();

	void AddEdge(int fromV, int toV);

	void DFS(int fromV);

	void FirstDFS();

	void reverseDFS(int fromV);

	void secondDFS();

	void wrtietime(double time);

	void print(); //������
};
