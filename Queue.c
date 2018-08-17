#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Queue.h"

//  Creates an empty queue
Queue* createQueue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue*));
	if(queue == NULL)
	{
		return NULL;
	}

	queue->front = NULL;
	queue->size = 0;

	return queue;
}

//  Destroys the queue
void destroyQueue(Queue** queue_ptr)
{
	if(queue_ptr == NULL || *queue_ptr == NULL)
	{
		return; 
	}

	while((*queue_ptr)->front != NULL)
	{
		dequeue(*queue_ptr);
	}

	free(*queue_ptr);
	*queue_ptr = NULL;
}

//  Enqueues the data into the queue
int enqueue(Queue* queue, void* data)
{
	if(queue == NULL || data == NULL)
	{
		return FALSE;
	}	

	if(queue->front == NULL)
	{
		queue->front = data;
		return TRUE;
	}

	Node* tail = createNode(data);
	Node* current = queue->front;
	while(current->next != NULL)
	{
		current = current->next;
	}

	current->next = tail;
	++(queue->size);

	return TRUE;
}

//  Removes the node at the front of the queue and returns its data
void* dequeue(Queue* queue)
{
	if(queue == NULL || queue->front == NULL)
	{
		return NULL;
	}

	Node* old_front = queue->front;
	void* old_front_data = old_front->data;
	queue->front = old_front->next;
	destroyNode(&old_front);
	--(queue->size);

	return old_front_data;
}

//  Returns the value stored in the queue's front node
void* peek(Queue* queue)
{
	if(queue == NULL || queue->front == NULL)
	{
		return NULL;
	}

	return queue->front->data;
}

//  Returns the number of elements in the queue
int getQueueSize(Queue* queue)
{
	return queue->size;
}
