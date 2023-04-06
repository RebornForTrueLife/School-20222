/********************************************
 * addInt - add two big integer
 * Uage: 
	- run object file
	- enter 2 integer
	- the program return the sum of 2 ints
 ********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// MODE
#define CODING		// coding mode
// #undef CODING

// CONST
const int INT_SIZE = 30;		// number of char in string integer
const int BLOCK_SIZE = 4;		// number of char in a block - 1; because of end string: '\0'
const char EMPTY_STRING[] = "";

// FUNC DECLARE
/*	add_int(string, string)
	- to add 2 integer in the string format
	- Input: stringInt1, stringInt2, result
	- output: result = sum of 2 integer in string format*/
char* add_int(char* result, char stringInt1[], char stringInt2[]);

/*	add_block(string, string, int, int, int)
	- to add a block of string integer 1 to the block 
	of string integer 2; a block is a substring of a string, 
	start from startIndex to endIndex in right-to-left order
	- Input: 
		- 2 string integers
		- startIndex and endIndex of blocks
		- mem: which memory adding, can be 1 or 0
		- result: string to hold the result
	- Output: return adding rememer: 1 or 0*/
int add_block(char* result, char bigInt[], char smallInt[], int startIndex, int endIndex, int mem);

/*	get_block(string, int, int)
	- to get a block of a string from start index to endIndex in right-to-left order
	- Input: a string, start index, end index
	- Output: change value in block address
		- Note: if startIndex, or endIndex is not valid, return EMPTY_STRING*/
void get_block(char string[], char* block, int startIndex, int endIndex);


int main(int argc, char const *argv[]) {
	char stringInt1[INT_SIZE + 1];		// string int 1
	char stringInt2[INT_SIZE + 1];		// string int 1
	char result[INT_SIZE + 1];			// sum in string
	// set 3 string to empty
	memset(stringInt1, '\0', INT_SIZE);
	memset(stringInt2, '\0', INT_SIZE);
	memset(result, '\0', INT_SIZE);
	// enter 2 string integer
	scanf("%s %s", stringInt1, stringInt2);
	// //
	#ifdef CODING 	// coding mode
		add_int(result, stringInt1, stringInt2);
		printf("%s\n", result);
	#else			// implement mode
		// compute adding and assign to result
		strcpy(result, add_int(stringInt1, stringInt2));
		// print result
		printf("%s\n", result);
	#endif	// close CODING
	// //
	return 0;
}	// end  main 


/////////////// IMPLEMENT

// add 2 string integer
char* add_int(char* result, char stringInt1[], char stringInt2[]) {
	// for simplity, assign integer in order
	char bigInt[INT_SIZE + 1];
	char smallInt[INT_SIZE + 1];
	// set 2 string empty
	memset(bigInt, '\0', INT_SIZE);
	memset(smallInt, '\0', INT_SIZE);
	if (strlen(stringInt1) > strlen(stringInt2)) {
		strcpy(bigInt, stringInt1);
		strcpy(smallInt, stringInt2);
	} else {
		strcpy(bigInt, stringInt2);
		strcpy(smallInt, stringInt1);
	}	// close if
	// startIndex from the right
	int startIndex = 0;
	int mem = 0;	// add remember
	char sumBlock[BLOCK_SIZE + 1];	// sum of pair blocks
	// add each block in 2 string integer until
	// 		end of bigInt
	while (1) {
		// terminate condition
		if (startIndex >= strlen(bigInt))
			break;
		// end index
		int endIndex = startIndex + BLOCK_SIZE - 1;
		// calculate sum of each block
		// // set sumBlock to empty
		memset(sumBlock, '\0', sizeof(sumBlock));
		// // add
		mem = add_block(sumBlock, bigInt, smallInt, startIndex, endIndex, mem);
		// Concatenate sumBlock to result
		char subString[BLOCK_SIZE + 1];
		memset(subString, '\0', BLOCK_SIZE);	// set empty
		// // sumBlock has 2 cases: HAS_MEM or NO_MEM
		if (strlen(sumBlock) > BLOCK_SIZE)	// has mem
			// take last BLOCK_SIZE chars of sumBlock
			strncpy(subString, (sumBlock + 1), BLOCK_SIZE);
		else		{// no mem
			// check if there is still adding after this block
			// // actual endIndex
			endIndex = startIndex + strlen(sumBlock);
			if (endIndex < strlen(bigInt)) {
				// fill left end of substring with '0' to fill block_size
				int numZeroFill = BLOCK_SIZE - strlen(sumBlock);
				memset(subString, '0', numZeroFill);
				strcpy((subString + numZeroFill), sumBlock);
			} else 
				// if there is no adding after this block
				// we dont fill 0
				strcpy(subString, sumBlock);
		}	// end if 1
		// // concatenate substring to begin of result
		char buffer[INT_SIZE + 1]; 	// buffer to hold old result
		memset(buffer, '\0', INT_SIZE);
		// // copy old result to buffer
		strcpy(buffer, result);
		// // set result to empty
		memset(result, '\0', INT_SIZE);
		// // concat sumBlock to begin of result
		strcpy(result, subString);
		// // concat old result to the end
		strcat(result, buffer);
		// INCREMENT startIndex
		startIndex += BLOCK_SIZE;
	}	// close while
	// check if there is adding remember
	if (mem == 1) {
		// move all char in result forword 1 position
		memmove(result + 1, result, strlen(result));
		// fill 1 to first char if result
		result[0] = '1';
	}	// close if
	return result;
}	// close add_int


// add 2 blocks of 2 strings
int add_block(char* result, char bigInt[], char smallInt[], int startIndex, int endIndex, int mem) {
	// set result to empty string
	memset(result, '\0', BLOCK_SIZE);
	// get 2 blocks from 2 string integer
	char bigBlock[BLOCK_SIZE + 1];
	char smallBlock[BLOCK_SIZE + 1];
	memset(bigBlock, '\0', BLOCK_SIZE + 1);
	memset(smallBlock, '\0', BLOCK_SIZE + 1);
	get_block(bigInt, bigBlock, startIndex, endIndex);
	get_block(smallInt, smallBlock, startIndex, endIndex);
	// convert 2 blocks to integer format
	int int1 = atoi(bigBlock);
	int int2 = atoi(smallBlock);
	// adding 2 converted blocks and memory adding
	int sum = int1 + int2 + mem;
	// convert sum to string and return
	sprintf(result, "%d", sum);
	// check if there is adding remember 1
	if (strlen(result) > BLOCK_SIZE)
		return 1;	// there is remember 1
	return 0;		// there is NOT remember
}	// close add_block


// get a block of a string
void get_block(char string[], char* block, int startIndex, int endIndex) {
	// set block to empty
	memset(block, '\0', BLOCK_SIZE);
	// length of string
	int length = strlen(string);
	// if startIndex is out of string index range
	if (startIndex >= length) {
		strcpy(block, EMPTY_STRING);
	} else {	// if startIndex is valid
		// check if endIndex is NOT valid
		if (endIndex >= length)
			// set it to end of string
			endIndex = length - 1;		
		// convert start and end index to left-to-right order
		int start = length - endIndex - 1;
		// number of char will be copied
		int size = endIndex - startIndex + 1;
		strncpy(block, (string + start), size);
		block[size] = '\0';
	}	// close if
}	// close get_block

