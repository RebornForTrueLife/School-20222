/********************************************
 * binarySequence - print all posible binary sequences 
 * of given length
 * Uage: 
	- run the object file
	- enter length
	- the program will print out all posible binary sequences
 ********************************************/

#include <stdio.h>

#define MAX_N 50

// CONST
// const int MAX_N = 50;

// global variable
int n;
int x[MAX_N];


// print solution
void solution() {
	for (int i = 0; i < n; i ++ ) {
		printf("%d", x[i]);
	}	// close for
	printf("\n");
}	// close solution


// try the digit at index k
void solve(int k) {
	// try all posible values
	for (int i = 0; i <= 1; i ++ ) {
		x[k] = i;
		if (k == n - 1) 
			solution();
		else
			solve(k + 1);
	}	// close for
}	// close solve


// MAIN
int main(int argc, char const *argv[]) {
	// enter length
	scanf("%d", &n);
	// solve problem
	solve(0);
	return 0;
}	// end  main 