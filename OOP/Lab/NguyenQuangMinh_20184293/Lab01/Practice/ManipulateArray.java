/*	
	This program is used to manipulate an integer array, 3 operators:
		1. sort
		2. sum
		3. get average value
 */

import java.util.Scanner;
import java.util.Arrays;


public class ManipulateArray {

	// FIELDs
	private int[] array;


	// FUNC MEMBERs
	// constructor
	ManipulateArray(int size) {
		array = new int [size];
		Scanner scan = new Scanner(System.in);
		System.out.print("Please enter the array: ");
		for (int i = 0; i < size; i ++ ) {
			array[i] = scan.nextInt();
		}	// close for
		
		System.out.println("Constructed Array!");
	}	// close constructor


	// print the array
	private void print_array() {
		System.out.println(Arrays.toString(array));
	}	// close print_array


	// sort array in accending order
	private void sort() {
		Arrays.sort(array);
		System.out.print("The array after sorted: ");
		print_array();
	}	// close sort


	// sum array
	private void sum() {
		int s = 0;	// sum of array
		for (int i : array) {
			s += i;
		}	// close for
		System.out.println("Sum of array = " + s);
	}	// close sum


	// average
	private void average() {
		int s = 0;	// sum of array
		for (int i : array) {
			s += i;
		}	// close for
		double a = (double) s / array.length;
		System.out.println("Average of array = " + a);
	}	// close average



	// provide user interface
	public void user_interface() {
		// check if array is not empty
		if (array == null) {
			System.out.println("The array is empty");
			System.exit(8);
		}	// close if
		// print interface
		System.out.println("The program provide 3 operators with the input array:");
		System.out.println("\t[1] Sort array.");
		System.out.println("\t[2] Sum all elements of array.");
		System.out.println("\t[3] Calculate average value.");
		System.out.println("\t[0] Quit.");
		Scanner scan = new Scanner(System.in);
		while (true) {
			System.out.print("Please enter the choice(a number): ");
			int choice = scan.nextInt();
			switch (choice) {
			case 1: 	// sort array
				sort();
				break;
			case 2:
				sum();
				break;
			case 3:
				average();
				break;
			default:
				System.out.println("SHUTDOWN...Have a nice day!");
				return;
			}	// close switch
		}	// close while
	}	// close user_interface


	// MAIN
	public static void main(String[] args) {
		// enter array
		System.out.print("Please enter the size of array: ");
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();

		// manipulate array
		ManipulateArray ma = new ManipulateArray(size);
		ma.user_interface();
		// provide user inteface to choose services(3)
		System.exit(0);
	}	// close main
}	// close class