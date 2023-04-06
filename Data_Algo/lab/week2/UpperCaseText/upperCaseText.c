/********************************************
 * upperCaseText - convert input Text into UPPER
 *  case Text
 * Uage: 
	- run object file
	- write Text at data.txt file(which redirect to stdin)
 ********************************************/

#include <stdio.h>
#include <ctype.h>

// MODE
#define CODING		// coding mode
#undef CODING		// turn off coding mode

// CONST
const long int STRING_SIZE = 100000;		// string size


// main
int main(int argc, char const *argv[]) {
	char string[STRING_SIZE + 1];	// input string
	// open data.txt and redirect to stdin in CODING MODE
	#ifdef CODING
		freopen("data.txt", "r", stdin);
	#endif	// CODING
	// Read each char in stdin, convert it into upper case
	// 		and store it into a string
	int i = 0;	// current index of string
	while (1) {
		// read a char from stdin
		char c = getchar();
		// terminate condition
		if (c == EOF)
			break;
		// convert c into upper case
		c = toupper(c);
		// put c into string
		string[i] = c;
		i += 1; 	// increment index of string
	}	// close while
	// add end-char to string
	string[i] = '\0';
	// print out the result string
	printf("%s\n", string);
	return 0;
}	// end  main 