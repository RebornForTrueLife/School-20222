/*
    A program to count the number of sub array that have weight
    in a range [low .. up]
 */

#include <stdio.h>
#include <stdlib.h>


// main
int main() {
    // // declare variable
    // n : array size; long int
    long int n;
    // k ; size of sub-array ; long int
    long int k;
    // up : upper bound ; long int
    long int up;
    // low ; lower bound ; long int
    long int low;
    // array : int array
    int *array;
    // scope ; sum of k consecutive elements
    long int scope = 0;
    // count ; number of sub-array has its weight match requirement
    long int count = 0;

    // debug
    // freopen("C:\20184293\week3\inputData.txt", "r", stdin);

    // Enter input data
    scanf("%ld %ld %ld %ld ", &n, &k, &low, &up);
    // Enter array
    //  allocate memory
    array = (int*)calloc(n, sizeof(int));
    //  enter element
    for (long int i = 0; i < n; i++) {
        scanf("%d", (array + i));
    }   // close for

    // calculate the first value of scope
    for (long int i = 0; i < k; i++) {
        scope += array[i];
    }   // close for

    // validate the first k-sub-array
    if ( (scope <= up) && (scope >= low) )
        count += 1;
        // close if

    // loop from index 1 to n - k
    for (long int i = 1; i <= (n - k); i ++ ) {
    //      calculate weight of k-sub-array
        scope -= array[i - 1];      // eliminate first ele of previous sub-array
        scope += array[i + k - 1];  // add new ele
    //      check if sub-array is match
        if ( (scope <= up) && (scope >= low) )
            count += 1;
            // close if
    }   // close for

    // return count
    printf("%ld\n", count);
    return 0;
} // close main
