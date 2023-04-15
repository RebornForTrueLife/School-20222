/*
	THis program is used to enter your name
 */

import javax.swing.JOptionPane;


public class AskingName {
	// MAIN
	public static void main(String[] args) {
		String name = JOptionPane.showInputDialog("Please enter your name: ");
		JOptionPane.showMessageDialog(null, "Hi " + name);
		System.exit(0);
	}	// close main
}	// close class