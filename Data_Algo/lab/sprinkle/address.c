/********************************************
 * test - test address as arguement
 * Uage: 
	- run object file
 ********************************************/

#include <stdio.h>
#include <stdlib.h>


// FUNC DECLARE

void test();

void gen(int n, int *array);

void print_array(int n, int *array);


// main
int main(int argc, char const *argv[]) {
	test();
	return 0;
}	// end  main 


// generate address
void test() {
	int n;		// size of array
	int *array;
	// enter size
	scanf("%d", &n);
	// allocate mem for array
	array = (int *) calloc (n, sizeof(int));
	gen(n, array);
	print_array(n, array);
}	// close test


// generate array
void gen(int n, int *array) {
	// enter value for array
	for (int i = 0; i < n; i ++ ) {
		scanf("%d", array + i);
	}	// close for
	printf("Successfully enter array!\n");
}	// close gen


// print array
void print_array(int n, int *array) {
	for (int i = 0; i < n; i ++ ) {
		printf("%d ", array[i]);
	}	// close for
	printf("\n");
}	// close print_array	