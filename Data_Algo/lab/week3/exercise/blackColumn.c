/********************************************
 * blackColumn - count the number of black column in 
 * the given matrix n x m 
 * Uage: 
	- run the object file
	- enter numbe of rows and number of columns
	- enter the matrix(value 1 or 0)
	- the program will number of column only has value 1
 ********************************************/

#include <stdio.h>
#include <stdlib.h>


// MODE
#define CODING		// coding mode
#undef CODING


// FUNC DECLARE
/*	countBlack
	- count number of black column of a given matrix
	- input: 
		1. the matrix
		2. number of row and number of column
	- output: number of black column */
int countBlack(int **matrix, int nRow, int nCol);

// print matrix
void print_matrix(int **matrix, int nRow, int nCol);


// MAIN
int main(int argc, char const *argv[]) {
	// while coding
	#ifdef CODING
		freopen("data.in", "r", stdin);
	#endif
	// enter number of row and col
	int n;	// number of row
	int m;	// number of column
	scanf("%d %d", &n, &m);
	// declare and allocate memory for matrix
	int **matrix = (int **) malloc (n * sizeof(int*));
	for (int i = 0; i < n; i ++ ) 
		matrix[i] = (int *) malloc (m * sizeof(int));
		// close for
	// enter matrix
	for (int row = 0; row < n; row ++ ) {
		for (int col = 0; col < m; col ++ ) 
			scanf("%d ", (*(matrix + row) + col));
		// printf("\n");
	}	// close for
	
	// print_matrix(matrix, n, m);
	// calculate number of black column
	int count = countBlack(matrix, n, m);
	// print result
	printf("%d\n", count);
	return 0;
}	// end  main 


// FUNC DEFINE
void print_matrix(int **matrix, int nRow, int nCol) {
	for (int row = 0; row < nRow; row ++ ) {
		for (int col = 0; col < nCol; col ++ )
			printf("%d ", *(*(matrix + row) + col));
		printf("\n");
	}	// close for
}	// close print_matrix


// count number of black column
int countBlack(int **matrix, int nRow, int nCol) {
	int count = 0;	// number of black col
	// check each col
	for (int col = 0; col < nCol; col ++ ) {
		int check = 1;
		// check value of each row
		for (int row = 0; row < nRow; row ++ ) 
			if ( (*(matrix + row))[col] == 0)
				check = 0;
		if (check == 1)	// if whole col is all 1
			count += 1;
	}	// close for
	return count;
}	// close countBlack