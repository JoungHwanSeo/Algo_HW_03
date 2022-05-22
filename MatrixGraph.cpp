#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int numv) {
	int** matrix = new int* [numv+1];
	for (int i = 1; i <= numv; i++) {
		matrix[i] = new int[numv+1];
		for (int j = 1; j <= numv; j++)
			matrix[i][j] = 0;
	}
	//0인 index는 사용하지 않음...
	visitinfo = new int[numv + 1];
	finishdrder = new int[numv + 1];
	memset(visitinfo, 0, sizeof(int) * numv);
	memset(finishdrder, 0, sizeof(int) * numv);

	numV = numv;
	numE = 0;

	order = 0; //DFS시 사용
}

void MatrixGraph::AddEdge(int fromV, int toV) {
	matrix[fromV][toV] = 1;
	numE++;
}

void MatrixGraph::DFS(int fromV) {
	visitinfo[fromV] = TRUE; //일단 방문했으므로 TRUE
	int num = 0;
	vector<int> adjvertex;
	for (int i = 1; i <= numV; i++) { //fromV에 연결된 i번째 vertex 있는가
		if (matrix[fromV][i]) { //i번째 vertex가 연결되어 있으면
			if (!visitinfo[i]) { //방문한 점이 아닌 경우
				DFS(i);
			}
		}
	}
	finishdrder[fromV] = ++order; //해당 점에서 DFS끝날시 
}