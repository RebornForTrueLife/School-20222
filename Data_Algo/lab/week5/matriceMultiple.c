/********************************************
 * matriceMultiple - multiple 2 given matrice
 * Uage: 
	- run the objec file
	- enter number of rows and cols of first matrix
	- enter the first matrix
	- enter number of rows and cols of second
	- enter the second matrix
	- The program will print out the product
	* Note: number of cols of first matrix must be equal
	* to the number of rows of second matrix
 ********************************************/

#include <stdio.h>
#include <stdlib.h>


// DATA DECLARE
typedef struct Matrix_ Matrix;

// Define Matrix
struct Matrix_ {
	int rowN; 	// number of rows
	int colN;	// number of columns
	int **value;	// matrix values
};	// close Matrix_


// FUNC DEFINE

// Enter 1 matrix
void input_matrix(Matrix *matrix);

// multiple 2 matrice
void multiple_matrice();

// print matrix
void print_matrix(Matrix *matrix);


// MAIN
int main(int argc, char const *argv[]) {
	multiple_matrice();
	return 0;
}	// end  main 


// FUNC DEFINE

// enter matrix

void input_matrix(Matrix *matrix) {
	int rowN = matrix->rowN;
	int colN = matrix->colN;
	int **value = matrix->value;
	for (int row = 0; row < rowN; row ++ ) {
		for (int col = 0; col < colN; col ++ ) {
			scanf("%d", (*(value + row) + col));
		}	// close for
	}	// close for
}	// close input_matrix


void print_matrix(Matrix *matrix) {
	int rowN = matrix->rowN;
	int colN = matrix->colN;
	int **value = matrix->value;
	for (int row = 0; row < rowN; row ++ ) {
		for (int col = 0; col < colN; col ++ ) {
			printf("%d ", *(*(value + row) + col));
		}	// close for
		printf("\n");
	}	// close for
}	// close print_matrix


// multiple 2 matrice
void multiple_matrice() {
	// enter first matrix
	Matrix *matrixA = (Matrix *) malloc (sizeof(Matrix));
	scanf("%d %d", &(matrixA->rowN), &(matrixA->colN));
	// allocate memory for matrix
	matrixA->value = (int **) calloc (matrixA->rowN, sizeof(int *));
	for (int row = 0; row < matrixA->rowN;  row ++ )
		matrixA->value[row] = (int *) calloc (matrixA->colN, sizeof(int));
	input_matrix(matrixA);
	// enter second matrix
	Matrix *matrixB = (Matrix *) malloc (sizeof(Matrix));
	scanf("%d %d", &(matrixB->rowN), &(matrixB->colN));
	// allocate memory for matrix
	matrixB->value = (int **) calloc (matrixB->rowN, sizeof(int *));
	for (int row = 0; row < matrixB->rowN;  row ++ )
		matrixB->value[row] = (int *) calloc (matrixB->colN, sizeof(int));
	input_matrix(matrixB);
	// multiple 2 matrix
	// Check if 2 matrice can be multiplized
	if (matrixA->colN != matrixB->rowN) {
		printf("Number of columns of first Matrix must be equal to number of rows of second Matrix\n");
		return;
	}	// close if
	// Allocate memory for product matrix
	Matrix *product = (Matrix *) malloc (sizeof(Matrix));
	product->rowN = matrixA->rowN;
	product->colN = matrixB->colN;
	// allocate memory for matrix
	product->value = (int **) calloc (product->rowN, sizeof(int *));
	for (int row = 0; row < product->rowN;  row ++ )
		product->value[row] = (int *) calloc (product->colN, sizeof(int));
	// multiplize
	for (int row = 0; row < product->rowN; row ++ ) {
		for (int col = 0; col < product->colN; col ++ ) {
			int sum = 0;
			for (int i = 0; i < matrixA->colN; i ++ ) 
				sum += matrixA->value[row][i] * matrixB->value[i][col];
			product->value[row][col] = sum;
		}	// close for
	}	// close for
	print_matrix(product);
}	// close multiple_matrice