/*
    * This program is used to calculate an expression of adding operators given in form of a string
    * Constaint: the given string includes only '+' operator and operands(which are positive integer)
                - number of operators upto 10000
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 // CONST
 #define SIZE 100000        // maximum size of expression
 #define MODULO 1000000007  // modulo number E+9 + 7


 // FUNC DECLARE

 // find integer: given a string ptr, find the first index of the first integer in string between + operator
 int find_integer(char *str);

 // convert first integer in string to an int
 int get_integer(char *str, int index);



 // MAIN
 int main() {
     // read the string from stdin
     char *str;   // the given adding expression
     str = (char *) calloc (SIZE, sizeof(char));
     scanf("%s", str);
     // read each integer in string
     int sum = 0;
     int value;
     int pos = 0;
     // find integer: return the index of the integer
     while (1) {
        if (strlen(str) == 0)   // string is empty
            break;
        // find the index of the first integer
        pos = find_integer(str);
        if (pos == -1) {
            printf("NOT_CORRECT\n");
            exit(8);
        }   // close if
        // read integer
        value = get_integer(str, pos);
        // add integer with modulo
        sum = (sum + value) % MODULO;
        // move to next operand
        while (1) {
            if ( (str[pos] < 48) || (str[pos] > 57) )
                break;
            pos += 1;
        }  // close while 1
        str += pos;
     }  // close while
     // print sum
     printf("%d\n", sum);
     return 0;
 }  // close main



 // FUNC DEFINE

 // find integer: given a string ptr, find the first index of the first integer in string between + operator
 int find_integer(char *str) {
     int pos = 0;
     int index = 0;
     // go through all '+'
     while (1) {
        if (str[pos] != '+')
            break;
        pos += 1;
     }  // close while
     // check if it reach an digit
     if ( (str[pos] < 48) || (str[pos] > 57) )
        return -1;  // mean the string contain INVALID char
     return pos;
 }  // close find_integer


 // convert first integer in string to an int
 int get_integer(char *str, int index) {
     int pos = index;
     // count size of the integer
     while (1) {
        pos += 1;
        if ( (str[pos] < 48) || (str[pos] > 57) )
            break;
     }  // close while
     char strInt[10];
     strncpy(strInt, str + index, pos - index);
     strInt[pos - index] = '\0';
     int value = atoi(strInt);
     return value;
 }  // close get_integer
