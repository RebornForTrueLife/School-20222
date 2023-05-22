/********************************************
 * Stack - Implement stack data structure
 * Uage: 
	- run object file
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

// operators of stack
typedef enum {PUSH, POP} Operator;

// operation structure for a stack
typedef struct Operation {
	Operator op;
	int operand;
	struct Operation *next;		// pointer to the next operation
} Operation;


typedef struct Node {
	int value;
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
void push(Stack *stack, int value);

// pop value
char pop(Stack *stack);

// read list of operations from stdin
Operation *readOperations();

// solve list of operations given a stack
void solve(Stack *stack, Operation *ops);


int main(int argc, char const *argv[]) {
	// intialize a stack
	Stack *stack = initializeStack();
	// read the list of operations
	Operation *ops = readOperations();
	// solve operations
	solve(stack, ops);
	return 0;
}	// end  main 


// FUNC DEFINE

// intialize stack
Stack *initializeStack() {
	Stack *stack = (Stack*) malloc (sizeof(Stack));
	stack->head = NULL;
	return stack;
}	// close initialize


// push value
void push(Stack *stack, int value) {
	isEmpty(stack);		// just to check if stack has been initialized
	// create new node
	Node *node = (Node*) malloc (sizeof(Node));
	node->value = value;
	node->next = stack->head;
	stack->head = node;
}	// close push stack


// pop value
char pop(Stack *stack) {
	int value = 0;					// default return value
	if (isEmpty(stack) == 0) {		// stack is not empty
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


// read operations
Operation *readOperations() {
	Operation *ops = (Operation*) malloc (sizeof(Operation));		// initialize operation list
	ops->next = NULL;												// reserve the first operation as a HEAD with no data
	Operation *head = ops;
	int LINE_SIZE = 100;
	char *buffer = (char*) malloc (LINE_SIZE * sizeof(char));		// an input line
	while (!feof(stdin)) {
		memset(buffer, '\0', LINE_SIZE);	// empty buffer
		fgets(buffer, LINE_SIZE, stdin);	// read a line
		if (buffer[0] == '#')		// whether reach the list terminator: #
			break;
		// read operator, operand
		char opStr[5];				// operator in string
		int operand;				// operand
		Operator op;
		sscanf(buffer, "%s %d", opStr, &operand);
		// classify operator
		if (strcmp(opStr, "PUSH") == 0)
			op = PUSH;
		else if (strcmp(opStr, "POP") == 0)
			op = POP;
		else
			continue;				// unknown operator, ignore the case and move to next operation
		// add operation to the ops list
		Operation *operation = (Operation*) malloc (sizeof(Operation));
		operation->op = op;
		operation->operand = operand;
		operation->next = NULL;
		ops->next = operation;
		ops = operation;
	}	// while	
	return head;
}	// close readOperations


// solve list of operations given a stack
void solve(Stack *stack, Operation *ops) {
	while (ops->next != NULL) {
		ops = ops->next;
		switch (ops->op) {
		case PUSH:
			push(stack, ops->operand);
			break;
		case POP:
			if (isEmpty(stack) == 0)
				printf("%d\n", pop(stack));
			else
				printf("NULL\n");
			break;
		default:
			break;
		}	// switch
	}	// while
}	// close solve