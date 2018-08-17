#ifndef NODE_H
#define NODE_H


/* Structure */
typedef struct Node
{
	struct	Node* next;
	void* data;
}Node;


/* Macros */
#define TRUE  1
#define FALSE 0 

/* Prototypes */
Node* createNode(void* data);
void* destroyNode(Node** node); 
int setNext(Node* node, Node* next);
int hasNext(Node* node);
Node* getNext(Node* node);
void* getData(Node* node);

#endif
