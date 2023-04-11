/********************************************
 * divisor - the program defind a function to 
 * 	find all divisors of an integer: int get_divisor(long, long*)
 * Uage: 
	- run the object file
	- enter an integer [1..1000,000]
	- program return increasing list of number's divisors
	** NOTE: this program used "math.h" library, so when
	* compile, should link it with prefix: "-lm"
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


// FUNC DECLARE
/*	a function to return list of divisor of an integer
	- input: the number, an long int array of all number's divisors
	- output: number of element int the array
		(in ascending order)*/
int get_divisor(long n, long *arr);

/*	function to allocate new long memory for a given array
		- input: 
			1. a pointer to first long element
			2. count: the number of current elements in the array
			3. the new long value
		- output:
			- allocate new memory for new value
			- put new value in the end of the array*/
void put_value(long *array, int count, long value);


// MAIN
int main(int argc, char const *argv[]) {
	// enter the input number
	long n;	// the number
	scanf("%ld", &n);
	// find list of divisors of number
	long *list = (long *) malloc (sizeof(long));
	int count = get_divisor(n, list);
	// print the list
	for (int i = 0; i < count; i ++ ) 
		printf("%ld ", list[i]);
	printf("\n");
	return 0;
}	// end  main 


// return the list of divisor of an integer
int get_divisor(long n, long *arr) {
	int count = 1;	// number of divisor, first divisor is always 1
	// find sqrt of n
	long sqrtN = sqrt(n);
	// initialize first divisor
	arr[0] = 1;
	// find divisor from 2 to sqrt
	for (long i = 2; i <= sqrtN; i ++ ) {
		if ((n % i) == 0) {
			// put new value in array
			put_value(arr, count, i);
			count += 1;	
		}	// close if
	}	// close 
	// Double the array to find the corrosponding divisors
	int number;	// number of values to be double 
	// if sprt(n) is integer: 
	if ((sqrtN * sqrtN) == n) 
		number = count - 1;
	else
		number = count;
	// double values
	for (int i = 0; i < number; i ++ ){
		// calculate correspond divisor of element i
		long newValue = n / arr[number - 1 - i];
		put_value(arr, count, newValue);
		count += 1;
	}	// close for
	// Double the array for negative values
		// allocate memory for negative values
	count *= 2;
	realloc (arr, count * sizeof(long));
		// 	move all elements forward to allocate for negative values
	memmove((arr + (count / 2)), arr, (count / 2) * sizeof(long));
		// assign negative values to array
	for (int i = 0; i < (count / 2); i ++ ) 
		arr[i] = (- 1) * arr[count - 1 - i];
	return count;
}	// close get_divisor


/*	function to allocate new long memory for a given array*/
void put_value(long *array, int count, long value) {
	// new size of array
	int newSize = (count + 1) * sizeof(long);
	// allocate new memory for new value
	realloc(array, newSize);
	// put new value in the array
	array[count] = value;
}	// close put_value