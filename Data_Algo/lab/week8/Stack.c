/********************************************
 * Stack - Implement stack data structure
 * Uage: 
	- run object file
 ********************************************/

#include <stdio.h>
#include <stdlib.h>


// DATA STRUCTURE
/* 
	- A stack of character data 
	- Implementation: 
		+ Stack is implemented by using singly linked list of Nodes;
		+ There is a pointer: 'Stack',  point to the current top node
		+ Stack is empty when the 'Stack' point to NULL
	- Operation
		+ PUSH operation is performed by adding new element at the begin of the list
		+ POP operation is to remove and return the head element of the list
 */
typedef struct Node {
	char value;
	struct Node *next;
} Node;


typedef struct Stack {
	Node *head;
} Stack;



// initialize stack: return the stack pointer
Stack *initializeStack();

// isEmpty: check if the stack is empty
/* return 1 if empty, otherwise return 0 */
int isEmpty(Stack *stack);

// push value
void push(Stack *stack, char value);

// pop value
char pop(Stack *stack);



// FUNC DEFINE

// intialize stack
Stack *initializeStack() {
	Stack *stack = (Stack*) malloc (sizeof(Stack));
	stack->head = NULL;
	return stack;
}	// close initialize


// push value
void push(Stack *stack, char value) {
	isEmpty(stack);		// just to check if stack has been initialized
	// create new node
	Node *node = (Node*) malloc (sizeof(Node));
	node->value = value;
	node->next = stack->head;
	stack->head = node;
}	// close push stack


// pop value
char pop(Stack *stack) {
	char value = '\0';				// default return value
	if (isEmpty(stack) == 1) {		// stack is not empty
		value = stack->head->value;
		Node *tmp = stack->head;
		// let head point to below element
		stack->head = stack->head->next;
		free(tmp);
	}	// close if
	return value;
}	// close pop stack


// isEmpty: check if the stack is empty
int isEmpty(Stack *stack) {
	if (stack == NULL) {
		printf("# THE STACK HAS NOT BEEN INITIALIZED\n");
		return 1;
	}	// close if
	if (stack->head == NULL) 	// stack is empty
		return 1;		
	return 0;					// stack is not emtpy
}	// close isEmpty