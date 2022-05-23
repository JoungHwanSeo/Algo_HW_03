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

	int* accumarr; //idx번째 vertex까지 누적된 edge개수
	vector<int>* tmpvec; // 임시로 각 vertex의 edge를 저장할 vector
	int* finalarr;

	//reverse용
	int* raccumarr;
	vector<int>* rtmpvec;
	int* rfinalarr;


	AdjarrGraph(int numv,string filename);

	~AdjarrGraph();

	void AddEdge(int fromV, int toV);

	void CompleteGraph(); //AddEdge가 모두 끝났을 때 실행

	void DFS(int fromV);

	void firstDFS();

	void reverseDFS(int fromV);

	void secondDFS();

	void wrtietime(double time);

	void print(); //디버깅용

	void printacc(); //디버깅용

	void printfinal(); //디버깅용




	void swap(int arr[], int a, int b);

	void quicksort(int arr[], int p, int r);

	int partition(int arr[], int p, int r);
};
