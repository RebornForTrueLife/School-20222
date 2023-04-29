/*
 * This class provide user interface for DVDs store 
 * */


public class Aims {
	
	public static void main (String[] args) {
		System.out.println("Welcome to DVDs store!");
		// Create new cart
		Cart cart = new Cart();
		// Create DVDs
		DigitalVideoDics dvd1 = new DigitalVideoDics(	"The lion king", "Animation", "Roger Allers", 87, 19.95f);
		DigitalVideoDics dvd2 = new DigitalVideoDics("Star wars", "Science fiction", "George Lucas", 87, 24.95f);
		DigitalVideoDics dvd3 = new DigitalVideoDics("Aladin", "Animation", 18.95f);
		// add DVDs
		cart.addDigitalVideoDics(dvd1);
		cart.addDigitalVideoDics(dvd2);
		cart.addDigitalVideoDics(dvd3);
		System.out.println("Total cost = " + cart.totalCost());
		cart.removeDigitalVideoDics(dvd3);
		System.out.println("Total cost = " + cart.totalCost());
	}	// close main
}	// close Aims
