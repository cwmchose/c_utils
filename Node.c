#include <stdlib.h>
#include <stdio.h>
#include "Node.h"

//  Initializes new node struct
Node* createNode(void* data)
{
	if(data == NULL)
	{
		printf("Null reference to data");
		return NULL;
	}

	Node* node = malloc(sizeof(Node*));
	if(node == NULL)
	{
		printf("we fucked");
		return NULL;
	}


	setNext(node, NULL); //  Default next node is null
	node->data = data;

	return node;
}

//  Destroys node struct
void* destroyNode(Node** node_ptr)
{
	//  Returns NULL if reference to node pointer does not exist
	if(node_ptr == NULL)
	{
		printf("Pointer to node pointer was null");
		return NULL;
	}
	//  Returns NULL if dereferenced node pointer does not exist
	if(*node_ptr == NULL)
	{
		return NULL;
	}
	
	void* node_data = (*node_ptr)->data; //  Stores data reference before it's freed

	//  Frees the reference to the next node
	free((*node_ptr)->next);
	(*node_ptr)->next = NULL;

	//  Frees the reference to the node's data
	free((*node_ptr)->data);
	(*node_ptr)->data = NULL;

	//  Frees the reference to the node
	free(*node_ptr);
	*node_ptr = NULL;

	return node_data;
}

//  Sets the node's reference to the next node
int setNext(Node* node, Node* next)
{
	if(node == NULL || next == NULL)
	{
		printf("Starting node or next node was null");
		return FALSE;
	}

	node->next = next;
	return TRUE;
}

//  Returns a reference to a node's next node
Node* getNext(Node* node)
{
	if(node == NULL)
	{
		printf("Current node was null");
		return NULL;
	}

	return node->next;
}

//  Returns TRUE or FALSE if the node node has a reference to a next node
int hasNext(Node* node)
{
	if(node == NULL)
	{
		printf("Current node was null");
		return FALSE;
	}

	if(node->next == NULL)
	{
		return FALSE;
	}

	return TRUE;
}

//  Returns data stored in a given node
void* getData(Node* node)
{
	if(node == NULL)
	{
		printf("Current node was null");
		return NULL;
	}

	return node->data;

}
