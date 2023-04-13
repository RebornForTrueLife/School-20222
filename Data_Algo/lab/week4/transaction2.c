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
 const int TRANS_SIZE = 100000;  // number of transaction

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

 // main
 int main() {
     // DECLARE
     char *fromAcc;        // from account
     char *toAcc;          // to account
     long money;           // transaction money
     char *timePoint;      // transaction time
     char *atm;            // transaction location


     // Debug mode
     freopen("data.in", "r", stdin);


     // Read list of transaction, stop when reach the line: '#'
     // WHILE true
     char *line;      // input line
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
        fromAcc = (char *) malloc (SIZE * sizeof(char));
        toAcc = (char *) malloc (SIZE * sizeof(char));
        timePoint = (char *) malloc (SIZE * sizeof(char));
        atm = (char *) malloc (SIZE * sizeof(char));
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
    int accCount = 0;       // number of unique accounts
    // read list of query lines
    read_line(list, &queryCount);
    // read account from query list
    struct Query **listQuery = (struct Query **) malloc (queryCount * sizeof(struct Query *));
    struct Query **listActualQuery = (struct Query **) malloc (queryCount * sizeof(struct Query *));
    for (int i = 0; i < queryCount; i ++ ) {
        char *query = (char *) malloc (LINE_SIZE * sizeof(char));
        char *acc = (char *) malloc (LINE_SIZE * sizeof(char));
        int number = sscanf(list[i], "%s %s", query, acc);
        // check if acc already stored in query list
        int flag = 0;   // not seen
        int accIndex = 0;
        for (accIndex = 0; accIndex < accCount; accIndex ++) {
            if (strcmp(acc, listQuery[accIndex]->acc) == 0) {
                flag = 1;   // seen
                // DEBUG
                printf("## %s - %d\n", acc, accIndex);
                break;
            }   // close if
        }   // close for 1

        if (flag == 0) {  // if account already seen, just move to next query
            listActualQuery[accCount] = (struct Query *) malloc (sizeof(struct Query));
            listActualQuery[accCount]->acc = acc;
            listActualQuery[accCount]->result = 0;
            accIndex = accCount;
            accCount += 1;
        }   // close if
        listQuery[i] = listActualQuery[accIndex];
    }   // close for
    // print out the query result
    total_amount(listTrans, count, listActualQuery, accCount);
    for (int i = 0; i < queryCount; i ++ ) {
        printf("%s - %ld\n", listQuery[i]->acc, listQuery[i]->result);
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
    long total = 0;
    // check each transaction in the list
    for (int i = 0; i < size; i ++ ) {
        // check for each query
        for (int j = 0; j < sizeQuery; j ++ ) {
            if (strcmp(list[i]->fromAcc, listQuery[j]->acc) == 0) {    // matched account
                listQuery[j]->result += list[i]->amount;
                // break;
            }   // close if
        }   // close for 1
    }   // close for
}   // close total_amount
