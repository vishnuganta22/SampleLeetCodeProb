#include <iostream>
#include "QueueLL.h"

using namespace std;

QueueLL::QueueLL() {
	mSize = 0;
	front = NULL;
	back = NULL;
};

bool QueueLL::isEmpty() {
	return front == NULL;
};

void QueueLL::enqueue(Node* data) {
	if (isEmpty()) {
	}
};