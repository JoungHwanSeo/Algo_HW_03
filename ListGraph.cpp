#include "ListGraph.h"

ListGraph::ListGraph(int vertexnum) {
	adjlist = new List[vertexnum];
	numV = vertexnum;
	numE = 0;
	VisitInfo = new int[vertexnum]; //�� vertex�� visit����
	memset(VisitInfo, 0, sizeof(int) * vertexnum);
}

void ListGraph::AddEdge(int fromV, int toV) {
	adjlist[fromV].Insert(toV);
	numE++;
}