/********************************************
 * replaceText - replace firstString with secondString 
 * in a given text
 * Uage: 
	- run object file
	- enter firstString
	- enter second String
	- enter text
	- the program will print new text after replacing 
	firstString with secondString in text
 ********************************************/

#include <stdio.h>
#include <string.h>

// MODE
#define CODING		// coding time
#undef CODING	
#define DEBUG		// debug mode
#undef DEBUG

// CONST
const int SIZE_STRING = 1000; 		// max size of a string

// FUNCTION DECLARE
/*	a function to replace firstString with secondString in 
	a text and write result in newText
	- input:	 beside 4 parameters already mentioned, 
	startIndex is used for recursive func; newText is initial 
	with empty string
	- output: NONE, just change the newText*/
void replace_string(char* text, char* newText, char* firstString,
					 char* secondString, int startIndex);

/*	a function to find a keyString in a text from the 
	given text, return the first index found if the keyString
	exist, -1 if keyString does Not exist in text
	- input: keyString, text and startIndex-the func
	will search from startIndex
	- output: the first index of keyString in the text
		-1 if keyString does Not exist in text*/
int find_string(char* keyString, char* text, int startIndex);

/*	a function to read a string from stdin
	- input: a string
	- output: just read string from stdin and write it to
	input string variable*/
void read_string(char* string);


// main
int main(int argc, char const *argv[]) {

	char firstString[SIZE_STRING];		// replaced string
	char secondString[SIZE_STRING];	// replacing string
	char text[SIZE_STRING];			// text
	char newText[SIZE_STRING];			// text after being replaced
	// set newText to empty
	memset(newText, '\0', sizeof(newText));

	// when coding mode is on, take input from file
	#ifdef CODING
		freopen("./inputData.txt", "r", stdin);
	#endif // CODING
	// enter the first string
	read_string(firstString);
	// enter the second string
	read_string(secondString);
	// enter the text
	read_string(text);
	// replace firstString with secondString in text
	#ifdef DEBUG
		printf("## firstString: %s\n", firstString);
		printf("## secondString: %s\n", secondString);
		printf("## text: %s\n", text);
		// strncat(newText, text + 10, 10);
		// printf("## newText 1ST: %s\n", newText);
	#endif // DEBUG
	replace_string(text, newText, firstString, secondString, 0);
	// print out the result
	printf("%s\n", newText);
	return 0;
}	// end  main 


// function to replace the firstString to secondString in
// 		the given text
void replace_string(char* text, char* newText, char* firstString,
					 char* secondString, int startIndex) {
	// stop condition
	if (startIndex < strlen(text)) {
		// the position of firstString in text
		int foundIndex; 	
		foundIndex = find_string(firstString, text, startIndex);
		// check if firstString is found
		if (foundIndex != -1) {	// found
			// concatenate substring of text to newText
			//// from: startIndex to foundIndex -1
			int sizeSubstring = foundIndex - startIndex;
			strncat(newText, (text + startIndex), sizeSubstring);
			// concatenate secondString to nexText
			strcat(newText, secondString);
			// Call ITSELF to find and replace last part of text
			int newStartIndex = foundIndex + strlen(firstString);
			replace_string(text, newText, firstString, secondString,
							newStartIndex);
		} else	// NOT Found
			// concatenate last part of text to newText
			strcat(newText, text + startIndex);
			// close if 1
	}	// close if
}	// end replace_string


// function to find the first position of keyString in a given text
int find_string(char* keyString, char* text, int startIndex) {
	// stop condition
	if (startIndex >= strlen(text)) 
		return -1;
	// # Find first char of keyString in text
	// pointer of first char in text from startIndex
	char* firstPointer = strchr(text + startIndex, keyString[0]);
	if (firstPointer != NULL) {	// found
		int firstIndex = firstPointer - text;
		// check if keyString exist in this firstIndex
		int isExist = 1;	// mean true
		for (int i = 0; i < strlen(keyString); i++) 
			// compare each pair char
			if (keyString[i] != text[firstIndex + i])
				isExist = 0;	// mean false
			//	close for
		// return result
		if (isExist == 1)
			return firstIndex;
		else		// continue searching in text from index after firstIndex
			return find_string(keyString, text, (firstIndex + 1));
	} else	// Not found
		return -1;
		// close if
}	// end find_string


// function to read a string from stdin
void read_string(char* string) {
	// read string from stdin
	fgets(string, sizeof(string), stdin);
	// check if last char in string is newline
	int len = strlen(string);
	if (string[len - 1] == '\n')	// is a newline
		string[len - 1] = '\0';		// replace it with END_OF_STRING char
}	// close read_string