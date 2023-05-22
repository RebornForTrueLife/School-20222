/********************************************
 * Queue - Define an interger Queue, which is a data struture with FIFO I/O order
 * Uage: 
	- Queue performs 2 operations
	(1) PUSH (i.e enqueue): insert the given number into the begin of queue
	(2) POP (i.e dequeue): remove and return the last number in the queue
		*Note: reuturn MAX_INT if queue is empty*
 * Implemented by Singly Linked List
 * 		- PUSH: insert at the end of the linked list
 * 		- POP: remove the first element of linked list
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// DATA STRUCTURE

const int NaN = INT_MAX;	// define a NaN value as max integer

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct Queue {
	Node *head;
	Node *tail;
} Queue;

// DATA OPERATION

// return an empty queue
Queue *initializeQueue();

// push value into the given queue
void push(Queue *queue, int value);

// pop the last value of the given queue, return NaN if queue is empty
int pop(Queue *queue);

// check if queue is empty. if it's empty, return 1; otherwise return 0
int isEmpty(Queue *queue);

// 

// operators of queue
typedef enum {PUSH, POP} Operator;

// operation structure for a queue
// *Note: reserve the first elements without any data*
typedef struct Operation {
	Operator op;
	int operand;
	struct Operation *next;		// pointer to the next operation
} Operation;

// read list of operations from stdin
Operation *readOperations();

// solve list of operations given a queue
void solve(Queue *queue, Operation *ops);


// FUNCTION DEFINE

// return an empty queue
Queue *initializeQueue() {
	Queue *queue = (Queue*) malloc (sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
}	// close initializeQueue	


// push value into the given queue
void push(Queue *queue, int value) {
	// create a new node
	Node *node = (Node*) malloc (sizeof(Node));
	node->value = value;
	node->next = NULL;
	if (isEmpty(queue)) {			// in case queue is empty
		queue->head = node;			// update both head and tail
		queue->tail = node;
	} else {						// queue not empty
		queue->tail->next = node;
		queue->tail = node;			// update tail
	}	// if
}	// close push


// remove and return the first value of the given queue, return NaN if queue is empty
int pop(Queue *queue) {
	if (isEmpty(queue) == 1)	// if queue is empty
		return NaN;
	int value = queue->head->value;
	Node *head = queue->head;
	queue->head = queue->head->next;	// update head
	free(head);							// delete first element
	if (queue->head == NULL)
		queue->tail = NULL;				// update tail if queue is empty now
	return value;
}	// close pop


// check if queue is empty. if it's empty, return 1; otherwise return 0
int isEmpty(Queue *queue) {
	if (queue == NULL) {
		printf("Queue has not been allocated memory!\n");
		return NaN;
	}	// close if
	if (queue->head == NULL)
		return 1;				// queue is empty
	return 0;					// queue is not empty
}	// close isEmpty


// read list of operations from stdin
Operation *readOperations() {
	Operation *ops = (Operation*) malloc (sizeof(Operation));
	ops->next = NULL;											
	Operation *head = ops;										// reserve the first elements without any data
	int LINE_SIZE = 20;											// maximum size of line
	char *buffer = (char*) malloc (sizeof(char) * LINE_SIZE);	// buffer for an input line
	while (!feof(stdin)) {
		memset(buffer, '\0', LINE_SIZE);	// empty buffer
		fgets(buffer, LINE_SIZE, stdin);	// read a line
		if (buffer[0] == '#')				// reach the terminate character of operation list
			break;
		// extract operation
		char opStr[5];
		int operand;
		Operator op;
		sscanf(buffer, "%s %d", opStr, &operand);
		if (strcmp(opStr, "PUSH") == 0)				// classify operator
			op = PUSH;
		else if (strcmp(opStr, "POP") == 0)
			op = POP;
		else
			continue;								// invalid operator: ignore and move to next operation
		Operation *operation = (Operation*) malloc (sizeof(Operation));
		operation->op = op;
		operation->operand = operand;
		ops->next = operation;
		ops = operation;
	}	// while
	return head;
}	// close readOperations


// solve list of operations given a queue
void solve(Queue *queue, Operation *ops) {
	while (ops->next != NULL) {
		ops = ops->next;
		switch (ops->op) {
		case PUSH:
			push(queue, ops->operand);
			break;
		case POP:
			if (isEmpty(queue) == 1)	// queue is empty
				printf("NULL\n");
			else
				printf("%d\n", pop(queue));
			break;
		default:
			break;
		}	// switch
	}	// close while
}	// close solve



int main(int argc, char const *argv[]) {
	// initialize queue
	Queue *queue = initializeQueue();
	// read operations
	Operation *ops = readOperations();
	// solve operations
	solve(queue, ops);
	
	return 0;
}	// end  main 