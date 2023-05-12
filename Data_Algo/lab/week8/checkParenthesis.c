/********************************************
 * checkParenthesis - given a string, check if all the 
 * parenthesises are in correct form(open one must have correspinding close one)
 * Uage: 
	- run the object file
	- input a string
	- the program will print out the validation
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// CONST
const int LENGTH = 1000;


// check if the string has correct parenthesis format
/* return 1 if string is correct, otherwise return 0 */
int check(char *str);



int main(int argc, char const *argv[]) {
	// input a string
	char *str = (char *) malloc (sizeof(char) * LENGTH);
	memset(str, '\0', sizeof(str));
	fgets(str, LENGTH, stdin);
	// check the string
	if (check(str) == 1)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}	// end  main 



// FUNC DEFINE

// DATA STRUCTURE SUPPORT
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

// given a character, check if the character is OPEN parenthesis
// return 1 if true, otherwise return 0
int isOpen(char c);

// given a character, check if the character is CLOSE parenthesis
// return 1 if true, otherwise return 0
int isClose(char c);

// check if a pair of parenthesises are match
// return 1 if true, otherwise return 0
int isMatch(char openChar, char closeChar);



// check string
int check(char *str) {
	Stack *stack = initializeStack();
	for (int i = 0; i < strlen(str); i ++ ) {
		if (isOpen(str[i]) == 1) 		// if current char is open parenthesis
			push(stack, str[i]);		// push the char into stack
		if (isClose(str[i]) == 1)	{	// if current char is close parenthesis
			char openChar = pop(stack);
			if (isMatch(openChar, str[i]) == 0)	// the close parenthesis is different with the nearest open one
				return 0;
		}	// close if 
	}	// close for
	if (isEmpty(stack)) 		// all check is done
		return 1;
	return 0;				// the string still has parenthesises left
}	// close check



// SUPPORT FUNC DEFINE

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


// given a character, check if the character is OPEN parenthesis
// return 1 if true, otherwise return 0
int isOpen(char c) {
	switch (c) {
	case '{':
	case '[':
	case '(':
	case '<':
		return 1;
	default:
		break;
	}	// close switch
	return 0;
}	// close isOpen


// given a character, check if the character is CLOSE parenthesis
// return 1 if true, otherwise return 0
int isClose(char c) {
	switch (c) {
	case '}':
	case ']':
	case ')':
	case '>':
		return 1;
	default:
		break;
	}	// close switch
	return 0;
}	// close isClose


// check if a pair of parenthesises are match
// return 1 if true, otherwise return 0
int isMatch(char openChar, char closeChar) {
	// validate openChar and closeChar
	if (isOpen(openChar) == 0)		// openChar is invalid
		return 0;
	if (isClose(closeChar) == 0)		// closeChar is invalid
		return 0;
	// check if they are matched
	switch (openChar) {
	case '{':
		if (closeChar == '}')
			return 1;
		break;
	case '[':
		if (closeChar == ']')
			return 1;
		break;
	case '(':
		if (closeChar == ')')
			return 1;
		break;
	case '<':
		if (closeChar == '>')
			return 1;
		break;
	default:
		break;
	}	// close switch
	return 0;
}	// close isMatch