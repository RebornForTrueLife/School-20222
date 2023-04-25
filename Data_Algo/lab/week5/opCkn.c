/********************************************
 * ckn - finding number of ways to choose k elements from
 * set of n elements, given k and n
 * Uage: 
	- run the program
	- enter n, k: [1 ..k, n.. 999]
	- return the number of ways modulo 10^9 + 7
 * Running time: Theta(k * n)
 ********************************************/

#include <stdio.h>
#include <string.h>


// Define
#define MAX 1000  	// max size of number of elements


// CONST
// const int MAX = 1000;
const int MODULO = 1000000007;

// global
int buffer[MAX][MAX];
int count = 0;


// finding
int find(int k, int n) {
	if ((k == 0) || (k >= n)) 
		buffer[k][n] = 1;
	else {
		if (buffer[k][n] == 0) {
			buffer[k][n] = (find(k, n - 1) + find(k - 1, n - 1)) % MODULO;
			// printf("Calculate for: C[%d][%d]\n", k, n);
		}	// close of
	}	// close if
	// count += 1;
	return buffer[k][n];
}	// close find


// MAIN
int main(int argc, char const *argv[]) {
	// enter k, n
	int k, n;
	scanf("%d %d", &k, &n);
	// find result
	for (int i = 0; i <= k; i ++ ) 
		for (int j = 0; j <= n; j ++ )
			buffer[i][j] = 0;
	// print result
	printf("%d\n", find(k, n));
	// printf("%d\n", count);
	return 0;
}	// end  main 