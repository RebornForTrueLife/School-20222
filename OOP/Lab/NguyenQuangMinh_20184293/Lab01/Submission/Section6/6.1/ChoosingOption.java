/*
 * This program is used to ask user choose 1 of 2 options	 
 */

import javax.swing.JOptionPane;

public class ChoosingOption {
	// choosing option with custom label button
	public static void choose() {
		Object[] options = {"I do", "I don't"};
		String askMess = "Do you want to change the first class ticket?";
		int option = JOptionPane.showOptionDialog(null, 
				askMess,							// message 
				"Confirm", 							// title
				JOptionPane.YES_NO_OPTION,			// option type
				JOptionPane.QUESTION_MESSAGE,		// message type
				null,								// no custom icon
				options,							// button titles
				options[0]							// default button
			); // close option
		String message = "You've chosen " + (option == JOptionPane.YES_OPTION?"I do":"I don't");
		JOptionPane.showMessageDialog(null, message);
		
	}	// close choose
	
	
	// default choosing
	public static void choose_default() {
		int option = JOptionPane.showConfirmDialog(null,
				"Do you want to change the first class ticket?", "", JOptionPane.YES_NO_OPTION);
		String message = "You've chosen " + (option == JOptionPane.YES_OPTION?"Yes":"No");
		JOptionPane.showMessageDialog(null, message);
	}	// close choose_default
	
	
	public static void main (String[] args) {
		ChoosingOption.choose();
		ChoosingOption.choose_default();
		System.exit(0);
	}	// close main
}	// close class
