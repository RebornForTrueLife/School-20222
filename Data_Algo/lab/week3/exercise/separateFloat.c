/********************************************
 * separateFloat - to separate integer and decimal part
 * of a float
 * Uage: 
	- run the object file
	- enter a float
	- the program will print out the integer and decimal 
	part of the float separately
 ********************************************/

#include <stdio.h>
#include <math.h>


// MAIN
int main(int argc, char const *argv[]) {
	// enter the float
	float f;		// input float
	scanf("%f", &f);	
	// get integer part
	int integer = floor(f);
	// get decimal part
	float decimal = f - integer;
	// print 2 part out
	printf("%d %.2f\n", integer, decimal);
	return 0;
}	// end  main 