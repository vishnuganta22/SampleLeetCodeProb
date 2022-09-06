#ifndef QNODE_H
#define QNODE_H

#include "Node.h"

struct QNode
{
	Node* data;
	QNode* next;
};

#endif // !QNODE_H