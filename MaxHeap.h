#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap {
private:
	int mSize;
	int* arr;
	int capacity;

	int getLeftChildIndex(int parentIndex);
	int getRightChildIndex(int parentIndex);
	int getParentIndex(int childIndex);

	bool hasLeftChild(int parentIndex);
	bool hasRightChild(int parentIndex);
	bool hasParent(int childIndex);

	int getLeftChild(int parentIndex);
	int getRightChild(int parentIndex);
	int getParent(int childIndex);

	void swap(int indexOne, int indexTwo);

	void heapifyDown();

	void heapifyUp();

	void increaseCapacity();

public:
	MaxHeap();

	~MaxHeap();

	void add(int x);

	int pop();

	int peek();

	bool isFull();

	bool isEmpty();

	int size();

	void printAll();
};

#endif // !MAXHEAP_H