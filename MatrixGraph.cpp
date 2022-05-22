#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int numv) {
	int** matrix = new int* [numv+1];
	for (int i = 1; i <= numv; i++) {
		matrix[i] = new int[numv+1];
		for (int j = 1; j <= numv; j++)
			matrix[i][j] = 0;
	}
	//0�� index�� ������� ����...
	visitinfo = new int[numv + 1];
	finishdrder = new int[numv + 1];
	memset(visitinfo, 0, sizeof(int) * numv);
	memset(finishdrder, 0, sizeof(int) * numv);

	numV = numv;
	numE = 0;

	order = 0; //DFS�� ���
}

void MatrixGraph::AddEdge(int fromV, int toV) {
	matrix[fromV][toV] = 1;
	numE++;
}

void MatrixGraph::DFS(int fromV) {
	visitinfo[fromV] = TRUE; //�ϴ� �湮�����Ƿ� TRUE
	int num = 0;
	vector<int> adjvertex;
	for (int i = 1; i <= numV; i++) { //fromV�� ����� i��° vertex �ִ°�
		if (matrix[fromV][i]) { //i��° vertex�� ����Ǿ� ������
			if (!visitinfo[i]) { //�湮�� ���� �ƴ� ���
				DFS(i);
			}
		}
	}
	finishdrder[fromV] = ++order; //�ش� ������ DFS������ 
}