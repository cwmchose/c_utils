#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{

	/*
	int data = NULL;
	Node* node = createNode(&data);
	if(node != NULL){
		printf("Node was not equal to null when created with null data pointer \n");
		return -1;
	}
	*/

	int data = 1;
	Node* node = createNode(&data);

	if(node == NULL)
	{	
		printf("Node was null after creation");
		return -1;
	}


	if(getNext(node) != NULL)
	{
		printf("next was not equal to null");
		return -1;
	}

	if( ((int*) getData(node)) != &data)
	{
		printf("data was equal to null");
		return -1;
	}
	
	if(hasNext(node) != FALSE)
	{
		printf("hasNext returned truen when expecting false");
		return -1;
	}


	Node* next = createNode(&data);

	if(setNext(node, next) == FALSE)
	{
		printf("next was unsuccessfully set");
		return -1;
	}

	if(hasNext(node) != TRUE)
	{
		printf("hasNext returned false when expecting true");
		return -1;
	}
	
	if(getNext(node) != next)
	{
		printf("getNext() did not return next");
		return -1;
	}

	if((int*) destroyNode(&node) != &data)
	{
		printf("destroyNode did not return data");
		return -1;
	}
	
	if(node != NULL)
	{
		printf("node is not NULL after being destroyed");
		return -1;
	}

	if(next == NULL)
	{
		printf("next was destroyed as well");
		return -1;
	}
	
	printf("swell\n");
	return 0;



}
