/*	
	This program is used to solve 3 kinds of euqations
		(1) Linear equation 1 variable: ax + b = 0
		(2) Linear equation 2 variables:
			a1.x + b1.y = c1
			a2.x + b2.y = c2
		(3) Quadratic equation 1 variable:
			ax^2 + bx + c = 0
	Usage:
		1. Choose 1 option
		2. Enter corresponding inforation to the option
		3. The program will solve the equation and show the solution
 */

 package hust.soict.dsai.lab01;

import javax.swing.JOptionPane;
import java.lang.Math;


public class SolveEquation {
	/* a method to solve linear 1 variable equation 
		- input: 2 double a and b
		- output: show the solutions */
	public static void solve_linear(double a, double b) {
		String solMess = "";		// solution message
		int flag = 1;		// just flag = 0 when a = 0 
		if (a == 0)
			flag = 0;

		switch (flag) {
		case 0:
			if (b == 0)
				solMess += "There is infinity solutions";
			else 
				solMess += "No Solution";
			break;
		default: 
			double sol = - b / a;
			solMess += "There is 1 solution, x = " + sol;
		}	// close switch
		// print solution
		JOptionPane.showMessageDialog(null, solMess);
	}	// close solveLinear 1 variable


	/* a method to solve linear 2 variables equation 
		- input: 6 double a1, b1, c1, a2, b2, c2
		- output: show the solutions */
	public static void solve_linear(double a1, double b1, double c1, double a2, double b2, double c2) {
		String solMess = "";
		// Calculate 3 determinants
		double d = a1 * b2 - a2 * b1;
		double dx = c1 * b2 - c2 * b1;
		double dy = a1 * c2 - a2 * c1;
		if (d == 0)
			// infinite solution
			if ((dx * dy != 0) || ((dx == 0) && (dy == 0)))
				solMess += "There is infinite solutions";
			else 
				solMess += "No solution";
		else {
			// CONTINUE HERE
			double x = dx / d;
			double y = dy / d;
			solMess += "x = " + x + "\ny = " + y + "\n";
		}	// close if
		JOptionPane.showMessageDialog(null, solMess, "Result", JOptionPane.INFORMATION_MESSAGE);
	}	// close solveLinear 2 variables

	/*	a method to solve quadratic  variable equation 
		- input: 3 double: a, b, c
		- output: show solution */
	public static void solve_quadratic(double a, double b, double c) {
		String solMess = "";
		double delta = (b * b) - 4 * a * c;
		if (delta > 0) {		// 2 roots
			delta = Math.sqrt(delta);
			double x1 = (-b + delta) / (2 * a);
			double x2 = (-b - delta) / (2 * a);
			solMess += "There are 2 roots: " + x1 + " and " + x2 + "\n";
		} else if (delta == 0) {		// double roots
			double x = -b / (2 * a);
			solMess += "There is 1 roots: " + x + "\n";
		} else {
			solMess += "No solutions\n";
		}	// close if
		JOptionPane.showMessageDialog(null, solMess, "Result", JOptionPane.INFORMATION_MESSAGE);
	}	// close solveQuadratic


	/*	a function to print the user interface and call the correspond solver */
	public static void user_interface() {
		// Print option list
		String optionMessage = "";
		optionMessage += "There 3 options for 3 kinds of equation:\n";
		optionMessage += "\t[1] Linear 1 variable equation\n";
		optionMessage += "\t[2] Linear 2 variables equation\n";
		optionMessage += "\t[3] Quadratic 1 variable equation\n";
		JOptionPane.showMessageDialog(null, optionMessage, "Option List", JOptionPane.INFORMATION_MESSAGE);
		// Get choice
		String choice = null;
		choice = JOptionPane.showInputDialog(null, "Enter option number: ", "Option choice", JOptionPane.INFORMATION_MESSAGE);
		// Declare variable
		String[] listString = new String[6];
		double[] listDouble = new double[6];
		// Call solver
		switch (choice) {
			// solve linear 1 var equation
		case "1":
			// get parameters
			listString[0] = JOptionPane.showInputDialog(null, "Enter a = ", "ax + b = 0", JOptionPane.INFORMATION_MESSAGE);
			listString[1] = JOptionPane.showInputDialog(null, "Enter b = ", "ax + b = 0", JOptionPane.INFORMATION_MESSAGE);
			listDouble[0] = Double.parseDouble(listString[0]);
			listDouble[1] = Double.parseDouble(listString[1]);
			// call solver
			solve_linear(listDouble[0], listDouble[1]);
			break;
			// solve linear 2 vars equation
		case "2":
			// enter 6 parameters
			listString[0] = JOptionPane.showInputDialog(null, "Enter a1 = ", "a1.x + b1.y = c1\na2.x + b2.y = c2", JOptionPane.INFORMATION_MESSAGE);
			listString[1] = JOptionPane.showInputDialog(null, "Enter b1 = ", "a1.x + b1.y = c1\na2.x + b2.y = c2", JOptionPane.INFORMATION_MESSAGE);
			listString[2] = JOptionPane.showInputDialog(null, "Enter c1 = ", "a1.x + b1.y = c1\na2.x + b2.y = c2", JOptionPane.INFORMATION_MESSAGE);
			listString[3] = JOptionPane.showInputDialog(null, "Enter a2 = ", "a1.x + b1.y = c1\na2.x + b2.y = c2", JOptionPane.INFORMATION_MESSAGE);
			listString[4] = JOptionPane.showInputDialog(null, "Enter b2 = ", "a1.x + b1.y = c1\na2.x + b2.y = c2", JOptionPane.INFORMATION_MESSAGE);
			listString[5] = JOptionPane.showInputDialog(null, "Enter c2 = ", "a1.x + b1.y = c1\na2.x + b2.y = c2", JOptionPane.INFORMATION_MESSAGE);
			// cast to double
			listDouble[0] = Double.parseDouble(listString[0]);
			listDouble[1] = Double.parseDouble(listString[1]);
			listDouble[2] = Double.parseDouble(listString[2]);
			listDouble[3] = Double.parseDouble(listString[3]);
			listDouble[4] = Double.parseDouble(listString[4]);
			listDouble[5] = Double.parseDouble(listString[5]);
			
			// call solver
			solve_linear(listDouble[0], listDouble[1], listDouble[2], listDouble[3], listDouble[4], listDouble[5]);
			break;
			// solve quadratic equation
		case "3":
			// enter parameters
			listString[0] = JOptionPane.showInputDialog(null, "Enter a: ", "ax^2 + bx + c = 0", JOptionPane.INFORMATION_MESSAGE);
			listString[1] = JOptionPane.showInputDialog(null, "Enter b: ", "ax^2 + bx + c = 0", JOptionPane.INFORMATION_MESSAGE);
			listString[2] = JOptionPane.showInputDialog(null, "Enter c: ", "ax^2 + bx + c = 0", JOptionPane.INFORMATION_MESSAGE);
			// cast to double
			listDouble[0] = Double.parseDouble(listString[0]);
			listDouble[1] = Double.parseDouble(listString[1]);
			listDouble[2] = Double.parseDouble(listString[2]);
			// call solver
			solve_quadratic(listDouble[0], listDouble[1], listDouble[2]);
			break;
			// invalid option
		default:
			JOptionPane.showMessageDialog(null, "Invalid option, must be 1 or 2 or 3!", "Warning", JOptionPane.INFORMATION_MESSAGE);
		}	// close switch
	}	// close userInterface


	// MAIN
	public static void main(String[] args) {
		SolveEquation.user_interface();
	}	// close main
}	// close class