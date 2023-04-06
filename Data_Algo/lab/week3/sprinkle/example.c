#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
	int* p;
	// p = (int*) malloc (10* sizeof(int));
	int b[10];

	// print array
	for (int i = 0; i < 10; i++ ) {
		printf("%d ", *(b + i));
	}	// close for
	printf("\n");
	// // //
	int **pp;
	pp = (int**) malloc (10 * sizeof(int*));
	// allocate mem for each element
	for (int i = 0; i < 10; i ++) {
		pp[i] = (int * ) malloc (1 * sizeof(int));
	}	// close for
	// print array
	for (int i = 0; i < 10; i++ ) {
		// printf("%d ", pp + i);
	}	// close for
	printf("\n");

	return 0;
}	// end  main 