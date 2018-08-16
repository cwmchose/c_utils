#IFNDEF NODE_H
#DEFINE NODE_H


/* Structure */
typedef struct Node
{
	Node* next;
	void* data;
}Node;


/* Macros */
#define TRUE  1
#define FALSE 0 

/* Prototypes */
Node* createNode(void* data);
void* destroyNode(Node** node_ptr); 
int setNext(Node* node, Node* next);
int hasNext(Node* node);
Node* getNext(Node* node);
void* getData(Node* node);
