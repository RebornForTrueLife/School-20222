/*
	This program is used to provide (1) operator for 2 given same size matrix:
		(1) Add
 */

import java.util.Scanner;


public class Matrice {

	// Variable members
	private int[][] matrixA;	// first matrix
	private int[][] matrixB;	// second matrix

	// FUNC MEMBERs

	// constructor
	Matrice() {
		// For simplicity, use constant matrices
		int[][] bufferA = {
			{1, 2, 3}, 	// row 0
			{4, 5, 6}, 	// row 1
			{7, 8, 9}, 	// row 2
		};
		matrixA = bufferA;
		int[][] bufferB = {
			{-1, -2, -3}, 	// row 0
			{-4, -5, -6}, 	// row 1
			{-7, -8, -9}, 	// row 2
		};
		matrixB = bufferB;
		System.out.println("Contructed Matrice");
		// print matrice
		System.out.println("First matrix: ");
		print_matrix(matrixA);
		System.out.println("Second matrix: ");
		print_matrix(matrixB);
	}	// close constructor


	// add 2 matrice
	public void add() {
		int rowN = matrixA.length;
		int colN = matrixA[0].length;
		int[][] sum = new int[rowN][colN];
		for (int row = 0; row < rowN; row ++ ) {
			for (int col = 0; col < colN; col ++ ) 
				sum[row][col] = matrixA[row][col] + matrixB[row][col];
		}	// close for
		// print result
		System.out.println("Sum matrix:");
		print_matrix(sum);
	}	// close add


	// print matrix
	public void print_matrix(int[][] matrix) {
		if (matrix == null) {
			System.out.println("The matrix is empty!");
			return;
		}	// close if
		// print
		for (int[] row : matrix) {
			for (int ele: row) {
				System.out.print(ele + " ");
			}	// close for 1
			System.out.println();
		}	// close for
	}	// close print_matrix


	// MAIN
	public static void main(String[] args) {
		Matrice ma = new Matrice();
		ma.add();
	}	// close main
}	// close class