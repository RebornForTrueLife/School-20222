#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// CONST
const int SIZE = 20;           // size of string vars
const int LINE_SIZE = 100;     // size of input line

// STRUCTURE DECLARE
struct Transaction {
char *fromAcc;      // from account
char *toAcc;        // to account
long amount;        // money
char *timePoint;    // time
char *atm;          // location
};

// FUNC DECLARE
/*  a function to read each lines from stdin until reach character: '#'
    PUT line to given list
    CHANGE the size to the number of actual read */
void read_line(char **list, int *size);


// MAIN
int main() {
    freopen("data.in", "r", stdin);
    char **list = (char **) malloc (LINE_SIZE * sizeof(char *));
    int count = 0;
    read_line(list, &count);
    printf("## number transaction = %d\n", count);

    char str1[] = "T000000044";
    char str2[] = "T000000013";
    printf("Compare T000000044 - T000000013: %d\n", strcmp(str1, str2));
}   // close main


// FUNC DEFINE

// read line
void read_line(char **list, int *size) {
    char *line;
    *size = 0;
    while (1) {
        // READ each input line
            // allocate new memory for a line
        line = (char*) calloc (LINE_SIZE, sizeof(char));
        fgets(line, LINE_SIZE, stdin);
            // add END_OF_STRING to line
        if (line[LINE_SIZE - 1] != '\0')
            line[LINE_SIZE - 1] = '\0';

        // DEBUG -------------------------
        printf("## %s", line);

        // CHECK if line is "#": GET OUT
        if (line[0] == '#')
            break;

        // PUT line into line array
        list[*size] = line;
        (*size) += 1;
     }  // close while
}   // close read_line
