/********************************************
 * combineSum - to print out all posible given size array,
 * which has sum equal to given number
 * Uage: 
	- run the object file
	- enter the size of array and the required sum
	- the program will print out all the posible ordered
	array that has given sum
 ********************************************/

#include <stdio.h>


// Define
#define MAX_N 20	// max size of array


// file scope variable
int x[MAX_N];	// solution array
int n;			// number of variables need to found
int m;			// the given sum
int total = 0; 	// the holder for sum of solution

// check
int check(int v, int k) {
	if (k < n - 1)
		if (v <= (m - total - (n - k - 1)))
			return 1;
	if (k == n - 1)
		if ((total + v) == m)
			return 1;
	return 0;
}	// close check


// print solution
void solution() {
	for (int i = 0; i < n; i ++ ) 
		printf("%d ", x[i]);
	printf("\n");
}	// close solution


// solve
void solve(int k) {
	// solve all posible value for element k
	for (int i = 1; i <= m - total; i ++ ) {
		if (check(i, k) == 0)
			continue;
		x[k] = i;
		total += x[k];
		if (k == n - 1)
			solution();
		else {
			solve(k + 1);
		}	// close if
		// recover total when back to the upper node
		total -= x[k];	
	}	// close for
}	// close solve


// main
int main(int argc, char const *argv[]) {
	// enter number of variables and the required sum
	scanf("%d %d", &n, &m);
	// solve from variable 0
	solve(0);
	return 0;
}	// end  main 
