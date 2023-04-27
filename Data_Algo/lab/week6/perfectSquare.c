/*
    The program: to count the number of perfect square in given integer sequence
 */

 #include <stdio.h>
 #include <math.h>


 // FUNC DECLARE

 // to check if a number is a perfect square
 int check(int number);



 // MAIN
 int main() {
     // enter the number of integers
     int size;
     scanf("%d", &size);
     // enter the sequence and count number of perfect square
     int count = 0;
     int value;
     for (int i = 0; i < size; i++ ) {
        scanf("%d", &value);
        if (check(value) == 1) {
            count += 1;
        }   // close if
     }  // close for
     // print the count
     printf("%d\n", count);
     return 0;
 } // close main



 // FUNC DEFINE

 // check: return 1 means true; 0 for the inverse
 int check(int number) {
     float sqrtNum = sqrt(number);
     int sqrtInt = floor(sqrtNum);
     if ( (sqrtInt * sqrtInt) == number ) {
        return 1;
     }  // close if
     return 0;
 }  // close check
