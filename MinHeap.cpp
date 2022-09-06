#include "MinHeap.h"
#include <iostream>
#include <stdio.h>

using namespace std;

MinHeap::MinHeap(){
	capacity = 50;
	arr = new int[capacity];
	mSize = 0;
}

MinHeap::~MinHeap() {
	delete[] arr;
}

int MinHeap::getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
int MinHeap::getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
int MinHeap::getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

bool MinHeap::hasLeftChild(int parentIndex) { return getLeftChildIndex(parentIndex) < mSize; }
bool MinHeap::hasRightChild(int parentIndex) { return getRightChildIndex(parentIndex) < mSize; }
bool MinHeap::hasParent(int childIndex) { return getParentIndex(childIndex) >= 0; }

int MinHeap::getLeftChild(int parentIndex) { return arr[getLeftChildIndex(parentIndex)]; }
int MinHeap::getRightChild(int parentIndex) { return arr[getRightChildIndex(parentIndex)]; }
int MinHeap::getParent(int childIndex) { return arr[getParentIndex(childIndex)]; }

void MinHeap::swap(int indexOne, int indexTwo) {
	int temp = arr[indexOne];
	arr[indexOne] = arr[indexTwo];
	arr[indexTwo] = temp;
}

void MinHeap::heapifyDown() {
	int index = 0;
	while (hasLeftChild(index)) {
		int smallerChildIndex = getLeftChildIndex(index);
		if (hasRightChild(index) && getRightChild(index) < arr[smallerChildIndex]) {
			smallerChildIndex = getRightChildIndex(index);
		}

		if (arr[index] < arr[smallerChildIndex]) {
			break;
		}
		else {
			swap(index, smallerChildIndex);
		}
		index = smallerChildIndex;
	}
}

void MinHeap::heapifyUp() {
	int index = mSize - 1;
	while (hasParent(index) && getParent(index) > arr[index]) {
		int parentIndex = getParentIndex(index);
		swap(parentIndex, index);
		index = parentIndex;
	}
}

void MinHeap::increaseCapacity() {
	int tempC = capacity;
	capacity = capacity * 2;
	int* newArr = new int[capacity];
	memcpy(newArr, arr, sizeof(int) * tempC);
	delete[] arr;
	arr = newArr;
}

void MinHeap::add(int x) {
	if (isFull()) increaseCapacity();
	arr[mSize] = x;
	mSize++;
	heapifyUp();
}

int MinHeap::pop() {
	if (isEmpty()) throw "Heap is Empty";
	int item = arr[0];
	arr[0] = arr[mSize - 1];
	mSize--;
	heapifyDown();
	return item;
}

int MinHeap::peek() {
	if (isEmpty()) throw "Heap is Empty";
	return arr[0];
}

void MinHeap::printAll() {
	if (!isEmpty()) {
		for (int i = 0; i < mSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

bool MinHeap::isFull() { return mSize >= capacity; }

bool MinHeap::isEmpty() { return mSize <= 0; }

int MinHeap::size() { return mSize; }