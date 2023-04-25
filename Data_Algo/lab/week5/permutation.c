/********************************************
 * permutation - generate all permutation from 1 to given
 * number
 * Uage: 
	- run the object files
	- enter the maximum range
	- the program will print out all permutation from 1 to 
	the given number
 ********************************************/

#include <stdio.h>
#include <stdlib.h>


/* Algo
1. Generate an array of permuation: 
	> SOLVE EACH elements:
		// TRY all posible value of element
		> ITERATE value = 1 to n:
			> CHECK if value is marked
				> IF marked: continue
			> ASSIGN value to current element
			> MARKED current value
			> IF index of element == n - 1
				> TRUE: 
					> PRINT array
				> ELSE: SOLVE next element
			> UNMARKED current value

2. Check if value is mark 
	- state is buffer memory to store state of values
	> LOOKUP state[value] == 1
		> RETURN 0
	> RETURN 1
*/


// FUNC DECLARE

// solve for element at index k [0..n-1]
void solve(int k, int n, int* perm, int *state);

// check if value is Not marked
int check(int v, int *state);

// print a permutation array
void print_solution(int *perm, int n);


// MAIn
int main(int argc, char const *argv[]) {
	// enter the number 
	int n;
	scanf("%d", &n);
	// generate permutattion
	int *perm = (int*) calloc (n, sizeof(int));
	int *state = (int*) calloc (n, sizeof(int));
	solve(0, n, perm, state);
	return 0;
}	// end  main 


// FUNC DEFINE

// solve for element at index k [0..n-1]
void solve(int k, int n, int* perm, int *state) {
	// try all posible value
	for (int i = 1; i <= n; i ++ ) {
		if (check(i, state) == 1)	// value is marked
			continue;
		perm[k] = i;
		state[i - 1] = 1;		// mark current value
		if (k == n - 1)		// last 
			print_solution(perm, n);
		else
			solve(k + 1, n, perm, state);
		state[i - 1] = 0;		// unmark current value
	}	// close for
}	// close solve

// check if value is marked
int check(int v, int *state) {
	if (state[v - 1] == 1)
		return 1;
	return 0;
}	// close check

// print a permutation array
void print_solution(int *perm, int n) {
	for (int i = 0; i < n; i ++ ) {
		printf("%d ", perm[i]);
	}	// close for
	printf("\n");
}	// close print_solution