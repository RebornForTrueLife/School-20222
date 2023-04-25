/********************************************
 * recursion - practice recursive func
 * Uage: 
	- run obj file
 ********************************************/

#include <stdio.h>


int sum(int n) {
	if (n == 1)
		return 1;
	return n + sum(n - 1);
}	// close sum


int main(int argc, char const *argv[]) {
	printf("Sum = %d\n", sum(3));
	return 0;
}	// end  main 