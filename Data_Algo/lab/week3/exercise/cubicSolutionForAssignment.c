/*	
	The program is used to find integer solution of a cubic equation in the below form:
		x^3 + ax^2 + bx + c, where x is the root; a, b, c is the input variables
	Output: (2)
		1. IF there is no integer solution: print NO SOLUTION
		2. If there is integer solution, then list all integer solution found
	// THe algorithms: (in simple)
	1. Find all divisors of [c], put them into a [array]
		> The integer solutions if exist, will be the subset of [array]
	2. For each element in [array]:
		> CHECK if the element is a solution
	3. If found, print out
		- else: print: NO SOLUTION
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// FUNC DECLARE
/*	function to allocate new int memory for a given array
		- input: 
			1. a pointer to first int element
			2. count: the number of current elements in the array
			3. the new int value
		- output:
			- allocate new memory for new value
			- put new value in the end of the array*/
void put_value(int *array, int count, int value);

/*	a function to return list of divisor of an integer
	- input: the number, an int int array of all number's divisors
	- output: number of element int the array
		(in ascending order)*/
int get_divisor(int n, int *arr);

/*	function to find all check all numbers in a given array
	if the number is a solution for the given cubic equation
	- input: 
		1. the integer array to check 
		2. the length of given integer array
		3. the result array(allocated 1 int memory)
		4. 3 parameters of the cubic equation: a, b, c
			x^3 + ax^2 + bx + c = 0 
	- output: 2 cases
		1. 0: if there is no solution found
		2. the number of solutions found*/
int check(int *set, int length, int *found, int a, int b, int c);

/*	function to find all integer solution of a given 
	cubic equation this format:
		x^3 + ax^2 + bx + c = 0, where a, b, c are integer 
		parameters
	- input: 
		1. an integer array to hold the solutions
		2. 3 integer: a, b, c
	- output: the number of solution found */
int solve(int *solution, int a, int b, int c);


/*	a function to find multipliers of given solutions
	- input: 
		1. solution array
		2. number of solution
		3. multiplier array
		4. 3 equation's parameters
	- output: number of multiplier */
int get_multi(int *solution, int length, int *multiplier, int a, int b, int c);


// print given array elements
void print_array(int *array, int length) {
	// printf("## Array: ");
	for (int i = 0; i < length; i ++ ) 
		printf("%d\n", array[i]);
	// printf("\n");
}	// close print_array


// // // // // //  MAIN
int main(int argc, char const *argv[]) {
	// enter 3 parameters
	int a, b, c; 		// x^3 + ax^2 + bx + c = 0
	scanf("%d %d %d", &a, &b, &c);
	// declare array for solution and allocate 1 int mem for the array
	int *solution = (int *) malloc (sizeof(int));
	// solve equation
	int numberSol = solve(solution, a, b, c);		// number of solution found
	// print result
	if (numberSol == 0) 
		printf("NO SOLUTION\n");
	else {
		// find multiplier of each root
			// declare and allocate memory for multiplier array
		int *multiplier = (int *) malloc (sizeof(int));
			// number of multiplier = number of roots
		int numberMul = get_multi(solution, numberSol, multiplier, a, b, c);
		// print result
		for (int i = 0; i < numberSol; i ++ ) 
			printf("%d %d\n", solution[i], multiplier[i]);
	} 	// close if
	return 0;
}	// end  main 


// // // // // // FUNC DEFINE

// return length of the list of divisor of an integer
int get_divisor(int n, int *arr) {
	// get absolute value of n
	n = abs(n);
	int count = 1;	// number of divisor, first divisor is always 1
	// find sqrt of n
	int sqrtN = sqrt(n);
	// initialize first divisor
	arr[0] = 1;
	// find divisor from 2 to sqrt
	for (int i = 2; i <= sqrtN; i ++ ) {
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
		int newValue = n / arr[number - 1 - i];
		put_value(arr, count, newValue);
		count += 1;
	}	// close for
	// Double the array for negative values
		// allocate memory for negative values
	count *= 2;
	realloc (arr, count * sizeof(int));
		// 	move all elements forward to allocate for negative values
	memmove((arr + (count / 2)), arr, (count / 2) * sizeof(int));
		// assign negative values to array
	for (int i = 0; i < (count / 2); i ++ ) 
		arr[i] = (- 1) * arr[count - 1 - i];
	return count;
}	// close get_divisor


/*	function to allocate new int memory for a given array*/
void put_value(int *array, int count, int value) {
	// new size of array
	int newSize = (count + 1) * sizeof(int);
	// allocate new memory for new value
	realloc(array, newSize);
	// put new value in the array
	array[count] = value;
}	// close put_value


// function to check if any number in given list is the solution of given equation
int check(int *set, int length, int *found, int a, int b, int c) {
	int count = 0;	// the number of solution
	// check each element in the set
	for (int i = 0; i < length; i ++ ) {
		int x = set[i];
		int result = (x * x * x) + (a * x * x) + (b * x) + c;
		if (result == 0) {
			// put found sol to found-array
			put_value(found, count, x);
			count += 1;
		}	// close if
	}	// close for
	// return the number of solution found
	return count;
}	// close check


// function to find all integer solution of a cubic equation
int solve(int *solution, int a, int b, int c) {
	int count = 0;	// number of solution
	// declare and allocate 1 int memory for set
	int *set = (int *) malloc (sizeof(int));
	// find the set of divisor of c
	int numberDivisor = get_divisor(c, set);
	// check each number in set if the number is a solution
	count = check(set, numberDivisor, solution, a, b, c);
	// return number of solution found
	return count;
}	// close solve	


// function to get corresponding multipliers to the paticular solution
/*	Algorithms:
		- Solultions list can have 4 cases
			(1) NONE: no need to find multiplier
			(2) 1 root: multiplier can be 1 or 3 
			(3) 2 roots: multiplier can be 1 or 2
			(4) 3 roots: mul is only 1
		- So we need to find only in case (1) or (2)
		- Step:
			1. CHOOSE 1 root found: called x1
			2. CALCULATE: h = a + x1; g = b + (h * x1)
			3. DECLARE: delta = h^2 - (4 * g)
			4. CHECK (delta):
				1. if delta < 0: multiplier(x1) = 1
				2. if delta == 0: multiplier(x1) = 1; multiplier(x2) = 2
				3. if delta > 0: multiplier(x1) = 2; multiplier(x2) = 1
	*/
int get_multi(int *solution, int length, int *multiplier, int a, int b, int c) {
	// there is 1 or 2 roots
	if ((length == 2) || (length == 1)) {
		int x1 = solution[0];	// choose 1 root
			int h = a + x1;
			int g = b + (h * x1);
			int delta = (h * h) - (4 * g);
			// when there is 2 roots
			if (delta == 0) {
				// multiplier of x1 is 1, of x2 is 2
				put_value(multiplier, 0, 1);
				put_value(multiplier, 1, 2);
				return 2;
			}	// close if
			// when there is 2 roots
			if (delta > 0) {
				// multiplier of x1 is 1, of x2 is 2
				put_value(multiplier, 0, 2);
				put_value(multiplier, 1, 1);
				return 2;
			}	// close if
			// when there is only 1 root
			if (delta < 0) {
				// put multipiler = 1 to multiplier list
				put_value(multiplier, 0, 1);
				return 1;
			}	// close if
	}	// close if
	// 3 roots
	if (length == 3)	{
		// each root has multiplier is 1
			put_value(multiplier, 0, 1);
			put_value(multiplier, 1, 1);
			put_value(multiplier, 2, 1);
			return 3;
	}	// close if
	// NO SOLUTION
	if (length == 0)
		return 0;
	// invalid number of roots
	printf("WARNING: The number of solution is not valid!\n");
	return -1;		
}	// close get_multi