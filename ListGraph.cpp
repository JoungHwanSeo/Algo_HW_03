#include "ListGraph.h"

ListGraph::ListGraph(int vertexnum, string filename) {
	adjlist = new List[vertexnum + 1];
	reverselist = new List[vertexnum + 1];

	numV = vertexnum;
	numE = 0;
	VisitInfo = new int[vertexnum + 1]; //�� vertex�� visit����
	Vertexorder = new int[vertexnum + 1]; 
	memset(VisitInfo, 0, sizeof(int) * (vertexnum + 1));
	memset(Vertexorder, 0, sizeof(int) * (vertexnum + 1));
	order = 0;

	ofs.open(filename);
}

ListGraph::~ListGraph() {
	delete[]adjlist;
	delete[]reverselist;
	delete[]VisitInfo;
	delete[] Vertexorder;
	ofs.close();
}

void ListGraph::AddEdge(int fromV, int toV) {
	adjlist[fromV].Insert(toV);
	numE++;

	reverselist[toV].Insert(fromV); //revers�� ���ÿ� ����
}

void ListGraph::DFS(int fromV) {
	VisitInfo[fromV] = TRUE;
	int nextV;
	if (adjlist[fromV].LFisrt(&nextV)) {
		//���� �ϳ� �̻��� ���Ҹ� �߽߰�
		if (VisitInfo[nextV] == FALSE) {
			DFS(nextV);
		}
		while (adjlist[fromV].LNext(&nextV)) {
			if (VisitInfo[nextV] == FALSE) {
				DFS(nextV);
			}
		}
	}
	Vertexorder[++order] = fromV;

	//������... ���� ��������
	cout << "Vertex : " << fromV << "  finish : " << order << endl;
}

void ListGraph::FirstDFS() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, numV);
	int startV = dis(gen);
	DFS(startV);
	for (int i = 1; i <= numV; i++) {
		if (VisitInfo[i] == FALSE) {
			DFS(i);
		}
	}

	order = 0;

	memset(VisitInfo, 0, sizeof(int) * (numV + 1));
}

void ListGraph::reverseDFS(int fromV) {
	VisitInfo[fromV] = TRUE;
	int nextV;
	if (reverselist[fromV].LFisrt(&nextV)) {
		if (VisitInfo[nextV] == FALSE) {
			reverseDFS(nextV);
		}
		while (reverselist[fromV].LNext(&nextV)) {
			if (VisitInfo[nextV] == FALSE) {
				reverseDFS(nextV);
			}
		}
	}
	ofs << fromV << " ";
	cout << fromV << " ";
}

void ListGraph::secondDFS() {
	int startV = Vertexorder[numV];
	//���� �ʰ� ���� vertex���� ����
	reverseDFS(startV);
	ofs << endl;
	cout << endl;

	for (int i = numV; i >= 1; i--) {
		if (VisitInfo[Vertexorder[i]]==FALSE) {
			//���� �ð��� ū �������� visit���� Ȯ��
			//vi
			reverseDFS(Vertexorder[i]);
			//�湮 �ȵ� �� �� ���� ���� �ð��� ū �Ϳ��� reverseDFS
			ofs << endl;
			cout << endl;
		}
	}

	memset(VisitInfo, 0, sizeof(int) * (numV + 1));
}

void ListGraph::print() {
	int nextV;
	for (int i = 1; i <= numV; i++) {
		cout << "Vertex " << i << " : ";
		if (adjlist[i].LFisrt(&nextV)) {
			cout << nextV << " ";
			while (adjlist[i].LNext(&nextV)) {
				cout << nextV << " ";
			}
		}
		cout << endl;
	}
}