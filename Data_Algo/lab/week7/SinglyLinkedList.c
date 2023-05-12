/********************************************
 * SinglyLinkedList - Implement The data type: Singly Linked List of integers
 * Uage: 

 ********************************************/

#include <stdio.h>
#include <stdlib.h>

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



int main(int argc, char const *argv[]) {
	// create a singly linked list of integers
	SinglyLinkedList *list = (SinglyLinkedList *) malloc (sizeof(SinglyLinkedList));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	// test
	insertLast(list, 10);
	insertLast(list, 10);
	insertLast(list, 23);
	insertLast(list, 10);
	insertLast(list, 10);
	insertLast(list, 10);
	insertLast(list, 10);
	insertLast(list, 92);
	insertLast(list, 10);
	insertLast(list, 10);
	print_list(list);
	removeValue(list, 10);
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
	printf("The first Node %d is removed\n", removedNode->value);
	free(removedNode);
}	// close removeFirst


// remove all
void removeAll(SinglyLinkedList *list) {
	if (list == NULL)
		return;
	if (list->head == NULL) {
		printf("Successfully removed all nodes\n");
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
	printf("Successfully reverse list\n");
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
		printf("%d does not exist in the list\n", value);
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
	printf("Successfully removed value: %d\n", value);
}	// close removeFirstValue


// print list
void print_list(SinglyLinkedList *list) {
	if ((list == NULL) || (list->head == NULL)) {
		printf("List is empty\n");
		return;
	}	// close if
	Node *node = list->head;
	printf("The list: ");
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
	printf("Successfully remove all value %d from the list\n", value);
}	// close removeValue