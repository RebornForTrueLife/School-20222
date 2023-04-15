/*
	The program is used to enter 2 number, and print
	out
 */

import javax.swing.JOptionPane;


public class ShowTwoNumber {
	// MAIN
	public static void main(String[] args) {
		// Enter first number
		String n1 = JOptionPane.showInputDialog(null, "Please enter the first number: ", "Input the first number", JOptionPane.INFORMATION_MESSAGE);
		// Enter second number
		String n2 = JOptionPane.showInputDialog(null, "Please enter the second number: ", "Input the second number", JOptionPane.INFORMATION_MESSAGE);
		// Print message
		String message = n1 + " \n " + n2;
		JOptionPane.showMessageDialog(null, message, "Show 2 numbers", JOptionPane.INFORMATION_MESSAGE);
		System.exit(0);
	}	// close main
}	// close class