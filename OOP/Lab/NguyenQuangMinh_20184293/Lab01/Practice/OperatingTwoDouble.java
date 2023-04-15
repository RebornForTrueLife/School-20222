/*
	This program is used to operating 2 input doubles
	with 4 operators: add, subtract, multiple, divide
	And show the result on screen
	* Note: operating in input order. Checking zero for 
	second double for division
 */

import javax.swing.JOptionPane;


public class OperatingTwoDouble {
	// MAIN
	public static void main(String[] args) {
		// Enter 2 number
		String sd1, sd2;	// 2 input string double 
		sd1 = JOptionPane.showInputDialog(null, "Enter first operand: ", "Input 2 double", JOptionPane.INFORMATION_MESSAGE);
		sd2 = JOptionPane.showInputDialog(null, "Enter first operand: ", "Input 2 double", JOptionPane.INFORMATION_MESSAGE);
		// cast to double type
		double d1 = Double.parseDouble(sd1);
		double d2 = Double.parseDouble(sd2);
		// OPERATING
			// adding
		double sum = d1 + d2;
			// subtract
		double difference = d1 - d2;
			// product
		double product = d1 * d2;

		// Show message
		String message = "Operand 1 = " + d1 + "\t Operand 2 = " + d2 + "\n"
						+ "Sum = " + sum + "\n"
						+ "Difference = " + difference + "\n"
						+ "Product = " + product + "\n";
		// check if d2 is 0
		if (d2 == 0)
			message += "Unable to divide 0\n";
		else {
			double quotient;
			quotient = d1 / d2;
			message += "Quotient = " + quotient + "\n";
		}	// close if

		JOptionPane.showMessageDialog(null, message, "Result", JOptionPane.INFORMATION_MESSAGE);
		System.exit(0);
	}	// close main
}	// close class