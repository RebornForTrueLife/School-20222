/*
    Program is used to respond defined queries given a sequence of integer
 */

 #include <stdio.h>
 #include <string.h>

// CONST
#define SIZE 10000          // max size of array
#define MAX_QUERY 10000     // max number of queries
#define LINE 1000           // max characters in a line


// DECLARE ENUM
typedef enum {MAX, MIN, SUM, MAX_SEG, UNKNOWN} QueryType;
typedef struct Query_ Query;

// STRUCT DEFINE
struct Query_ {
    QueryType type;
    int startIndex;
    int endIndex;
};


// FUNC DECLARE

// read integer array
void read_array(int *array, int *size);


// read list of queries
void read_query(Query *queryList, int *size);


// respond to a query
void respond(Query *query, int *array, int size);



 // MAIN
 int main() {
     // read integer array
     int array[SIZE];
     int size;      // size of array
     read_array(array, &size);
     // read query list
     Query queryList[MAX_QUERY];
     int numQuery;  // number of queries
     read_query(queryList, &numQuery);
     // respond to each query
     for (int i = 0; i < numQuery; i ++ )
        respond(&queryList[i], array, size);
     return 0;
 }  // close main



// FUNC DEFINE

// read integer array
void read_array(int *array, int *size) {
    // read number of integers
    int n;
    scanf("%d", &n);
    *size = n;
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", array + i);
    }   // close for
    // remove the END_ARRAY LINE: "*"
    char buffer[10];
    while (!feof(stdin)) {
        fgets(buffer, 10, stdin);
        if (buffer[0] == '*')
            break;
    }   // close while
}   // close readArray


// read list of queries
void read_query(Query *queryList, int *size) {
    char buffer[LINE];
    *size = 0;
    while (1) {
        fgets(buffer, LINE, stdin);
        buffer[strlen(buffer)] = '\0';
        // break when reach line: "***"
        if ( (buffer[0] == '*') && (buffer[1] == '*') && (buffer[2] == '*') )
            break;
        if (feof(stdin))
            break;
        // read query
        char queryStr[100];
        QueryType type;
        sscanf(buffer, "%s", queryStr);
            // find type of query
        if (strcmp(queryStr, "find-max") == 0)
            type = MAX;
        else if (strcmp(queryStr, "find-min") == 0)
            type = MIN;
        else if (strcmp(queryStr, "sum") == 0)
            type = SUM;
        else if (strcmp(queryStr, "find-max-segment") == 0)
            type = MAX_SEG;
        else
            type = UNKNOWN;
            // if query type is find-max-segment -> read 2 indices of the segment
        int startIndex = 0;
        int endIndex = 0;
        if (type == MAX_SEG)
            sscanf(buffer, "%s %d %d", queryStr, &startIndex, &endIndex);
            // create a query with read info
        if (type == UNKNOWN)
            continue;
        queryList[*size].type = type;
        queryList[*size].startIndex = startIndex - 1;   // input index start from 1
        queryList[*size].endIndex = endIndex - 1;
        // increase size of list
        *size += 1;
    }   // close while
}   // close read_query


// respond to a query
void respond(Query *query, int *array, int size) {
    int max = - 2000;   // minimum value of element is -1000
    int min = 2000;     // maximum value of element is 1000
    int sum = 0;
    switch (query->type) {
    case MAX:
        for (int i = 0; i < size; i ++ )
            if (max < array[i])
                max = array[i];
        printf("%d\n", max);
        return;
    case MIN:
        for (int i = 0; i < size; i ++ )
            if (min > array[i])
                min = array[i];
        printf("%d\n", min);
        return;
    case SUM:
        for (int i = 0; i < size; i ++ )
            sum += array[i];
        printf("%d\n", sum);
        return;
    case MAX_SEG:
        for (int i = query->startIndex; i <= query->endIndex; i ++ )
            if (max < array[i])
                max = array[i];
        printf("%d\n", max);
        return;
    default:
        return;
    }   // close switch
}   // close query
