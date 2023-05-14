/*
 * This program is used to get information of user:
 * 	1. Name
 * 	2. Age
 * 	3. Height
 */

package hust.soict.dsai.lab01;

import java.util.Scanner;


public class InputFromKeyboard {
	// MAIN
	public static void main (String[] args) {
		// create a scanner
		Scanner scan = new Scanner(System.in);
		// ask name
		System.out.println("What is your name?");
		String name = scan.nextLine();
		// ask age
		System.out.println("How old are you?");
		int age = scan.nextInt();
		// ask height
		System.out.println("How tall are you?");
		double height = scan.nextDouble();
		// print info
		System.out.println("Sir/Madam " + name + ", " + age + " years old." + " Your height is " + height + ".");
		// close scan		
		scan.close();
		System.exit(0);
	}	// close main
}	// close class
