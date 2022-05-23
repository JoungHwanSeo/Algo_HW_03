#include "AdjarrGraph.h"

AdjarrGraph::AdjarrGraph(int numv,string filename) {
	ofs.open(filename);
	numV = numv;
	numE = 0;
	order = 0;

	visitinfo = new int[numv + 1]; //각 vertex의 visit정보
	Vertexorder = new int[numv + 1];
	memset(visitinfo, 0, sizeof(int) * (numv + 1));
	memset(Vertexorder, 0, sizeof(int) * (numv + 1));

	accumarr = new int[numv + 1];
	memset(accumarr, 0, sizeof(int) * (numv + 1));

	tmpvec = new vector<int>[numv + 1];

	//reverse용///////////////////////
	raccumarr = new int[numv + 1];
	memset(raccumarr, 0, sizeof(int) * (numv + 1));
	rtmpvec = new vector<int>[numv + 1];
	//reverse/////////////////////////

	ofs.open(filename);
}

AdjarrGraph::~AdjarrGraph() {
	delete[] visitinfo;
	delete[] Vertexorder;
	delete []accumarr;
	delete[]finalarr;
	ofs.close();
}


void AdjarrGraph::AddEdge(int fromV, int toV){
	accumarr[fromV] += 1;
	tmpvec[fromV].push_back(toV); //vec은 0부터 push_back됨....
	numE++;

	//reverse는 방향 반대
	raccumarr[toV] += 1;
	rtmpvec[toV].push_back(fromV); 
	//cout << "tmpvec[" << fromV << "] " << toV << endl;
}


void AdjarrGraph::CompleteGraph() {
	for (int i = 1; i < numV; i++) {
		accumarr[i + 1] += accumarr[i];
		raccumarr[i + 1] += raccumarr[i];
	}

	int idx = 0;
	int ridx = 0;
	finalarr = new int[numE + 1];
	rfinalarr = new int[numE + 1];
	for (int i = 1; i <= numV; i++) {
		for (size_t j = 0; j < tmpvec[i].size(); j++) {
			finalarr[++idx] = tmpvec[i][j];
		}
	}

	for (int i = 1; i <= numV; i++) {
		for (size_t j = 0; j < rtmpvec[i].size(); j++) {
			rfinalarr[++ridx] = rtmpvec[i][j];
		}
	}

	

	delete[] tmpvec;
}

void AdjarrGraph::DFS(int fromV) {
	visitinfo[fromV] = TRUE;
	int nextV;
	for (int i = accumarr[fromV - 1] + 1; i <= accumarr[fromV]; i++) {
		//해당 fromV에 이어진 vertex조사
		nextV = finalarr[i];
		if (visitinfo[nextV] == FALSE) {
			DFS(nextV);
		}
	}
	Vertexorder[++order] = fromV;

	//cout << "Vertex : " << fromV << "  finish : " << order << endl;
}

void AdjarrGraph::firstDFS() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, numV);
	int startV = dis(gen);
	DFS(startV);
	for (int i = 1; i <= numV; i++) {
		if (visitinfo[i] == FALSE) {
			DFS(i);
		}
	}
	order = 0;

	memset(visitinfo, 0, sizeof(int) * (numV + 1));

}

void AdjarrGraph::reverseDFS(int fromV) {
	visitinfo[fromV] = TRUE;
	int nextV;
	for (int i = raccumarr[fromV - 1] + 1; i <= raccumarr[fromV]; i++) {
		//해당 fromV에 이어진 vertex조사
		nextV = rfinalarr[i];///////////
		if (visitinfo[nextV] == FALSE) {
			reverseDFS(nextV);
		}
	}
	ofs << fromV << " ";
	cout << fromV << " ";

}

void AdjarrGraph::secondDFS() {
	int startV = Vertexorder[numV];
	reverseDFS(startV);

	ofs << endl;
	cout << endl;

	for (int i = numV; i >= 1; i--) {
		if (visitinfo[Vertexorder[i]] == FALSE) {
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

void AdjarrGraph::wrtietime(double time) {
	ofs << time << "ms";
	cout << time << "ms";
}

void AdjarrGraph::print() {
	for (int i = 1; i <= numV; i++) {
		cout << "Vertex [" << i << "] : ";
		for (int j = accumarr[i - 1] + 1; j <= accumarr[i]; j++) {
			cout << finalarr[j] << " ";
		}
		cout << endl;
	}
}


void AdjarrGraph::printacc() {
	for (int i = 0; i <= numV; i++)
		cout << accumarr[i] << " ";
	cout << endl;
}

void AdjarrGraph::printfinal() {
	for (int i = 1; i < numE; i++)
		cout << finalarr[i] << " ";
	cout << endl;
}




///Sort function...

void AdjarrGraph::swap(int arr[], int a, int b) {
	if (a == b)
		return;
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void AdjarrGraph::quicksort(int arr[], int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		quicksort(arr, p, q - 1);
		quicksort(arr, q + 1, r);
	}
}

int AdjarrGraph::partition(int arr[], int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (x > arr[j])
			swap(arr, ++i, j);
	}
	swap(arr, ++i, r);
	return i;
}
