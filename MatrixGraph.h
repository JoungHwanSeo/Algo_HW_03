#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>

#define TRUE 1
#define FASLE 0

using namespace std;

///���� ������ �͵� �����ؾ���...

class MatrixGraph {
public:
	int* visitinfo;
	//int* finishorder;

	int* Vertexorder;

	int** matrix;
	int numV;
	int numE;

	int order;  //DFS�� ���

	ofstream ofs;

	MatrixGraph(int numv,string filename); //�����ڿ��� Vertex���� ������

	~MatrixGraph(); //delete, close��...

	void AddEdge(int fromV, int toV);

	void DFS(int fromV);  //���� �� oreder = 0�� �ʱ�ȭ �������

	void firstDFS();

	void reverseDFS(int fromV); //������ DFS

	void secondDFS(); 

	void writetime(double duration);

	void printM();
};