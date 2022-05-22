#pragma once
#include <iostream>

class adjarray {
public:
	int* accumsize;
	int* array;

	adjarray(int size,int arrsize);
	~adjarray();
};