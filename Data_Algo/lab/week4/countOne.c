/********************************************
 * countOne - count number of integer from 1 to given 
 * number n, which digit 1 appears at most once
 * Uage: 
	- run object file
	- enter number n [1 .. 10000000]
	- return number of integer found
 ********************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// ALGO DESCRIPTION
/* Algo
	problem = find all integer smaller than n, and contain once 1 or no 1
	Denote:
		1. the smallest int have same the number of digits to n is base_n
		2. the number of digits of n is size
	Divide problem to 2 subproblems
		(1) find number of integer containing once 1
		(1) find number of integer containing NO 1
	Code design:
		> DECLARE [count] = 0
		> DECLARE [flag] = 0  // if digits seen has once 1
		> FOR EACH [digit] in [n]:
			> DECLARE [pos] = position of [digit] in [n] (index start with 0)
			> IF [flag Equal to 0]
				// Count for subproblem (1)
				> COUNT number of integer has -> [result]
					(1) number digit is Smaller Or Equal to [size] - [pos]
					(2) first digit < first digit of [digit]
					(3) contain once digit 1
					(4) other digit in range [0, 2, .. , 9]
				// Count for subproblem (2)
				> COUNT number of integer has -> [result]
					(1) number digit is Smaller Or Equal to [size] - [pos]
					(2) first digit < first digit of [digit]
					(3) No contain digit 1
					(4) digit in range [0, 2, .. , 9]
				> ADD [result] to [count]

			> IF [digit] Equal to 1
				> INCREASE [flag] by 1

		> IF [flag] Smaller than 2
			> INCREASE [count] by 1

		// remove integer 0 from count
		> RETURN [count] - 1
 */

// FUNC DEFINE

/*	a function to count the number of integer from
	1 to given number n, which contain at most once 1
	- input: max range n [1 .. 10 000 000] 
	- output: number of integer found */
int count(int n);

/* to count all integer in subproblem 1 */
int countOnce(int digit, int size);

/* to count all integers in subproblem 2 */
int countNone(int digit, int size);


// MAIN
int main(int argc, char const *argv[]) {
	// enter number n
	int n;	// input number
	scanf("%d", &n);
	// find number of integer containing at most once 1
	printf("%d\n", count(n) - 1);
	// print the result
	return 0;
}	// end  main 


// FUNC DEFINE

// count number of int contain at most once 1
int count(int n) {
	// > DECLARE [count] = 0
	int count = 0;
	// 	> DECLARE [flag] = 0  // if digits seen has once 1
	int flag = 0;
	int size = (int)(ceil(log10(n)));
	if ( ((int)(ceil(log10(n))) - (int)(floor(log10(n)))) == 0)		// log10(n) is an integer
		size += 1;
	// map each digit into an array
	int *digitList = (int *) calloc (size, sizeof(int));
	int copyN = n;
	for (int i = 0; i < size; i ++ ) {
		digitList[size - 1 - i] = copyN % 10;
		copyN /= 10;
	}	// close for
	// 	Start counting
	for (int pos = 0; pos < size; pos ++ ) {
		int digit = digitList[pos];
	// 		> IF [flag Equal to 0]
		if (flag == 0) {
			count += countOnce(digit, size - pos);
			count += countNone(digit, size - pos);
		}	// close if
	// 		> IF [digit] Equal to 1
		if (digit == 1)
			flag += 1;
	}	// close for
	// 	> IF [flag] Smaller than 2
	if (flag < 2)
		count += 1;
	return count;
}	// close find


// count once
/* Algo
	- 1st [0 .. digit) 
	- */
int countOnce(int digit, int size) {
	int count = 0;
	if (digit == 0) 
		return 0;
	for (int firstDigit = 0; firstDigit < digit; firstDigit ++ ) {
		int countPart = 0;
		if (firstDigit == 1) {
			int pro = 1;
			// range of ther digit: 0 2 .. 9
			for (int i = 1; i < size; i ++ ) 
				pro *= 9;
			countPart = pro;
		} else {
			// 1 digit is 1, other in range 0 2 .. 9
			if (size == 1)
				countPart = 0;
			else { 	// size > 1
				int pro = 1;
				for (int i = 2; i < size; i ++ ) 
					pro *= 9;
				countPart = (size - 1) * pro;
			}	// close if 1
		}	// close if
		count += countPart;
	}	// close for
	return count;
}	// close countOnce


// count None 1
int countNone(int digit, int size) {
	int count = 0;
	// in case there is no integer with 
	if (digit == 0)
		return 0;
	// range of digit: 0 2 .. 9
	for (int firstDigit = 0; firstDigit < digit; firstDigit ++ ) {
		if (firstDigit == 1)
			continue;
		int pro = 1;
		for (int i = 1; i < size; i ++ ) 
			pro *= 9;
		count += pro;
	}	// close for
	return count;
}	// close countNone