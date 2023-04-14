/*
    The program is used to get the transactions information
    And calculate the total amount of transaction money from given account
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 // CONST
 const int SIZE = 20;           // size of string vars
 const int LINE_SIZE = 100;     // size of input line
 const int TRANS_SIZE = 1000000;  // number of transaction

// STRUCTURE DECLARE
struct Transaction {
    char *fromAcc;      // from account
    char *toAcc;        // to account
    long amount;        // money
    char *timePoint;    // time
    char *atm;          // location
};

struct Query {
    char *acc;      // account
    long result;    // total amount
};

// FUNC DECLARE
/*  a function to read each lines from stdin until reach character: '#'
        PUT line to given list
        CHANGE the size to the number of actual read */
void read_line(char **list, int *size);

/*  a function to count all money transaction of each account in the given list of query
    - input:
        1. list of transaction
        2. number of transaction in the list
        3. list of query
        4. number of query
    - output: return value in listQuery */
 void total_amount(struct Transaction **list, int size, struct Query **listQuery, int sizeQuery);

/*  a function to convert account string to an integer
    - input: the account string
    - output: an integer */
int getID(char *acc);


 // main
 int main() {
     // DECLARE
     char *fromAcc;        // from account
     char *toAcc;          // to account
     long money;           // transaction money
     char *timePoint;      // transaction time
     char *atm;            // transaction location


     // Debug mode
     // freopen("data.in", "r", stdin);


     // Read list of transaction, stop when reach the line: '#'
     // WHILE true
     // allocate LINE_SIZE memory for store transaction lines
     char **list = (char**) malloc ( TRANS_SIZE * sizeof(char*));
     int count = 0;   // number of transaction
     // read list of lines
     read_line(list, &count);


    // READ: [fromAccount] [toAccount] [money] [timePoint] [atm]
    struct Transaction **listTrans = (struct Transaction **) malloc (count * sizeof(struct Transaction*));    // list of transaction
        // input data from line to list of Transaction
    for (int i = 0; i < count; i ++ ) {
        // allocate new memory
        fromAcc = (char *) calloc (SIZE, sizeof(char));
        toAcc = (char *) calloc (SIZE, sizeof(char));
        timePoint = (char *) calloc (SIZE, sizeof(char));
        atm = (char *) calloc (SIZE, sizeof(char));
        // read data in line
        int number = sscanf(list[i], "%s %s %ld %s %s", fromAcc, toAcc, &money, timePoint, atm);
        if (number != 5) {   // not enough data
            printf("THE data fields is not enough at record: %d\n", i);
            exit(8);
        }   // close if
        listTrans[i] = (struct Transaction *) malloc (sizeof(struct Transaction));
        listTrans[i]->fromAcc = fromAcc;
        listTrans[i]->toAcc = toAcc;
        listTrans[i]->timePoint = timePoint;
        listTrans[i]->atm = atm;
        listTrans[i]->amount = money;
    }   // close for


    // Read query of user: only one query for this program: total transaction money
    int queryCount = 0;     // the number of query
    // read list of query lines
    read_line(list, &queryCount);
    // read account from query list
        // query list contains query in input order
    struct Query **listQuery = (struct Query **) malloc (queryCount * sizeof(struct Query *));
        // query list contains unique accounts
    struct Query **listUniQuery = (struct Query **) malloc (TRANS_SIZE * sizeof(struct Query *));
    memset(listUniQuery, (int) NULL, TRANS_SIZE);
    for (int i = 0; i < queryCount; i ++ ) {
        char *query = (char *) calloc (LINE_SIZE, sizeof(char));
        char *acc = (char *) calloc (LINE_SIZE, sizeof(char));
        int number = sscanf(list[i], "%s %s", query, acc);
        // get ID number of account
        int id = getID(acc);
        // check if acc already stored in query list
        if (listUniQuery[id] == NULL) { // if query has NOT been seen
            // create new query
            struct Query *newQuery = (struct Query *) malloc (sizeof(struct Query));
            newQuery->acc = acc;
            newQuery->result = 0;
            // put new query to unique query list
            listUniQuery[id] = newQuery;
        }   // close if
        // add query to query list
        listQuery[i] = listUniQuery[id];
    }   // close for
    // print out the query result
    total_amount(listTrans, count, listUniQuery, TRANS_SIZE);
    for (int i = 0; i < queryCount; i ++ ) {
        printf("%ld\n", listQuery[i]->result);
    }   // close for
    return 0;
 }  // close main


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
        // printf("## %s", line);

        // CHECK if line is "#": GET OUT
        if (line[0] == '#')
            break;

        // PUT line into line array
        list[*size] = line;
        (*size) += 1;
     }  // close while
}   // close read_line


// get total amount
void total_amount(struct Transaction **list, int size, struct Query **listQuery, int sizeQuery) {
    // check each transaction in the list
    for (int i = 0; i < size; i ++ ) {
        // check for each query
        int id = getID(list[i]->fromAcc);
        if (listQuery[id] != NULL)
            listQuery[id]->result += list[i]->amount;
    }   // close for
}   // close total_amount


// get id number from account
int getID(char *acc) {
    // get ID from fifth char to the end of string
    int id = atoi(acc + 4);
    return id;
}   // close getID