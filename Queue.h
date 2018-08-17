#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

/* Structure */
typedef struct Queue
{
	Node* front;
	int size;
} Queue;

/* Prototypes */
Queue* createQueue();
void destroyQueue(Queue** queue);
int enqueue(Queue* queue, void* data);
void* dequeue(Queue* queue);
void* peek(Queue* queue);
int getQueueSize(Queue* queue);

#endif
