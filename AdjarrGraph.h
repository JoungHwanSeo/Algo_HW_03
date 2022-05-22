#pragma once
#include <iostream>
#include "adjarray.h"

class AdjarrGraph {
public:
	adjarray* adjarr;

	AdjarrGraph(int numv,int nume);

	void swap(int arr[], int a,int b);

	void quicksort(int arr[],int p,int r);

	int partition(int arr[],int p,int r);

	void AddEdge(int fromV, int V[]);
};
