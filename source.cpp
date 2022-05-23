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
	ifs >> v; //vertex ����

	int edgenum; // �� vertex�� ������ edge���� �޾ƿ�
	int tovertex; //�� vertex�� ��� vertex�� �̾������� �޾ƿ�

	ListGraph* listgraph = new ListGraph(v, "adj_list_output.txt");

	for (int i = 1; i <= v; i++) {
		ifs >> edgenum; // i��° vertex���� ������ vertex����
		for (int j = 0; j < edgenum; j++) {
			ifs >> tovertex;

			//List ����

			listgraph->AddEdge(i, tovertex);

		}
	}
	//listgraph->print();

	listgraph->FirstDFS();

	listgraph->secondDFS();

	

	/////////������ delete��...
	delete listgraph;


	///////Matrix!!////////
	/*MatrixGraph* mgraph = new MatrixGraph(v,"adj_mat_output.txt");

	int edgenum; // �� vertex�� ������ edge���� �޾ƿ�
	int tovertex; //�� vertex�� ��� vertex�� �̾������� �޾ƿ�

	for (int i = 1; i <= v; i++) {
		ifs >> edgenum; // i��° vertex���� ������ vertex����
		for (int j = 0; j < edgenum; j++) {
			ifs >> tovertex;

			//matrix ����

			mgraph->AddEdge(i, tovertex);

		}
	}

	mgraph->printM();

	mgraph->firstDFS();

	mgraph->secondDFS();

	for (int i = 1; i <= v; i++)
		cout << mgraph->visitinfo[i] << " ";

	/// ������!!! delete �� ���ֱ�
	delete mgraph;*/

	/////////////////////////////////////////////////////////////
	///List
	////////////////////////////////////////////////////////////


	/*ifstream ifs("input.txt");
	int v;
	int* edge = nullptr;
	int tovertex;
	ifs >> v; //vertex ����
	
	int** matrix = new int*[v];
	for (int i = 0; i < v; i++) {
		matrix[i] = new int[v];
		for (int j = 0; j < v; j++)
			matrix[i][j] = 0;
	}

	List* listarr = new List[v]; // ũ�Ⱑ v�� list�� pointer�� ��� arr

	int edgenum;

	int* accedgenum = new int[v]; //�� vertex���� ���� edge������ ����
	
	int edgesize = 0;

	for (int i = 1; i <= v; i++) {
		ifs >> edgenum; // i��° vertex���� ������ vertex����
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
		/// i =0�� ���
		for (int j = 0; j < accedgenum[i]; j++) {
			listarr[i].LFisrt(&(adjarr->array[j]));
			while(listarr[i].LNext(&(adjarr->array[j])))

		}
	}






	//////////������.. delete��...
	delete[]listarr;

	delete[]accedgenum;

	delete adjarr;

	for (int i = 0; i < v; i++) 
		delete[]matrix[i];
	delete[]matrix;

	ifs.close();*/
}