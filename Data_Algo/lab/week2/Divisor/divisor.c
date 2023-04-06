/********************************************
 * divisor - find all divisible number of a given integer
 * Uage: 
	- run the object file
	- enter an integer n: [1..1 000 000]
	- the program prints out divisible number of n
 ********************************************/

#include <stdio.h>
#include <math.h>

// declare type of input number
typedef long int Type;

// CONST
const int SIZE = 1000;	// max size of divisors set of number


// main
int main(int argc, char const *argv[]) {
	// declare number
	Type number;		// input number
	// declare an array to hold divisors of number
	Type array[SIZE];	// array of divisors
	// enter number
	scanf("%ld", &number);
	// search in range [1..sqrt(n)] to find divisors of number
	// 		put divisor in array
	int count = 0;
	long int sqrtNumber = (long int) sqrt(number);
	for (int i = 1; i <= sqrtNumber; i ++ ) {
		if ((number % i) == 0) {		// number is divisible to i
			array[count] = i;
			count += 1;
		}	// close if
	}	// close for
	// extend the set of divisor by take number / element of array
	// 		check if last element is sqrt(number) or not
	int startIndex = count - 1;  	// start index to extend array
	if ( (sqrtNumber * sqrtNumber) == number)
		startIndex = count - 2;		// mean that sqrt(n) only count 1 times
	for (int i = startIndex; i >= 0; i --) {
		array[count] = number / array[i];
		count += 1;
	}	//close for
	// print out the negative of array in reverse order
	for (int i = count - 1; i >= 0; i -- ) 
		printf("%ld ", - array[i]);
	// print out the array
	for (int i = 0; i < count; i ++ )
		printf("%ld ", array[i]);
	return 0;
}	// end  main 