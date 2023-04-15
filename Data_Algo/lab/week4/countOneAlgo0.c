/********************************************
 * countOne - to count number of integer that has at most 
 * 1 digit 1 from 1 to given upper bound
 * Uage: 
	- run the object file
	- enter the upper bound n [1 .. 10 000 000]
	- program will print out the number of integer found
 ********************************************/

#include <stdio.h>


// FUNC DECLARE

/*	a function to check if a integer is match this condition:
		(1) number of digit 1 is 0 or 1 
	- input: the integer
	- output:
		(1) 1: mean true
		(2) 0: false */
int check(int value);


/*	a function to count the number of integers match
having at most 1 digit 1, which from 1 to given upper bound
- input: upper bound
- output: the number of integers found */
int count(int n);


// MAIN
int main(int argc, char const *argv[]) {
	// enter n
	int n;
	scanf("%d", &n);
	// count number matched integer
	int number = 0;
	number = count(n);
	// print count
	printf("%d\n", number);
	return 0;
}	// end  main 


// FUNC DEFINE

// check 
int check(int value) {
	int count = 0;
	// count number of digit 1 in value
	while (value != 0) {
		int digit = value % 10;
		value /= 10;
		if (digit == 1) 
			count += 1;
	}	// close
	if (count <= 1)
		return 1;
	return 0;
}	// close check


// count
int count(int n) {
	int number = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (check(i) == 1)
			number += 1;
	}	// close for
	return number;
}	// close count