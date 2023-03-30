/********************************************
 * testC - test C program
 * Uage: 
	- run the object file
 ********************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	FILE* file;		// file
	// open file
	file = fopen("data1.txt", "w");
	// check if file is valid
	if (file == NULL) 
		printf("File does not exist\n");
	else
		printf("File exist\n");
	// print file
	printf("%c\n", fgetc(file));
	printf("%c\n", fgetc(file));
	// put data
	fprintf(file, "%s\n", "Hi");
	// ENTER some char
	int number;
	scanf("%d", &number);
	return 0;
}	// end  main 