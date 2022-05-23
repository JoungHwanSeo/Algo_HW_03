#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int numv,string filename) {
	matrix = new int*[numv+1];
	for (int i = 0; i <= numv; i++) {
		matrix[i] = new int[numv+1];
		for (int j = 0; j <= numv; j++)
			matrix[i][j] = 0;
	}


	//0인 index는 사용하지 않음...
	visitinfo = new int[numv + 1];
	//finishorder = new int[numv + 1];
	Vertexorder = new int[numv + 1];
	memset(visitinfo, 0, sizeof(int) * (numv + 1));
	//memset(finishorder, 0, sizeof(int) * numv);
	memset(Vertexorder, 0, sizeof(int) * (numv + 1));

	numV = numv;
	numE = 0;

	order = 0; //DFS시 사용

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

void MatrixGraph::DFS(int fromV) { //끝낸 뒤 order 0로 초기화 해줘야 함
	visitinfo[fromV] = TRUE; //일단 방문했으므로 TRUE
	for (int i = 1; i <= numV; i++) { //fromV에 연결된 i번째 vertex 있는가
		if (matrix[fromV][i]) { //i번째 vertex가 연결되어 있으면(edge 있으면)
			if (!visitinfo[i]) { //방문한 점이 아닌 경우
				DFS(i);
			}
		}
	}
	//finishorder[fromV] = ++order; //해당 점에서 DFS끝날시 
	Vertexorder[++order] = fromV;  //idx가 해당 order의 Vertex return

	//cout << "Vertex : " << fromV << "  finish : " << order << endl;
}

void MatrixGraph::firstDFS() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, numV);
	int startV = dis(gen);
	DFS(startV);
	for (int i = 1; i <= numV; i++) {
		if (!visitinfo[i]) {  //해당 vertex를 방문하지 않았다면

			//cout << "DFS new start" << endl;

			DFS(i); //방문 안된 점에서 DFS시작
		}
		//i를 초기화해줄 필요는 없음... 
	}
	order = 0;


	memset(visitinfo, 0, sizeof(int) * (numV+1));
	//visitinfo를 다시 초기화
}

void MatrixGraph::reverseDFS(int fromV) {
	//순서 뒤집어야 함
	visitinfo[fromV] = TRUE;  //이건 뒤집어지고 말고 상관 없음
	for (int i = 0; i < numV; i++) {
		if (matrix[i][fromV]) { //뒤집어진 graph라서 column row 순서 반대
			//뒤집어진 것 기준 fromV->i 가 있느냐 문제는
			//원래 기준 i -> fromV가 있느냐의 문제와 같음
			if (!visitinfo[i]) { //fromV의 이웃중 방문되지 않은 vertex i
				reverseDFS(i);
			}
		}
	}
	ofs << fromV << " "; //한 reverse DFS 끝날시 강연결 요소 한줄에 나오도록
	cout << fromV << " ";

}

void MatrixGraph::secondDFS() {
	int startV = Vertexorder[numV]; //가장 늦게 끝난 것 부터 시작
	reverseDFS(startV);

	cout << endl;
	ofs << endl; //한 reverseDFS끝날때마다 띄어주기
	for (int i = numV; i >= 1; i--) {
		if (!visitinfo[Vertexorder[i]]) {
			//끝난 시간이 큰 순서부터 visit여부 확인
			//vi
			reverseDFS(Vertexorder[i]);
			//방문 안된 것 중 가장 끝난 시간이 큰 것에서 reverseDFS
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