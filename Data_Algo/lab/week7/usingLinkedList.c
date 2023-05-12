/********************************************
 * usingLinkedList - using a singly linked list
 * Uage: 
	- run the object file
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data declare
#define LINE_SIZE 100		// maximum size of a line

// Query
typedef enum {ADD_LAST, ADD_FIRST, ADD_AFTER, ADD_BEFORE, REMOVE, REVERSE} Query_Type;

typedef struct Query {
	Query_Type type;
	int firstKey;
	int secondKey;
	struct Query *next;
} Query;


// Singly linked list
typedef struct Node {
	int value;			// value of node
	struct Node* next;	// ptr to next node
} Node;

typedef struct SinglyLinkedList {
	Node *head;	// ptr to head
	Node *tail;		// ptr to last node
	int size;			// number of current node
} SinglyLinkedList;



// FUNC DECLARE

// Singly linked list operations
// allocate memory for new node
Node *createNode(int value);

// add a node to last of list
Node *insertLast(SinglyLinkedList *list, int value);

// remove the first node of list
void removeFirst(SinglyLinkedList *list);

// remove first value 
void removeFirstValue(SinglyLinkedList *list, int value);

// remove all node has the given value
void removeValue(SinglyLinkedList *list, int value);

// remove all
void removeAll(SinglyLinkedList *list);

// return number of current node
int count(SinglyLinkedList *list);

// reverse the list
void reverse(SinglyLinkedList *list);

// print list
void print_list(SinglyLinkedList *list);


// Qyery operations
// read list query from stdin
Query *getListQuery();

// create query
Query *addQuery(Query *firstQuery, Query_Type type, int firstKey, int secondKey);

// respond all query
void respond(SinglyLinkedList *list, Query *firstQuery);



int main(int argc, char const *argv[]) {
	// create a singly linked list of integers
	SinglyLinkedList *list = (SinglyLinkedList *) malloc (sizeof(SinglyLinkedList));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	// read list
	int size;		// size of list
	int value;	// value
	scanf("%d", &size);
	for (int i = 0; i < size; i ++ ) {
		scanf("%d", &value);
		insertLast(list, value);
	}	// close for
	// read list query
	Query *firstQuery = getListQuery();
	Query *current = firstQuery;
	// print 
	respond(list, firstQuery);
	print_list(list);
	return 0;
}	// end  main 



// FUNC DEFINE

// allocate memory for new node
Node *createNode(int value) {
	Node *node = (Node *) malloc (sizeof(Node));
	node->value = value;
	node->next = NULL; 
	return node;
}	// close createNode


// add a node to last of list
Node *insertLast(SinglyLinkedList *list, int value) {
	Node *node = createNode(value);
	// check if list is not null
	if (list == NULL)
		return NULL;
	// check if list is not empty
	if (list->size == 0)			// list is empty
		list->head = node;
	else {						// list is not empty
		if (list->tail == NULL) {		// list has only 1 node
			list->tail = node;
			list->head->next = list->tail;
		} else {						// list has more than 1 node
			list->tail->next = node;
			list->tail = node;
		}	// close if 1
	}	// close if
	list->size += 1;
	return node;
}	// close insertLast


// remove the first node of list
void removeFirst(SinglyLinkedList *list) {
	if (list == NULL)
		return;
	if (list->size == 0)		// list is empty
		return;
	Node *removedNode = list->head;
	list->head = list->head->next;
	list->size -= 1;
	if (list->size == 0)		// empty tail if list is empty
		list->tail = NULL;
	// printf("The first Node %d is removed\n", removedNode->value);
	free(removedNode);
}	// close removeFirst


// remove all
void removeAll(SinglyLinkedList *list) {
	if (list == NULL)
		return;
	if (list->head == NULL) {
		// printf("Successfully removed all nodes\n");
		return;
	}	// close if
	removeFirst(list);
	removeAll(list);
}	// close removeAll


// return number of current node
int count(SinglyLinkedList *list) {
	if (list == NULL)
		return 0;
	return list->size;
}	// close count


// reverse the list
void reverse(SinglyLinkedList *list) {
	if (list == NULL)
		return;
	if (list->size <= 1)	// list is empty or has only 1 node
		return;			// do nothing
	Node *head = list->head;
	Node *current = list->head;
	Node *next;
	Node *prev = NULL;
	// travel the list
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}	// close while
	list->head = prev;
	list->tail = head;
	// printf("Successfully reverse list\n");
}	// close reverse


// remove first value 
void removeFirstValue(SinglyLinkedList *list, int value) {
	if (list == NULL)
		return;
	if (list->size == 0)	// list is empty
		return;
	Node *prev = NULL;
	Node *node = list->head;
	while (node != NULL) {
		if (node->value == value)
			break;
		node = node->next;
		prev = node;
	}	// close while
	if (node == NULL)	{
		// printf("%d does not exist in the list\n", value);
		return;		
	}	// close if
	if (prev == NULL)	// head has the value
		list->head = node->next;
	else {
		prev->next = node->next;
		list->size -= 1;
	}	// close if
	if (node == list->tail)
		list->tail = prev;
	free(node);
	// printf("Successfully removed value: %d\n", value);
}	// close removeFirstValue


// print list
void print_list(SinglyLinkedList *list) {
	if ((list == NULL) || (list->head == NULL)) {
		// printf("List is empty\n");
		return;
	}	// close if
	Node *node = list->head;
	// printf("The list: ");
	while(node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}	// close while
	printf("\n");
}	// close print_list


// remove all node has the given value
Node *removeValueNode(SinglyLinkedList *list, Node *head, int value) {
	if (head == NULL)			// reach end of list
		return NULL;
	if (head->value == value) {	// found a match
		Node *tmp = head;
		head = head->next;
		free(tmp);
		list->size -= 1;
		return removeValueNode(list, head, value);
	}	// close if
	head->next = removeValueNode(list, head->next, value);
	return head;
}	// close removeValueNode

void removeValue(SinglyLinkedList *list, int value) {
	Node *head = list->head;
	head = removeValueNode(list, head, value);
	list->head = head;
	if (list->size != 0) {		// list is not empty
		Node *node = list->head;
		while (node->next != NULL)		// find tail
			node = node->next;
		list->tail = node;
	}	// close if
	// printf("Successfully remove all value %d from the list\n", value);
}	// close removeValue



// Qyery operations
// read list query from stdin
Query *getListQuery() {
	Query *firstQuery = NULL;
	// read from stdin
	char *buffer = (char*) malloc (LINE_SIZE * sizeof(char));
	memset(buffer, '\0', sizeof(buffer));
	while (!feof(stdin) && (buffer[0] != '#')) {
		fgets(buffer, LINE_SIZE, stdin);
		buffer[strlen(buffer) - 1] = '\0';
		char typeStr[LINE_SIZE];
		Query_Type type;
		int firstKey = 0;
		int secondKey = 0;
		sscanf(buffer, "%s %d %d", typeStr, &firstKey, &secondKey);
		if (strcmp(typeStr, "addlast") == 0)
			type = ADD_LAST;
		else if (strcmp(typeStr, "addfirst") == 0)
			type = ADD_FIRST;
		else if (strcmp(typeStr, "addafter") == 0)
			type = ADD_AFTER;
		else if (strcmp(typeStr, "addbefore") == 0)
			type = ADD_BEFORE;
		else if (strcmp(typeStr, "remove") == 0)
			type = REMOVE;
		else if (strcmp(typeStr, "reverse") == 0)
			type = REVERSE;
		else 
			continue;	// unknown query, go to next line
		firstQuery = addQuery(firstQuery, type, firstKey, secondKey);
	}	// close while
	return firstQuery;
}	// close getListQuery

// create query
Query *addQuery(Query *firstQuery, Query_Type type, int firstKey, int secondKey) {
	Query *query = (Query *) malloc (sizeof(Query));
	query->type = type;
	query->firstKey = firstKey;
	query->secondKey = secondKey;
	query->next = NULL;
	if (firstQuery == NULL)		// list query is empty
		return query;
	Query *current = firstQuery;
	while (current->next != NULL)	// go to last query
		current = current->next;
	current->next = query;
	return firstQuery;
}	// close addQuery


// Respond all queries
/* check if a value exists in the list, return null if not existing, 
		otherwise, return node's ptr of the first node that has the given value*/
Node* isExist(SinglyLinkedList *list, int value) {
	if ((list == NULL) || (list->size == 0))
		return 0;
	Node* node = list->head;
	while (node != NULL) {
		if (node->value == value)
			break;
		node = node->next;
	}	// close node
	return node;
}	// close isExist

// add last, no duplicate
void add_last(SinglyLinkedList *list, Query *query) {
	if (list == NULL)	// list is not initialized
		return;
	if (list->size == 0) {	// list is empty
		insertLast(list, query->firstKey);
		return;
	}	// close if
	if (isExist(list, query->firstKey) != NULL)	// value existed
		return;									// do nothing
	insertLast(list, query->firstKey);
}	// close add_last

// add first
void add_first(SinglyLinkedList *list, Query *query) {
	if (list == NULL)
		return;
	if (list->size == 0) {		// list is empty
		insertLast(list, query->firstKey);
		return;
	}	// close if
	if (isExist(list, query->firstKey) != NULL)	// value existed
		return;									// do nothing
	Node *node = createNode(query->firstKey);
	node->next = list->head;
	list->head = node;
	list->size += 1;
}	// close add_first

// add after
void add_after(SinglyLinkedList *list, Query *query) {
	if (list == NULL)
		return;
	if (isExist(list, query->secondKey) == NULL)		// secondKey does not exist
		return;										// do nothing
	if (isExist(list, query->firstKey) != NULL) 		// insert value existed
		return;										// do nothing
	Node *node = createNode(query->firstKey);
	Node *pos = isExist(list, query->secondKey);
	node->next = pos->next;
	pos->next = node;
	list->size += 1;
	if (node->next == NULL)	// node is tail
		list->tail = node;		// update tail
}	// close add_after

// add before
void add_before(SinglyLinkedList *list, Query *query) {
	if (list == NULL)
		return;
	if (isExist(list, query->secondKey) == NULL)		// secondKey does not exist
		return;										// do nothing
	if (isExist(list, query->firstKey) != NULL) 		// insert value existed
		return;										// do nothing
	Node *node = createNode(query->firstKey);
	Node *pos = node;
	pos->next = list->head;
	while (pos->next != NULL) {
		if (pos->next->value == query->secondKey)
			break;
		pos = pos->next;
	}	// close while
	if (pos == node)	// node is the first node
		list->head = node;
	else {
		node->next = pos->next;
		pos->next = node;
	}	// close if
	list->size += 1;
}	// close add_before

void respond(SinglyLinkedList *list, Query *firstQuery) {
	if (firstQuery == NULL)
		return;
	switch (firstQuery->type) {
	case ADD_LAST:
		add_last(list, firstQuery);
		break;
	case ADD_FIRST:
		add_first(list, firstQuery);
		break;
	case ADD_AFTER:
		add_after(list, firstQuery);
		break;
	case ADD_BEFORE:
		add_before(list, firstQuery);
		break;
	case REMOVE:
		removeValue(list, firstQuery->firstKey);
		break;
	case REVERSE:
		reverse(list);
		break;
	default:
		break;
	}	// close switch
	// respond next query
	respond(list, firstQuery->next);
}	// close respond