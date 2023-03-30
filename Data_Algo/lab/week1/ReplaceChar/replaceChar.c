/********************************************
 * replaceChar - replace a char with other char in
 * the given string
 * Uage: 
	- run object file
	- enter a string(no space)
	- enter the replaced char and the replacing char
	- the program will print the string after being replaced
 ********************************************/

#include <stdio.h>
#include <string.h>

// CONST
const int SIZE_STRING = 10000;		// max size of string

// FUNCTION DECLARE
/*	a function to replace the first char to second char 
in a given string
	- input: firstChar, secondChar and the string
	- output: replacing firstChar with secondChar 
	in the input string*/
void replace_char(char* string, const char firstChar, const char secondChar);


// main
int main(int argc, char const *argv[]) {
	char inputString[SIZE_STRING];		// input string
	char firstChar;		// replaced char
	char secondChar;		// replacing char
	// enter the string, 2 chars
	scanf("%s %c %c", inputString, &firstChar, &secondChar);
	// replaced char in string
	replace_char(inputString, firstChar, secondChar);
	// print out the string result
	printf("%s\n", inputString);
	return 0;
}	// end  main 


// function to replace first char to second char in 
// 		the given string
void replace_char(char* inputString, const char firstChar, const char secondChar) {
	// go to each char in string
	for (int i = 0; i < strlen(inputString); i++) 
		// check of current char is equal to firstChar
		if (inputString[i] == firstChar)
			// replace current char with second char
			inputString[i] = secondChar;
		// close for
}	// end replace_char