#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

#define TRUE 1
#define FALSE 0

using namespace std;


class AdjarrGraph {
public:
	int numV;
	int numE;
	int* visitinfo;
	int* Vertexorder;
	int order;
	ofstream ofs;

	int* accumarr; //idx��° vertex���� ������ edge����
	vector<int>* tmpvec; // �ӽ÷� �� vertex�� edge�� ������ vector
	int* finalarr;

	//reverse��
	int* raccumarr;
	vector<int>* rtmpvec;
	int* rfinalarr;


	AdjarrGraph(int numv,string filename);

	~AdjarrGraph();

	void AddEdge(int fromV, int toV);

	void CompleteGraph(); //AddEdge�� ��� ������ �� ����

	void DFS(int fromV);

	void firstDFS();

	void reverseDFS(int fromV);

	void secondDFS();

	void wrtietime(double time);

	void print(); //������

	void printacc(); //������

	void printfinal(); //������




	void swap(int arr[], int a, int b);

	void quicksort(int arr[], int p, int r);

	int partition(int arr[], int p, int r);
};
