/********************************************
 * maze - find the shortest exit path, given a maze
 * Uage: 
	- run the object file
	- enter the maze
	- the program will print out the number of steps 
	of the shortest exit path. Return -1 if the program
	is unable to find any exit path.
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DATA STRUCTURE DECLARE
// Maze
typedef enum{FREE, BLOCK, EXIT} CellState;		
typedef enum{NORTH, EAST, SOUTH, WEST} Direction;
typedef int Location[2];
typedef struct Maze Maze;
// PathTree
typedef struct Node Node;
typedef struct ListNode ListNode;
typedef struct PathTree PathTree;
// Queue
typedef Node* ValueType;
typedef struct QueueNode QueueNode;
typedef struct Queue Queue;

// DATA STRUCTURE DEFINE

// ##################### MAZE ######################
struct Maze {
	CellState** matrix;
	int numRow;
	int numCol;
	Location *startLocation;
};

// read the maze from stdin; padding around maze with value EXIT
// 		to denote the exit cells
void readMaze(Maze *maze);

// get the state of a location
CellState getCellState(Maze *maze, Location *loc);

// get location from given direction
Location *getLocation(Location *loc, Direction direct);

// check if 2 location is equal, return 1 if equal, otherwise return 0
int isEqualLocation(Location *loc1, Location *loc2);

// DEFINE FUNC

void readMaze(Maze *maze) {
	int LINE_SIZE = 100;					// size of a line
	int numRow, numCol, startRow, startCol;
	// read metadata of maze
	scanf("%d %d %d %d", &numRow, &numCol, &startRow, &startCol);
	maze->startLocation = (Location*) malloc (sizeof(Location));
	*(maze->startLocation)[0] = startRow;
	*(maze->startLocation)[1] = startCol;
	maze->numRow = numRow + 2;
	maze->numCol = numCol + 2;
	// read matrix of the maze
	numRow += 2;	// because of padding EXIT values
	numCol += 2;
	maze->matrix = (CellState**) malloc (sizeof(CellState*) * numRow);
	for (int row = 0; row < numRow; row ++) {
		maze->matrix[row] = (CellState*) malloc (sizeof(CellState) * numCol);
		if ((row == 0) || (row == numRow - 1)) {
			for (int col = 0; col < numCol; col ++ )
				maze->matrix[row][col] = EXIT;
			continue;
		}	// if
		for (int col = 0; col < numCol; col ++ ) {
			if ((col == 0) || (col == numCol - 1)) {
				maze->matrix[row][col] = EXIT;
				continue;
			}	// if
			int value;
			scanf("%d", &value);
			maze->matrix[row][col] = (value == 0) ? FREE : BLOCK;
		}	// for
	}	// for
}	// close readMaze


// get state of a cell
CellState getCellState(Maze *maze, Location *loc) {
	return maze->matrix[*loc[0]][*loc[1]];
}	// close getCellState


// get location
Location *getLocation(Location *loc, Direction direct) {
	int x, y;
	switch (direct) {
	case NORTH:
		x = *loc[0] - 1;
		y = *loc[1];
		break;
	case EAST:
		x = *loc[0];
		y = *loc[1] + 1;
		break;
	case SOUTH:
		x = *loc[0] + 1;
		y = *loc[1];
		break;
	case WEST:
		x = *loc[0];
		y = *loc[1] - 1;
		break;
	default:
		return NULL;
	}	// switch
	Location *resultLoc = (Location*) malloc (sizeof(Location));
	*resultLoc[0] = x;
	*resultLoc[1] = y;
	return resultLoc;
}	// close getLocation


int isEqualLocation(Location *loc1, Location *loc2) {
	if (*loc1[0] != *loc2[0])
		return 0;
	if (*loc1[1] != *loc2[1])
		return 0;
	return 1;
}	// close isEqualLocation


// print maze
void printMaze(Maze *maze) {
	for (int row = 0; row < maze->numRow; row ++ ) {
		for (int col = 0; col < maze->numCol; col ++ )
			printf("%d ", maze->matrix[row][col]);
		printf("\n");
	}	// for
}	// close printMaze
// ##################### MAZE ######################


// #################### QUEUE ######################
const ValueType NaN = NULL;	// define a NaN value as max integer

struct QueueNode {
	ValueType value;
	struct QueueNode *next;
};

struct Queue {
	QueueNode *head;
	QueueNode *tail;
};

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
// ##################### QUEUE #####################


// ##################### PATH-TREE #################
struct Node {
	Location *value;
	Node *parent;
	ListNode *children;
};

struct ListNode {
	Node **list;
	int size;
};

struct PathTree {
	Node *root;
	Maze *maze;
};

// initialize path tree
PathTree *initializePathTree(Maze *maze);

// build the tree
Node* buildPathTree(PathTree *tree);

// get number step from a node to root
int getNumStep(PathTree *tree, Node *node);

// check if a node contain exit cell, return 1 if true, otherwise return 0
int isExitNode(PathTree *tree, Node *node);

// assign list of children to a given node
void born(PathTree *tree, Node *node);

// check if a location is possible move from given node
int isPossibleLocation(PathTree *tree, Node *node, Location *loc);

// prune tree from given node upto its ancestor
void pruneNode(Node *node);


// OPERATION DEFINE
// initialize path tree
PathTree *initializePathTree(Maze *maze) {
	PathTree *tree = (PathTree*) malloc (sizeof(PathTree));
	tree->maze = maze;
	tree->root = (Node*) malloc (sizeof(Node));
	tree->root->parent = NULL;
	tree->root->children = NULL;
	tree->root->value = maze->startLocation;
	return tree;
}	// close initializePathTree


// build the tree
Node *buildPathTree(PathTree *tree) {
	Queue *queue = initializeQueue();
	push(queue, tree->root);
	while (isEmpty(queue) == 0) {
		Node *node = pop(queue);
		if (isExitNode(tree, node) == 1)
			return node;
		born(tree, node);
		if (node->children != NULL)
			for (int i = 0; i < node->children->size; i ++ ) 
				push(queue, node->children->list[i]);
		pruneNode(node);
	}	// while
	return NULL;
}	// close buildPathTree


// check if a node contain exit cell, return 1 if true, otherwise return 0
int isExitNode(PathTree *tree, Node *node) {
	CellState nodeState = getCellState(tree->maze, node->value);
	return nodeState == EXIT? 1 : 0;
}	// close isExitNode


// assign list of children to a given node
void born(PathTree *tree, Node *node) {
	int size = 0;
	Direction directs[4] = {NORTH, EAST, SOUTH, WEST};
	int isDirects[4];
	for (int i = 0; i < 4; i ++ ) {
		Location *loc = getLocation(node->value, directs[i]);
		if (isPossibleLocation(tree, node, loc) == 1) {
			isDirects[i] = 1;
			size += 1;
		} else 
			isDirects[i] = 0;
		free(loc);
	}	// for
	if (size == 0) {	// no possible move
		node->children = NULL;
		return;
	}	// if 
	node->children = (ListNode*) malloc (sizeof(ListNode));
	node->children->list = (Node**) malloc (sizeof(Node*) * size);
	node->children->size = size;
	int count = 0;
	for (int i = 0; i < 4; i ++ ) 
		if (isDirects[i] == 1) {
			Location *loc = getLocation(node->value, directs[i]);
			Node *child = (Node*) malloc (sizeof(Node));
			child->parent = node;
			child->children = NULL;
			child->value = loc;
			node->children->list[count] = child;
			count += 1;
		}	// if
}	// close born


// check if a location is possible move from given node
// 		return 1 if possible: when loc is not walked through by any node in the path from current node to the root
// 		return 0 otherwise
int isPossibleLocation(PathTree *tree, Node *node, Location *loc) {
	if (getCellState(tree->maze, loc) == BLOCK)
		return 0;
	Node *parent = node->parent;
	while (parent != NULL) {
		if (isEqualLocation(parent->value, loc) == 1)
			return 0;
		parent = parent->parent;
	}	// while	
	return 1;
}	// close isPossibleLocation


// get number step from a node to root
int getNumStep(PathTree *tree, Node *node) {
	int step = 0;
	while (node != NULL) {
		step += 1;
		// printf("%d - %d\n", *node->value[0], *node->value[1]);
		node = node->parent;
	}	// close while
	return step;
}	// close getNumStep


// check if a node has no child
int isNoChild(Node *node) {
	if (node->children == NULL)
		return 1;
	if (node->children->size == 0)
		return 1;
	return 0;
}	// close isNoChild


// free memory of a node
void freeNode(Node *node) {
	free(node->value);
	if (node->children != NULL) 
		free(node->children);
	free(node);
}	// close freeNode


// remove a node from parent
void removeNodeFromParent(Node *parent, Node *node) {
	int pos = 0;
	for (; pos < parent->children->size; pos ++ ) {
		if (parent->children->list[pos] == node)
			break;
	}	// close for
	for (int i = pos; i < parent->children->size - 1; i ++ ) {
		parent->children->list[i] = parent->children->list[i + 1];
	}	// close for
	parent->children->size -= 1;
}	// close removeNodeFromParent


// prune tree from a node
void pruneNode(Node *node) {
	if (isNoChild(node) == 0)
		return;
	Node *parent = node->parent;
	removeNodeFromParent(parent, node);
	freeNode(node);
	pruneNode(parent);
}	// close pruneNode


// ##################### PATH-TREE #################



int main(int argc, char const *argv[]) {
	Maze *maze = (Maze*) malloc (sizeof(Maze));	// allocate maze memory
	readMaze(maze);
	PathTree *tree = initializePathTree(maze);
	Node *node = buildPathTree(tree);
	printf("%d\n", getNumStep(tree, node) - 1);
	return 0;
}	// end  main 


