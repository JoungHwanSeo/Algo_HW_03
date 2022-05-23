#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

#define TRUE 1
#define FASLE 0

using namespace std;

///간선 뒤집는 것도 구현해야함...

class MatrixGraph {
public:
	int* visitinfo;
	//int* finishorder;

	int* Vertexorder;

	int** matrix;
	int numV;
	int numE;

	int order;  //DFS시 사용

	ofstream ofs;

	MatrixGraph(int numv,string filename); //생성자에서 Vertex개수 정해짐

	~MatrixGraph(); //delete, close등...

	void AddEdge(int fromV, int toV);

	void DFS(int fromV);  //끝낸 뒤 oreder = 0로 초기화 해줘야함

	void firstDFS();

	void reverseDFS(int fromV); //뒤집은 DFS

	void secondDFS(); 

	void writetime(double duration);

	void printM();
};