#ifndef STACK_H_
#define STACK_H_

#include "Node.h"

/* Structure */
typedef struct Stack
{
	Node* top;
	int size;
}Stack;

/* Prototypes */
Stack* createStack();
void destroyStack(Stack** stack);
int push(Stack* stack, void* data);
void* pop(Stack* stack);
int getStackSize(Stack* stack);

#endif
