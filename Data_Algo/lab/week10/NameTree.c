/********************************************
 * NameTree - represented a family name by a tree
 * Uage: 
	- Use the UI
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NameTree NameTree;
typedef struct Node Node;

/************************ Name Tree **********************/

// DATA-STRUCTURE
struct NameTree {
	Node *root;
};

struct Node {
	char *name;
	Node *leftMostChild;
	Node *rightSibling;
};

// OPERATIONs

// initializeTree
NameTree *initializeTree(char *nameRoot);

// allocate new node with name
Node *makeNode(char *name);

// load name tree from given file
NameTree *load(char *fileName);

// find node by name from given node
Node *findNode(Node *node, char *name);

/************************ Name Tree **********************/

/************* UTILs **************/

// get list of string in the current line of file
char **readStringLine(FILE *file, int *count);

/************* UTILs **************/


// MAIN
int main(int argc, char const *argv[]) {
	NameTree *tree = initializeTree("John#0");
	tree->root->leftMostChild = makeNode("Jame#1");
	tree->root->leftMostChild->rightSibling = makeNode("Mary#1");
	tree->root->leftMostChild->rightSibling->rightSibling = makeNode("Tom#1");
	tree->root->leftMostChild->leftMostChild = makeNode("June#2");
	tree->root->leftMostChild->rightSibling->leftMostChild = makeNode("Tome#2");
	Node *found = findNode(tree->root, "June#7");
	if (found != NULL) 
		printf("%s\n", found->name);
	else
		printf("Not found\n");
	tree = load("/home/minh/School/Learning/20222/Data_Algo/lab/week10/data-name-tree.in");
	printf("Node name: %s\n", tree->root->leftMostChild->name);
	return 0;
}	// end  main 


/******** Name Tree - FUNCTION DEFINE ********************/

// initializeTree
NameTree *initializeTree(char *nameRoot) {
	NameTree *tree = (NameTree*) malloc (sizeof(NameTree));
	Node *root = makeNode(nameRoot);
	tree->root = root;
	return tree;
}	// close initializeTree


// allocate new node with given parent
Node *makeNode(char *name) {
	Node *node = (Node*) malloc (sizeof(Node));
	node->name = name;
	node->leftMostChild = NULL;
	node->rightSibling = NULL;
	return node;
}	// close makeNode


// load name tree from given file
NameTree *load(char *fileName) {
	// open file
	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Unable to open file: %s\n", fileName);
		return NULL;
	}	// if
	// read root
	int count;
	char **list = readStringLine(file, &count);
	NameTree *tree;
	tree = initializeTree(list[0]);
	// add chidlren for root
	if (count > 1) {					// at least 1 child
		tree->root->leftMostChild = makeNode(list[1]);
		Node *sib = tree->root->leftMostChild;
		for (int i = 2; i < count; i ++ ) {
			sib->rightSibling = makeNode(list[i]);
			sib = sib->rightSibling;
		}	// for
	}	// if
	// read all left lines
	while (feof(file)) {
		list = readStringLine(file, &count);
		if (count == 0) 				// get to the terminate string: "$$"
			break;
		Node *parent = findNode(tree->root, list[0]);
		if (parent == NULL) {
			printf("Un-notice name: %s\n", list[0]);
			return NULL;
		}	// if
		if (count > 1) {
			parent->leftMostChild = makeNode(list[1]);
			Node *sibling = parent->leftMostChild;
			for (int i = 2; i < count; i ++ ) {
				sibling->rightSibling = makeNode(list[i]);
				sibling = sibling->rightSibling;
			}	// for
		}	// if	
	}	// close while
	return tree;
}	// close load


// find node by name
Node *findNode(Node *node, char *name) {
	if (node == NULL)					// terminate condition
		return NULL;
	if (strcmp (node->name, name) == 0 )
		return node;					// Found!
	// check name for all sibling
	Node *sib = node->rightSibling;
	while (sib != NULL) {
		if (strcmp (sib->name, name) == 0)
			return sib;					// Found!
		sib = sib->rightSibling;
	}	// while
	// search subtree of the current level
	Node *found;
	sib = node;
	while (sib != NULL) {
		found = findNode(sib->leftMostChild, name);
		if (found != NULL)
			return found;
		sib = sib->rightSibling;
	}	// while
	return NULL;						// Not found the given node
}	// close findNode


/******** Name Tree - FUNCTION DEFINE ********************/

/* UTILITIES DEFINE */
// get list of string in the current line of file
char **readStringLine(FILE *file, int *count) {
	// Read first line
	int LINE_SIZE = 1000;
	char *line = (char*) malloc (sizeof(char) * LINE_SIZE);
	fgets(line, LINE_SIZE, file);
	// read list string in current line
	int NUM_STR = 100;
	int STR_SIZE = 100;
	char **list = (char **) malloc (sizeof(char*) * NUM_STR);
	char *str = (char*) malloc (sizeof(char) * STR_SIZE);
	*count = 0;									// number of string
	while ((str != NULL) && (str[0] != '$')) {
		memset(str, '\0', STR_SIZE);
		sscanf(line, "%s", str);
		char *strCpy = (char*) malloc (sizeof(char) * STR_SIZE);
		line += strlen(str) + 1;
		list[*count] = strcpy(strCpy, str);
		*count += 1;
	}	// close while
	if (list[*count - 1][0] == '$')				// remove the terminate string
		*count -= 1;
	return list;
}	// close readStringLine