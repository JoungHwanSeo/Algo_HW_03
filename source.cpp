#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "adjarray.h"
#include "List.h"

#define idx(x) x-1

using namespace std;

int main(void) {
	ifstream ifs("input.txt");
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

	ifs.close();
}