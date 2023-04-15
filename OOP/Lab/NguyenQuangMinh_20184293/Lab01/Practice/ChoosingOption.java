import javax.swing.JOptionPane;

public class ChoosingOption {
	public static void main (String[] args) {
		int option = JOptionPane.showConfirmDialog(null, 
				"Do you want to change the first class ticket?");
		String message = "You've chosen " + (option == JOptionPane.YES_OPTION?"Yes":"No"); 
		JOptionPane.showMessageDialog(null, message);
		System.exit(0);
	}	// close main
}	// close class