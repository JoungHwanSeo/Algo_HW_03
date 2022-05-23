#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int numv,string filename) {
	matrix = new int*[numv+1];
	for (int i = 0; i <= numv; i++) {
		matrix[i] = new int[numv+1];
		for (int j = 0; j <= numv; j++)
			matrix[i][j] = 0;
	}


	//0�� index�� ������� ����...
	visitinfo = new int[numv + 1];
	//finishorder = new int[numv + 1];
	Vertexorder = new int[numv + 1];
	memset(visitinfo, 0, sizeof(int) * (numv + 1));
	//memset(finishorder, 0, sizeof(int) * numv);
	memset(Vertexorder, 0, sizeof(int) * (numv + 1));

	numV = numv;
	numE = 0;

	order = 0; //DFS�� ���

	ofs.open(filename);
}

MatrixGraph::~MatrixGraph() {
	ofs.close();
	for (int i = 0; i <= numV; i++)
		delete[] matrix[i];
	delete[]matrix;

	delete[]visitinfo;
	delete[] Vertexorder;
}

void MatrixGraph::AddEdge(int fromV, int toV) {
	matrix[fromV][toV] = 1;
	numE++;
}

void MatrixGraph::DFS(int fromV) { //���� �� order 0�� �ʱ�ȭ ����� ��
	visitinfo[fromV] = TRUE; //�ϴ� �湮�����Ƿ� TRUE
	for (int i = 1; i <= numV; i++) { //fromV�� ����� i��° vertex �ִ°�
		if (matrix[fromV][i]) { //i��° vertex�� ����Ǿ� ������(edge ������)
			if (!visitinfo[i]) { //�湮�� ���� �ƴ� ���
				DFS(i);
			}
		}
	}
	//finishorder[fromV] = ++order; //�ش� ������ DFS������ 
	Vertexorder[++order] = fromV;  //idx�� �ش� order�� Vertex return

	//cout << "Vertex : " << fromV << "  finish : " << order << endl;
}

void MatrixGraph::firstDFS() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, numV);
	int startV = dis(gen);
	DFS(startV);
	for (int i = 1; i <= numV; i++) {
		if (!visitinfo[i]) {  //�ش� vertex�� �湮���� �ʾҴٸ�

			//cout << "DFS new start" << endl;

			DFS(i); //�湮 �ȵ� ������ DFS����
		}
		//i�� �ʱ�ȭ���� �ʿ�� ����... 
	}
	order = 0;


	memset(visitinfo, 0, sizeof(int) * (numV+1));
	//visitinfo�� �ٽ� �ʱ�ȭ
}

void MatrixGraph::reverseDFS(int fromV) {
	//���� ������� ��
	visitinfo[fromV] = TRUE;  //�̰� ���������� ���� ��� ����
	for (int i = 0; i < numV; i++) {
		if (matrix[i][fromV]) { //�������� graph�� column row ���� �ݴ�
			//�������� �� ���� fromV->i �� �ִ��� ������
			//���� ���� i -> fromV�� �ִ����� ������ ����
			if (!visitinfo[i]) { //fromV�� �̿��� �湮���� ���� vertex i
				reverseDFS(i);
			}
		}
	}
	ofs << fromV << " "; //�� reverse DFS ������ ������ ��� ���ٿ� ��������
	cout << fromV << " ";

}

void MatrixGraph::secondDFS() {
	int startV = Vertexorder[numV]; //���� �ʰ� ���� �� ���� ����
	reverseDFS(startV);

	cout << endl;
	ofs << endl; //�� reverseDFS���������� ����ֱ�
	for (int i = numV; i >= 1; i--) {
		if (!visitinfo[Vertexorder[i]]) {
			//���� �ð��� ū �������� visit���� Ȯ��
			//vi
			reverseDFS(Vertexorder[i]);
			//�湮 �ȵ� �� �� ���� ���� �ð��� ū �Ϳ��� reverseDFS
			ofs << endl;
			cout << endl;
		}
	}

	memset(visitinfo, 0, sizeof(int) * (numV + 1));
}

void MatrixGraph::writetime(double duration) {
	ofs << duration << "ms";
}

void MatrixGraph::printM() {
	for (int i = 0; i <= numV; i++) {
		for (int j = 0; j <= numV; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}