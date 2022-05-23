#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "adjarray.h"
#include "List.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

#define idx(x) x-1

using namespace std;

int main(void) {



	ifstream ifs("input1.txt");
	int v;
	ifs >> v; //vertex 개수

	int edgenum; // 각 vertex가 가지는 edge개수 받아옴
	int tovertex; //각 vertex가 어느 vertex로 이어지는지 받아옴

	ListGraph* listgraph = new ListGraph(v, "adj_list_output.txt");

	for (int i = 1; i <= v; i++) {
		ifs >> edgenum; // i번째 vertex에서 가지는 vertex개수
		for (int j = 0; j < edgenum; j++) {
			ifs >> tovertex;

			//List 구현

			listgraph->AddEdge(i, tovertex);

		}
	}
	//listgraph->print();

	listgraph->FirstDFS();

	listgraph->secondDFS();

	

	/////////마무리 delete등...
	delete listgraph;


	///////Matrix!!////////
	/*MatrixGraph* mgraph = new MatrixGraph(v,"adj_mat_output.txt");

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

	mgraph->printM();

	mgraph->firstDFS();

	mgraph->secondDFS();

	for (int i = 1; i <= v; i++)
		cout << mgraph->visitinfo[i] << " ";

	/// 마무리!!! delete 등 해주기
	delete mgraph;*/

	/////////////////////////////////////////////////////////////
	///List
	////////////////////////////////////////////////////////////


	/*ifstream ifs("input.txt");
	int v;
	int* edge = nullptr;
	int tovertex;
	ifs >> v; //vertex 개수
	
	int** matrix = new int*[v];
	for (int i = 0; i < v; i++) {
		matrix[i] = new int[v];
		for (int j = 0; j < v; j++)
			matrix[i][j] = 0;
	}

	List* listarr = new List[v]; // 크기가 v인 list의 pointer를 담는 arr

	int edgenum;

	int* accedgenum = new int[v]; //각 vertex에서 누적 edge개수를 저장
	
	int edgesize = 0;

	for (int i = 1; i <= v; i++) {
		ifs >> edgenum; // i번째 vertex에서 가지는 vertex개수
		edgesize += edgenum;
		accedgenum[idx(i)] = edgesize;
		for (int j = 1; j <= edgenum; j++) {
			ifs >> tovertex;

			/////////////Matrix/////////////////
			matrix[idx(i)][idx(tovertex)] = 1; 

			//////////////list///////////////////////
			listarr[idx(i)].Insert(idx(tovertex));

			/////////////array////////////////////////
			

		}
	}
	adjarray* adjarr = new adjarray(v, edgesize);
	for (int i = 0; i < v; i++) {
		adjarr->accumsize[i] = accedgenum[i]; 
		/// i =0인 경우
		for (int j = 0; j < accedgenum[i]; j++) {
			listarr[i].LFisrt(&(adjarr->array[j]));
			while(listarr[i].LNext(&(adjarr->array[j])))

		}
	}






	//////////마무리.. delete등...
	delete[]listarr;

	delete[]accedgenum;

	delete adjarr;

	for (int i = 0; i < v; i++) 
		delete[]matrix[i];
	delete[]matrix;

	ifs.close();*/
}