#ifndef QUEUELL_H
#define QUEUELL_H

#include "QNode.h"

class QueueLL {
private:
	QNode* front;
	QNode* back;
	int mSize;
public:
	QueueLL();
	bool isEmpty();
	void enqueue(Node* data);
	Node* dequeue();
	Node* peek();
	int size();
	void printAll();
};

#endif // !QUEUELL_H