/********************************************
 * ckn - finding number of ways to choose k elements from
 * set of n elements, given k and n
 * Uage: 
	- run the program
	- enter n, k: [1 ..k, n.. 999]
	- return the number of ways modulo 10^9 + 7
 * Running time: Theta(2^n)
 ********************************************/

#include <stdio.h>


// finding
int find(int k, int n) {
	// base case
	if (k == 0)
		return 1;
	if (n <= k )
		return 1;
	return find(k, n - 1) + find(k - 1, n - 1);
}	// close find


// MAIN
int main(int argc, char const *argv[]) {
	// enter k, n
	int k, n;
	scanf("%d %d", &k, &n);
	// print result
	printf("%d\n", find(k, n));
	return 0;
}	// end  main 