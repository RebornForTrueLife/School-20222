/********************************************
 * test - test how compiler allocate memory
 * Uage: 
	- run object file
 ********************************************/

#include <iostream>
#include <iomanip>


// MAIN
int main(int argc, char const *argv[]) {
	int var1 = 16;
	int *pointer;

	std::cout << std::oct;
	std::cout << "Address of var1 = " << &var1 << "\n";
	std::cout << "Address of pointer = " << &pointer << "\n";
	std::cout << "Number byte distance =  " << (long)&pointer - (long)&var1 << "\n";
	pointer = &var1;
	std::cout << "Address of pointer = " << pointer << "\n";
	std::cout << std::dec;
	return 0;
}	// end  main 