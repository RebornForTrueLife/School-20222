/********************************************
 * arrayEquality - check a number of test of a pair of 
 * array if they are equal or not
 * Uage: 
	- run the object file
	- enter number of tests
	- For each test: enter size1 and size2 of 2 arrays, 
	enter array1 and array2
	- the program will print out result of each test in each line
	which is number: 1 or 0; 
	1 for equal, 0 for not equal
 ********************************************/

#include <stdio.h>

// CONST
const int SIZE_ARRAY = 1000;	// max size of array
const int SIZE_TEST = 100;	// max size of number of tests

// FUNCTION DECLARE
/*	a function to input the size and elements of 
2 arrays
	- input: address of size1, size2, array1, array2
	- output: enter all value of input variables*/
void input_array(int* size1, int* size2, int* array1, int* array2);

/*	a function to check the equality of 2 given array
	- input: sizes of 2 array, address of 2 arrays
	- output: value 1 or 0; 1 for equal, 0 for Not equal*/
int check_equal(const int size1, const int size2, const int* array1, const int* array2);


// main
int main(int argc, char const *argv[]) {
	int numberTest;		// number of test
	int size1, size2; 	// sizes of 2 array
	int array1[SIZE_ARRAY]; 	// array 1
	int array2[SIZE_ARRAY]; 	// array 2
	int resultArray[SIZE_TEST];
	// enter number of test
	scanf("%d", &numberTest);
	// input value and check for each test
	for (int test = 0; test < numberTest; test ++) {
		// enter value for sizes and arrays
		input_array(&size1, &size2, array1, array2);
		// check if current arrays are equal and put
		// 		result to resultArray
		resultArray[test] = check_equal(size1, size2, array1, array2);
	}	// close for
	// print out result
	for (int test = 0; test < numberTest; test ++) 
		printf("%d\n", resultArray[test]);
	return 0;
}	// end  main 


// function to input sizes and arrays
void input_array(int* size1, int* size2, int* array1, int* array2) {
	// enter size 1 and 2
	scanf("%d %d", size1, size2);
	// enter array 1
	for (int i = 0; i < *size1; i++) 
		scanf("%d", &array1[i]); // enter each element
	// enter array 2
	for (int i = 0; i < *size2; i++) 
		scanf("%d", &array2[i]); // enter each element
}	// end input_array


// function to check if 2 arrays are equal or not
int check_equal(const int size1, const int size2, const int* array1, const int* array2) {
	// check if 2 sizes are equal
	if ( size1 == size2 ) {
		// check each pair of element in 2 arrays
		for (int i = 0; i < size1; i++) 
			// check if 2 elements in same index are equal
			if (array1[i] != array2[i])	// if NOT
				return 0;	
			// close for
		return 1;	// if all pair elements are equal
	}	// close if
	// if 2 sizes are not equal
	return 0;
}	// end check_equal
