#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class List {
private:
	Node* head;
	Node* cur;
	Node* before;
	int numofData;
public:
	List();
	bool LFisrt(int* pdata);
	bool LNext(int* pdata);
	void Insert(int data);
	int remove();
};