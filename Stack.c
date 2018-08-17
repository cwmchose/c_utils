#include "Stack.h" 
#include <stdlib.h>
#include <stdio.h>

Stack* createStack()
{
	Stack* stack = (Stack*) malloc(sizeof(Stack*));
	if(stack == NULL)
		return NULL;
	stack->size = 0;
	return stack;
}

void destroyStack(Stack** stack_ptr)
{
	if(stack_ptr == NULL || *stack_ptr == NULL)
	{
		return;
	}
	while(getStackSize != 0)
	{
		pop(*stack_ptr);
	}

	free(*stack_ptr);
	*stack_ptr = NULL;
}

int push(Stack* stack, void* data)
{
	if(stack == NULL || data == NULL)
		return FALSE;

	Node* new_node = createNode(data);
	setNext(new_node, stack->top);
	stack->top = new_node;
	++(stack->size); 
	return TRUE;
}

void* pop(Stack* stack)
{
	if(stack == NULL || stack->top == NULL) 
		return NULL;
	Node* old_top = stack->top;
	stack->top = old_top->next;
	
	void* temp = old_top->data;

	destroyNode(&old_top);
	--(stack->size);
	return temp;
}

int getStackSize(Stack* stack)
{
	if(stack == NULL)
		return 0;
	return stack->size;
}

