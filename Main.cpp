#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"

using namespace std;

int main() {
	MinHeap minheap;
	minheap.add(10);
	minheap.add(3);
	minheap.add(20);
	minheap.add(2);
	minheap.add(1);
	minheap.add(5);
	minheap.add(7);
	minheap.printAll();

	do {
		cout << minheap.pop() << endl;
	} while (minheap.size() > 0);



	MaxHeap maxheap;
	maxheap.add(10);
	maxheap.add(3);
	maxheap.add(20);
	maxheap.add(2);
	maxheap.add(1);
	maxheap.add(5);
	maxheap.add(7);
	maxheap.printAll();

	do {
		cout << maxheap.pop() << endl;
	} while (maxheap.size() > 0);

	return 0;
}