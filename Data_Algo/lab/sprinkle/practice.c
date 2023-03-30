#include <stdio.h>

int main(int argc, char const *argv[]) {
	FILE *file;	// file pointer

	// open file
	file = fopen("data1.txt", "w");
	// check if file is valid
	if (file == NULL) 
		printf("File does not exist\n");
	else
		printf("File exist\n");
	// put data
	fprintf(file, "%s\n", "hello");
	// enter a number
	int number;
	scanf("%d", &number);
	return 0;
}	// end  main 