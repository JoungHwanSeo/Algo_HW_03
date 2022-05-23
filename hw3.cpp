#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "List.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "AdjarrGraph.h"

#define idx(x) x-1

using namespace std;

int main(int argc, char** argv) {

	clock_t start, finish;
	double duration;

	int v; // vertex개수 받아옴
	int edgenum; // 각 vertex가 가지는 edge개수 받아옴
	int tovertex; //각 vertex가 어느 vertex로 이어지는지 받아옴

	int a = 3;

	if (a == 1) {
		///////Matrix!!////////
		ifstream ifs("input1.txt");
		ifs >> v; //vertex 개수


		MatrixGraph* mgraph = new MatrixGraph(v, "adj_mat_output.txt");

		int edgenum; // 각 vertex가 가지는 edge개수 받아옴
		int tovertex; //각 vertex가 어느 vertex로 이어지는지 받아옴

		for (int i = 1; i <= v; i++) {
			ifs >> edgenum; // i번째 vertex에서 가지는 vertex개수
			for (int j = 0; j < edgenum; j++) {
				ifs >> tovertex;

				//matrix 구현

				mgraph->AddEdge(i, tovertex);

			}
		}

		//여기까지 graph 완성됨

		start = clock();
		mgraph->firstDFS();

		mgraph->secondDFS();
		finish = clock();
		duration = (double)(finish - start);
		mgraph->writetime(duration);

		/// 마무리!!! delete 등 해주기
		delete mgraph;
	}
	else if (a == 2) {

		ifstream ifs("input1.txt");
		ifs >> v; //vertex 개수

		ListGraph* listgraph = new ListGraph(v, "adj_list_output.txt");

		for (int i = 1; i <= v; i++) {
			ifs >> edgenum; // i번째 vertex에서 가지는 vertex개수
			for (int j = 0; j < edgenum; j++) {
				ifs >> tovertex;

				//List 구현

				listgraph->AddEdge(i, tovertex);

			}
		}
		//여기까지 그래프 완성됨

		start = clock();

		listgraph->FirstDFS();
		listgraph->secondDFS();

		finish = clock();
		duration = (double)(finish - start);
		listgraph->wrtietime(duration);



		/////////마무리 delete등...
		delete listgraph;
	}
	else {
		ifstream ifs("input1.txt");
		ifs >> v; //vertex 개수

		//ListGraph* listgraph = new ListGraph(v, "adj_list_output.txt");
		AdjarrGraph* arrgraph = new AdjarrGraph(v, "adj_arr_output.txt");

		for (int i = 1; i <= v; i++) {
			ifs >> edgenum; // i번째 vertex에서 가지는 vertex

			for (int j = 0; j < edgenum; j++) {
				ifs >> tovertex;

				//arr구현
				arrgraph->AddEdge(i, tovertex);

				//listgraph->AddEdge(i, tovertex);

			}
		}

		arrgraph->CompleteGraph();
		//그래프 읽어오는 시간 여기서 그래프 완성

		start = clock();

		arrgraph->firstDFS();
		arrgraph->secondDFS();

		finish = clock();
		duration = (double)(finish - start);
		arrgraph->wrtietime(duration);

		delete arrgraph;
	}
}