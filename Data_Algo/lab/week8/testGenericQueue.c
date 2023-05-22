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
#include <limits.h>

// DATA STRUCTURE

typedef struct Point Point;
struct Point {
	int x;
	int y;
};

typedef Point* ValueType;
const ValueType NaN = NULL;	// define a NaN value as max integer

typedef struct QueueNode {
	ValueType value;
	struct QueueNode *next;
} QueueNode;

typedef struct Queue {
	QueueNode *head;
	QueueNode *tail;
} Queue;

// DATA OPERATION

// return an empty queue
Queue *initializeQueue();

// push value into the given queue
void push(Queue *queue, ValueType value);

// pop the last value of the given queue, return NaN if queue is empty
ValueType pop(Queue *queue);

// check if queue is empty. if it's empty, return 1; otherwise return 0
int isEmpty(Queue *queue);


// FUNCTION DEFINE

// return an empty queue
Queue *initializeQueue() {
	Queue *queue = (Queue*) malloc (sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
}	// close initializeQueue	


// push value into the given queue
void push(Queue *queue, ValueType value) {
	// create a new node
	QueueNode *node = (QueueNode*) malloc (sizeof(QueueNode));
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
ValueType pop(Queue *queue) {
	if (isEmpty(queue) == 1)	// if queue is empty
		return NaN;
	ValueType value = queue->head->value;
	QueueNode *head = queue->head;
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
		return 1;
	}	// close if
	if (queue->head == NULL)
		return 1;				// queue is empty
	return 0;					// queue is not empty
}	// close isEmpty


int main(int argc, char const *argv[]) {
	Queue *queue = initializeQueue();
	Point *p1 = (Point*) malloc (sizeof(Point));
	Point *p2 = (Point*) malloc (sizeof(Point));
	Point *p3 = (Point*) malloc (sizeof(Point));
	Point *p4 = (Point*) malloc (sizeof(Point));
	push(queue, p1);
	push(queue, p2);
	printf("%d\n", pop(queue)->x);
	printf("%d\n", pop(queue)->x);
	return 0;
}	// end  main 