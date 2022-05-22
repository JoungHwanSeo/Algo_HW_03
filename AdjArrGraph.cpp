#include "AdjarrGraph.h"

AdjarrGraph::AdjarrGraph(int vnum,int nume) {
	adjarr = new adjarray(vnum, nume);

}

void AdjarrGraph::swap(int arr[], int a, int b) {
	if (a == b)
		return;
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void AdjarrGraph::quicksort(int arr[], int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		quicksort(arr, p, q - 1);
		quicksort(arr, q + 1, r);
	}
}

int AdjarrGraph::partition(int arr[], int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (x > arr[j])
			swap(arr, ++i, j);
	}
	swap(arr, ++i, r);
	return i;
}


void AdjarrGraph::AddEdge(int fromV, int V[]) {

}

