/*
 * Provide printing a triangle with dot given the size of the triangle 
 * */

 package hust.soict.dsai.lab01;

import java.util.Scanner;


public class Triangle {

	public static String make_string(char c, int number) {
		String buffer = ""; 
		for (int i = 0; i < number; i ++ ) {
			buffer += c;
		}	// close for
		return buffer;
	}	// close make_string
	

	// show triangle
	public static void show(int size) {
		// for each line
		for (int line = 0; line < size; line ++ ) {
			// find number of SPACE
			int spaceN = size - line;
			// find number of *
			int starN = line * 2 + 1;
			String lineStar = make_string(' ', spaceN) + make_string('*', starN);
			System.out.println(lineStar);
		}	// close for
	}	// close 


	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Please enter the size of triangle: ");
		int size = scan.nextInt();
		Triangle.show(size);
		scan.close();
	}	// close main
}	// close class
