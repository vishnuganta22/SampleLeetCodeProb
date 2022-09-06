#include "MaxHeap.h"
#include <iostream>
#include <stdio.h>

using namespace std;

MaxHeap::MaxHeap(){
	capacity = 50;
	arr = new int[capacity];
	mSize = 0;
}

MaxHeap::~MaxHeap() {
	delete[] arr;
}

int MaxHeap::getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
int MaxHeap::getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
int MaxHeap::getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

bool MaxHeap::hasLeftChild(int parentIndex) { return getLeftChildIndex(parentIndex) < mSize; }
bool MaxHeap::hasRightChild(int parentIndex) { return getRightChildIndex(parentIndex) < mSize; }
bool MaxHeap::hasParent(int childIndex) { return getParentIndex(childIndex) >= 0; }

int MaxHeap::getLeftChild(int parentIndex) { return arr[getLeftChildIndex(parentIndex)]; }
int MaxHeap::getRightChild(int parentIndex) { return arr[getRightChildIndex(parentIndex)]; }
int MaxHeap::getParent(int childIndex) { return arr[getParentIndex(childIndex)]; }

void MaxHeap::swap(int indexOne, int indexTwo) {
	int temp = arr[indexOne];
	arr[indexOne] = arr[indexTwo];
	arr[indexTwo] = temp;
}

void MaxHeap::heapifyDown() {
	int index = 0;
	while (hasLeftChild(index)) {
		int smallerChildIndex = getLeftChildIndex(index);
		if (hasRightChild(index) && getRightChild(index) > arr[smallerChildIndex]) {
			smallerChildIndex = getRightChildIndex(index);
		}

		if (arr[index] > arr[smallerChildIndex]) {
			break;
		}
		else {
			swap(index, smallerChildIndex);
		}
		index = smallerChildIndex;
	}
}

void MaxHeap::heapifyUp() {
	int index = mSize - 1;
	while (hasParent(index) && getParent(index) < arr[index]) {
		int parentIndex = getParentIndex(index);
		swap(parentIndex, index);
		index = parentIndex;
	}
}

void MaxHeap::increaseCapacity() {
	int tempC = capacity;
	capacity = capacity * 2;
	int* newArr = new int[capacity];
	memcpy(newArr, arr, sizeof(int) * tempC);
	delete[] arr;
	arr = newArr;
}

void MaxHeap::add(int x) {
	if (isFull()) increaseCapacity();
	arr[mSize] = x;
	mSize++;
	heapifyUp();
}

int MaxHeap::pop() {
	if (isEmpty()) throw "Heap is Empty";
	int item = arr[0];
	arr[0] = arr[mSize - 1];
	mSize--;
	heapifyDown();
	return item;
}

int MaxHeap::peek() {
	if (isEmpty()) throw "Heap is Empty";
	return arr[0];
}

void MaxHeap::printAll() {
	if (!isEmpty()) {
		for (int i = 0; i < mSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

bool MaxHeap::isFull() { return mSize >= capacity; }

bool MaxHeap::isEmpty() { return mSize <= 0; }

int MaxHeap::size() { return mSize; }