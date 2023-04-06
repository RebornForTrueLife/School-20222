/*
    The program is used to get the transactions information
    And calculate the total money from input transactions
 */

 #include <stdio.h>
 #include <stdlib.h>

 // CONST
 const int SIZE = 20;           // size of string vars
 const int LINE_SIZE = 100;     // size of input line


 // main
 int main() {
     // DECLARE
     char fromAcc[SIZE + 1];    // from account
     char toAcc[SIZE + 1];      // to account
     long money;                // transaction money
     char timePoint[SIZE];      // transaction time
     char atm[SIZE];            // transaction location
     char line[LINE_SIZE];      // input line
     long total = 0;            // total transaction money

     // Debug mode
     // freopen("dataEx2", "r", stdin);


     // Read list of transaction, stop when reach the line: '#'
     // WHILE true
     while (1) {
        // READ each input line
        fgets(line, LINE_SIZE, stdin);

        printf("## %s", line);

        // CHECK if line is "#": GET OUT
        if (line[0] == '#')
            break;
        // READ: [fromAccount] [toAccount] [money] [timePoint] [atm]
        int number = sscanf(line, "%s %s %ld %s %s", fromAcc, toAcc, &money, timePoint, atm);
        // CHECK if read enough data
        if (number != 5)
            break;
        // ADD [money] to [total]
        total += money;
     }  // close while

    // Read query of user: only one query for this program: total transaction money
    // WHILE true
    while (1) {
        // READ [line]
        fgets(line, LINE_SIZE, stdin);
        // CHECK if [line] is "#": GET OUT
        if (line[0] == '#')
            break;
        // READ [query]
            // do nothing: cuz there is only one query can be in this program
    }   // close while

    // print the total money
    printf("%ld\n", total);

    return 0;
 }  // close main
