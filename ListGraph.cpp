#include "ListGraph.h"

ListGraph::ListGraph(int vertexnum) {
	adjlist = new List[vertexnum];
	numV = vertexnum;
	numE = 0;
	VisitInfo = new int[vertexnum]; //각 vertex의 visit정보
	memset(VisitInfo, 0, sizeof(int) * vertexnum);
}

void ListGraph::AddEdge(int fromV, int toV) {
	adjlist[fromV].Insert(toV);
	numE++;
}