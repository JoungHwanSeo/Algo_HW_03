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

	string inputdirectory = argv[1];
	string outputdirectory = argv[2];
	string sel = argv[3];

	ifstream ifs(inputdirectory);

	clock_t start, finish;
	double duration;

	int v; // vertex���� �޾ƿ�
	int edgenum; // �� vertex�� ������ edge���� �޾ƿ�
	int tovertex; //�� vertex�� ��� vertex�� �̾������� �޾ƿ�

	string sel_1("adj_mat");
	string sel_2("adj_list");

	if (argv[3] == sel_1) {
		///////Matrix!!////////
		//ifstream ifs("input1.txt");
		ifs >> v; //vertex ����


		//MatrixGraph* mgraph = new MatrixGraph(v, "adj_mat_output.txt");
		MatrixGraph* mgraph = new MatrixGraph(v, outputdirectory);

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

		//������� graph �ϼ���

		start = clock();
		mgraph->firstDFS();

		mgraph->secondDFS();
		finish = clock();
		duration = (double)(finish - start);
		mgraph->writetime(duration);

		/// ������!!! delete �� ���ֱ�
		delete mgraph;
	}
	else if (argv[3] == sel_2) {

		//ifstream ifs("input1.txt");
		ifs >> v; //vertex ����

		//ListGraph* listgraph = new ListGraph(v, "adj_list_output.txt");
		ListGraph* listgraph = new ListGraph(v, outputdirectory);

		for (int i = 1; i <= v; i++) {
			ifs >> edgenum; // i��° vertex���� ������ vertex����
			for (int j = 0; j < edgenum; j++) {
				ifs >> tovertex;

				//List ����

				listgraph->AddEdge(i, tovertex);

			}
		}
		//������� �׷��� �ϼ���

		start = clock();

		listgraph->FirstDFS();
		listgraph->secondDFS();

		finish = clock();
		duration = (double)(finish - start);
		listgraph->wrtietime(duration);



		/////////������ delete��...
		delete listgraph;
	}
	else {
		//ifstream ifs("input1.txt");
		ifs >> v; //vertex ����

		//AdjarrGraph* arrgraph = new AdjarrGraph(v, "adj_arr_output.txt");
		AdjarrGraph* arrgraph = new AdjarrGraph(v, outputdirectory);

		for (int i = 1; i <= v; i++) {
			ifs >> edgenum; // i��° vertex���� ������ vertex

			for (int j = 0; j < edgenum; j++) {
				ifs >> tovertex;

				//arr����
				arrgraph->AddEdge(i, tovertex);


			}
		}

		arrgraph->CompleteGraph();
		//�׷��� �о���� �ð� ���⼭ �׷��� �ϼ�

		start = clock();

		arrgraph->firstDFS();
		arrgraph->secondDFS();

		finish = clock();
		duration = (double)(finish - start);
		arrgraph->wrtietime(duration);

		delete arrgraph;
	}
}