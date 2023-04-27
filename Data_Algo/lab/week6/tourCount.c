/*
    The program is used to find the number of tours through all given cities
        which has the total distance less or equal given length
 */

#include <stdio.h>


// CONST
#define SIZE 16     // max number of cities


// FUNC DECLARE
// read input
void read_data();

// validate city
int validate(int city, int des, int length);

// try each des
void tryDes(int des, int length);



// GLOBAL DATA
int distance[SIZE][SIZE];   // matrix of cities distance
int numCity;                // number of cities
int maxLength;              // maximum travel length of tour
int count;                  // number of tour found
int tour[SIZE];             // possible tour
int mark[SIZE];             // marking the cities whether it is traveled


// MAIN
int main () {
    // read number of cities and the maximum length
    read_data();
    // count
    count = 0;
    tour[0] = 0;
    mark[0] = 1;
    tryDes(1, 0);
    // print count
    printf("%d\n", count);
    return 0;
}   // close main


// read data
void read_data() {
    scanf("%d %d", &numCity, &maxLength);
    for (int row = 0; row < numCity; row ++ ) {
        for (int col = 0; col < numCity; col ++ )
            scanf("%d", &distance[row][col]);
    }   // close for
}   // close read_data


// validate city
int validate(int city, int des, int length) {
    if (mark[city] == 1)
        return 0;
    if ( (length + distance[des][city]) > maxLength)
        return 0;
    return 1;
}   // close validate


// try each des
void tryDes(int des, int length) {
    for (int city = 0; city < numCity; city ++ ) {
        if (validate(city, des, length) == 0)
            continue;
        tour[des] = city;
        mark[city] = 1;
        if (des == numCity - 1)
            count += 1;
        else
            tryDes(des + 1, length + distance[des - 1][des]);
        mark[city] = 0;
    }   // close for
}   // close tryDes
