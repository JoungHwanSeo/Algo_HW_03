#include "adjarray.h"

adjarray::adjarray(int size,int arrsize) {
	accumsize = new int[size];
	array = new int[arrsize];
}

adjarray::~adjarray() {
	if (accumsize != nullptr)
		delete accumsize;
	if (array != nullptr)
		delete array;
}

//class adjarray {
//public:
//	int* accumsize;
//	int* array;
//
//	adjarray(int size);
//	~adjarray()
//};