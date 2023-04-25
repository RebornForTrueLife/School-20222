/********************************************
 * fibonacci - calculate a fibonacci number given the index
 * in fibonacci array
 * Uage: 
	- run object file
 ********************************************/

#include <stdio.h>


int fibonacci(int n) {
	printf("Finding %d\n", n);
	if (n <= 1) 
		return 1;
	int fib1 = fibonacci(n - 1);
	printf("Return fib %d\n", n - 1);
	int fib2 = fibonacci(n - 2);
	printf("Return fib %d\n", n - 2);
	return  fib1 + fib2;
}	// close fibonacci


int main(int argc, char const *argv[]) {
	printf("fibonacci 10 = %d\n", fibonacci(10));
	return 0;
}	// end  main 