/********************************************
 * sumArray.o - sum all elements in an integer array
 * Uage: 
	- run object file
	- enter size of array (1 <= n <= 100,000)
	- enter n integers (separate by 1 space)
	- output: sum of elements in the array
 ********************************************/

#include <stdio.h>

// CONST
const long int SIZE = 100000;	// max size of array

/*a function to enter the size and the elements
in the array
	- input: reference to size, and array address
	- output: enter value into size, elements of array*/
void input_array(int* size, int* array);

/* a function to sum all element in a given array
	- input: size of array, array address
	- output: sum of elements in array */
int sum_array(const int size, int* array);

// main
int main(int argc, char const *argv[]) {
	int size;		// size of array
	int array[SIZE];
	int sum = 0;		// sum of array
	// input size and array elements
	input_array(&size, array);
	// calculate sum of array
	sum = sum_array(size, array);
	// print out the result
	printf("%d\n", sum);
	return 0;
}	// end  main 


// function to enter size and array
void input_array(int *size, int* array) {
	// enter size
	scanf("%d", size);
	// enter each elements
	for (int i = 0; i < *size; i++) 
		scanf("%d", &array[i]);	// enter each element
		// close for
}	//end input_array


// function to sum all elements in the array
int sum_array(const int size, int* array) {
	int sum = 0; 	// sum of array
	// go to all element
	for (int i = 0; i < size; i ++) 
		sum += array[i];		// add element to sum
		// close for
	return sum;
}	// end sum_array